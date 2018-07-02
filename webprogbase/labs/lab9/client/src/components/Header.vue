<template>

<div>
  <nav class="navbar navbar-inverse bg-inverse">
    <div class="container-fluid">
        <div class="navbar-header">
                <a href="/" class="navbar-brand">BookA</a>           
        </div>
        <ul class="nav navbar-nav hidden-sm hidden-xs">
            
                <li><a href="books/search">Пошук</a></li>
                <li><a href="/books/create">Добавити</a></li>
                <li><a href="/books?page=1">Книги</a></li>
        </ul>
            <ul class="nav navbar-nav navbar-right">
                <li class="dropdown">
                    <a href="#" class="dropdown-toggle profile-image" data-toggle="dropdown" aria-expanded="false">
                        <span></span>
                        <b class="caret"></b>
                    </a>
                    <ul class="dropdown-menu">
                        <li><a href="/api">Api</a></li>
                        <li><a href="search" class="visible-sm visible-xs">Search </a><li>
                        <li><a href="create" class="visible-sm visible-xs">Add </a><li>
                        <li><a href="/books?page=1" class="visible-sm visible-xs">Books </a><li>
                        <li><a href="/profile"><i class="fa fa-cog"></i>Profile</a></li>
                        <li class="divider"></li>
                        <li><a href="/logout"><i class="fa fa-sign-out"></i>Logout</a></li>
                    </ul>
                </li>
            </ul>
            
            <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                <form class="navbar-form navbar-left">
                    <div class="form-group">
                        <input type="text" v-model="search" @input="searchReq"  placeholder="Введіть назву книжки">    
                       
                            
                    </div> 
                </form>
            </div>
     
    </div>   
</nav>
</div>
</template>

<script>
import _ from 'lodash'
export default {
  data () {
    return {
      search: ''
    }
  },
  watch: {

  },
  methods: {
    searchReq(event){
      this.search = event.target.value;
      this.$emit('newSearchreq', this.search);
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>


</style>
