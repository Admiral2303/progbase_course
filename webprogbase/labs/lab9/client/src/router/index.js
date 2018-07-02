import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'

import Books from '@/components/Header'
import BooksList from '@/components/BooksList'
import CreateBook from '@/components/CreateBook'
import store from '@/store/store'
Vue.use(Router)

const router = new Router({
    routes: [

        {
            path: '/bookslist',
            name: 'BooksList',
            component: BooksList
        },
        {
            path: '/bookslist/add',
            name: 'add',
            component: CreateBook
        }

    ]
})

// router.beforeEach((to, from, next) => {
//     if (to.matched.some(record => record.meta.isUserLoggedIn))
//         if (store.state.isUserLoggedIn === false) {
//             next({
//                 path: '/login',
//                 query: {
//                     redirect: to.fullPath,
//                 },
//             });
//         } else {
//             next();
//         }
//     else {
//         next();
//     }

// })

export default router;