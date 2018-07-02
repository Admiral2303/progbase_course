const express = require('express');
const router = express.Router();
let check = require('./../modules/check');
let user = require('./../modules/bd_user');
let chat = require('./../modules/bd_chat');
let chatusers = require('./../modules/bd_chatusers');



router.get("/", check.checkAuth, async(req, res) => {
    try {
        let chatusersId = await chatusers.getChatUser(req.user._id);
        let Users = [];
        for (let chatuserId of chatusersId) {
            let User = await user.getUserById(chatuserId);
            Users.push(User);
        }
        res.render('testchat', { user: req.user, users: Users, messages: null });
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});



router.get("/:id", check.checkAuth, async(req, res) => {
    try {
        let chatusersId = await chatusers.getChatUser(req.user._id);
        let Users = [];
        for (let chatuserId of chatusersId) {
            let User = await user.getUserById(chatuserId);
            Users.push(User);
        }
        let receiver_id = req.params.id;
        let sender_id = req.user._id;
        let mes = await chat.getMessages(receiver_id, sender_id);
        let receiverUser = await user.getUserById(receiver_id);
        res.render('testchat', { user: req.user, users: Users, messages: mes, receiver: receiverUser });
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});



router.post("/sendMessage", check.checkAuth, async(req, res) => {
    try {
        //let date = new Date();
        let message = {
            sender_id: req.user._id,
            receiver_id: req.body.receiver_id,
            data: req.body.message,
            // date: date
        }
        await chat.addMessage(message);
        let check = await chatusers.checkChatUsers(req.user._id, req.body.receiver_id);
        if (check == null) {
            await chatusers.createChat(req.user._id, req.body.receiver_id);
        }
        let url = "/chat/" + req.body.receiver_id;
        res.redirect(url)
    } catch (err) {
        res.render('error', { error: "500", text: 'Internal Server Error' });
    }
});

module.exports = router;