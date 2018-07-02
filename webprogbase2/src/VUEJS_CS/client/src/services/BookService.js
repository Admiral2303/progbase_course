import Api from '@/services/Api'

export default {
    index(page) {
        return Api().get('/books?page=' + page)
    },
    post(book) {
        return Api().post('/books/create', book, { headers: { 'Content-Type': 'multipart/form-data' } })
    },
    search(book, page) {
        return Api().get('/books/search1?name=' + book.name + "&authorname=" + book.authorname + "&authorSurname=" + book.authorSurname + "&year=" + book.year + "&language=" + book.language + "&page=" + page);
    },
    getById(id) {
        return Api().get('/books/' + id);
    },
    deleteBook(id) {
        return Api().post('/books/delete/' + id, null)
    },
    updateBook(book) {
        return Api().post('/books/update/', book)
    },
    updateBookAva(data) {
        return Api().post('/books/updateBookAva/', data, { headers: { 'Content-Type': 'multipart/form-data' } })
    },
    addComment(data) {
        return Api().post('/books/addcoment', data)
    },
    getuserbooks(page) {
        return Api().get('/books/userbooks?page=' + page);
    },
    mybookssearch(book, page) {
        return Api().get('/books/userbooks/search?name=' + book.name + "&authorname=" + book.authorname + "&authorSurname=" + book.authorSurname + "&year=" + book.year + "&language=" + book.language + "&page=" + page);
    },
    getuserbookmarks(page) {
        return Api().get('/books/userbookmarks?page=' + page);
    },
    bookmarkssearch(book, page) {
        return Api().get('/books/userbookmarks/search?name=' + book.name + "&authorname=" + book.authorname + "&authorSurname=" + book.authorSurname + "&year=" + book.year + "&language=" + book.language + "&page=" + page);
    },
    getrentbooks(id) {
        return Api().get('/books/rentbooks?id=' + id);
    },
    deleteRentBook(data) {
        return Api().post('/books/rentbooks/delete', data)
    },
    deleteBookInRent(data) {
        return Api().post('/books/booksinrent/delete', data);
    },
    getbooksinrent(id) {
        return Api().get('/books/booksinrent?id=' + id);
    },
    returnBooktoRent(data) {
        return Api().post('/books/returnbooktorent', data);
    }




}