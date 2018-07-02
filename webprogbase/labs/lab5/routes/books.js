const express = require('express');
const router = express.Router();
let storage = require('./../modules/bd_books');
let check = require('./../modules/check');



router.get("/", check.checkAuth, (req, res) => {
    let count = 5;
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
        })
        .catch(error => {
            res.sendStatus(404);
        })
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