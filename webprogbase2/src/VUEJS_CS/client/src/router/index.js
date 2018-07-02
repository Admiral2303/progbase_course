import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'
import Register from '@/components/Register'
import Login from '@/components/Login'
import ViewBook from '@/components/bookpage/BookPage'
import BooksPage from '@/components/bookspage/BooksPage'
import BookAdd from '@/components/bookspage/BookAdd'
import Profile from '@/components/profilepage/Profile'

import UserProfile from '@/components/profilepage/UserProfile'

import MybooksPage from '@/components/bookspage/MybooksPage'

import Bookmarks from '@/components/bookspage/Bookmarks'

import Chat from '@/components/chat/Chat'

import Rentbooks from '@/components/booksrent/RentBooks'

import Booksinrent from '@/components/booksrent/BooksInRentPage'

import Payments from '@/components/payments/PaymentsPage'

import ErrorPage from '@/components/Error'

import store from '@/store/store'
Vue.use(Router)

const router = new Router({
    routes: [{
            path: '/',
            name: 'MainPage',
            component: BooksPage
        },
        {
            path: '/books',
            name: 'BooksPage',
            component: BooksPage
        },
        {
            path: '/books/add',
            name: 'BookAdd',
            component: BookAdd,
            meta: { isUserLoggedIn: true }
        },
        {
            path: '/books/:bookId',
            name: 'book',
            component: ViewBook,
            meta: { isUserLoggedIn: true }
        },
        {
            path: '/profile',
            name: 'profile',
            component: Profile,
            meta: { isUserLoggedIn: true }
        },
        {
            path: '/profile/:id',
            name: 'Userprofile',
            component: UserProfile,
            meta: { isUserLoggedIn: true }
        },
        {
            path: '/mybooks/',
            name: 'MybooksPage',
            component: MybooksPage,
            meta: { isUserLoggedIn: true }
        },
        {
            path: '/bookmarks/',
            name: 'Bookmarks',
            component: Bookmarks,
            meta: { isUserLoggedIn: true }
        },
        {
            path: '/chat/',
            name: 'Chat',
            component: Chat,
            meta: { isUserLoggedIn: true }
        },
        {
            path: '/rentbooks/',
            name: 'Rentbooks',
            component: Rentbooks,
            meta: { isUserLoggedIn: true }
        },
        {
            path: '/booksinrent/',
            name: 'Booksinrent',
            component: Booksinrent,
            meta: { isUserLoggedIn: true }
        },
        {
            path: '/payments/',
            name: 'Payments',
            component: Payments,
            meta: { isUserLoggedIn: true }
        },
        {
            path: '/eror/',
            name: 'ErrorPage',
            component: ErrorPage
        },
        {
            path: '*',
            redirect: to => {
                store.dispatch('setError', 'Not Found');
                store.dispatch('setErrorCode', '404');
                return { name: 'ErrorPage' };
            }

        },


    ]
})

router.beforeEach((to, from, next) => {
    if (to.matched.some(record => record.meta.isUserLoggedIn))
        if (store.state.isUserLoggedIn === false) {

            store.dispatch('setError', 'Unauthorized');
            store.dispatch('setErrorCode', '401');

            next({
                path: '/eror',
                query: {
                    redirect: 'ErrorPage',
                },
            });
        } else {
            next();
        }
    else {
        next();
    }

})

export default router;