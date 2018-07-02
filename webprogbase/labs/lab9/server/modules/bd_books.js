let fs = require('fs');

const mongoose = require('mongoose');
mongoose.Promise = require('bluebird');
let env = require('node-env-file');
env('./config' + '/.env');

let db = mongoose.connect(process.env.MLAB, {
    useMongoClient: true,
});

let cloudinary = require('cloudinary');

cloudinary.config({
    cloud_name: 'booka-herokuapp-com',
    api_key: '287166916858793',
    api_secret: '-LVPCQmUbsmKmzodih-fBzn1Rf8'
});









// let db = mongoose.connect('mongodb://Admiral2303:vadim2303@ds241055.mlab.com:41055/books', {
//     useMongoClient: true,
// });



let Book = db.model('Book', {
    name: String,
    authorname: String,
    authorSurname: String,
    year: String,
    pages: String,
    language: String,
    image: String,
    mimetype: String,
    date: String,
    content: String
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



async function create(book) {
    let IMG = (await loadImage(book.image.mimetype, book.image.data));
    console.log(IMG);
    let newbook = new Book({
        name: book.name,
        authorname: book.authorname,
        authorSurname: book.authorSurname,
        year: book.year,
        pages: book.pages,
        language: book.language,
        image: IMG,
        date: book.date,
        content: book.content
    });

    try {
        await newbook.save();
        return newbook;
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