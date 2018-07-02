let fs = require('fs');
const read = require('./read');

const mongoose = require('mongoose');
mongoose.Promise = require('bluebird');
let env = require('node-env-file');
env('./config' + '/.env');

let db = mongoose.connect(process.env.MLAB, {
    useMongoClient: true,
});



let User = db.model('User', {
    name: String,
    login: String,
    password: String,
    role: String,
    year: String,
    email: String,
    image: Buffer,
    mimetype: String
});


async function createUser(user) {
    let newUser = new User({
        name: user.name,
        login: user.login,
        password: user.password,
        role: "user",
        year: user.year,
        email: user.email,
        image: user.image.data,
        mimetype: user.image.mimetype
    });
    newUser.save();
    return (true);
}

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
    getUsers
};