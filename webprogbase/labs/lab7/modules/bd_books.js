let fs = require('fs');

const mongoose = require('mongoose');
mongoose.Promise = require('bluebird');
let env = require('node-env-file');
env('./config' + '/.env');

let db = mongoose.connect(process.env.MLAB, {
    useMongoClient: true,
});











// let db = mongoose.connect('mongodb://Admiral2303:vadim2303@ds241055.mlab.com:41055/books', {
//     useMongoClient: true,
// });



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
    content: String
});



function create(book) {
    console.log(book.image.data);
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
        content: book.content
    });
    newbook.save();
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
    let books = await Book.find();
    if (books) return books;
    else return null;
}




async function getById(id) {
    let book = await Book.findOne({ _id: id });
    if (book) return book;
    else return `User with _id ${id} not found`;
}






async function findbyName(name) {
    let books = await Book.find({ name: name });
    if (books) return books;
    else return `User with _id ${name} not found`;
}





async function remove(id) {
    let book = Book.remove({ _id: id });
    return book;
}


module.exports = {
    Book,
    getAll,
    create,
    getById,
    remove,
    findbyName,
    searchBooks
};