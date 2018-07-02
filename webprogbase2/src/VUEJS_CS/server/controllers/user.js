let express = require('express');
let router = express.Router();
let jwt = require('jsonwebtoken');
let User = require('../models/user');
let env = require('node-env-file');
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
        password: sha512(req.body.password, serverSalt).passwordHash
    };

    console.log(user);
    let token = jwtSignUser(user);
    if (!await User.getUserbyLogin(req.body.login)) {
        try {
            let img = await fs.readFile("./public/images/images.jpeg", async function(err, dat) {
                user.image = {
                    data: dat,
                    mimetype: "jpeg"
                }
                await User.createUser(user);
            });
            ///await User.createUser(user);
            res.send({
                user: user,
                token: token
            });
        } catch (err) {
            res.status(400).send({
                error: err
            })
            console.log(err);
        }
    } else {
        res.send({ error: "this login is already used" });
    }

});

router.post('/login', async function(req, res) {
    try {
        let user = await User.getUserByLoginAndPasshash(req.body.login, sha512(req.body.password, serverSalt).passwordHash);
        console.log(req.body);
        let U = {
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

module.exports = router;