import Api from '@/services/Api'

export default {
    payments() {
        return Api().get('/webmoney/payments');
    },
    sendadress(data) {
        return Api().post('webmoney/payments/addadress', data);
    },
    sendbook(id) {
        return Api().post('webmoney/payments/sendbook', id);
    },
    returnbook(id) {
        return Api().post('webmoney/payments/returnbook', id);
    },
    takebook(id) {
        return Api().post('webmoney/payments/takebook', id);
    },
    sendstatus(id) {
        return Api().post('webmoney/payments/setstatus', id);
    },
}