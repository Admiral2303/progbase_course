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
                                <div v-if="user1">
                                    <img :src="user1.image" alt="img" class="img">
                                </div>
                                <div v-else>
                                    <img :src="user.image" alt="img" class="img">
                                </div>
                                    <h3>
                                    <div v-if="user1">
                                        {{user1.name}}
                                        {{user1.surname}}
                                    </div>
                                    <div v-else>
                                        {{user.name}}
                                        {{user.surname}}
                                    </div>
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
                                    
                                    <li class=""><a href="#edit" data-toggle="tab">Редагувати</a></li>
                                    
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
                                                    <div v-if="user1">
                                                        {{user1.name}}
                                                    </div>
                                                    <div v-else>
                                                        {{user.name}}
                                                    </div>
                                                    </td>
                                                </tr>
                                                <tr>
                                                    <td class="active">Прізвище:</td>
                                                    <td>
                                                    <div v-if="user1">
                                                        {{user1.surname}}
                                                    </div>
                                                    <div v-else>
                                                        {{user.surname}}
                                                    </div>  
                                                    </td>
                                                </tr>
                                                <tr>
                                                    <td class="active">Стать:</td>
                                                    <td>
                                                    <div v-if="user1">
                                                        {{user1.sex}}
                                                    </div>
                                                    <div v-else>
                                                        {{user.sex}}
                                                    </div>
                                                        
                                                    </td>
                                                </tr>
                                                <tr>
                                                    <td class="active">Країна:</td>
                                                    <td>
                                                    <div v-if="user1">
                                                        {{user1.country}}
                                                    </div>
                                                    <div v-else>
                                                        {{user.country}}
                                                    </div>
                                                        
                                                    </td>
                                                </tr>
                                                <tr>
                                                    <td class="active">Місто:</td>
                                                    <td>
                                                    <div v-if="user1">
                                                        {{user1.city}}
                                                    </div>
                                                    <div v-else>
                                                        {{user.city}}
                                                    </div>
                                                        
                                                    </td>
                                                </tr>
                                                <tr>
                                                    <td class="active">email:</td>
                                                    <td>
                                                    <div v-if="user1">
                                                        {{user1.email}}
                                                    </div>
                                                    <div v-else>
                                                        {{user.email}}
                                                    </div>
                                                        
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
                                    <div class="tab-pane fade" id="edit">
                                        <p></p>
                                        <change-profile> </change-profile>
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
    import ChangeProfile from './ChangeProfile'
    export default {
        name: 'login',
        data() {
            return {
                user1: null
            }
        },
        computed: {
            user() {
                return this.$store.getters.user
            },
            ...mapState([
            'isUserLoggedIn',
            'user',
            'route'
        ])
        
        },

        methods: {

            
        },
        components: {
            ChangeProfile,
            PageHeader
        },
        async mounted(){
            console.log("+++++");
            console.log(this.route.params.id);
        }

    }
</script>

<style scoped>
.img{
    max-width: 200px;
    max-height: 250px;
}
</style>