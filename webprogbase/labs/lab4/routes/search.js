const express = require('express');
const router = express.Router();
let storage = require('./../modules/books');


router.get("/", (req, res) => {
    //console.log(req.query.name);
    let count = 5;


    storage.findbyName(req.query.name).
    then((arr) => {
        let query = req.query.name;
        let pages = Math.ceil(arr.length / count);
        let currentpage = req.query.page;
        console.log(arr.length);
        let currentarr = arr.slice((currentpage - 1) * count, currentpage * count);
        let data = {
            pages: pages,
            searchReq: query,
            books: currentarr,
            page: req.query.page
        }
        res.render('searchres', data);
    });
});


// router.get("/:page", (req, res) => {
//     storage.findbyName(req.query.name).
//     then((arr) => {
//         let query = req.query.name;
//         let data = {
//             searchReq: query,
//             books: arr,
//             page: req.params.page
//         }
//         res.render('searchres', data);
//     });
// });


module.exports = router;