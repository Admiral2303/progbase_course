<template>
<div>
      <page-header/>
        <div class="container">
            <div id="main">
                <div class="row" id="real-estates-detail">
                    <div class="col-lg-4 col-md-4 col-xs-12">
                        <div class="panel panel-default">
                            <div class="panel-heading">
                                <header class="panel-title">
                                    <div class="text-center">
                                        <strong>Користувач сайту</strong>
                                    </div>
                                </header>
                            </div>
                            <div class="panel-body">
                                <div class="text-center" id="author">
                                    <img :src="user.image" alt="img" class="img">
                                    <h3>
                                        {{user.name}}
                                        {{user.surname}}
                                    </h3>
                                    <small class="label label-warning">{{user.country}}</small>
                                    <p class="sosmed-author">
                                        <a href="#"><i class="fa fa-facebook" title="Facebook"></i></a>
                                        <a href="#"><i class="fa fa-twitter" title="Twitter"></i></a>
                                        <a href="#"><i class="fa fa-google-plus" title="Google Plus"></i></a>
                                        <a href="#"><i class="fa fa-linkedin" title="Linkedin"></i></a>
                                    </p>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="col-lg-8 col-md-8 col-xs-12">
                        <div class="panel">
                            <div class="panel-body">
                                <ul id="myTab" class="nav nav-pills">
                                    <li class="active"><a href="#detail" data-toggle="tab">Інформація про користувача</a></li>
                                    <!--<li class=""><a href="#contact" data-toggle="tab">Отправить сообщение</a></li> -->
                                    <li class=""><a href="#sendmessage" data-toggle="tab">Написати</a></li>
                                
                                    
                                </ul>
                                <div id="myTabContent" class="tab-content">
                                    <hr>
                                    <div class="tab-pane fade active in" id="detail">
                                        <h4>Основна інформація</h4>
                                        <table class="table table-th-block">
                                            <tbody>      
                                                <tr>
                                                    <td class="active">Ім'я:</td>
                                                    <td>
                                                        {{user.name}}
                                                    </td>
                                                </tr>
                                                <tr>
                                                    <td class="active">Прізвище:</td>
                                                    <td>
                                                        {{user.surname}}
                                                    </td>
                                                </tr>
                                                <tr>
                                                    <td class="active">Стать:</td>
                                                    <td>
                                                        {{user.sex}}
                                                        
                                                    </td>
                                                </tr>
                                               
                                                <tr>
                                                    <td class="active">Країна:</td>
                                                    <td>
                                                        {{user.country}}
                                                        
                                                    </td>
                                                </tr>
                                                <tr>
                                                    <td class="active">Місто:</td>
                                                    <td>
                                                
                                                        {{user.city}}

                                                        
                                                    </td>
                                                </tr>
                                                <tr>
                                                    <td class="active">email:</td>
                                                    <td>
                                                    
                                                        {{user.email}}
                                                
                                                        
                                                    </td>
                                                </tr>
                                                
                                                <div v-if="!user">
                                                <tr>
                                                    <td class="active">Логін:</td>
                                                    <td>
                                                        {{user.login}}
                                                    </td>
                                                </tr>
                                                </div>
                                            </tbody>
                                        </table>
                                    </div>
                                    <div class="tab-pane fade" id="sendmessage">
                                        <form v-on:submit.prevent="sendMessage">
                                            <div class="form-group has-feedback">
                                                <label for="login" class="control-label col-xs-3">Введіть повідомлення:</label>
                                                <div class="col-xs-6">
                                                    <div class="input-group">
                                                        <span class="input-group-addon"><i class="glyphicon glyphicon-user"></i></span>
                                                        <textarea v-model="message" class="form-control" data-error="error" id="message" name="message" required></textarea>
                                                    </div>
                                                    <span class="glyphicon form-control-feedback"></span>
                                                </div>
                                            </div>
                                            
                                            <div class="modal-footer">
                                                
                                                <button id="save" type="submit" class="btn btn-primary" >Відправити</button>
                                            </div>
                                        </form>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>

        </div>
        <!-- /.main -->
        </div>
        <!-- /.container -->

</div >
</template>

<script>
    import {mapState} from 'vuex'
    import PageHeader from '../Header'
    import UserService from '@/services/UserService'
    import ChatService from '@/services/ChatService'
    export default {
        name: 'login',
        data() {
            return {
                user: {}
            }
        },
        computed: {
            ...mapState([
            'isUserLoggedIn',
            'route'
        ])
        
        },

        methods: {
           async sendMessage(){
           let id = this.user._id;
           console.log(id);
           let data = {
               receiver_id: id,
               message: this.message
           }
           
           await ChatService.sendmessage(data);
       }
            
        },
        components: {
            PageHeader
        },
        async mounted(){
            let User = await UserService.user(this.route.params.id);
            console.log(User.data.user);
            this.user = User.data.user;
        }

    }
</script>

<style scoped>
.img{
    max-width: 200px;
    max-height: 250px;
}
</style>