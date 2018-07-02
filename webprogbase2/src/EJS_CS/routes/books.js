const express = require('express');
const router = express.Router();
let storage = require('./../modules/bd_books');
let check = require('./../modules/check');
let user = require('./../modules/bd_user');
const fs = require('fs');

router.get("/", check.checkAuth, (req, res) => {
    let count = 6;
    storage.getAll()
        .then(books => {
            let pages = Math.ceil(books.length / count);
            let currentpage = req.query.page;
            let currentarr = books.slice((currentpage - 1) * count, currentpage * count);
            let data = {
                books: currentarr,
                page: req.query.page,
                pages: pages,
                user: req.user,
                error: "",
                search: "0",
                userbooks: "0"
            }
            res.render('books', data);
        })
        .catch(error => {
            res.render('error', { error: "500", text: 'Internal Server Error' });
        })
});







router.post("/delete/:id", check.checkAuth, async(req, res) => {
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
        res.redirect('/books?page=1');
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});

router.get("/create", check.checkAuth, (req, res) => {
    try {
        res.render('addbook', { user: req.user });
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});




router.post("/addcoment", check.checkAuth, async(req, res) => {
    try {
        await storage.addComentToBook(req.body.book_id, req.body.comment, req.user._id);
        let src = "/books/" + req.body.book_id;
        res.redirect(src);
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
})



router.get("/search", check.checkAuth, async(req, res) => {
    let count = 6;
    let searchreq = {
        name: req.query.name,
        authorname: req.query.authorname,
        authorSurname: req.query.authorSurname,
        year: req.query.year,
        language: req.query.language
    }
    storage.searchBooks(searchreq)
        .then(books => {

            let pages = Math.ceil(books.length / count);
            let currentpage = req.query.page;
            let currentarr = books.slice((currentpage - 1) * count, currentpage * count);
            let data = {
                books: currentarr,
                page: req.query.page,
                pages: pages,
                user: req.user,
                error: "Книжок по даному запиту не знайдено",
                search: searchreq,
                userbooks: "0"
            }
            res.render('books', data);
        })
        .catch(error => {
            res.render('error', { error: "500", text: 'Internal Server Error' });
        });
});


router.post("/update", check.checkAuth, async(req, res) => {
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
        await storage.updateBook(req.body.book_id, book);
        res.redirect('/books/' + req.body.book_id);
    } catch (error) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});




router.post("/updateBookAva", check.checkAuth, async(req, res) => {
    try {
        if (req.files.ava.data != null) {
            image = {
                data: req.files.ava.data,
                mimetype: req.files.ava.mimetype
            }
            await storage.updateBookImage(req.body.book_id, image);
        }
        res.redirect('/books/' + req.body.book_id);
    } catch (error) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});


router.post("/create", check.checkAuth, async(req, res) => {
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
            user_id: req.user._id,
            content: req.body.content
        };
        if (req.files.ava.data != null) {
            book.image = {
                data: req.files.ava.data,
                mimetype: req.files.ava.mimetype
            }
            let l = await storage.create(book);
            let idbook = await storage.getBookIdbyparams(book.name, book.authorname, book.authorSurname)
            user.addBooktoUser(req.user._id, idbook._id);
            res.redirect('/books?page=1');
        } else {
            let img = await fs.readFile("./public/images/book.png", async function(err, dat) {
                book.image = {
                    data: dat,
                    mimetype: "png"
                }
                console.log(book);
                let l = await storage.create(book);
                let idbook = await storage.getBookIdbyparams(book.name, book.authorname, book.authorSurname)
                user.addBooktoUser(req.user._id, idbook._id);
                res.redirect('/books?page=1');
            });
        }
    } catch (error) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});



router.get("/userbooks", check.checkAuth, async(req, res) => {
    let count = 6;
    try {
        let books = await user.getUserBooks(req.user._id);
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
            page: req.query.page,
            pages: pages,
            user: req.user,
            error: "",
            search: "0",
            userbooks: "1"
        }
        res.render('books', data);
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});


router.get("/userbookmarks", check.checkAuth, async(req, res) => {
    let count = 6;
    try {
        let books = await user.getUserBookmarks(req.user._id);
        let userBooks = [];
        for (let bookid of books) {
            let book = await storage.getById(bookid);
            userBooks.push(book);
        }
        console.log(books);

        let pages = Math.ceil(userBooks.length / count);
        let currentpage = req.query.page;
        let currentarr = userBooks.slice((currentpage - 1) * count, currentpage * count);
        let data = {
            books: currentarr,
            page: req.query.page,
            pages: pages,
            user: req.user,
            error: "",
            search: "0",
            userbooks: "2"
        }
        res.render('books', data);
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});



router.get("/userbooks/:id", check.checkAuth, async(req, res) => {
    let count = 6;
    try {
        let books = await user.getUserBooks(req.params.id);
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
            page: req.query.page,
            pages: pages,
            user: req.user,
            error: "Немає книг ",
            search: "0",
            userbooks: "1"
        }
        res.render('books', data);
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});




router.get("/:id", check.checkAuth, async(req, res) => {
    try {
        let book = await storage.getById(req.params.id);
        let booksender = await user.getUserById(book.user_id);
        let usersId = [];
        for (let coment of book.coments) {
            usersId.push(coment.user_id);
        }
        let users = [];
        for (let id of usersId) {
            let obj = await user.getUserById(id);
            users.push(obj);
        }
        let Bookmark = req.user.bookmarks.find(function(bookmark) {
            if (bookmark == req.params.id) {
                return true;
            }
        });

        res.render('book', {
            book: book,
            user: req.user,
            coment_users: users,
            postcreator: booksender,
            bookmark: Bookmark
        });
    } catch (error) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    };
});








module.exports = router;