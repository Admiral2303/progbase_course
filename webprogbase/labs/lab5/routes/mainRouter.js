const express = require('express');
const router = express.Router();
let storage = require('./../modules/bd_books');
let check = require('./../modules/check');
router.get("/", (req, res) => {
    //res.cookie('cart', 'test', { expires: new Date(Date.now() + 10000), httpOnly: true });
    // console.log('Cookies: ', req.cookies);
    res.render('index', {
        user: req.user
    });
});
// router.get("/input", (req, res) => {
//     res.render('input', { book });
// });

router.get("/search", check.checkAuth, (req, res) => {
    res.render('search', { user: req.user });
});


router.get("/profile", check.checkAuth, (req, res) => {
    res.render('profile', { user: req.user });
});

router.post("/delete/:id", (req, res) => {
    storage.remove(req.params.id);
    res.redirect('/books?page=1');
});

module.exports = router;