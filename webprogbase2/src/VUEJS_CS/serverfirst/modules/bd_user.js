let fs = require('fs');


const mongoose = require('mongoose');
mongoose.Promise = require('bluebird');
let env = require('node-env-file');
env('./config' + '/.env');

let db = mongoose.connect(process.env.MLAB, {
    useMongoClient: true,
});


// let db = mongoose.connect("mongodb://localhost:27017/users", {
//     useMongoClient: true,
// });






let User = db.model('User', {
    name: String,
    surname: String,
    year: String,
    country: String,
    city: String,
    university: String,
    sex: String,
    email: String,
    information: String,
    login: String,
    password: String,
    role: String,
    image: Buffer,
    mimetype: String,
    books: [String],
    bookmarks: [String]
});



async function createUser(user) {
    console.log(user);
    let newUser = new User({
        name: user.name,
        surname: user.surname,
        year: user.year,
        country: user.country,
        city: user.city,
        university: user.university,
        sex: user.sex,
        email: user.email,
        login: user.login,
        information: user.information,
        password: user.password,
        role: "user",
        image: user.image.data,
        mimetype: user.image.mimetype,
        books: [],
        bookmarks: []
    });
    try {
        await newUser.save();
    } catch (err) {
        throw err;
    }
}


async function addBookmarktoUser(id, book_id) {
    return await User.findByIdAndUpdate(id, { $push: { bookmarks: book_id } }, function(err, data) {
        if (err) console.log("++++");
    });

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
    getUserBookmarks
};