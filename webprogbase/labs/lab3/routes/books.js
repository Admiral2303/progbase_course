const express = require('express');
const router = express.Router();
let storage = require('./../modules/books');


 

router.get("/", (req, res) => {
    storage.getAll()
        .then(books => {
            let data = {
                books: books
            }
            res.render('books', data);
        })
        .catch(error => { 
            res.sendStatus(404);
        })
});


router.get("/:id", async(req, res) => {
    try{
        let book = await storage.getById(req.params.id);
        res.render('book', {book});
    }
    catch(err){
        res.sendStatus(404);
    }
});













// router.get("/json", (req, res) => {
// 	res.json(films);
// });

// router.get("/:index", (req, res) => {
// 	let index = req.params.index;
// 	if (index >=0 && index < books.length) {
		
// 		let data = {
// 			title: film.title,
// 			year: film.year,
// 			index: index
// 		};
// 		res.render('film', data);
// 	} else {
// 		res.status(404).end(`No film with index ${index} found`);
// 	}
// });

// router.get("/:index/json", (req, res) => {
// 	let index = req.params.index;
// 	if (index >=0 && index < films.length) {
// 		res.json(films[index]);
// 	} else {
// 		res.status(404).end(`No film with index ${index} found`);
// 	}
// });

module.exports = router;