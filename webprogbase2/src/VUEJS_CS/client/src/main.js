// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'
import { sync } from 'vuex-router-sync'
import store from '@/store/store'
import jQuery from 'jquery'
import VeeValidate from 'vee-validate';

import Paginate from 'vuejs-paginate'
Vue.use(VeeValidate);



global.jQuery = jQuery


let Bootstrap = require('bootstrap');
import 'bootstrap/dist/css/bootstrap.css'

Vue.config.productionTip = false


Vue.component('paginate', Paginate)




sync(store, router)
    /* eslint-disable no-new */
new Vue({
    el: '#app',
    router,
    store,
    VeeValidate,
    template: '<App/>',
    components: {
        App
    }
})