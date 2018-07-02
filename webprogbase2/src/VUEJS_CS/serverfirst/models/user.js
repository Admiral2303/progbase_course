var mongoose = require('mongoose');
mongoose.Promise = require('bluebird');
var Schema = mongoose.Schema;



let User = mongoose.model('User', {
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
        year: "",
        country: "",
        city: "",
        university: "",
        sex: "",
        email: user.email,
        login: user.login,
        information: "",
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

async function getUserbyLogin(log) {
    let user = await User.findOne({ login: log }).exec();
    console.log(user);
    return user;
}

async function getUserByLoginAndPasshash(login, passHash) {
    let user = await User.findOne({ login: login, password: passHash });
    if (user) return user;
    else return null;
}



async function getUserById(id) {
    let user = await User.findOne({ _id: id });
    if (user) return user;
    else return `User with id ${id} not found`;
}

module.exports = {
    User,
    createUser,
    getUserbyLogin,
    getUserByLoginAndPasshash,
    getUserById
};