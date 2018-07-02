<template>

<div>
 
<div class="col-md-3  hidden-xs">
    <div class="sidebar-nav-fixed affix">
        <div class="well">
            <ul class="nav">
                <li class="nav-header">
                    <form class="line">
                        <div class="form-group">
                            <label for="name" class="control-label">Назва кижки</label>
                            <input type="text" v-model="book.name" class="form-control"  id="name" name="name"  pattern="^[А-Яа-яa-zA-Z\s]+$"  placeholder="Назва кижки" >
                        </div>
                        <div class="form-group">
                            <label for="authorname">Ім'я автора</label>
                            <input type="text"  v-model="book.authorname" class="form-control"  id="authorname" name="authorname"  pattern="^[А-Яа-яa-zA-Z\s]+$" placeholder="Ім'я автора">
                        </div>
                        <div class="form-group">
                            <label for="authorSurname">Прізвище автора</label>
                            <input type="text" v-model="book.authorSurname" class="form-control"  id="authorSurname" name="authorSurname"  pattern="^[А-Яа-яa-zA-Z\s]+$" placeholder="Прізвище автора">
                        </div>        
                        <div class="form-group">
                            <label for="language">Виберіть мову</label>
                            <select v-model="book.language" class="form-control" id="language" name="language">
                                <option value=""></option> 
                                <option value="Англійська">Англійська</option>
                                <option value="Українська">Українська</option>
                                <option value="Російська">Російська</option>
                                <option value="Китайська">Китайська</option>
                            </select>        
                        </div>
                    </form> 
                    <div class="col-md-3 col-md-offset-3">
                        <div class="form-group">
                            <button @click="formSubmit" class="btn btn-warning" >Шукати </button>
                        </div>
                    </div>
               
                </li> 
            </ul>
        </div>
    </div>
</div>
<div class="col-xs-12 visible-xs">
    <form class="line">
        <div class="form-group">
            <label for="name" class="control-label">Назва кижки</label>
            <input type="text" v-model="book.name" class="form-control"  id="name" name="name" required pattern="^[А-Яа-яa-zA-Z\s]+$"  placeholder="Назва кижки" >
        </div>
        <div class="form-group">
            <label for="authorname">Ім'я автора</label>
            <input type="text" v-model="book.authorname" class="form-control"  id="authorname" name="authorname" required pattern="^[А-Яа-яa-zA-Z\s]+$" placeholder="Ім'я автора">
        </div>
        <div class="form-group">
            <label for="authorSurname">Прізвище автора</label>
            <input type="text" v-model="book.authorSurname" class="form-control"  id="authorSurname" name="authorSurname" required pattern="^[А-Яа-яa-zA-Z\s]+$" placeholder="Прізвище автора">
        </div>        
        
        <div class="form-group">
            <label for="year">Рік видання</label>
            <input v-model="book.year" type="number" class="form-control"  id="year" name="year" required >
        </div>
        <div class="form-group">
            <select  class="form-control" v-model="book.language" id="language" name="language"> 
                <option value="" disabled="" selected="">Виберіть мову</option>
                <option value="Англійська">Англійська</option>
                <option value="Українська">Українська</option>
                <option value="Російська">Російська</option>
                <option value="Китайська">Китайська</option>
            </select>        
        </div>
    </form> 
</div>






</div>
</template>

<script>
import BookService from '@/services/BookService'
export default {
  components: { 
  },
  data () {
    return {
        book: {
            name: null,
            authorname: null,
            authorSurname: null, 
            year: null,
            language: null,
        }
     
    }
  },
  methods: {
      async formSubmit(){
          if((this.book.name == null || this.book.name == '') && 
          (this.book.authorname == null || this.book.authorname == '') &&
          (this.book.authorSurname == null || this.book.authorSurname == '')&&
          
          (this.book.language == null || this.book.language == '')){
              if(this.$store.getters.mybooksflag == false && this.$store.getters.bookmarksflag == false){
                this.$store.dispatch('setSearchFlag', false);
                let response = (await BookService.index(1));
                this.$store.dispatch('setBooks', response.data.books);
                this.$store.dispatch('setPages', response.data.pages);
                this.$store.dispatch('setSearch', {});
              } else if(this.$store.getters.mybooksflag == true && this.$store.getters.bookmarksflag == false){
                    this.$store.dispatch('setSearchFlag', false);
                    let response = (await BookService.getuserbooks(1));
                    this.$store.dispatch('setBooks', response.data.books);
                    this.$store.dispatch('setPages', response.data.pages)
                    this.$store.dispatch('setSearch', {});
              } else if(this.$store.getters.mybooksflag == false && this.$store.getters.bookmarksflag == true){
                    this.$store.dispatch('setSearchFlag', false);
                    let response = (await BookService.getuserbookmarks(1));
                    this.$store.dispatch('setBooks', response.data.books);
                    this.$store.dispatch('setPages', response.data.pages)
                    this.$store.dispatch('setSearch', {});
              }
              
          }else{
              if(this.$store.getters.mybooksflag == false && this.$store.getters.bookmarksflag == false){
                  this.$store.dispatch('setSearchFlag', true);
                  this.$store.dispatch('setSearch', this.book);
                  let response = await BookService.search(this.book, "1");
                  this.$store.dispatch('setBooks', response.data.books);
                  this.$store.dispatch('setPages', response.data.pages)
                  this.book = {};  
              } else if(this.$store.getters.mybooksflag == true && this.$store.getters.bookmarksflag == false){
                  this.$store.dispatch('setSearchFlag', true);
                  this.$store.dispatch('setSearch', this.book);
                  let response = await BookService.mybookssearch(this.book, "1");
                  this.$store.dispatch('setBooks', response.data.books);
                  this.$store.dispatch('setPages', response.data.pages)
                  this.book = {};  
              } else if(this.$store.getters.mybooksflag == false && this.$store.getters.bookmarksflag == true){
                  this.$store.dispatch('setSearchFlag', true);
                  this.$store.dispatch('setSearch', this.book);
                  let response = await BookService.bookmarkssearch(this.book, "1");
                  this.$store.dispatch('setBooks', response.data.books);
                  this.$store.dispatch('setPages', response.data.pages)
                  this.book = {};  
              }
          }

      }
  }

}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>


</style>
