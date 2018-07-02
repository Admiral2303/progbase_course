// const express = require('express');
// const app = express();
// const booksRouter = require('./routes/books');
// const ejs = require('ejs');
// let storage = require('./modules/books');
// app.use(express.static('public'));

// app.set("view engine", "ejs");
// let bodyParser = require('body-parser');
// app.use(bodyParser.urlencoded({ extended: false }));
// // app.use(express.bodyParser());
// app.use(bodyParser.json());


const booksRouter = require('./routes/books');
const searchRouter = require('./routes/search');

let express = require('express');
let bodyParser = require('body-parser');
const busboyBodyParser = require('busboy-body-parser');
let storage = require('./modules/books');
let app = express();

app.set('view engine', 'ejs');
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(busboyBodyParser());

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
// let images = {

// };

app.get("/", (req, res) => {
    res.render('index');
});
app.get("/input", (req, res) => {
    res.render('input', { book });
});

app.get("/search", (req, res) => {
    res.render('search');
});

app.get("/form", (req, res) => {
    res.render('form');

});

// app.get("/page/:index", (req, res) => {
// 	storage.getAll()
// 		.then(books => {
// 			let data = {
// 				searchReq: "",
// 				books: books,
// 				page: req.params.index
// 			}
// 			res.render('books', data);
// 		})
// 		.catch(error => {
// 			res.sendStatus(404);
// 		})
// });












// app.get("/searchbook", (req, res) => {
//     //console.log(req.query.name);
//     storage.findbyName(req.query.name).
//     then((arr) => {
//         let query = req.query.name;
//         let data = {
//             searchReq: query,
//             books: arr,
//             page: 1
//         }
//         res.render('searchres', data);
//     });
// });
// app.get("/searchbook/:page", (req, res) => {
//     storage.findbyName(req.query.name).
//     then((arr) => {
//         let query = req.query.name;
//         let data = {
//             searchReq: query,
//             books: arr,
//             page: req.params.page
//         }
//         res.render('searchres', data);
//     });
// });







app.post("/delete/:id", (req, res) => {
    console.log(req.params.id + "----------");
    storage.remove(req.params.id);
    res.redirect('/books?page=1');
});




app.use("/searchbook", searchRouter);

app.use("/books", booksRouter);


app.post("/create", (req, res) => {
    // book.name = req.body.name;
    // book.authorname = req.body.authorname;
    // book.authorSurname = req.body.authorSurname;
    // book.language = req.body.language;
    // book.year = req.body.year;
    // book.pages = req.body.pages;
    // book.image = req.body.name + ".jpg";
    // console.log(req.body);
    let Data = new Date();
    let Year = Data.getFullYear();
    let Month = Data.getMonth();
    let Day = Data.getDate();
    let date = Day + "-" + Month + "-" + Year;
    // console.log(date);
    console.log(req.body.content);
    let book = {
        id: 0,
        name: req.body.name,
        authorname: req.body.authorname,
        authorSurname: req.body.authorSurname,
        year: req.body.year,
        pages: req.body.pages,
        language: req.body.language,
        image: req.body.name + ".jpg",
        date: date,
        content: req.body.content
    };
    if (req.files.ava) {
        //let filename = req.files.ava.name;
        // images[filename] = req.files.ava;
        // book.avaname = filename;
        require("fs").writeFile("./public/images/" + book.image, req.files.ava.data, 'base64', function(err) {
            console.log(err);
        });
    }
    storage.create(book);
    res.redirect('/');
});







const PORT = 3001;
app.listen(PORT, function() {
    console.log(`Example app listening on port ${PORT}!`);
});