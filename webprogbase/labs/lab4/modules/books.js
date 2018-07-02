let fs = require('fs');
const read = require('./read');




async function create(book) {
    // return new Promise(async function (resolve, reject) {
    let buffer = await read.ReadFile("b.json");
    let jsonArr = JSON.parse(buffer.toString());
    book.id = jsonArr.id + 1;
    jsonArr.books.push(book);
    jsonArr.id += 1;
    // console.log(jsonArr);
    fs.writeFile('b.json', JSON.stringify(jsonArr, null, 4), (err, data) => {
        if (err) return Promise.reject(err);
        else return Promise.resolve(book);
    });

    // });
}


async function getAll() {
    let buffer = await read.ReadFile('./b.json')
    let jsonArr = JSON.parse(buffer.toString());
    console.log(jsonArr);
    if (jsonArr) return Promise.resolve(jsonArr.books);
    else return Promise.reject(error);
}





async function getById(id) {
    let jsonArr = await getAll();
    let book = jsonArr.find(function findId(b) {
        return b.id == id;
    });
    if (book) return Promise.resolve(book);
    else return Promise.reject("error");
}






async function findbyName(name) {
    //return new Promise(function(resolve, reject) {
    let array = await getAll();
    let searchArr = array.filter(function filterbyName(obj) {
        if (obj.name === name) {
            return true;
        }
        return false;
    })
    if (searchArr) return Promise.resolve(searchArr);
    else return Promise.reject("error");

}




async function remove(id) {
    // return new Promise(function(resolve, reject) {
    let data = await read.ReadFile("b.json")
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
    return Promise.resolve(object);

}


module.exports = {
    getAll,
    create,
    getById,
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