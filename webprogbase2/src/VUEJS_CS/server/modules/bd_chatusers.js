let fs = require('fs');
const mongoose = require('mongoose');
mongoose.Promise = require('bluebird');
let env = require('node-env-file');
env('./config' + '/.env');

let db = mongoose.connect(process.env.MLAB, {
    useMongoClient: true,
});




let ChatUsers = db.model('ChatUsers', {
    user1_id: String,
    user2_id: String
});



async function createChat(id1, id2) {
    let chatUsers = new ChatUsers({
        user1_id: id1,
        user2_id: id2
    });
    try {
        await chatUsers.save();
    } catch (err) {
        throw err;
    }
}

async function checkChatUsers(id1, id2) {
    try {
        let checkChat1 = await ChatUsers.findOne({ user1_id: id1, user2_id: id2 }, function(err, obj) {});
        let checkChat2 = await ChatUsers.findOne({ user1_id: id2, user2_id: id1 }, function(err, obj) {});
        if (checkChat1) {
            return checkChat1;
        } else if (checkChat2) {
            return checkChat2;
        } else {
            return null;
        }
    } catch (err) {
        throw err;
    }
}


async function getChatUser(id) {
    try {
        let checkChat1 = await ChatUsers.find({ user1_id: id }, function(err, obj) {});
        let checkChat2 = await ChatUsers.find({ user2_id: id }, function(err, obj) {});
        if (checkChat1 && checkChat2) {
            let usersArr = [];
            for (let userId of checkChat1) {
                if (userId.user2_id != id) {
                    usersArr.push(userId.user2_id);
                }
            }
            for (let userID of checkChat2) {
                if (userID.user1_id != id) {
                    usersArr.push(userID.user1_id);
                }
            }
            return Promise.resolve(usersArr);

        } else if (checkChat1) {
            let usersArr = [];
            for (let userId of checkChat1) {
                if (userId.user2_id != id) {
                    usersArr.push(userId.user2_id);
                }
            }
            return Promise.resolve(usersArr);
        } else if (checkChat2) {
            let usersArr = [];
            for (let userID of checkChat2) {
                if (userID.user1_id != id) {
                    usersArr.push(userID.user1_id);
                }
            }
            return Promise.resolve(usersArr);
        } else {
            return null;
        }

    } catch (err) {
        throw err;
    }
}




module.exports = {
    createChat,
    checkChatUsers,
    getChatUser
};