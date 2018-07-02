const booksRouter = require('./routes/books');
const mainRouter = require('./routes/mainRouter');
const chatRouter = require('./routes/chat');
const profileRouter = require('./routes/profile');
const usersRouter = require('./routes/users');
const fs = require('fs');
let check = require('./modules/check');



let express = require('express');
let bodyParser = require('body-parser');
const busboyBodyParser = require('busboy-body-parser');
let storage = require('./modules/bd_books');
let user = require('./modules/bd_user');
let app = express();
let env = require('node-env-file');
env('./config' + '/.env');

const cookieParser = require('cookie-parser');
const session = require('express-session');
const crypto = require('crypto');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;

app.set('view engine', 'ejs');
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(busboyBodyParser({ limit: '2mb' }));
app.use(bodyParser.json());
app.use(cookieParser());
app.use(session({
    secret: "Asd",
    resave: false,
    saveUninitialized: true
}));
app.use(passport.initialize());
app.use(passport.session());

app.use("/books", booksRouter);
app.use("/", mainRouter);
app.use("/chat", chatRouter);
app.use("/profile", profileRouter);
app.use("/users", usersRouter);







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
        user.getUserByLoginAndPasshash(username, hash)
            .then(user => {
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
    async(req, res) => {
        let Data = new Date();
        let Year = Data.getFullYear();
        let age = Year - req.body.year;
        if (!await user.getUserbyLogin(req.body.login)) {
            let User = {
                name: req.body.name,
                surname: req.body.surname,
                year: age,
                country: req.body.country,
                city: req.body.city,
                university: req.body.university,
                sex: req.body.sex,
                email: req.body.email,
                information: req.body.information,
                login: req.body.login,
                password: sha512(req.body.password, serverSalt).passwordHash,
                role: "user",

            };
            if (req.files.ava.data != null) {
                User.image = {
                    data: req.files.ava.data,
                    mimetype: req.files.ava.mimetype
                }
                user.createUser(User)
                    .then(() => {
                        res.redirect('/');
                    });

            } else {
                let img = await fs.readFile("./public/images/images.jpeg", function(err, dat) {
                    User.image = {
                        data: dat,
                        mimetype: "jpeg"
                    }
                    user.createUser(User)
                        .then(() => {
                            res.redirect('/');
                        });
                });
            }


        } else {
            res.render('index', { user: req.user, error: '1' });
        }
    });





app.get('/logout',
    check.checkAuth,
    (req, res) => {
        req.logout();
        res.redirect('/');
    });

app.post('/login',
    passport.authenticate('local', {
        successRedirect: '/books?page=1',
        failureRedirect: '/'
    }));

app.get('*', (req, res) => {
    res.render('error', { error: "404", text: 'Not Found' });
});



app.listen(process.env.PORT || process.env.PORT);