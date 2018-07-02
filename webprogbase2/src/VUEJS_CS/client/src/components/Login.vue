<template>
<div>
<div class="modal fade" id="myModal" tabindex="-1" role="dialog">
    <div class="modal-dialog">
        <div class="modal-content">
            <!-- Заголовок модального окна -->
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal">×</button>
                <h4 class="modal-title" id="myModalLabel">Авторизація</h4>
            </div>
            <!-- Основная часть модального окна, содержащая форму для регистрации -->
            <div class="modal-body">
                <!-- Форма для регистрации -->
                <form role="form" class="form-horizontal" >
                    <!-- Блок для ввода логина -->
                    <div class="form-group has-feedback">
                        <label for="login" class="control-label col-xs-3">Логин:</label>
                        <div class="col-xs-6">
                            <div class="input-group">
                                <span class="input-group-addon"><i class="glyphicon glyphicon-user"></i></span>
                                <input  label="Login" v-model="login" type="text" class="form-control" required="required">
                            </div>
                            <span class="glyphicon form-control-feedback"></span>
                        </div>
                    </div>
                    <!-- Блок для ввода email -->
                    <div class="form-group has-feedback">
                        <label for="email" class="control-label col-xs-3">Пароль:</label>
                        <div class="col-xs-6">
                            <div class="input-group">
                                <span class="input-group-addon"><i class="glyphicon glyphicon-envelope"></i></span>
                                <input type="password" v-model="password" class="form-control" required="required" >
                            </div>
                            <span class="glyphicon form-control-feedback"></span>
                        </div>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Отмена</button>
                        <button id="save"  @click="signin" class="btn btn-primary" data-dismiss="modal" >Увійти</button>
                    </div>
                    <!-- Конец блока для ввода email-->
                </form>
            </div>
            <!-- Нижняя часть модального окна -->
            
        </div>
     </div>
</div>



</div >
</template>

<script>
    import AuthenticationService from '@/services/AuthenticationService'
    export default {
        name: 'login',
        data() {
            return {
                login: 'Admiral2303',
                password: '2303',
                error: null
            }
        },

        methods: {

            async signin() {
                try {
                    const responce = await AuthenticationService.login({
                        login: this.login,
                        password: this.password
                    })
                    console.log(responce.data);
                    this.$store.dispatch('setToken', responce.data.token)
                    this.$store.dispatch('setUser', responce.data.user)
                } catch (error) {
                    this.error = error.response.data.error
                    console.log(error);
                }
            },
            logout() {
                this.$store.dispatch('setToken', null)
                this.$store.dispatch('setUser', null)

            }
        }

    }
</script>

<style scoped>

</style>