import Api from '@/services/Api'

export default {
    chatusers() {
        return Api().get('/chat');
    },
    sendmessage(data) {
        return Api().post('/chat/sendMessage', data);
    },
    getmessages(id) {
        return Api().get('/chat/' + id)
    }
}