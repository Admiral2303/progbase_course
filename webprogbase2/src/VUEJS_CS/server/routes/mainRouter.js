const express = require('express');
const router = express.Router();

const crypto = require('crypto');




router.get("/", (req, res) => {
    res.render('index', {
        user: req.user,
        error: "0"
    });
});




router.get("/help", (req, res) => {
    res.render('help', {
        user: req.user
    });
});



module.exports = router;