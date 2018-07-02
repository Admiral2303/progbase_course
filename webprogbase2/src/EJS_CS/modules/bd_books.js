let fs = require('fs');

const mongoose = require('mongoose');
mongoose.Promise = require('bluebird');
let env = require('node-env-file');
env('./config' + '/.env');

let db = mongoose.connect(process.env.MLAB, {
    useMongoClient: true,
});





let Book = db.model('Book', {
    name: String,
    authorname: String,
    authorSurname: String,
    year: Number,
    pages: Number,
    language: String,
    image: Buffer,
    mimetype: String,
    date: Date,
    content: String,
    user_id: String,
    coments: [{
        text: String,
        user_id: String
    }]
});



async function create(book) {
    try {
        let newbook = new Book({
            name: book.name,
            authorname: book.authorname,
            authorSurname: book.authorSurname,
            year: book.year,
            pages: book.pages,
            language: book.language,
            image: book.image.data,
            mimetype: book.image.mimetype,
            date: book.date,
            content: book.content,
            user_id: book.user_id,
            coments: []
        });
        return await newbook.save();
    } catch (err) {
        throw err;
    }
}



async function addComentToBook(id, comment, userId) {
    try {
        return await Book.findByIdAndUpdate(id, { $push: { coments: { text: comment, user_id: userId } } }, function(err, data) {
            if (err) console.log("----");
            else console.log("++");
        });
    } catch (err) {
        throw err;
    }
}







async function getBookIdbyparams(name1, authorname1, authorSurname1) {
    try {
        let book = await Book.findOne({ name: name1, authorname: authorname1, authorSurname: authorSurname1 }, function(err, obj) {});
        if (book) return book;
    } catch (err) {
        throw err;
    }
}


async function searchBooks(book) {
    let query = {};
    if (book.name) {
        query['name'] = book.name;
    }
    if (book.authorname) {
        query['authorname'] = book.authorname;
    }
    if (book.authorSurname) {
        query['authorSurname'] = book.authorSurname;
    }
    if (book.university) {
        query['university'] = book.university;
    }
    if (book.year) {
        query['year'] = book.year;
    }
    if (book.language) {
        query['language'] = book.language;
    }

    try {
        let books = await Book.find(query);
        if (books) return books;
        else return null;
    } catch (err) {
        throw err;
    }
}




async function getAll() {
    try {
        let books = await Book.find();
        if (books) return books;
        else return null;
    } catch (err) {
        throw err;
    }
}




async function getById(id) {
    try {
        let book = await Book.findOne({ _id: id });
        if (book) return book;
        else return `Book with _id ${id} not found`;
    } catch (err) {
        throw err;
    }
}





async function findbyName(name) {
    try {
        let books = await Book.find({ name: name });
        if (books) return books;
        else return `User with _id ${name} not found`;
    } catch (err) {
        throw err;
    }
}





async function remove(id) {
    try {
        return await Book.remove({ _id: id });
    } catch (err) {
        throw err;
    }
}




async function updateBook(id, book) {
    try {
        return await Book.findByIdAndUpdate(id, { $set: { name: book.name, authorname: book.authorname, authorSurname: book.authorSurname, year: book.year, pages: book.pages, language: book.language } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
        });
    } catch (err) {
        throw err;
    }
}

async function updateBookImage(id, img) {
    try {
        return await Book.findByIdAndUpdate(id, { $set: { image: img.data, mimetype: img.mimetype } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
        });
    } catch (err) {
        throw err;
    }
}


module.exports = {
    getAll,
    create,
    getById,
    remove,
    findbyName,
    getBookIdbyparams,
    searchBooks,
    addComentToBook,
    addComentToBook,
    updateBook,
    updateBookImage
};