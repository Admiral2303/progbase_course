<template>
<div>
<div class="col-md-6">
    <form v-on:submit.prevent="onSubmit">
        <div class="form-group">
            <label class="control-label" for="name" >Імʼя</label>
            <span class="form-group-addon"><i class="glyphicon glyphicon-user"></i></span>
            <input v-model="User.name" class="form-control" data-error="Введіть імʼя" id="name" name="name"  type="text"  />
            <div class="help-block with-errors"></div>
        </div>
        <div class="form-group">
            <label class="control-label" for="surname">Прізвище</label>
            <span class="form-group-addon"><i class="glyphicon glyphicon-user"></i></span>
            <input v-model="User.surname" class="form-control" data-error="Введіть прізвище" id="surname" name="surname" placeholder="Name"  type="text"  />
            <div class="help-block with-errors"></div>
        </div>
        <div class="form-group">
            <label class="control-label" for="country" >Країна</label>
            <span class="form-group-addon"><i class="glyphicon glyphicon-user"></i></span>
            <input v-model="User.country" class="form-control" data-error="Введіть імʼя" id="country" name="country"  type="text"  />
            <div class="help-block with-errors"></div>
        </div>
        <div class="form-group">
            <label class="control-label" for="city" >Місто</label>
            <span class="form-group-addon"><i class="glyphicon glyphicon-user"></i></span>
            <input v-model="User.city" class="form-control" data-error="Введіть імʼя" id="city" name="city"  type="text"  />
            <div class="help-block with-errors"></div>
        </div>
        <div class="form-group">
            <label for="email" class="control-label">Email</label>
            <span class="form-group-addon"><i class="glyphicon glyphicon-envelope"></i></span>
            <input v-model="User.email" type="email" class="form-control" id="email" name="email" data-error="Введіть правильний email" placeholder="Email" >
            <div class="help-block with-errors"></div>
        </div>
        <div class="form-group">
            <label for="login" class="control-label">Логін</label>
            <span class="form-group-addon"><i class="glyphicon glyphicon-home"></i></span>
            <input v-model="User.login" type="text" class="form-control" id="login" name="login" data-error="Введіть правильний email" placeholder="Email" required>
            <div class="help-block with-errors"></div>
        </div>               
        <div class="form-group">
            <button class="btn btn-primary" type="submit">
                Обновити
            </button>
        </div>
    </form>
</div>

<div class="col-md-6">
    <form v-on:submit.prevent="changePassword">
         <div class="form-group">
            <label for="password" class="control-label">Пароль</label>
            <span class="form-group-addon"><i class="glyphicon glyphicon-lock"></i></span>
            <input v-model="password" type="password" id="password1" name="password" data-minlength="5" class="form-control" v-validate="'required'"   data-error="Пароль має містити мінімум 5 символів" placeholder="Пароль" required>
            
        </div>
        <div class="form-group">
            <label for="password2" class="control-label">Повторіть пароль</label>
            <span class="form-group-addon"><i class="glyphicon glyphicon-lock"></i></span>
            <input type="password" v-validate="'confirmed:password'" :class="{'input': true, 'is-danger': errors.has('password') }" v-model="password2" id="password2" name="password2" data-minlength="5" class="form-control"  data-error="Паролі не співпадають" placeholder="Пароль" required>
            <div class="alert alert-danger" v-show="errors.any()">
            <div v-if="errors.has('password')">
              Введіть пароль
            </div>
            <div v-if="errors.has('password2')">
              Паролі не співпадають
            </div>
            </div>  
        </div>
        <div class="form-group">
            <button id="save" type="submit" class="btn btn-primary">Змінити пароль</button>
        </div>
    </form>
<hr class="line"/>
<form  v-on:submit.prevent="changeImg"> 
    <div class="form-group">
        <label class="col-md-4 control-label">Kартинкa</label>
        <div class="col-md-4 inputGroupContainer">
            <div class="form-group">
                <input v-validate="'image|size:2000'" :class="{'input': true, 'is-danger': errors.has('password') }" @change="uploadImage"  type="file" name="image" required accept="image/*">
                 <span class="error">{{ errors.first('image') }}</span> 
            </div>
        </div>
    </div>
    <div class="form-group">
        <button id="save" type="submit" class="btn btn-primary">Змінити аватарку</button>
    </div>
</form>
</div>
</div >
</template>

<script>
    import UserService from '@/services/UserService'
    import AuthenticationService from '@/services/AuthenticationService'
    import {mapState} from 'vuex'
    export default {
        name: 'login',
        data() {
            return {
                User: {},
                password: null,
                password2: null,
                data: null
            }
        },
        computed: {
            ...mapState([
            'isUserLoggedIn',
            'user',
            'route'
            ])
        },

        methods: {
            async onSubmit(){
                let image = this.user.image;
                this.User.image = image;
                await UserService.update(this.User);
                let userAfterUpdate = await UserService.user(this.User._id);
                this.$store.dispatch('setUser', userAfterUpdate.data.user);


            },
            async changePassword(){
                let data = {
                    _id: this.User._id,
                    pass: this.password
                }
                await UserService.updatePassword(data);
            },
            uploadImage: function(e) {
                console.log("---");
                let files = e.target.files;
                if(!files[0]) {
                    return;
                }
                let data = new FormData();
                data.append('image', files[0]);
                this.data = data;
            },
            async changeImg(){
                this.data.append('id', this.User._id);
                await UserService.updateImage(this.data);   
                let userAfterUpdate = await UserService.user(this.User._id);
                this.$store.dispatch('setUser', userAfterUpdate.data.user);
            }
            
        },
        async mounted(){
            //console.log(this.user._id);
             let U = await UserService.user(this.user._id)
             console.log(U.data.user)
             this.User = U.data.user;
        },

    }
</script>

<style scoped>
.line{
    color: black;
    background-color: black;
}
</style>