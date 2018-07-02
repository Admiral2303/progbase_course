import axios from 'axios';
import store from '@/store/store'
import Globals from "./globals"

export default () => {
    return axios.create({
        baseURL: Globals.ROOT_URL,
        headers: {
            Authorization: `Bearer ${store.state.token}`
        }
    })
}