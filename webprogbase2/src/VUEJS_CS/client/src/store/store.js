import Vue from 'vue'
import Vuex from 'vuex'
import createPersistedState from 'vuex-persistedstate'

Vue.use(Vuex)

export default new Vuex.Store({
    strict: true,
    plugins: [
        createPersistedState()
    ],
    state: {
        token: null,
        user: null,
        isUserLoggedIn: false,
        books: [],
        pages: null,
        searchflag: false,
        search: null,
        book: null,
        bookComents: null,
        mybooksflag: false,
        bookmarksflag: false,
        chatUserid: null,
        error: null,
        errorcode: null
    },
    mutations: {
        setToken(state, token) {
            state.token = token
            if (token) {
                state.isUserLoggedIn = true
            } else {
                state.isUserLoggedIn = false
            }
        },
        setUser(state, user) {
            state.user = user
        },
        setBooks(state, books) {
            state.books = books
        },
        setPages(state, pages) {
            state.pages = pages
        },
        setSearchFlag(state, flag) {
            state.searchflag = flag;
        },
        setSearch(state, search) {
            state.search = search;
        },
        setBook(state, book) {
            state.book = book;
        },
        setBookComents(state, coments) {
            state.bookComents = coments;
        },
        setMyBooksFlag(state, mybooksflag) {
            state.mybooksflag = mybooksflag;
        },
        setBookmarksFlag(state, bookmarksflag) {
            state.bookmarksflag = bookmarksflag;
        },
        setChatUserid(state, chatUserid) {
            state.chatUserid = chatUserid;
        },
        setError(state, error) {
            state.error = error;
        },
        setErrorCode(state, errorcode) {
            state.errorcode = errorcode;
        },

    },
    actions: {
        setToken({ commit }, token) {
            commit('setToken', token)
        },
        setUser({ commit }, user) {
            commit('setUser', user)
        },
        setBooks({ commit }, books) {
            commit('setBooks', books)
        },
        setPages({ commit }, pages) {
            commit('setPages', pages)
        },
        setSearchFlag({ commit }, flag) {
            commit('setSearchFlag', flag)
        },
        setSearch({ commit }, search) {
            commit('setSearch', search)
        },
        setBook({ commit }, book) {
            commit('setBook', book)
        },
        setBookComents({ commit }, coments) {
            commit('setBookComents', coments)
        },
        setMyBooksFlag({ commit }, mybooksflag) {
            commit('setMyBooksFlag', mybooksflag)
        },
        setBookmarksFlag({ commit }, bookmarksflag) {
            commit('setBookmarksFlag', bookmarksflag)
        },
        setChatUserid({ commit }, chatUserid) {
            commit('setChatUserid', chatUserid)
        },
        setError({ commit }, error) {
            commit('setError', error)
        },
        setErrorCode({ commit }, errorcode) {
            commit('setErrorCode', errorcode)
        },
    },
    getters: {
        user(state) {
            return state.user;
        },
        books(state) {
            return state.books;
        },
        pages(state) {
            return state.pages;
        },
        searchflag(state) {
            return state.searchflag;
        },
        search(state) {
            return state.search;
        },
        book(state) {
            return state.book;
        },
        coments(state) {
            return state.bookComents;
        },
        mybooksflag(state) {
            return state.mybooksflag;
        },
        bookmarksflag(state) {
            return state.bookmarksflag;
        },
        chatUserid(state) {
            return state.chatUserid;
        },
        error(state) {
            return state.error;
        },
        errorcode(state) {
            return state.errorcode;
        },

    },
})