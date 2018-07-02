const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');

var serveStatic = require('serve-static');

let http = require('http').Server(express);
let io = require('socket.io')(http);


const busboyBodyParser = require('busboy-body-parser');

//const morgan = require('morgan');
//app.use(morgan('combined'));
const app = express();
app.set('view engine', 'ejs');
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(busboyBodyParser({ limit: '5mb' }));
app.use(cors());
app.use(express.static('public'));


let mongoose = require('mongoose');

let verifyToken = require('./middlewares/verifyToken');

let jwt = require('jsonwebtoken');


require('./passport')
    //let User = require('./routes/user');




io.on('connection', function(socket) {
    var user = Date.now();

    socket.on('message.sent', function(message) {
        console.log("++++++++++")
        io.emit('message', user + ': ' + message);
    });

    io.emit('message', 'User ' + user + ' connected');
});






app.use(serveStatic(__dirname + "/dist"));
app.get('/',
    (req, res) => res.sendFile(path.join(__dirname, './views/index.html')));


app.use('/user', require('./routes/users'));
app.use('/books', require('./routes/books'));
app.use('/chat', require('./routes/chat'));


app.use('/webmoney', require('./routes/webmoney'));

app.get('*', (req, res) => {
    res.render('error', { error: "404", text: 'Not Found' });
});



app.listen(process.env.PORT || 23000);