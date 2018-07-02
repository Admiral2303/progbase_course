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



let Book = db.model('Book', {
    name: String,
    authorname: String,
    authorSurname: String,
    year: Number,
    pages: Number,
    language: String,
    image: String,
    date: Date,
    price: Number,
    content: String,
    user_id: String,
    coments: [{
        text: String,
        user_id: String
    }],
    rentflag: String,
    payflag: String
});



async function create(book) {
    let IMG = (await loadImage(book.image.mimetype, book.image.data));
    // console.log(IMG);
    try {
        let newbook = new Book({
            name: book.name,
            authorname: book.authorname,
            authorSurname: book.authorSurname,
            year: book.year,
            pages: book.pages,
            language: book.language,
            price: book.price,
            image: IMG,
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

async function addBooktoRent(id, flag) {
    try {
        return await Book.findByIdAndUpdate(id, { $set: { rentflag: flag } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
        });
    } catch (err) {
        throw err;
    }
}

async function SetPayflag(id, flag) {
    try {
        return await Book.findByIdAndUpdate(id, { $set: { payflag: flag } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
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
    if (book.name != 'null') {
        query['name'] = book.name;
    }
    if (book.authorname != 'null') {
        query['authorname'] = book.authorname;
    }
    if (book.authorSurname != 'null') {
        query['authorSurname'] = book.authorSurname;
    }
    if (book.year != 'null') {
        query['year'] = book.year;
    }
    if (book.language != 'null') {
        query['language'] = book.language;
    }

    try {
        // console.log(query);
        let books = await Book.find(query);
        if (books) return books;
        else return null;
    } catch (err) {
        console.log(err);
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
        return await Book.findByIdAndUpdate(id, { $set: { name: book.name, authorname: book.authorname, authorSurname: book.authorSurname, year: book.year, pages: book.pages, language: book.language, content: book.content } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
        });
    } catch (err) {
        throw err;
    }
}

async function updateBookImage(id, img) {
    let IMG = (await loadImage(img.mimetype, img.data));
    console.log(IMG);
    try {
        return await Book.findByIdAndUpdate(id, { $set: { image: IMG } }, { new: true }, function(err, dat) {
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
    updateBookImage,
    addBooktoRent,
    SetPayflag
};