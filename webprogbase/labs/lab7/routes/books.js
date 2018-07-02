const express = require('express');
const router = express.Router();
let storage = require('./../modules/bd_books');
let check = require('./../modules/check');
let path = require('path');





router.get("/", check.checkAuth, async(req, res) => {


    let count = 2;
    storage.getAll()
        .then(books => {
            let pages = Math.ceil(books.length / count);
            let currentpage = req.query.page;
            let currentarr = books.slice((currentpage - 1) * count, currentpage * count);
            let data = {
                books: currentarr,
                page: req.query.page,
                pages: pages,
                user: req.user
            }
            res.render('books', data);
            //res.json(currentarr);
        })
        .catch(error => {
            res.sendStatus(404);
        })
});

router.get("/search", check.checkAuth, (req, res) => {
    res.render('search', { user: req.user });
});

router.post("/delete/:id", check.checkAuth, (req, res) => {
    storage.remove(req.params.id);
    res.redirect('/books?page=1');
});

router.get("/create", check.checkAuth, (req, res) => {
    console.log("sdfsdf");
    res.render('form', { user: req.user });
});
router.post("/create", check.checkAuth, (req, res) => {
    let date = Date.now();
    let book = {
        id: 0,
        name: req.body.name,
        authorname: req.body.authorname,
        authorSurname: req.body.authorSurname,
        year: req.body.year,
        pages: req.body.pages,
        language: req.body.language,
        image: {
            data: req.files.ava.data,
            mimetype: req.files.ava.mimetype
        },
        date: date,
        content: req.body.content
    };
    storage.create(book);
    res.redirect('/');
});


router.get("/:id", check.checkAuth, (req, res) => {
    storage.getById(req.params.id)
        .then(book => {
            res.render('book', {
                book: book,
                user: req.user
            });
        })
        .catch(error => {
            res.sendStatus(404);
        })
});












module.exports = router;