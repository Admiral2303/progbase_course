<template>
<div>
<div class="modal fade" id="myModal3" tabindex="-1" role="dialog">
    <div class="modal-dialog">
        <div class="modal-content">
            <!-- Заголовок модального окна -->
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal">×</button>
                <h4 class="modal-title" id="myModalLabel">Обновити інформацію</h4>
            </div>
            <!-- Основная часть модального окна, содержащая форму для регистрации -->
            <div class="modal-body">
                <form>
                    <div class="form-group ">
                        <label for="name" class="control-label">Назва кижки</label>
                        <input type="text" v-model="book.name" class="form-control"  id="name" name="name" required pattern="^[А-Яа-яa-zA-Z\s]+$"  placeholder="Назва кижки"  >
                    </div>
                    <div class="form-group">
                        <label for="authorname">Ім'я автора</label>
                        <input class="form-control" v-model="book.authorname" data-error="Введіть прізвище" id="authorname" name="authorname" v-validate="'required|alpha','regex:^[А-Яа-яa-zA-Z\s]+$'" data-vv-delay="500" :class="{'input': true, 'is-danger': errors.has('authorname') }"  type="text" placeholder="Ім'я автора" required/>
                        <i v-show="errors.has('authorname')" class="fa fa-warning"></i>
                        <span v-show="errors.has('authorname')" class="help is-danger" style="color:red;">Введіть коректне ім'я</span>   
                    </div>
                    <div class="form-group">
                        <label for="authorSurname">Прізвище автора</label>
                        <input class="form-control" v-model="book.authorSurname" data-error="Введіть прізвище" id="authorSurname" name="authorSurname" v-validate="'required|alpha','regex:^[А-Яа-яa-zA-Z\s]+$'" data-vv-delay="500" :class="{'input': true, 'is-danger': errors.has('authorname') }"  type="text" placeholder="Прізвище автора" required/>
                        <i v-show="errors.has('authorname')" class="fa fa-warning"></i>
                        <span v-show="errors.has('authorSurname')" class="help is-danger" style="color:red;">Введіть коректне прізвище</span>   
                   
                    </div>
                    <div class="form-group">
                        <select  v-model="book.language" class="form-control" id="language" name="language"> 
                           <option selected="selected">
                            </option>
                            <option value="Англійська">Англійська</option>
                            <option value="Українська">Українська</option>
                            <option value="Російська">Російська</option>
                            <option value="Китайська">Китайська</option>
                        </select>
                            
                    </div>
                    <div class="form-group"> 
                        <label for="year">Рік видання</label>
                        <input v-model="book.year"
                            v-validate="'required|numeric'" :class="{'input': true, 'is-danger': errors.has('year') }"
                            type="number" class="form-control"
                            min=1800
                            max=2017
                            id="year"
                            name="year"
                            required >
                            <span v-show="errors.has('year')" class="help is-danger" style="color:red;">Введіть правильний рік</span>   
 
                    </div>
                   
                    <div class="form-group">
                        <label for="pages">Кількість сторінок</label>
                        <input type="number" v-model="book.pages" class="form-control" min=0 id="pages" name="pages" required >
                    </div>
                    <div class="form-group">
                        <label for="content">Інформація про книгу</label>
                        <textarea id="content" v-model="book.content" name="content" class="form-control" required  rows="5"></textarea>
                    </div>
                </form>
                <div class="form-group">
                    <button class="btn btn-success" @click="updateBook">Обновити </button>
                </div>
                <form>
                    <div class="form-group">
                        <input @change="uploadImage"  type="file" name="image" required accept="image/*">
                    </div>
                </form>
                    <div class="form-group">
                        <button class="btn btn-success" @click="updateImage">Обновити </button>
                    </div>
                  
            </div>
        </div>
    </div>
</div>

</div>

</template>

 
<script>
import {mapState} from 'vuex'
import BookService from '@/services/BookService'
import _ from 'lodash'

export default {
    data() {
       return {
           book: {},
           data: null
       }
    },
    computed: {
        // book() {
        //     return this.$store.getters.book
        // },
        ...mapState([
            'isUserLoggedIn',
            'user',
            'route'
        ])
    },
    async mounted(){
       let response = (await BookService.getById(this.route.params.bookId));
       this.book = response.data.book;
    },
    methods:{
       async updateBook(){
           console.log(this.book);
           await BookService.updateBook(this.book);
           console.log(this.book.content);
           let response = (await BookService.getById(this.route.params.bookId));
           this.$store.dispatch('setBook', response.data.book);
       },
        uploadImage: function(e) {
            console.log("---");
            let files = e.target.files;
            if(!files[0]) {
                return;
            }
            let data = new FormData();
            data.append('image', files[0]);
            data.append('book_id', this.route.params.bookId);
            this.data = data;
        },
        async updateImage(){
            await BookService.updateBookAva(this.data);
            let response = (await BookService.getById(this.route.params.bookId));
           this.$store.dispatch('setBook', response.data.book);
        }
    }



};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

</style>
