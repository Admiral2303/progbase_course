const express = require('express');
const router = express.Router();
let check = require('./../modules/check');
let user = require('./../modules/bd_user');


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



router.get("/", check.checkAuth, (req, res) => {
    res.render('profile', { user: req.user, user1: "" });
});


router.get("/:id", check.checkAuth, async(req, res) => {
    try {
        let getuser = await user.getUserById(req.params.id);
        res.render('profile', { user: req.user, user1: getuser });
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});


router.post("/updateUser", check.checkAuth, async(req, res) => {
    try {
        if (req.body.name) {
            await user.updateUserfield(req.user._id, "name", req.body.name);
            res.redirect('/profile')
        }
        if (req.body.surname) {
            await user.updateUserfield(req.user._id, "surname", req.body.surname);
            res.redirect('/profile')
        }
        if (req.body.year) {
            let Data = new Date();
            let Year = Data.getFullYear();
            let age = Year - req.body.year;
            await user.updateUserfield(req.user._id, "year", age);
            res.redirect('/profile')
        }
        if (req.body.country) {
            await user.updateUserfield(req.user._id, "country", req.body.country);
            res.redirect('/profile')
        }
        if (req.body.city) {
            await user.updateUserfield(req.user._id, "city", req.body.city);
            res.redirect('/profile')
        }
        if (req.body.sex) {
            await user.updateUserfield(req.user._id, "sex", req.body.sex);
            res.redirect('/profile')
        }
        if (req.body.email) {
            await user.updateUserfield(req.user._id, "email", req.body.email);
            res.redirect('/profile')
        }
        if (req.body.login) {
            await user.updateUserfield(req.user._id, "login", req.body.login);
            res.redirect('/profile')
        }
        if (req.body.information) {
            await user.updateUserfield(req.user._id, "information", req.body.information);
            res.redirect('/profile')
        }
        if (req.body.password) {
            let ps = sha512(req.body.password, serverSalt).passwordHash;
            await user.updateUserfield(req.user._id, "password", sha512(req.body.password, serverSalt).passwordHash);
            res.redirect('/profile')
        }
        if (req.files) {
            let image = {
                data: req.files.ava.data,
                mimetype: req.files.ava.mimetype
            }
            if (req.files.ava.data != null) {
                image = {
                    data: req.files.ava.data,
                    mimetype: req.files.ava.mimetype
                }
                console.log("+++");
                user.updateUserfield(req.user._id, "image", image);
            }
            res.redirect('/profile')
        }
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});





module.exports = router;