let fs = require('fs');
const read = require('./read');


function ReadFile(filename) {
	return new Promise(function (resolve, reject) {
		fs.readFile(filename, (err, data) => {
			if (err) reject(err);
			else {
				resolve(data.toString());
			}
		});
	});
}






// name, author, date,year,pages
async function createBook() {
	let name = await read.readConsole("Name:", "");
	let surname = await read.readConsole("Surname:", "");
	let year = await read.readConsole("Year:", "");
	if(isNaN(year)) throw new Error("Error its not a number");
	let pages = await read.readConsole("Pages:", "");
	if(isNaN(pages)) throw new Error("Error its not a number");
	let Data = new Date();
	let Year = Data.getFullYear();
	let Month = Data.getMonth();
	let Day = Data.getDate();
	let date = Day + "-" + Month + "-" + Year;
	let book = {
		name: name,
		surname: surname,
		date: date,
		year: year,
		pages: pages
	};
	console.clear();
	return book;

}

// createBook()
// 	.then(bo => console.log(bo));


function create(book) {
	return new Promise(function (resolve, reject) {
		ReadFile("books.json")
			.then(buffer => {
				let jsonArr = JSON.parse(buffer.toString());
				jsonArr.push(book);
				fs.writeFile('books.json', JSON.stringify(jsonArr, null, 4), (err, data) => {
					if (err) reject(err);
					else resolve(book);
				});
			})
			.catch(error => {
                console.log('Oops, there was some error');
                })
	});
}


function getAll() {
	return new Promise(function (resolve, reject) {
		ReadFile('books.json')
			.then((buffer) => {
				let jsonArr = JSON.parse(buffer.toString());
				resolve(jsonArr);
			})
			.catch(error => {
                console.log('Oops, there was some error');
                });
	});
}




function getById(index) {
	return new Promise(function (resolve, reject) {
		getAll()
			.then((jsonArr) => {
				let object = jsonArr[index];
				resolve(object);
			})
			.catch(error => {
                console.log('Oops, there was some error');
                });
	});
}



function update(index, object) {
	return new Promise(function (resolve, reject) {
		getAll()
			.then((jsonArr) => {
				if(index <=jsonArr.length){	
					jsonArr[index] = object;
					fs.writeFileSync('books.json', JSON.stringify(jsonArr, null, 4), 'utf8');
					resolve(object);
				}
				else{
					resolve(object);
				}
			})
	});
}

function remove(index) {
	return new Promise(function (resolve, reject) {
		getAll()
			.then((jsonArr) => {
				let object = jsonArr[index];
				let length = jsonArr.length;
				if (index === 0) {
					jsonArr.shift();
				}
				else if (index === length - 1) {
					jsonArr.pop();
				}
				else {
					jsonArr.splice(index, 1);

				}
				// console.log(jsonArr);
				fs.writeFileSync('books.json', JSON.stringify(jsonArr, null, 4), 'utf8');
				resolve(object);
			})
			.catch(error => {
                console.log('Oops, there was some error');
                });
	});
}



module.exports = {
	getAll,
	createBook,
	create,
	ReadFile,
	getById,
	update,
	remove
};
















// let b = createBook("Ye", "sds", "sss", 2012, 145);
// create(b);


// remove(1);


// let obj = createBook("Sashko", "Korovii", 2015,18,201);
// update(1, obj);



// getById(0)
// 	.then((object) => {
// 		console.log(object);
// 	});






// ReadFile("books.json")
// 	.then(jsonArr => create(jsonArr, "Illya", "Telefus", 25, 1999, 756))
// 	.then(book => console.log(book));



// getAll()
// 	.then((jsonArr) => {
// 		jsonArr.map(function(object) {
// 			 console.log(`name: '${object.name}'`);
// 			 console.log(`author: '${object.author}'`);
// 			 console.log(`date: '${object.date}'`);
// 			 console.log(`year: '${object.year}'`);
// 			 console.log(`pages: '${object.pages}'`);
// 			 console.log("\n");
// 		});
// 	});






// [
//     {
//         "name":"name",
//         "author":"author",
//         "date":50
//     },
//     {
//         "name":"n",
//         "author":"a",
//         "date":1
//     }
// ]

// [{"name":"name","author":"author","date":50,"year":2012,"pages":256},{"name":"a","author":"b","date":20,"year":2015,"pages":256}]