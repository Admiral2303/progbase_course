const express = require('express');
const app = express();
const booksRouter = require('./routes/books');
const ejs = require('ejs');
let storage = require('./modules/books');
app.use(express.static('public'));

app.set("view engine", "ejs");


;


app.get("/", (req, res) => {
	res.render('index');
});
app.use("/books", booksRouter);



const PORT = 3001;
app.listen(PORT, function () {
  console.log(`Example app listening on port ${PORT}!`);
});
