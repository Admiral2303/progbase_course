<template>
<div>
    <chat-users @Changechat="ChangechatUser"> </chat-users>
    <div class="col-md-9  col-md-offset-0 border">
            <ol class="chat"> 
                <div v-if="messages">
                    <div v-for="message of messages" :key="message.date"> 
                        <div v-if="message.sender_id == user._id">
                            <li class="self">
                                <div class="avatar"><img :src="user.image" alt="<%= user.name %>" draggable="false" /> </div>
                                <div class="msg">
                                    <p>
                                        {{message.data}}
                                    </p>
                                    <time>{{message.date}}</time>
                                </div>
                            </li>
                        </div>
                        <div v-else>
                            <li class="other">
                                <div class="avatar"><img :src="seconduser.image" alt="image" draggable="false" > </div>
                                <div class="msg">
                                    <p>{{message.data}}</p>
                                    <time>{{message.date}}</time>
                                </div>
                            </li>
                        </div>
                    </div> 
                </div>
            </ol>
            <form v-on:submit.prevent="sendMessage">
              <input v-model="message" class="textarea" type="text" name="message" id="message"> 
              <input type="submit" value="Отправить">
            </form>
            
            
        </div>
        
</div>
</template>



<script>
import ChatService from '@/services/ChatService'
import ChatUsers from './ChatUsers'
export default {
    data () {
        return {
            messages: null,
            seconduser:null,
            user: null,
            message: null
        }
    },
    computed: {
        receiver() {
            return this.$store.getters.chatUserid
        },
        
    },

    components: {
        ChatUsers
    },
    async mounted(){  
         setInterval(async ()=>{
               
                
         if(this.receiver != null){
            let chat_obj = await ChatService.getmessages(this.receiver);
            // console.log(chat_obj);
            this.messages = chat_obj.data.messages;
            this.user = chat_obj.data.user;
            this.seconduser = chat_obj.data.receiver;
        }else{
            console.log("++++");
        }
        }, 500);

       
    },
    methods:{
        async sendMessage(){
           //let id = this.$store.getters.user._id;
           let id = this.receiver;
           //console.log(id);
           let data = {
               receiver_id: id,
               message: this.message
           }
           await ChatService.sendmessage(data);
            let chat_obj = await ChatService.getmessages(id);
            
            this.messages = chat_obj.data.messages;
            this.receiver = chat_obj.data.receiver;
            this.user = chat_obj.data.user;
            this.message = "";
           // socket.emit('message.sent', this.message);
       },
       async ChangechatUser(){
           let chat_obj = await ChatService.getmessages(this.receiver);
            console.log(chat_obj.data);
            this.messages = chat_obj.data.messages;
            this.user = chat_obj.data.user;
       },
        init: async function(){
             
           await ChatService.sendmessage(data);
            let chat_obj = await ChatService.getmessages(id);
            
            this.messages = chat_obj.data.messages;
            this.receiver = chat_obj.data.receiver;
            this.user = chat_obj.data.user;
            this.ping();
        },
        
        ping:function(){
            // exemple of getting messages in API with conversations params
            setInterval(()=>{
            console.log('get messages');
            }, 500);
        }
    }



};

</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
@import url(https://fonts.googleapis.com/css?family=Lato:100,300,400,700);
@import url(https://maxcdn.bootstrapcdn.com/font-awesome/4.2.0/css/font-awesome.min.css);
html,
body {
    background: #e5e5e5;
    margin: 0px auto;
}

::selection {
    background: rgba(82, 179, 217, 0.3);
    color: inherit;
}

a {
    color: rgba(82, 179, 217, 0.9);
}


/* M E N U */

.menu {
    position: fixed;
    top: 0px;
    left: 180px;
    right: 0px;
    width: 100%;
    height: 50px;
    background: rgba(82, 179, 217, 0.9);
    z-index: 100;
    -webkit-touch-callout: none;
    -webkit-user-select: none;
    -moz-user-select: none;
    -ms-user-select: none;
}

.back {
    position: absolute;
    width: 90px;
    height: 50px;
    top: 0px;
    left: 0px;
    color: #fff;
    line-height: 50px;
    font-size: 30px;
    padding-left: 10px;
    cursor: pointer;
}

.back img {
    position: absolute;
    top: 5px;
    left: 30px;
    width: 40px;
    height: 40px;
    background-color: rgba(255, 255, 255, 0.98);
    border-radius: 100%;
    -webkit-border-radius: 100%;
    -moz-border-radius: 100%;
    -ms-border-radius: 100%;
    margin-left: 15px;
}

.back:active {
    background: rgba(255, 255, 255, 0.2);
}

.name {
    position: absolute;
    top: 3px;
    left: 110px;
    font-family: 'Lato';
    font-size: 25px;
    color: rgba(255, 255, 255, 0.98);
    cursor: default;
}

.last {
    position: absolute;
    top: 30px;
    left: 115px;
    font-weight: 400;
    color: rgba(255, 255, 255, 0.6);
    cursor: default;
}


/* M E S S A G E S */

.chat {
    overflow: scroll;
    /* Добавляем полосы прокрутки */
    width: 100%;
    /* Ширина блока */
    height: 460px;
    list-style: none;
    background: none;
    margin: 0;
    padding: 0 0 50px 0;
    margin-top: 60px;
    margin-bottom: 10px;
}

.chat li {
    padding: 0.5rem;
    overflow: hidden;
    display: flex;
}

.chat .avatar {
    width: 40px;
    height: 40px;
    position: relative;
    display: block;
    z-index: 2;
    border-radius: 100%;
    -webkit-border-radius: 100%;
    -moz-border-radius: 100%;
    -ms-border-radius: 100%;
    background-color: rgba(255, 255, 255, 0.9);
}

.chat .avatar img {
    width: 40px;
    height: 40px;
    border-radius: 100%;
    -webkit-border-radius: 100%;
    -moz-border-radius: 100%;
    -ms-border-radius: 100%;
    background-color: rgba(255, 255, 255, 0.9);
    -webkit-touch-callout: none;
    -webkit-user-select: none;
    -moz-user-select: none;
    -ms-user-select: none;
}

.chat .day {
    position: relative;
    display: block;
    text-align: center;
    color: #c0c0c0;
    height: 20px;
    text-shadow: 7px 0px 0px #e5e5e5, 6px 0px 0px #e5e5e5, 5px 0px 0px #e5e5e5, 4px 0px 0px #e5e5e5, 3px 0px 0px #e5e5e5, 2px 0px 0px #e5e5e5, 1px 0px 0px #e5e5e5, 1px 0px 0px #e5e5e5, 0px 0px 0px #e5e5e5, -1px 0px 0px #e5e5e5, -2px 0px 0px #e5e5e5, -3px 0px 0px #e5e5e5, -4px 0px 0px #e5e5e5, -5px 0px 0px #e5e5e5, -6px 0px 0px #e5e5e5, -7px 0px 0px #e5e5e5;
    box-shadow: inset 20px 0px 0px #e5e5e5, inset -20px 0px 0px #e5e5e5, inset 0px -2px 0px #d7d7d7;
    line-height: 38px;
    margin-top: 5px;
    margin-bottom: 20px;
    cursor: default;
    -webkit-touch-callout: none;
    -webkit-user-select: none;
    -moz-user-select: none;
    -ms-user-select: none;
}

.other .msg {
    order: 1;
    border-top-left-radius: 0px;
    box-shadow: -1px 2px 0px #D4D4D4;
}

.other:before {
    content: "";
    position: relative;
    top: 0px;
    right: 0px;
    left: 40px;
    width: 0px;
    height: 0px;
    border: 5px solid #fff;
    border-left-color: transparent;
    border-bottom-color: transparent;
}

.self {
    justify-content: flex-end;
    align-items: flex-end;
}

.self .msg {
    order: 1;
    border-bottom-right-radius: 0px;
    box-shadow: 1px 2px 0px #D4D4D4;
}

.self .avatar {
    order: 2;
}

.self .avatar:after {
    content: "";
    position: relative;
    display: inline-block;
    bottom: 19px;
    right: 0px;
    width: 0px;
    height: 0px;
    border: 5px solid #fff;
    border-right-color: transparent;
    border-top-color: transparent;
    box-shadow: 0px 2px 0px #D4D4D4;
}

.msg {
    background: white;
    min-width: 50px;
    padding: 10px;
    border-radius: 2px;
    box-shadow: 0px 2px 0px rgba(0, 0, 0, 0.07);
}

.msg p {
    font-size: 2rem;
    margin: 0 0 0.2rem 0;
    color: #777;
}

.msg img {
    position: relative;
    display: block;
    width: 450px;
    border-radius: 5px;
    box-shadow: 0px 0px 3px #eee;
    transition: all .4s cubic-bezier(0.565, -0.260, 0.255, 1.410);
    cursor: default;
    -webkit-touch-callout: none;
    -webkit-user-select: none;
    -moz-user-select: none;
    -ms-user-select: none;
}

@media screen and (max-width: 800px) {
    .msg img {
        width: 300px;
    }
}

@media screen and (max-width: 550px) {
    .msg img {
        width: 200px;
    }
}

.msg time {
    font-size: 0.7rem;
    color: #ccc;
    margin-top: 3px;
    float: right;
    cursor: default;
    -webkit-touch-callout: none;
    -webkit-user-select: none;
    -moz-user-select: none;
    -ms-user-select: none;
}

.msg time:before {
    content: "\f017";
    color: #ddd;
    font-family: FontAwesome;
    display: inline-block;
    margin-right: 4px;
}

emoji {
    display: inline-block;
    height: 18px;
    width: 18px;
    background-size: cover;
    background-repeat: no-repeat;
    margin-top: -7px;
    margin-right: 2px;
    transform: translate3d(0px, 3px, 0px);
}

emoji.please {
    background-image: url(https://imgur.com/ftowh0s.png);
}

emoji.lmao {
    background-image: url(https://i.imgur.com/MllSy5N.png);
}

emoji.happy {
    background-image: url(https://imgur.com/5WUpcPZ.png);
}

emoji.pizza {
    background-image: url(https://imgur.com/voEvJld.png);
}

emoji.cryalot {
    background-image: url(https://i.imgur.com/UUrRRo6.png);
}

emoji.books {
    background-image: url(https://i.imgur.com/UjZLf1R.png);
}

emoji.moai {
    background-image: url(https://imgur.com/uSpaYy8.png);
}

emoji.suffocated {
    background-image: url(https://i.imgur.com/jfTyB5F.png);
}

emoji.scream {
    background-image: url(https://i.imgur.com/tOLNJgg.png);
}

emoji.hearth_blue {
    background-image: url(https://i.imgur.com/gR9juts.png);
}

emoji.funny {
    background-image: url(https://i.imgur.com/qKia58V.png);
}

@-webikt-keyframes pulse {
    from {
        opacity: 0;
    }
    to {
        opacity: 0.5;
    }
}

::-webkit-scrollbar {
    min-width: 12px;
    width: 12px;
    max-width: 12px;
    min-height: 12px;
    height: 12px;
    max-height: 12px;
    background: #e5e5e5;
    box-shadow: inset 0px 50px 0px rgba(82, 179, 217, 0.9), inset 0px -52px 0px #fafafa;
}

::-webkit-scrollbar-thumb {
    background: #bbb;
    border: none;
    border-radius: 100px;
    border: solid 3px #e5e5e5;
    box-shadow: inset 0px 0px 3px #999;
}

::-webkit-scrollbar-thumb:hover {
    background: #b0b0b0;
    box-shadow: inset 0px 0px 3px #888;
}

::-webkit-scrollbar-thumb:active {
    background: #aaa;
    box-shadow: inset 0px 0px 3px #7f7f7f;
}

::-webkit-scrollbar-button {
    display: block;
    height: 26px;
}


/* T Y P E */

input.textarea {
    width: 80%;
    height: 50px;
    z-index: 99;
    background: #fafafa;
    border: none;
    outline: none;
    padding-left: 55px;
    padding-right: 55px;
    color: #666;
    font-weight: 400;
}

.emojis {
    position: fixed;
    display: block;
    bottom: 8px;
    left: 7px;
    width: 34px;
    height: 34px;
    background-image: url(https://i.imgur.com/5WUpcPZ.png);
    background-repeat: no-repeat;
    background-size: cover;
    z-index: 100;
    cursor: pointer;
}

.emojis:active {
    opacity: 0.9;
}

.img {
    height: 50px;
    width: 50px;
    max-height: 50px;
    max-width: 50px;
}

.border {
    border: 2px solid #6E6B6B;
}
    
</style>
