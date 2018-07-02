// const express = require('express');
// const app = express();
// const booksRouter = require('./routes/books');
// const ejs = require('ejs');
// let storage = require('./modules/books');
// app.use(express.static('public'));

// app.set("view engine", "ejs");
// let bodyParser = require('body-parser');
// app.use(bodyParser.urlencoded({ extended: false }));
// // app.use(express.bodyParser());
// app.use(bodyParser.json());




const booksRouter = require('./routes/books');
const searchRouter = require('./routes/search');
const mainRouter = require('./routes/mainRouter');
const createRouter = require('./routes/create');


let express = require('express');
let bodyParser = require('body-parser');
const busboyBodyParser = require('busboy-body-parser');
let storage = require('./modules/bd_books');
let user = require('./modules/bd_user');
let app = express();





const cookieParser = require('cookie-parser');
const session = require('express-session');
const crypto = require('crypto');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;

app.set('view engine', 'ejs');
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(busboyBodyParser({ limit: '5mb' }));



app.use(cookieParser());
app.use(session({
    secret: "Asd",
    resave: false,
    saveUninitialized: true
}));
app.use(passport.initialize());
app.use(passport.session());





app.use("/searchbook", searchRouter);

app.use("/books", booksRouter);
app.use("/", mainRouter);
app.use("/create", createRouter);






const serverSalt = "45%sAlT_";


function sha512(password, salt) {
    const hash = crypto.createHmac('sha512', salt);
    hash.update(password);
    const value = hash.digest('hex');
    return {
        salt: salt,
        passwordHash: value
    };
};



passport.use(new LocalStrategy(
    function(username, password, done) {
        let hash = sha512(password, serverSalt).passwordHash;
        // console.log(username, password);
        user.getUserByLoginAndPasshash(username, hash)
            .then(user => {
                //console.log(user);
                done(user ? null : false, user);
            });
    }
));


passport.serializeUser(function(user, done) {
    done(null, user._id);
});

passport.deserializeUser(function(id, done) {
    user.getUserById(id)
        .then(user => {
            done(user ? null : 'No user', user);
        });
});


app.get('/register',
    (req, res) => res.render('registration', {
        user: req.user,
        error: null
    }));


app.post('/register',
    (req, res) => {
        if (req.body.password === req.body.password1) {
            let User = {
                name: req.body.name,
                login: req.body.login,
                password: sha512(req.body.password, serverSalt).passwordHash,
                year: req.body.year,
                email: req.body.email,
                role: "user",
                image: {
                    data: req.files.ava.data,
                    mimetype: req.files.ava.mimetype
                }
            };
            user.createUser(User)
                .then(() => {
                    res.redirect('/');
                });
        } else {
            res.render('registration', { user: req.user, error: "Паролі не співпадіють" });
        }

    });



app.get('/avtorization',
    (req, res) => res.render('avtorization', {
        user: req.user
    }));

app.get('/logout',
    checkAuth,
    (req, res) => {
        req.logout();
        res.redirect('/');
    });

app.post('/login',
    passport.authenticate('local', {
        successRedirect: '/',
        failureRedirect: '/register'
    }));

function checkAuth(req, res, next) {
    if (!req.user) return res.sendStatus(401);
    next();
}


function checkAdmin(req, res, next) {
    if (req.user.role !== 'admin') return res.sendStatus(403);
    next();
}

app.get('/admin',
    checkAuth,
    checkAdmin,
    (req, res) => {
        user.getUsers()
            .then(users => {
                res.render('users', {
                    user: req.user,
                    users: users
                });
            })
            .catch(() => res.sendStatus(500));
    });









app.listen(process.env.PORT || 23000);
// const PORT = 3000;
// app.listen(PORT, function() {
//     console.log(`Example app listening on port ${PORT}!`);
// });