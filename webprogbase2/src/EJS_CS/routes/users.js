const express = require('express');
const router = express.Router();
let check = require('./../modules/check');
let user = require('./../modules/bd_user');
let storage = require('./../modules/bd_books');



router.get("/", check.checkAuth, check.checkAdmin, async(req, res) => {
    try {
        let allUsers = await user.getUsers();
        res.render('users', {
            users: allUsers,
            user: req.user
        });
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});

router.get("/users/:id", check.checkAuth, check.checkAdmin, async(req, res) => {
    res.redirect('/users');
});


router.post("/addbookmark/:id", check.checkAuth, async(req, res) => {
    try {
        await user.addBookmarktoUser(req.user._id, req.params.id);
        let url = "/books/" + req.params.id;
        res.redirect(url);
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});

router.post("/deletebookmark/:id", check.checkAuth, async(req, res) => {
    try {
        await user.deleteUserbookmark(req.user._id, req.params.id);
        let url = "/books/" + req.params.id;
        res.redirect(url);
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});







module.exports = router;