let express = require('express');
let router = express.Router();
let jwt = require('jsonwebtoken');
let User = require('../modules/bd_user');
let env = require('node-env-file');
let storage = require('./../modules/bd_books');
let isAuthenticated = require('./../modules/isAuthenticated');
const fs = require('fs');
env('./config' + '/.env');



const crypto = require('crypto');
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






function jwtSignUser(user) {
    const ONE_WEEK = 60 * 60 * 24 * 7
    return jwt.sign(user, process.env.JWTSECRET, {
        expiresIn: ONE_WEEK
    })
}

router.post('/register', async function(req, res) {
    console.log(req.body);
    let user = {
        login: req.body.login,
        password: sha512(req.body.password, serverSalt).passwordHash,
        name: req.body.name,
        surname: req.body.surname,
        email: req.body.email,
        img: "http://res.cloudinary.com/booka-herokuapp-com/image/upload/v1512760269/images_dqi8fx.jpg"
    };
    console.log(user);
    // let token = jwtSignUser(user);
    // console.log(token);
    if (!await User.getUserbyLogin(req.body.login)) {

        try {
            await User.createUser(user);
            // console.log(u);
            res.send({ status: "ok" });
        } catch (err) {
            // res.status(400).send({
            //     error: 'err'
            // })
            console.log(err);
        }
    } else {
        res.send({ error: "this login is already used" });
    }
});


router.post('/wallet', async function(req, res) {
    console.log("++++")
    try {
        await User.SetWallet(req.body.user_id, req.body.wallet);
        res.send({ status: true });
    } catch (err) {
        console.log(err);
    }

});


router.post('/rentBook', async function(req, res) {
    // console.log(req.body);
    await User.addRentBooks(req.body.rentuser_id, req.body.book_id);
    await User.addBooksInRent(req.body.book_owner_id, req.body.book_id);
    await storage.addBooktoRent(req.body.book_id, "true");
    await storage.SetPayflag(req.body.book_id, "false");
    res.send({ status: true });

});



router.post('/login', async function(req, res) {
    try {
        console.log(sha512(req.body.password, serverSalt).passwordHash);
        let user = await User.getUserByLoginAndPasshash(req.body.login, sha512(req.body.password, serverSalt).passwordHash);

        let U = {
            _id: user._id,
            login: user.login,
            password: user.password,
            name: user.name,
            surname: user.surname,
            email: user.email
        };
        let token = jwtSignUser(U);
        res.send({
            user: user,
            token: token
        })
    } catch (err) {
        res.send({ error: "errrr" });
        console.log(err);
    }
});



router.get('/userbyId', async function(req, res) {
    console.log(req.query);
    let user = await User.getUserById(req.query.id);
    res.send({ user: user });
});



router.post('/update', async function(req, res) {
    console.log(req.body);
    await User.updateUser(req.body);
    res.send({ status: true });
});

router.post('/changepassword', async function(req, res) {
    // let pass = (req.body.password).toString();
    let password = sha512(req.body.pass, serverSalt).passwordHash;
    await User.updatePass(req.body._id, password);
    res.send({ status: true });
});


router.post('/changeImage', async function(req, res) {
    //console.log(req.files);
    console.log("++++++")

    let image = {
        data: req.files.image.data,
        mimetype: req.files.image.mimetype
    }
    await User.updateImage(req.body.id, image);
    res.send({ status: true });
});




router.post("/addbookmark/:id", isAuthenticated, async(req, res) => {
    try {
        await User.addBookmarktoUser(req.user._id, req.params.id);
        res.send({ status: true })
    } catch (err) {
        console.log(err)
            //res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});

router.post("/deletebookmark/:id", isAuthenticated, async(req, res) => {
    try {
        await User.deleteUserbookmark(req.user._id, req.params.id);
        res.send({ status: true });
    } catch (err) {
        console.log(err);
        //res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});

module.exports = router;