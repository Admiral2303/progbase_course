const express = require('express');
const router = express.Router();
let storage = require('./../modules/bd_books');
let isAuthenticated = require('./../modules/isAuthenticated');

let user = require('./../modules/bd_user');
let test = require('./../modules/bd_test');

let payments = require('./../modules/bd_payments');



const fs = require('fs');

router.get("/", (req, res) => {
    // console.log(req.user);
    let count = 6;
    storage.getAll()
        .then(resbooks => {
            let books = [];
            for (let book of resbooks) {
                if (book.rentflag != 'true') {
                    books.push(book);
                } else {
                    console.log("++++")
                }
            }
            let pages = Math.ceil(books.length / count);
            let currentpage = req.query.page;
            let currentarr = books.slice((currentpage - 1) * count, currentpage * count);
            let data = {
                    books: currentarr,
                    page: req.query.page,
                    pages: pages,
                    user: req.user,
                }
                //console.log(data);
            res.send(data);
        })
        .catch(error => {
            res.send({ error: "Internal Server Error", errorcode: '500' })
        })
});






// router.get("/", isAuthenticated, async(req, res) => {

//     let booksinrent = await storage.getUserRentBooks();

//     res.send(data);
// });



router.get("/rentbooks", isAuthenticated, async(req, res) => {
    try {
        let user_id = req.query.id;
        let rentBooksId = await user.getRentBooks(user_id);
        let books = [];
        for (let bookId of rentBooksId) {
            let pay = await test.takeWebmoneypay(bookId);
            if (pay != false) {
                if (pay.processing != true && pay.processing != 'true') {
                    await storage.SetPayflag(bookId, "true");
                    let rentbook = await storage.getById(bookId);
                    let date = new Date(pay.test.date_to_return);
                    let Payment = {
                        renter: user_id,
                        owner: rentbook.user_id,
                        datetoreturn: date,
                        book: bookId,
                        wallet: pay.test.LMI_PAYER_PURSE,
                        payment_amount: pay.test.LMI_PAYMENT_AMOUNT
                    }
                    await payments.addPayment(Payment);
                    await test.SetPayProcessing(pay._id, "true");
                }
            } else {
                await storage.SetPayflag(bookId, "false");
            }

            let book = await storage.getById(bookId);
            books.push(book);
        }
        let Payments = await payments.getPayments();
        let send = [];
        if (Payments.length != 0) {
            for (let book of books) {
                for (let pay of Payments) {
                    if (book._id == pay.book) {
                        let objtoreturn = {
                            book: book,
                            payment: pay
                        };
                        send.push(objtoreturn);

                        break;
                    } else if (Payments.indexOf(pay) == (Payments.length - 1)) {
                        send.push({ book: book, payment: null });
                        break;
                    }
                }
            }
            res.send({ books: send });
        } else {
            let send = [];
            for (let b of books) {
                let objtoreturn = {
                    book: b,
                    payment: {}
                };
                send.push(objtoreturn);
            }
            res.send({ books: send });
        }
    } catch (err) {
        res.send({ error: "Internal Server Error", errorcode: '500' })
    }

});





router.get("/booksinrent", isAuthenticated, async(req, res) => {
    try {
        let user_id = req.query.id;
        let rentBooksId = await user.getBooksinrent(user_id);
        console.log(rentBooksId);
        let books = []
        for (let bookId of rentBooksId) {
            let book = await storage.getById(bookId);
            books.push(book);
        }
        let Payments = await payments.getPayments();
        let send = [];
        if (Payments.length != 0) {
            for (let book of books) {
                for (let pay of Payments) {
                    if (book._id == pay.book) {
                        let renter = await user.getUserById(pay.renter);
                        console.log(renter);
                        let objtoreturn = {
                            book: book,
                            payment: pay,
                            renter: renter
                        };
                        send.push(objtoreturn);
                    }
                }
            }
            res.send({ books: send });
        } else {
            let send = [];
            for (let b of books) {
                let objtoreturn = {
                    book: b,
                    payment: {}
                };
                send.push(objtoreturn);
            }
            // console.log(send)
            res.send({ books: send });
        }
    } catch (err) {
        res.send({ error: "Internal Server Error", errorcode: '500' })
    }

});




router.post("/booksinrent/delete", isAuthenticated, async(req, res) => {
    try {
        let book_id = req.body.book_id;
        let owner_id = req.body.owner_id;
        console.log(req.body);
        await user.deleteBookinrent(owner_id, book_id);
        res.send({ status: true });
    } catch (err) {
        console.log(err);
    }
});


router.post('/returnbooktorent', isAuthenticated, async(req, res) => {
    try {
        let book_id = req.body.book_id;
        let user_id = req.body.user_id;
        await user.deleteBookinrent(user_id, book_id);
        let users = await user.getUsers();

        for (let User of users) {
            for (let bookId of User.rentbooks) {
                if (book_id == bookId) {
                    await user.deleteRentBook(User._id, book_id);
                    console.log("---------------------------")
                }
            }
        }
        await storage.addBooktoRent(book_id, "false");
        res.send({ status: true });
    } catch (err) {
        console.log(err);
    }

});


router.post("/rentbooks/delete", isAuthenticated, async(req, res) => {
    try {
        let book_id = req.body.book_id;
        let user_id = req.body.user_id;
        await user.deleteRentBook(user_id, book_id);
        await storage.addBooktoRent(book_id, "false");
        res.send({ status: true });
    } catch (err) {
        console.log(err);
    }
});




router.post("/delete/:id", isAuthenticated, async(req, res) => {
    try {
        let book = await storage.getById(req.params.id);
        userId = book.user_id;
        await storage.remove(req.params.id);
        await user.deleteUserbook(userId, req.params.id);
        let users = await user.getUsers();
        for (let User of users) {
            for (let bookmark of User.bookmarks) {
                if (bookmark == req.params.id) {
                    await user.deleteUserbookmark(User._id, req.params.id);
                }
            }
        }
        res.send({ status: true });
    } catch (err) {
        res.send({ error: "Internal Server Error", errorcode: '500' })
    }
});

router.get("/create", isAuthenticated, isAuthenticated, (req, res) => {
    try {
        res.render('addbook', { user: req.user });
    } catch (err) {
        res.send({ error: "Internal Server Error", errorcode: '500' })
    }
});




router.post("/addcoment", isAuthenticated, isAuthenticated, async(req, res) => {
    try {
        await storage.addComentToBook(req.body.book_id, req.body.comment, req.user._id);
        let src = "/books/" + req.body.book_id;
        res.send({ status: true });
    } catch (err) {
        res.send({ error: "Internal Server Error", errorcode: '500' })
    }
})



router.get("/search", isAuthenticated, async(req, res) => {
    let count = 6;
    let searchreq = {
        name: req.query.name,
        authorname: req.query.authorname,
        authorSurname: req.query.authorSurname,
        year: req.query.year,
        language: req.query.language
    }
    storage.searchBooks(searchreq)
        .then(resbooks => {
            let books = [];
            for (let book of resbooks) {
                if (book.rentflag != 'true') {
                    books.push(book);
                } else {
                    console.log("++++")
                }
            }

            //console.log(books);
            let pages = Math.ceil(books.length / count);
            let currentpage = req.query.page;
            let currentarr = books.slice((currentpage - 1) * count, currentpage * count);
            let data = {
                books: currentarr,
                page: req.query.page,
                pages: pages,
                userbooks: "0"
            }

            res.send(data);
        })
        .catch(error => {
            res.send({ error: "Internal Server Error", errorcode: '500' })

        });
});




router.get('/search1', async(req, res) => {
    console.log(req.query);
    let resbooks = await storage.getAll();
    let count = 6;
    let books = [];
    for (let book of resbooks) {
        if (book.rentflag != 'true') {
            books.push(book);
        } else {
            console.log("++++")
        }
    }
    let booksarr = books;
    if (req.query.name != 'null' && req.query.name != '' && req.query.name != 'undefined') {
        let filter = req.query.name;
        booksarr = !filter ? books : books.filter(x => x.name.toLowerCase().includes(filter));

    }
    if (req.query.authorname != 'null' && req.query.authorname != '' && req.query.authorname != 'undefined') {
        let filter = req.query.authorname;
        booksarr = !filter ? booksarr : booksarr.filter(x => x.authorname.toLowerCase().includes(filter));
    }
    if (req.query.authorSurname != 'null' && req.query.authorSurname != '' && req.query.authorSurname != 'undefined') {
        let filter = req.query.authorSurname;
        booksarr = !filter ? booksarr : booksarr.filter(x => x.authorSurname.toLowerCase().includes(filter));
    }
    if (req.query.language != 'null' && req.query.language != '' && req.query.language != 'undefined') {
        let filter = req.query.language;
        booksarr = !filter ? booksarr : booksarr.filter(x => x.language.includes(filter));

    }
    let pages = Math.ceil(booksarr.length / count);
    let currentpage = 1;
    if (req.query.page) {
        currentpage = req.query.page;
    }
    let currentarr = booksarr.slice((currentpage - 1) * count, currentpage * count);
    let resp = {
        books: currentarr,
        pages: pages
    }
    res.send(resp);
})








router.post("/update", isAuthenticated, async(req, res) => {
    try {
        let book = {
            name: req.body.name,
            authorname: req.body.authorname,
            authorSurname: req.body.authorSurname,
            year: req.body.year,
            pages: req.body.pages,
            language: req.body.language,
            user_id: req.user._id,
            content: req.body.content
        };
        await storage.updateBook(req.body._id, book);
        res.send({ status: true });
    } catch (error) {
        res.send({ error: "Internal Server Error", errorcode: '500' })
    }
});




router.post("/updateBookAva", isAuthenticated, async(req, res) => {

    try {
        if (req.files.image.data != null) {
            image = {
                data: req.files.image.data,
                mimetype: req.files.image.mimetype
            }
            await storage.updateBookImage(req.body.book_id, image);
        }
        res.send({ status: true });
    } catch (error) {
        res.send({ error: "Internal Server Error", errorcode: '500' })
    }
});


router.post("/create", isAuthenticated, async(req, res) => {
    try {
        let date = Date.now();
        let book = {
            name: req.body.name,
            authorname: req.body.authorname,
            authorSurname: req.body.authorSurname,
            year: req.body.year,
            pages: req.body.pages,
            language: req.body.language,
            date: date,
            user_id: req.body.id,
            content: req.body.content,
            price: req.body.price,
            image: {
                data: req.files.image.data,
                mimetype: req.files.image.mimetype
            }
        };
        let l = await storage.create(book);
        let idbook = await storage.getBookIdbyparams(book.name, book.authorname, book.authorSurname)
        await user.addBooktoUser(req.body.id, idbook._id)
        res.send({ status: true });
    } catch (error) {
        res.send({ error: "Internal Server Error", errorcode: '500' })
    }
});



router.get("/userbooks", isAuthenticated, async(req, res) => {
    let count = 6;
    try {
        let resbooks = await user.getUserBooks(req.user._id);

        let books = [];
        for (let book of resbooks) {
            if (book.rentflag != 'true') {
                books.push(book);
            } else {
                console.log("++++")
            }
        }



        let userBooks = [];
        for (let bookid of books) {
            let book = await storage.getById(bookid);
            userBooks.push(book);
        }
        console.log(userBooks);

        let pages = Math.ceil(userBooks.length / count);
        let currentpage = req.query.page;
        let currentarr = userBooks.slice((currentpage - 1) * count, currentpage * count);
        let data = {
            books: currentarr,
            pages: pages,
            user: req.user,
        }

        res.json(data);
    } catch (err) {
        res.send({ error: "Internal Server Error", errorcode: '500' })
    }
});



router.get('/userbooks/search', isAuthenticated, async(req, res) => {
    console.log(req.query.page);
    let resbooks = await user.getUserBooks(req.user._id);

    let userBooks = [];
    for (let book of resbooks) {
        if (book.rentflag != 'true') {
            userBooks.push(book);
        } else {
            console.log("++++")
        }
    }

    let books = [];
    for (let bookid of userBooks) {
        let book = await storage.getById(bookid);
        books.push(book);
    }


    let count = 6;
    let booksarr = books;
    if (req.query.name != 'null' && req.query.name != '' && req.query.name != 'undefined') {
        let filter = req.query.name;
        booksarr = !filter ? books : books.filter(x => x.name.toLowerCase().includes(filter));

    }
    if (req.query.authorname != 'null' && req.query.authorname != '' && req.query.authorname != 'undefined') {
        let filter = req.query.authorname;
        booksarr = !filter ? booksarr : booksarr.filter(x => x.authorname.toLowerCase().includes(filter));
        console.log("1");
    }
    if (req.query.authorSurname != 'null' && req.query.authorSurname != '' && req.query.authorSurname != 'undefined') {
        let filter = req.query.authorSurname;
        booksarr = !filter ? booksarr : booksarr.filter(x => x.authorSurname.toLowerCase().includes(filter));
        console.log("2");
    }
    if (req.query.language != 'null' && req.query.language != '' && req.query.language != 'undefined') {
        let filter = req.query.language;
        booksarr = !filter ? booksarr : booksarr.filter(x => x.language.includes(filter));
        console.log("3");
    }
    let pages = Math.ceil(booksarr.length / count);
    let currentpage = 1;
    if (req.query.page) {
        currentpage = req.query.page;
    }
    let currentarr = booksarr.slice((currentpage - 1) * count, currentpage * count);
    let resp = {
        books: currentarr,
        pages: pages
    }
    res.send(resp);
})




router.get("/userbookmarks", isAuthenticated, async(req, res) => {
    let count = 6;
    try {
        let resbooks = await user.getUserBookmarks(req.user._id);

        let books = [];
        for (let book of resbooks) {
            if (book.rentflag != 'true') {
                books.push(book);
            } else {
                console.log("++++")
            }
        }


        let userBooks = [];
        for (let bookid of books) {
            let book = await storage.getById(bookid);
            userBooks.push(book);
        }
        // console.log(books);

        let pages = Math.ceil(userBooks.length / count);
        let currentpage = req.query.page;
        let currentarr = userBooks.slice((currentpage - 1) * count, currentpage * count);
        let data = {
            books: currentarr,
            // page: req.query.page,
            pages: pages,
            user: req.user,
            // error: "",
            // search: "0",
            // userbooks: "2"
        }
        res.json(data);
    } catch (err) {
        res.send({ error: "Internal Server Error", errorcode: '500' })
            // res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});


router.get('/userbookmarks/search', isAuthenticated, async(req, res) => {
    console.log(req.query.page);
    let resbooks = await user.getUserBookmarks(req.user._id);

    let userBooks = [];
    for (let book of resbooks) {
        if (book.rentflag != 'true') {
            userBooks.push(book);
        } else {
            console.log("++++")
        }
    }


    let books = [];
    for (let bookid of userBooks) {
        let book = await storage.getById(bookid);
        books.push(book);
    }
    let count = 6;
    let booksarr = books;
    if (req.query.name != 'null' && req.query.name != '' && req.query.name != 'undefined') {
        let filter = req.query.name;
        booksarr = !filter ? books : books.filter(x => x.name.toLowerCase().includes(filter));

    }
    if (req.query.authorname != 'null' && req.query.authorname != '' && req.query.authorname != 'undefined') {
        let filter = req.query.authorname;
        booksarr = !filter ? booksarr : booksarr.filter(x => x.authorname.toLowerCase().includes(filter));
        console.log("1");
    }
    if (req.query.authorSurname != 'null' && req.query.authorSurname != '' && req.query.authorSurname != 'undefined') {
        let filter = req.query.authorSurname;
        booksarr = !filter ? booksarr : booksarr.filter(x => x.authorSurname.toLowerCase().includes(filter));
        console.log("2");
    }
    if (req.query.language != 'null' && req.query.language != '' && req.query.language != 'undefined') {
        let filter = req.query.language;
        booksarr = !filter ? booksarr : booksarr.filter(x => x.language.includes(filter));
        console.log("3");
    }
    let pages = Math.ceil(booksarr.length / count);
    let currentpage = 1;
    if (req.query.page) {
        currentpage = req.query.page;
    }
    let currentarr = booksarr.slice((currentpage - 1) * count, currentpage * count);
    let resp = {
        books: currentarr,
        pages: pages
    }
    res.send(resp);
})





router.get("/:id", isAuthenticated, async(req, res) => {

    try {
        let book = await storage.getById(req.params.id);
        let booksender = await user.getUserById(book.user_id);
        let usersId = [];
        let comentBook = [];
        for (let coment of book.coments) {
            let obj = await user.getUserById(coment.user_id);
            comentBook.push({
                text: coment.text,
                name: obj.name,
                image: obj.image
            })

        }
        let Bookmark = false;

        Bookmark = req.user.bookmarks.find(function(bookmark) {
            if (bookmark == req.params.id) {
                return true;
            }
        });

        if (Bookmark != undefined) {
            Bookmark = true;
        } else {
            Bookmark = false;
        }
        // console.log(Bookmark);
        res.send({
            book: book,
            user: req.user,
            coments: comentBook,
            postcreator: booksender,
            bookmark: Bookmark
        });
    } catch (error) {
        res.send({ error: "Internal Server Error", errorcode: '500' })
    };
});








module.exports = router;