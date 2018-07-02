let fs = require('fs');
const read = require('./read');

const mongoose = require('mongoose');
mongoose.Promise = require('bluebird');
let db = mongoose.connect('mongodb://localhost:27017/users', {
    useMongoClient: true,
});
// let db = mongoose.connect('mongodb://Admiral2303:vadim2303@ds241055.mlab.com:41055/books', {
//     useMongoClient: true,
// });


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
    if (user) return Promise.resolve(user);
    else return null; // Promise.reject(`User with login ${login} not found`);
}

async function getUserById(id) {
    let user = await User.findOne({ _id: id });
    if (user) return Promise.resolve(user);
    else return Promise.reject(`User with id ${id} not found`);
}

async function getUsers() {
    let users = await User.find();
    if (users) return Promise.resolve(users);
    else return Promise.reject(`Users not found`);
}


module.exports = {
    createUser,
    getUserByLoginAndPasshash,
    getUserById,
    getUsers
};