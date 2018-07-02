import Api from '@/services/Api'

export default {
    user(id) {
        return Api().get('/user/userbyId?id=' + id);
    },
    update(data) {
        return Api().post('/user/update', data);
    },
    updatePassword(data) {
        return Api().post('/user/changepassword', data);
    },
    updateImage(data) {
        return Api().post('/user/changeImage', data, { headers: { 'Content-Type': 'multipart/form-data' } });
    },
    addBookmarktoUser(id) {
        return Api().post('/user/addbookmark/' + id);
    },
    deleteUserBookmark(id) {
        return Api().post('/user/deletebookmark/' + id);
    },
    rentBook(data) {
        return Api().post('/user/rentBook', data);
    },
    setWallet(data) {
        return Api().post('/user/wallet', data);
    },


}