let model = {
    books: [],
    //pages: "",
    filterString: "",

    get filteredbooks() {
        let filter = model.filterString.toLowerCase().trim();
        return !filter ?
            this.books :
            this.books
            .filter(x => x.name.toLowerCase().includes(filter));
    }
};

window.addEventListener('load', function() {

    let inputEl = document.getElementById('filter_string');
    // let but = document.getElementById('search');
    inputEl.addEventListener('input', function(e) {
        model.filterString = e.target.value; //document.getElementById('filter_string').value;
        renderbooks(1);
    });
    inputEl.value = model.filterString;

    requestbooks();
});




function requestbooks() {
    let ajax = new XMLHttpRequest();

    ajax.onreadystatechange = function() {
        if (ajax.readyState === 4 && ajax.status === 200) {
            let booksObj = JSON.parse(ajax.response);
            model.books = booksObj.books;
            // model.pages = booksObj.pages;
            renderbooks(1);
            console.log("++++++++++++");
        }
    };

    // ajax.open('GET', '/books/data')
    ajax.open('GET', '/api/v1/books');
    ajax.send();
}

function renderbooks(page) {
    let Pages = [];
    let count = 2;
    let filteredbookspages = Math.ceil(model.filteredbooks.length / count);
    console.log("pages: " + filteredbookspages);
    for (let i = 1; i <= filteredbookspages; i++) {
        Pages.push({ page: i });
    }

    let currentarr = model.filteredbooks.slice((page - 1) * count, page * count);
    // console.log(model.pages);


    let template = document.getElementById("my-list-template").innerHTML;
    let renderedHTML = Mustache.render(template, { list: currentarr, pages: Pages });
    document.getElementById("app").innerHTML = renderedHTML;


    let pagination = document.getElementById("footer").innerHTML;

    for (let i = 1; i <= parseInt(filteredbookspages); i++) {
        let button = document.getElementById('Page' + i);
        button.addEventListener('click', function(e) {
            renderbooks(i);
        });
    }




}





// }