const express = require('express');
const router = express.Router();
let storage = require('./../modules/bd_books');
let user = require('./../modules/bd_user');
let check = require('./../modules/check');

const crypto = require('crypto');

let bodyParser = require('body-parser');
const busboyBodyParser = require('busboy-body-parser');
let auth = require('basic-auth');


const serverSalt = "45%sAlT_";

function sha512(password, salt) {
    const hash = crypto.createHmac('sha512', salt);
    hash.update(password);
    const value = hash.digest('hex');
    return {
        salt: salt,
        passwordHash: value
    };
};



router.get('/', (req, res) => {
    res.status(200).send({
        "books_url": "https:/localhost:23000/api/v1/books",
        "book_url": "https:/localhost:23000/api/v1/books/{book_id}",
        "book_create_url": "https:/localhost:23000/api/v1/books/create",
        "book_delete_url": "https:/localhost:23000/api/v1/books/{book_id}",
        "users_url": "https:/localhost:23000/api/v1/users",
        "users_create_url": "https:/localhost:23000/api/v1/users/create",
    });
});

router.get('/users', check.baseauth, async(req, res) => {
    // let credentials = auth(req);
    // if (!credentials || !(await user.getUserByLoginAndPasshash(credentials.name, sha512(credentials.pass, serverSalt).passwordHash))) {
    //     res.status(401).send({
    //         "success": false,
    //         "error": "Login or password is false"
    //     });
    // } else {
    user.getUsers()
        .then(users => {
            res.status(200).send(users);
        })
        .catch(err => {
            res.status(401).send({
                "success": false,
                "error": "No users"
            });
        });
    // }
});



router.get('/books/filter', async(req, res) => {
    console.log(req.query.page);
    console.log(req.query.name);
    let filter = req.query.name;
    let books = await storage.getAll();
    let count = 2;
    let booksarr = !filter ? books : books.filter(x => x.name.toLowerCase().includes(filter));
    let pages = Math.ceil(booksarr.length / count);
    let currentpage = 1;
    if (req.query.page) {
        currentpage = req.query.page;
    }
    let currentarr = booksarr.slice((currentpage - 1) * count, currentpage * count);

    let resp = {
            books: currentarr,
            pages: pages
        }
        // console.log(resp);
    res.json(resp);


})



router.post("/users/create", async(req, res) => {
    if (!await user.getUserbyLogin(req.body.login)) {
        if (req.body.name && req.body.login && req.body.password && req.body.year && req.body.email && req.files.image) {
            console.log("+++");
            let User = {
                name: req.body.name,
                login: req.body.login,
                password: sha512(req.body.password, serverSalt).passwordHash,
                year: req.body.year,
                email: req.body.email,
                role: "user",
                image: {
                    data: req.files.image.data,
                    mimetype: req.files.image.mimetype
                }
            };
            user.createUser(User)
                .then(() => {
                    res.status(200).send(User);
                });
        } else {
            return res.status(400).send({
                "success": false,
                error: "Всі поля обов'язкові до заповнення"
            });
        }
    } else {
        res.res.status(400).send({
            success: false,
            error: "Логін занятий"
        });
    }
});




router.get('/books', (req, res) => {
    let count = 2;
    console.log("+++");
    let searchreq = {}
    if (req.query.name) searchreq.name = req.query.name;
    if (req.query.authorname) searchreq.authorname = req.query.authorname;
    if (req.query.authorSurname) searchreq.authorSurname = req.query.authorSurname;
    if (req.query.year) searchreq.year = req.query.year;
    if (req.query.language) searchreq.language = req.query.language;
    storage.Book.find(searchreq, function(err, books) {
        let pages = Math.ceil(books.length / count);
        let currentpage = 1;
        let currentarr = [];
        currentarr = books;
        if (req.query.page) {
            currentpage = req.query.page;
        }
        currentarr = books.slice((currentpage - 1) * count, currentpage * count);
        let resp = {
            books: currentarr,
            pages: pages
        }
        res.send(resp);

    });
});



// router.get('/books', (req, res) => {
//     let count = 2;

//     console.log("+++");
//     let searchreq = {}
//     if (req.query.name) searchreq.name = req.query.name;
//     if (req.query.authorname) searchreq.authorname = req.query.authorname;
//     if (req.query.authorSurname) searchreq.authorSurname = req.query.authorSurname;
//     if (req.query.year) searchreq.year = req.query.year;
//     if (req.query.language) searchreq.language = req.query.language;
//     storage.Book.find(searchreq, function(err, books) {
//         let pages = Math.ceil(books.length / count);
//         let currentpage = 1;
//         let currentarr = [];
//         currentarr = books;
//         if (req.query.page) {
//             currentpage = req.query.page;
//             currentarr = books.slice((currentpage - 1) * count, currentpage * count);
//         }

//         if (req.query.page > pages) {
//             return res.status(400).send({
//                 "success": false,
//                 "error": "page " + req.query.page + " not found"
//             });

//         }
//         let resp = {
//             books: currentarr,
//             pages: pages
//         }
//         if (err) return res.status(500).send("There was a problem finding the books.");
//         res.status(200).send(resp);
//     });

// });



router.get("/books/:id", (req, res) => {
    storage.getById(req.params.id)
        .then(book => {
            book.image = " ";
            res.status(200).send(book);
        })
        .catch(error => {
            return res.status(500).send({
                success: false,
                error: "There was a problem finding the book."
            });
        })
});

router.post("/img", async(req, res) => {
    let date = Date.now();
    let book = {
        name: req.body.name,
        authorname: req.body.authorname,
        authorSurname: req.body.authorSurname,
        year: req.body.year,
        pages: req.body.pages,
        language: req.body.language,
        date: date,
        image: {
            data: req.files.image.data,
            mimetype: req.files.image.mimetype
        },
        content: req.body.content
    };
    let newbook = await storage.create(book);
    res.send(newbook);
});


router.post("/books/create", (req, res) => {
    let date = Date.now();
    console.log(req.body);
    // let credentials = auth(req);
    // if (!credentials || credentials.name !== 'Admiral2303' || credentials.pass !== '2303') {
    //     res.status(401).send({
    //         "success": false,
    //         "error": "Login or password is false"
    //     });
    // } else {
    try {
        if (req.body.name && req.body.authorname && req.body.authorSurname && req.body.year && req.body.pages && req.body.language && req.body.content && req.files.image) {
            let book = {
                name: req.body.name,
                authorname: req.body.authorname,
                authorSurname: req.body.authorSurname,
                year: req.body.year,
                pages: req.body.pages,
                language: req.body.language,
                date: date,
                image: {
                    data: req.files.image.data,
                    mimetype: req.files.image.mimetype
                },
                content: req.body.content
            };
            storage.create(book);
            res.status(200).send(book);
        } else {
            return res.status(400).send({
                "success": false,
                error: "All fields are required"
            });
        }
    } catch (err) {
        console.log(err);
        return res.status(500).send({
            "success": false,
            error: "There was a problem adding the information to the database."
        });
    }
    // }
});


router.delete("/books/:id", async(req, res) => {
    let credentials = auth(req);
    if (!credentials || !(await user.getUserByLoginAndPasshash(credentials.name, sha512(credentials.pass, serverSalt).passwordHash))) {
        res.status(401).send({
            "success": false,
            "error": "Login or password is false"
        });
    } else {
        try {
            let book = await storage.remove(req.params.id);
            res.status(200).send(book);
        } catch (err) {
            console.log(err);
            res.status(500).send({
                "success": false,
                "error": "Error removing book"
            });
        }
    }
});



module.exports = router;







/*
 console.log(model.books);
    let bookS = [
        { name: "sdsds" },
        { name: "sddsfsf" }
    ]


    let template = document.getElementById("my-list-template").innerHTML;
    // згенерувати HTML строку на основі шаблону і даних
    let renderedHTML = Mustache.render(template, { list: bookS });
    // помістити строку з HTML всередину елемента з ідентифікатором "my-list"
    document.getElementById("list-group").innerHTML = renderedHTML;




    console.log("++");
    */