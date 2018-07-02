let fs = require('fs');

const mongoose = require('mongoose');
mongoose.Promise = require('bluebird');

let env = require('node-env-file');
env('./config' + '/.env');

let db = mongoose.connect(process.env.MLAB, {
    useMongoClient: true,
});




let Message = db.model('Message', {
    sender_id: String,
    receiver_id: String,
    data: String,
    date: { type: Date, default: Date.now }
});



async function addMessage(message) {

    let mes = new Message({
        sender_id: message.sender_id,
        receiver_id: message.receiver_id,
        data: message.data,
        // date: message.date
    });
    try {
        await mes.save();
    } catch (err) {
        throw err;
    }
}


async function getMessages(id1, id2) {
    try {
        return await Message.find({ $or: [{ sender_id: id1, receiver_id: id2 }, { sender_id: id2, receiver_id: id1 }] }).sort({ date: 1 });
    } catch (err) {
        throw err;
    }
}
// getMessages("5a08327399b4a910dd7e937d", "5a075c2647699b1c6d2fe56d").then(arr => {
//     for (let i of arr) {
//         console.log(i);
//     }
// })


module.exports = {
    addMessage,
    getMessages
};