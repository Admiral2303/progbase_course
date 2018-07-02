let fs = require('fs');
const read = require('./read');








// name, author, date,year,pages
async function createBook() {
	// let testName =  /^[A-ZА-Я'][a-zA-Zа-яА-Я-' ]+[a-zA-Zа-яА-Я']?$/;
	let testName = /^[A-ZА-Я'][a-zа-я-' ]+[a-zA-Zа-яА-Я']?$/;

	// console.log(prov.test("Fvvv"));
	let name = await read.readConsole("Name:", "");
	if (testName.test(name) == false) throw new Error("Error in name");
	let surname = await read.readConsole("Surname:", "");
	if (testName.test(surname) == false) throw new Error("Error in name");
	let year = await read.readConsole("Year:", "");
	let testYear = /(\d{4})/;
	if (testYear.test(year) == false) throw new Error("Error it's not a year");
	// if(isNaN(year)) throw new Error("Error its not a number");
	let pages = await read.readConsole("Pages:", "");
	if (isNaN(pages)) throw new Error("Error its not a number");
	let Data = new Date();
	let Year = Data.getFullYear();
	let Month = Data.getMonth();
	let Day = Data.getDate();
	let data = await ReadFile('books.json');
	let jsonArr = JSON.parse(data.toString());
	let id = jsonArr.id + 1;;
	let date = Day + "-" + Month + "-" + Year;
	let book = {
		id: id,
		name: name,
		surname: surname,
		date: date,
		year: year,
		pages: pages
	};
	console.clear();
	return book;

}




// function create(book) {
// 	return new Promise(function (resolve, reject) {
// 		ReadFile("b.json")
// 			.then(buffer => {
// 				let jsonArr = JSON.parse(buffer.toString());
// 				jsonArr.books.push(book);
// 				jsonArr.id += 1;
// 				console.log(jsonArr);

// 				fs.writeFile('b.json', JSON.stringify(jsonArr, null, 4), (err, data) => {
// 					if (err) reject(err);
// 					else resolve(book);
// 				});
// 			})
// 			.catch(error => {
// 				console.log('Oops, there was some error');
// 			})
// 	});
// }

 function create(book) {
	return new Promise(async function (resolve, reject) {
		let buffer = await read.ReadFile("b.json");
		let jsonArr = JSON.parse(buffer.toString());
		book.id = jsonArr.id + 1;
		jsonArr.books.push(book);
		jsonArr.id += 1;
		// console.log(jsonArr);
		fs.writeFile('b.json', JSON.stringify(jsonArr, null, 4), (err, data) => {
			if (err) reject(err);
			else resolve(book);
		});
			
});
}
// let book = {
// 	id: 0,
// 	name: "name",
// 	authorname: "authorname",
// 	authorSurname: "authorSurname",
// 	year: "year",
// 	pages: "pages",
// 	language:"language",
// 	// avaname: null
// 	image: "image"
// };
// create(book);


function getAll() {
	return new Promise(function (resolve, reject) {
		read.ReadFile('./b.json')
			.then((buffer) => {
				let jsonArr = JSON.parse(buffer.toString());
				resolve(jsonArr.books);
			})
			.catch(error => {
				reject(error);
			});
	});
}




function getById(id) {
	return new Promise(function (resolve, reject) {
		getAll()
			.then((jsonArr) => {
				for (let book of jsonArr) {
					if (book.id == id) {
						resolve(book);
					}
				}
				reject("error");
			})
	});
}


function update(id) {
	return new Promise(function (resolve, reject) {
		read.ReadFile("books.json")
			.then(async (data) => {
				let jsonArr = JSON.parse(data.toString());
				let i = 0;
				for (let book of jsonArr.books) {
					if (book.id == id) {
						break;
					}
					i++;
				}
				if (i < jsonArr.books.length) {
					let object = await createBook();
					object.id = jsonArr.books[i].id;
					jsonArr.books[i] = object;
					fs.writeFileSync('books.json', JSON.stringify(jsonArr, null, 4), 'utf8');
					resolve(object);
				}
				else {
					resolve(data);
				}
			})
			.catch(error => {
				reject(error);
			});
	});
}



 function findbyName(name){
	return new Promise(function   (resolve, reject) {
	getAll()
		.then((array) => {
			let searchArr = array.filter(function filterbyName(obj){
				if(obj.name === name){
					return true;
				}
				return false;
			})
				resolve(searchArr);
			});
		}
)
}
// findbyName("Оно")
// 	.then((data) => {
// 		console.log(data);
// 	});



function remove(id) {
	return new Promise(function (resolve, reject) {
		read.ReadFile("b.json")
			.then(async (data) => {
				let jsonArr = JSON.parse(data.toString());
				let i = 0;
				for (let book of jsonArr.books) {
					if (book.id == id) {
						break;
					}
					i++;
				}
				let object;
				if (i < jsonArr.books.length) {
					object = jsonArr.books[i];
					jsonArr.books.splice(i, 1);
				}
				fs.writeFileSync('b.json', JSON.stringify(jsonArr, null, 4), 'utf8');
				resolve(object);
			})
			.catch(err => {
				reject(err);
			})
	});
}


module.exports = {
	getAll,
	createBook,
	create,
	getById,
	update,
	remove,
	findbyName
};





// var prov =  /^[A-ZА-Я'][a-zA-Zа-яА-Я-' ]+[a-zA-Zа-яА-Я']?$/;
// console.log(prov.test("Fvvv"));










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


// {
//     "books" :[
//         {
//         "id": 1,
//         "name": "dfdf",
//         "author": "fdfd",
//         "date": "fdfd",
//         "year": "fdf",
//         "pages": "dfd"
//     },
//     {
//         "id": 3,
//         "name": "11",
//         "surname": "1",
//         "date": "3-9-2017",
//         "year": "1",
//         "pages": "1"
//     },
//     {
//         "id": 6,
//         "name": "54",
//         "surname": "5",
//         "date": "3-9-2017",
//         "year": "5",
//         "pages": "5"
//     },
//     {
//         "id": 5,
//         "name": "285",
//         "surname": "5",
//         "date": "3-9-2017",
//         "year": "5",
//         "pages": "5"
//     }

// ],
//     "id": 5
// }