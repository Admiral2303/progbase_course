let model = {
    books: [],
    filterString: "",

    // get filteredBooks() {
    //     let filter = model.filterString.toLowerCase().trim();
    //     return !filter ?
    //         this.books :
    //         this.books
    //         .filter(x => x.name.toLowerCase().includes(filter));
    // }
};

window.addEventListener('load', function() {
    // let inputEl = document.getElementById('filter_string');
    // inputEl.addEventListener('input', function(e) {
    //     //console.log(e.target.value);
    //     model.filterString = e.target.value;
    //     renderBooks();
    // });
    // inputEl.value = model.filterString;
    console.log("887");
    requestBooks();
});


function requestBooks() {
    let ajax = new XMLHttpRequest();

    ajax.onreadystatechange = function() {

        console.log(ajax.readyState, ajax.response, ajax.status);
        if (ajax.readyState === 4 && ajax.status === 200) {
            let booksObj = JSON.parse(ajax.response);
            model.books = booksObj;
            renderBooks();
        }
    };
    ajax.open('GET', '/books/data');
    ajax.send();

}


function renderBooks(books) {
    let appEl = document.getElementById('app');
    appEl.innerHTML = "";
    let listEl = document.createElement('ul');
    appEl.appendChild(listEl);

    for (let book of books) {
        let bookEl = document.createElement('li');
        bookEl.innerHTML = `${books.name} (${book._id})`;
        listEl.appendChild(bookEl);
    }
}

// function renderBooks() {
//     let appEl = document.getElementById('app');
//     appEl.innerHTML = "";
//     let booksListEl = document.createElement('ul');
//     booksListEl.className = "list-group";
//     booksListEl.setAttribute('id', 'books');
//     appEl.appendChild(booksListEl);
//     let counterEl = document.createElement('span');
//     let filteredbooks = model.filteredbooks;
//     counterEl.innerText = `Filter: "${model.filterString}" Total: ${filteredbooks.length}`;

//     appEl.insertBefore(counterEl, booksListEl);
//     for (let book of filteredbooks) {
//         let bookEl = document.createElement('li');
//         bookEl.className = "list-group-item";
//         let bookNameEl = document.createElement('span');
//         bookNameEl.innerText = book.name;
//         let bookScoreEl = document.createElement('b');
//         bookScoreEl.innerText = book.score;
//         bookEl.appendChild(bookNameEl);
//         booksListEl.appendChild(bookEl);
//     }
// }