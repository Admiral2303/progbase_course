<template>
  <form id="demo" @submit.prevent="validateBeforeSubmit()">
  <div class="input-group">
    <div class="input-group-addon">
      Enter Password
    </div>

    <div class="input-fields">
      <input v-validate="'required'" name="password" type="password" class="form-control" placeholder="Password">

      <input v-validate="'required|confirmed:password'" name="password_confirmation" type="password" class="form-control" placeholder="Password, Again" data-vv-as="password">
    </div>
  </div>

  <div class="alert alert-danger" v-show="errors.any()">
    <div v-if="errors.has('password')">
      {{ errors.first('password') }}
    </div>
    <div v-if="errors.has('password_confirmation')">
      {{ errors.first('password_confirmation') }}
    </div>
  </div>

  <button type="submit" class="btn btn-primary">
        Validate!
    </button>
</form>



</template>



<script>

export default {



  name: 'form-example',
  data: () => ({
    email: '',
    name: '',
    phone: '',
    url: ''
  }),
  
   methods: {
    validateBeforeSubmit() {
      this.$validator
        .validateAll()
        .then(function(response) {
          // Validation success if response === true
        })
        .catch(function(e) {
          // Catch errors
        })
    }
  
  }
};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
form {
  max-width: 500px;
  width: 100%;
  margin: 30px auto;
  border: 1px solid #ccc;
  padding: 15px;
  background: #fafafa;
}

.input-group {
  padding: 15px;
}

.input-fields {
  width: 100%;
}

input[type=password] {
  width: 100% !important;
  display: block !important;
}

button {
  margin: 0 auto;
  display: block !important;
  width: 200px;
  cursor: pointer;
}

.footer {
  text-align: center;
  font-size: 13px;
}


.invalid .multiselect__tags {
  border-color: red;
}
.input.is-danger, .textarea.is-danger {
        border-color: #ff3860;
    }

.help.is-danger {
        color: #ff3860;
}
    
</style>
