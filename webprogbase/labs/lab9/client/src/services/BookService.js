import Api from '@/services/Api'

export default {
    index() {
        return Api().get('/api/v1/books')
    },
    post(book) {
        return Api().post('/api/v1/img', book, { headers: { 'Content-Type': 'multipart/form-data' } })
    },
    search(filter) {
        return Api().get('/api/v1/books/filter?name=' + filter);
    },
    getpageBooks(page) {
        return Api().get('/api/v1/books?page=' + page);
    },
    searchPage(search, page) {
        return Api().get('/api/v1/books/filter?name=' + search + "&page=" + page);
    }

}