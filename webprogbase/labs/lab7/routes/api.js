const express = require('express');
const router = express.Router();
let storage = require('./../modules/bd_books');
let check = require('./../modules/check');

let auth = require('basic-auth');
// let user = auth(req)

// let methodOverride = require('method-override');
// let bodyParser = require('body-parser');
// let morgan = require('morgan');
// let restful = require('node-restful');
// let mongoose = restful.mongoose;
// var app = express();

// router.use(morgan('dev'));
// router.use(bodyParser.urlencoded({ 'extended': 'true' }));
// router.use(bodyParser.json());
// router.use(bodyParser.json({ type: 'application/vnd.api+json' }));
// router.use(methodOverride());







// let Resource = router.resource = restful.model('resource', mongoose.Schema({
//         title: String,
//         year: Number,
//     }))
//     .methods(['get', 'post', 'put', 'delete']);



// Resource.route('recommend.get', function(req, res, next) {
//     res.send('I have a recommendation for you!');
// });


// Resource.route('recommend', ['get', 'put', 'delete'], function(req, res, next) {});



// Resource.register(router, '/');









router.get('/books', function(req, res) {
    let count = 2;
    let credentials = auth(req);
    if (!credentials || credentials.name !== 'Admiral2303' || credentials.pass !== '2303') {
        res.status(401).send("There was a problem with auth");
    } else {
        let searchreq = {}
        if (req.query.name) searchreq.name = req.query.name;
        if (req.query.authorname) searchreq.authorname = req.query.authorname;
        if (req.query.authorSurname) searchreq.authorSurname = req.query.authorSurname;
        if (req.query.year) searchreq.year = req.query.year;
        if (req.query.language) searchreq.language = req.query.language;

        storage.Book.find(searchreq, function(err, books) {
            let pages = Math.ceil(books.length / count);
            let currentpage = 1;
            if (req.query.page) {
                currentpage = req.query.page;
            }
            let currentarr = books.slice((currentpage - 1) * count, currentpage * count);
            if (err) return res.status(500).send("There was a problem finding the books.");
            for (let book of books) {
                book.image = " ";
            }
            res.status(200).send(currentarr);
        });
    }
});


router.get("/books/:id", (req, res) => {
    storage.getById(req.params.id)
        .then(book => {
            book.image = " ";
            res.status(200).send(book);
        })
        .catch(error => {
            return res.status(500).send("There was a problem finding the book.");
        })
});


router.post("/create", (req, res) => {
    let date = Date.now();
    console.log(req.body);
    try {
        let book = {
            name: req.body.name,
            authorname: req.body.authorname,
            authorSurname: req.body.authorSurname,
            year: req.body.year,
            pages: req.body.pages,
            language: req.body.language,
            date: date,
            image: "",
            mimetype: "",
            content: req.body.content
        };
        storage.create(book);
        res.status(200).send(book);
    } catch (err) {
        return res.status(500).send("There was a problem adding the information to the database.");
    }
});


router.post("/delete/:id", async(req, res) => {
    try {
        let book = await storage.remove(req.params.id);
        // console.log(book);
        res.status(200).send(book);
    } catch (err) {
        console.log(err);
        res.status(500).send("Problem");
    }
});




module.exports = router;