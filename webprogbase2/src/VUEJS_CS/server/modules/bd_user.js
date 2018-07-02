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






let User = db.model('User', {
    name: String,
    surname: String,
    year: String,
    country: String,
    city: String,
    email: String,
    login: String,
    password: String,
    role: String,
    image: String,
    wallet: String,
    books: [String],
    bookmarks: [String],
    rentbooks: [String],
    booksinrent: [String]
});



async function createUser(user) {

    let newUser = new User({
        name: user.name,
        surname: user.surname,
        email: user.email,
        login: user.login,
        password: user.password,
        role: "user",
        image: user.img,
        books: [],
        bookmarks: []
    });
    try {
        return await newUser.save();
    } catch (err) {
        throw err;
    }
}

async function SetWallet(id, wal) {
    try {
        return await User.findByIdAndUpdate(id, { $set: { wallet: wal } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
        });
    } catch (err) {
        throw err;
    }
}


async function getRentBooks(id) {
    try {
        let user = await User.findOne({ _id: id });
        let rentbooks = user.rentbooks;
        return rentbooks;
    } catch (err) {
        console.log(err);
    }
}






async function getBooksinrent(id) {
    try {
        let user = await User.findOne({ _id: id });
        // console.log(user);
        let booksinRent = user.booksinrent
        return booksinRent;
    } catch (err) {
        console.log(err);
    }
}



async function deleteRentBook(id, book_id) {
    return await User.update({ _id: id }, { $pull: { rentbooks: book_id } }, function(err, data) {
        if (err) console.log(err);
    });
}

async function deleteBookinrent(id, book_id) {
    return await User.update({ _id: id }, { $pull: { booksinrent: book_id } }, function(err, data) {
        // console.log("++++++++++++++++++++++++++++++++++++++++++++");
        if (err) console.log(err);
    });
}




async function addRentBooks(id, book_id) {
    return await User.findByIdAndUpdate(id, { $push: { rentbooks: book_id } }, function(err, data) {
        if (err) console.log("++++");
    });
}

async function addBooksInRent(id, book_id) {
    return await User.findByIdAndUpdate(id, { $push: { booksinrent: book_id } }, function(err, data) {
        if (err) console.log("++++");
    });
}





async function addBookmarktoUser(id, book_id) {
    return await User.findByIdAndUpdate(id, { $push: { bookmarks: book_id } }, function(err, data) {
        if (err) console.log("++++");
    });
}


async function updateUser(user) {
    try {
        console.log(user);
        await User.update({ _id: user._id }, user, { upsert: true });
    } catch (err) {
        console.log(err);
    }
}


async function updatePass(id, pass) {
    try {
        console.log(id + "-----" + pass)
        await User.update({ _id: id }, { password: pass }, { upsert: true });
    } catch (err) {
        console.log(err);
    }
}

async function updateImage(id, img) {
    try {
        let IMG = (await loadImage(img.mimetype, img.data));
        await User.update({ _id: id }, { image: IMG }, { upsert: true });
    } catch (err) {
        console.log(err);
    }
}


async function deleteUserbook(id, book_id) {
    return await User.update({ _id: id }, { $pull: { books: book_id } }, function(err, data) {
        if (err) console.log(err);
    });
}

async function deleteUserbookmark(id, book_id) {
    return await User.update({ _id: id }, { $pull: { bookmarks: book_id } }, function(err, data) {
        if (err) console.log(err);
    });

}


async function addBooktoUser(id, book_id) {
    return await User.findByIdAndUpdate(id, { $push: { books: book_id } }, function(err, data) {
        if (err) console.log("++++");
    });
}

async function updateUserfield(id, field, data) {
    if (field == "name") {
        await User.findByIdAndUpdate(id, { $set: { name: data } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
            else console.log(dat);
        });
    }
    if (field == "surname") {
        await User.findByIdAndUpdate(id, { $set: { surname: data } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
            else console.log(dat);
        });
    }
    if (field == "year") {
        await User.findByIdAndUpdate(id, { $set: { year: data } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
            else console.log(dat);
        });
    }
    if (field == "country") {
        await User.findByIdAndUpdate(id, { $set: { country: data } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
            else console.log(dat);
        });
    }
    if (field == "city") {
        await User.findByIdAndUpdate(id, { $set: { city: data } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
            else console.log(dat);
        });
    }
    if (field == "sex") {
        await User.findByIdAndUpdate(id, { $set: { sex: data } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
            else console.log(dat);
        });
    }
    if (field == "email") {
        await User.findByIdAndUpdate(id, { $set: { email: data } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
            else console.log(dat);
        });
    }
    if (field == "login") {
        await User.findByIdAndUpdate(id, { $set: { login: data } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
            else console.log(dat);
        });
    }
    if (field == "information") {
        await User.findByIdAndUpdate(id, { $set: { information: data } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
            else console.log(dat);
        });
    }
    if (field == "password") {
        await User.findByIdAndUpdate(id, { $set: { password: data } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
            else console.log(dat);
        });
    }
    if (field == "image") {
        await User.findByIdAndUpdate(id, { $set: { image: data.data, mimetype: data.mimetype, } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
            else console.log(dat);
        });
    }
}





async function getUserBookmarks(id) {
    try {
        return (await User.findOne({ _id: id })).bookmarks;
    } catch (err) {
        throw err;
    }
}


async function getUserBooks(id) {
    try {
        return (await User.findOne({ _id: id })).books;
    } catch (err) {
        throw err;
    }
}


//addBooktoUser("5a04c686145f833c1f1a68a6", "59fcd90782b6083bf577f92d");

async function getUserByLoginAndPasshash(login, passHash) {
    let user = await User.findOne({ login: login, password: passHash });
    // console.log(passHash);
    if (user) return user;
    else return null;
}

async function getUserbyLogin(log) {
    let user = await User.findOne({ login: log }).exec();
    console.log(user);
    return user;
}





async function getUserById(id) {
    let user = await User.findOne({ _id: id });
    if (user) return user;
    else return `User with id ${id} not found`;
}

async function getUsers() {
    let users = await User.find();
    if (users) return users;
    else return `Users not found`;
}


module.exports = {
    createUser,
    getUserbyLogin,
    getUserByLoginAndPasshash,
    getUserById,
    getUsers,
    addBooktoUser,
    getUserBooks,
    updateUserfield,
    deleteUserbook,
    addBookmarktoUser,
    deleteUserbookmark,
    getUserBookmarks,
    updateUser,
    updatePass,
    updateImage,
    addRentBooks,
    addBooksInRent,
    getRentBooks,
    getBooksinrent,
    deleteRentBook,
    deleteBookinrent,
    SetWallet
};