const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');

const busboyBodyParser = require('busboy-body-parser');

//const morgan = require('morgan');

const app = express();
//app.use(morgan('combined'));
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(busboyBodyParser({ limit: '5mb' }));
app.use(cors());
app.use(express.static('public'));

let mongoose = require('mongoose');

let verifyToken = require('../middlewares/verifyToken');

let jwt = require('jsonwebtoken');
let User = require('../models/user');

let db = mongoose.connect("mongodb://localhost:27017/users", {
    useMongoClient: true,
});

let jwt_secret = "shhh";



// const isAuthenticated = require('../modules/isAuthenticated');


app.use('/user', require('../controllers/user'));
app.use('/books', require('../controllers/books'));



//app.use('/protected', verifyToken, require('../controllers/protected'));


app.listen(process.env.PORT || 23000);