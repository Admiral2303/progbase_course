const express = require('express');
const router = express.Router();
let storage = require('./../modules/bd_books');
let check = require('./../modules/check');




router.get("/", check.checkAuth, (req, res) => {
    res.render('form', { user: req.user });
});




router.post("/", check.checkAuth, (req, res) => {

    let date = Date.now();
    let book = {
        id: 0,
        name: req.body.name,
        authorname: req.body.authorname,
        authorSurname: req.body.authorSurname,
        year: req.body.year,
        pages: req.body.pages,
        language: req.body.language,
        image: {
            data: req.files.ava.data,
            mimetype: req.files.ava.mimetype
        },
        date: date,
        content: req.body.content
    };
    storage.create(book);
    res.redirect('/');
});


module.exports = router;










/*


<div class="container container-table text-center">
<div class="row vertical-center-row">
    <div class="col-md-4 col-md-offset-4">
        <form action="/create" method="POST" enctype='multipart/form-data'>
            <div class="form-group ">
                <label for="name" class="control-label">Назва кижки</label>
                <input type="text" class="form-control"  id="name" name="name" require pattern="^[А-Яа-яa-zA-Z\s]+$"  placeholder="Example input" >
            </div>
            <div class="form-group">
                <label for="authorname">Ім'я автора</label>
                <input type="text" class="form-control"  id="authorname" name="authorname" require pattern="^[А-Яа-яa-zA-Z\s]+$" placeholder="Another input">
            </div>
            <div class="form-group">
                <label for="authorSurname">Прізвище автора</label>
                <input type="text" class="form-control"  id="authorSurname" name="authorSurname" require pattern="^[А-Яа-яa-zA-Z\s]+$" placeholder="Another input">
            </div>
            
            <div class="form-group">
                <select class="selectpicker" id="language" name="language"> 
                    <option value="" disabled="" selected="">Виберіть мову</option>
                    <option value="Англійська">Англійська</option>
                    <option value="Українська">Українська</option>
                    <option value="Російська">Російська</option>
                    <option value="Китайська">Китайська</option>
                </select>
                    
            </div>
            <div class="form-group">
                <label for="year">Рік видання</label>
                <select class="form-control" id="year" name="year">
            <%for(let i = 1999; i <=2017; i++){%>
                <option><%=i%></option>
            <% } %>
            </select>
            </div>
            <div class="form-group">
                <label for="pages">Кількість сторінок</label>
                <input type="number" class="form-control" id="pages" name="pages" placeholder="Another input">
            </div>
            <div class="form-group">
                <label for="content">Інформація про книгу</label>
                <textarea id="comment" name="content" class="form-control" placeholder="Введіть інформацію" rows="5"></textarea>
            </div>
            <div class="form-group">
                <label for="ava">Виберіть картинку</label>
                <input type="file" id="ava" name="ava" />
            </div>
            <div class="form-group">
                <input type="submit" class="btn btn-primary" value="OK" />
            </div>
        </form>
    </div>
</div>
</div>*/