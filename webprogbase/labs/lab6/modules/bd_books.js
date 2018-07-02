let fs = require('fs');

const read = require('./read');

const mongoose = require('mongoose');
mongoose.Promise = require('bluebird');

let path = JSON.parse(fs.readFileSync("./config/config.json", 'UTF-8'));




let db = mongoose.connect(path.mongo, {
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




async function getAll() {
    let books = await Book.find();
    if (books) return Promise.resolve(books);
    else return Promise.reject("no books");
}




async function getById(id) {
    let book = await Book.findOne({ _id: id });
    if (book) return Promise.resolve(book);
    else return Promise.reject(`User with _id ${id} not found`);
}






async function findbyName(name) {
    let books = await Book.find({ name: name });
    if (books) return Promise.resolve(books);
    else return Promise.reject(`User with _id ${name} not found`);
}





async function remove(id) {
    let book = Book.remove({ _id: id });
    Promise.resolve(book);
}


module.exports = {
    getAll,
    create,
    getById,
    remove,
    findbyName
};