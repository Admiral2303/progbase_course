<template>
<div>
<div class="modal fade" id="myModal1" tabindex="-1" role="dialog">
      <div class="modal-dialog">
        <div class="modal-content">

          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal">×</button>
            <h4 class="modal-title" id="myModalLabel">Регистрация</h4>
          </div>

          <div class="modal-body">
                <div class="panel panel-primary" >
                <div class="panel-heading"></div>
                    <div class="panel-body">
                        <form  v-on:submit.prevent="validateBeforeSubmit" >
                            <div class="form-group">
                                <label class="control-label" for="name" >Імʼя</label>
                                <span class="form-group-addon"><i class="glyphicon glyphicon-user"></i></span>
                                <input class="form-control" v-model="name" data-error="Введіть імʼя" id="name" name="name" v-validate="'required|alpha','regex:^[А-Яа-яa-zA-Z\s]+$'" data-vv-delay="500" :class="{'input': true, 'is-danger': errors.has('name') }"  type="text" required/>
                                <i v-show="errors.has('name')" class="fa fa-warning"></i>
                                <span v-show="errors.has('name')" class="help is-danger">Введіть коректне ім'я</span>
                            </div>
                            <div class="form-group">
                                <label class="control-label" for="surname">Прізвище</label>
                                <span class="form-group-addon"><i class="glyphicon glyphicon-user"></i></span>
                                <input class="form-control" v-model="surname" data-error="Введіть прізвище" id="surname" name="surname" v-validate="'required|alpha','regex:^[А-Яа-яa-zA-Z\s]+$'" data-vv-delay="500" :class="{'input': true, 'is-danger': errors.has('surname') }"  type="text" placeholder="Прізвище" required/>
                                <i v-show="errors.has('surname')" class="fa fa-warning"></i>
                                <span v-show="errors.has('surname')" class="help is-danger">Введіть коректне прізвище</span>
                            </div>
                            <div class="form-group">
                                <label for="email" class="control-label">Email</label>
                                <span class="form-group-addon"><i class="glyphicon glyphicon-envelope"></i></span>
                                <input  class="form-control" name="email" v-model="email" v-validate="'required|email'" data-vv-delay="1000" :class="{'input': true, 'is-danger': errors.has('email') }"type="text" placeholder="Email" required>
                                <i v-show="errors.has('email')" class="fa fa-warning"></i>
                                <span v-show="errors.has('email')" class="help is-danger">Введіть коректний email</span>
                            </div> 
                            <div class="form-group">
                                <label for="login" class="control-label">Логін</label>
                                <span class="form-group-addon"><i class="glyphicon glyphicon-home"></i></span>
                                <input type="text" v-model="login" class="form-control" id="login" name="login" data-error="Введіть правильний email" placeholder="Логін" required>
                                
                            </div>
                            <div class="form-group">
                                <label for="password" class="control-label">Пароль</label>
                                <span class="form-group-addon"><i class="glyphicon glyphicon-lock"></i></span>
                                <input type="password" v-model="password" v-validate="'required'" id="password" name="password" data-minlength="5" class="form-control"  data-error="Пароль має містити мінімум 5 символів" placeholder="Пароль" required>
                                
                            </div>

                            <div class="form-group">
                                <label for="password2" class="control-label">Повторіть пароль</label>
                                <span class="form-group-addon"><i class="glyphicon glyphicon-lock"></i></span>
                                <input type="password" v-validate="'confirmed:password'" :class="{'input': true, 'is-danger': errors.has('password') }" id="password2" name="password2" data-minlength="5" class="form-control"  data-error="Паролі не співпадають" placeholder="Пароль" required>
                                <div class="alert alert-danger" v-show="errors.any()">
                                  <div v-if="errors.has('password')">
                                    Введіть пароль
                                  </div>
                                  <div v-if="errors.has('password2')">
                                    Паролі не співпадають
                                  </div>
                                </div>
                                
                            </div>
                            <div class="modal-footer">
                                <button type="button" class="btn btn-default" data-dismiss="modal">Отмена</button>
                                <button  type="submit" class="btn btn-warning" >Реєстрація <span class="glyphicon glyphicon-send"></span></button>
                            </div>
                        </form>
                        
                    </div>   
            </div>
          </div>
        </div>
      </div>
    </div>
</div>    
</template>

<script>
import AuthenticationService from '@/services/AuthenticationService'
export default {
  name: 'register',
  data () {
    return {
      name: "",
      surname: "",
      email: "",
      login: "",
      password: ""
    }
  },
  methods: {
    validateBeforeSubmit(e) {
        this.$validator.validateAll();
        if (!this.errors.any()) {
            this.formSubmit()
        } else{
            alert("Дані введено не правильно")
        }
      },



    async formSubmit (){
    
      const responce = await AuthenticationService.register({
          name: this.name,
          surname: this.surname,
          email: this.email,
          login: this.login,
          password: this.password
      });
      if(responce.data.error){
        alert("Логін занятий")
      } else{
            alert("Ваш акаунт створено")
      }
      console.log(responce.data);
    }
  }

}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

/* .invalid .multiselect__tags {
  border-color: red;
} */
 .textarea.is-danger {
        border-color: #ff3860;
  }
.is-danger{
  color: red;
}

/* .help.is-danger {
        color: #ff3860;
} */
</style>