let express = require('express');
let router = express.Router();
let jwt = require('jsonwebtoken');
let storage = require('../models/books');
let env = require('node-env-file');
const fs = require('fs');
env('./config' + '/.env');


router.get("/", (req, res) => {
    let count = 6;
    storage.getAll()
        .then(books => {
            console.log(books);
            let pages = Math.ceil(books.length / count);
            let currentpage = req.query.page;
            let currentarr = books.slice((currentpage - 1) * count, currentpage * count);
            let data = {
                books: currentarr,
                page: req.query.page,
                pages: pages,
                user: req.user,
                error: "",
                search: "0",
                userbooks: "0"
            }
            res.send(data);
        })
        .catch(error => {
            res.render('error', { error: "500", text: 'Internal Server Error' });
        })
});

router.post("/create", async(req, res) => {
    console.log(req.body);

    res.send({ name: "sdsd" });
    /*try {
        let date = Date.now();
        let book = {
            name: req.body.name,
            authorname: req.body.authorname,
            authorSurname: req.body.authorSurname,
            year: req.body.year,
            pages: req.body.pages,
            language: req.body.language,
            date: date,
            user_id: req.user._id,
            content: req.body.content
        };
        if (req.files.ava.data != null) {
            book.image = {
                data: req.files.ava.data,
                mimetype: req.files.ava.mimetype
            }
            let l = await storage.create(book);
            let idbook = await storage.getBookIdbyparams(book.name, book.authorname, book.authorSurname)
            user.addBooktoUser(req.user._id, idbook._id);
            
        } else {
            let img = await fs.readFile("./public/images/book.png", async function(err, dat) {
                book.image = {
                    data: dat,
                    mimetype: "png"
                }
                console.log(book);
                let l = await storage.create(book);
                let idbook = await storage.getBookIdbyparams(book.name, book.authorname, book.authorSurname)
                user.addBooktoUser(req.user._id, idbook._id);
                res.redirect('/books?page=1');
            });
        }
    } catch (error) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }*/
});









module.exports = router;