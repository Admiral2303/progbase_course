const express = require('express');
const router = express.Router();
let storage = require('./../modules/bd_books');
let check = require('./../modules/check');
let path = require('path');
let cloudinary = require('cloudinary');

cloudinary.config({
    cloud_name: 'booka-herokuapp-com',
    api_key: '287166916858793',
    api_secret: '-LVPCQmUbsmKmzodih-fBzn1Rf8'
});




// router.get('/',
//     async(req, res) => {
//         console.log("+++++");
//         // res.render('books', { user: req.user });
//         res.sendFile('../../views/books.ejs', { root: path.join(__dirname, 'views'), user: req.user });
//     });

router.get('/data', async(req, res) => {

    let count = 2;
    console.log("----");
    storage.getAll()
        .then(books => {
            res.json(books);
        })
})

router.get('/', async(req, res) => {
    // console.log("+++++");
    // res.render('books', { user: req.user });
    //res.sendFile('books.html', sendFileOpts);
    res.render('books', { user: req.user });
});
// router.get("/", check.checkAuth, async(req, res) => {

//     res.sendFile('index.html', sendFileOpts);
//     // let count = 2;
//     // storage.getAll()
//     //     .then(books => {
//     //         let pages = Math.ceil(books.length / count);
//     //         let currentpage = req.query.page;
//     //         let currentarr = books.slice((currentpage - 1) * count, currentpage * count);
//     //         let data = {
//     //             books: currentarr,
//     //             page: req.query.page,
//     //             pages: pages,
//     //             user: req.user
//     //         }
//     //         res.render('books', data);
//     //         //res.json(currentarr);
//     //     })
//     //     .catch(error => {
//     //         res.sendStatus(404);
//     //     })
// });

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

router.post("/create", check.checkAuth, async(req, res) => {
    let date = Date.now();
    let IMG = (await loadImage(req.files.ava.mimetype, req.files.ava.data));

    let book = {
        id: 0,
        name: req.body.name,
        authorname: req.body.authorname,
        authorSurname: req.body.authorSurname,
        year: req.body.year,
        pages: req.body.pages,
        language: req.body.language,
        image: IMG,
        date: date,
        content: req.body.content
    };
    storage.create(book);
    res.redirect('/');
});


function loadImage(mimetype, buffer, id) {
    return new Promise((resolve, reject) => {
        cloudinary.v2.uploader.upload(`data:${mimetype};base64,${buffer.toString('base64')}`, { public_id: id }, (err, result) => {
            resolve(result.secure_url);
        });
    });
}

function deleteImage(public_id) {
    return new Promise((resolve, reject) => {
        cloudinary.v2.uploader.destroy(public_id, (err, result) => {
            if (err) reject(err);
            else resolve(result);
        });
    });
}


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