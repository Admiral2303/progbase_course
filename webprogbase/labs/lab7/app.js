const booksRouter = require('./routes/books');
const searchRouter = require('./routes/search');
const mainRouter = require('./routes/mainRouter');
const apiRouter = require('./routes/api');
//const createRouter = require('./routes/create');



var auth = require('basic-auth')
var http = require('http')








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

let path = require('path');

app.set('view engine', 'ejs');
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: false }));
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
app.use("/books/", booksRouter);
app.use("/", mainRouter);
app.use("/api/v1", apiRouter);


// app.use("/create", createRouter);


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






// const sendFileOpts = {
//     root: path.join(__dirname, 'views')
// };

// app.get('/books',
//     async(req, res) => {
//         console.log("+++++");
//         res.sendFile('books.ejs', sendFileOpts);
//     });

// app.get('/books/data', async(req, res) => {

//     let count = 2;
//     storage.getAll()
//         .then(books => {
//             res.json(books);
//         })
// })









app.get('/register',
    (req, res) => res.render('registration', {
        user: req.user,
        error: null
    }));

app.post('/register',
    async(req, res) => {
        if (!await user.getUserbyLogin(req.body.login)) {
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
        } else {
            res.render('registration', { user: req.user, error: "Логін занятий" });
        }
    });



app.get('/login',
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
        failureRedirect: 'login'
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

app.listen(process.env.PORT || process.env.PORT);









/*
<!doctype html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <title>Books</title>


    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js">
        < /script
        <!-- Optional theme -->
        
        link rel = "stylesheet"
        href = "https://maxcdn.bosotstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css"
        integrity = "sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp"
        crossorigin = "anonymous" >
            <!-- Latest compiled and minified JavaScript -->
            
            <script src = "https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"
        integrity = "sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa"
        crossorigin = "anonymous" >
    </script>



    <meta name="viewport" content="width=device-width, initial-scale=1">

    <meta name="viewport" content="width=device-width" />
    <meta name="author" content="Vadim Scherbina">
    <link rel="stylesheet" type="text/css" href="/stylesheets/booksstyle.css">
</head>

<body>
    <% include partials/header %>
        <%if(books.length != 0){%>
            <ul>
                <%for(let book of books){%>
                    <li>
                        <div class="container">
                            <div class="row">
                                <div class="col-md-2 col-md-offset-2">
                                    <a href="books/<%=book.id %>"><img src = "data:<%=book.mimetype%>;base64,<%=book.image.toString('base64')%>" alt="<%= book.name %>" class="img"></a>
                                </div>
                                <div class="col-md-4 col-md-offset-1">
                                    <h1 style="color: #110E0E;font-family: 'Century Schoolbook L', bold;font-size: 40px;font-weight: 600">
                                        <%= book.name %>
                                    </h1>
                                    <h3 style="font-family: 'Century Schoolbook L', bold;font-size: 20px;font-weight: 600;border: 2px solid #333;border: 2px solid #333; padding-left:10%;">
                                        Автор -
                                        <%= book.authorName %>
                                        <%= book.authorSurname %><br> Язык издания -
                                        <%= book.language %><br> Количество страниц -
                                        <%= book.pages %><br> Год выпуска -
                                        <%= book.year %><br> Дата добавления -
                                        <%= book.date %><br>
                                    </h3>
                                </div>
                            </div>
                            <hr>
                        </div>
                    </li>
                    <% } %>
                        <% } %>
                            <footer id="footer" class="footer navbar-bottom">
                                <form id="search" action="/books" method="get">
                                    <%if(page != 1){%>
                                        <a class="prev" href="?page=<%=parseInt(page) - 1 %>">
                                            <button type="button" class="btn btn-secondary"><</button>
                                        </a>
                                        <%}%>
                                            <%let i = 1%>
                                                <%if(page >= 3) i = page - 1 ;%>
                                                    <%if(page == pages && page > 3) i = page - 2;%>
                                                        <%for(let k = 0;  i <= pages ; i++, k++){%>
                                                            <%if(k== 3){ break;}%>
                                                                <input type="submit" class="btn btn-secondary" id="page" name="page" value="<%=i %>">
                                                                <% } %>
                                                                    <%if(page != pages){%>
                                                                        <a class="next" href="?page=<%=parseInt(page) + 1 %>">
                                                                            <button type="button" class="btn btn-secondary">></button>
                                                                        </a>
                                                                        <%}%>
                                </form>
                                <div class="number">
                                    <h1>
                                        <%=parseInt(page) %>
                                    </h1>
                                </div>
                            </footer>
</body>
</html>
*/
