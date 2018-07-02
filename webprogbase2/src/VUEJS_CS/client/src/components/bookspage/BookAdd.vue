<template>
<div>       
<page-header/>
    <div class="container">
        <form  v-on:submit.prevent="formSubmit" class="well form-horizontal" >
            <fieldset>  
                <legend>Добавити книгу</legend>
                <div class="form-group">
                    <label class="col-md-4 control-label">Назва кижки</label>  
                    <div class="col-md-4 inputGroupContainer">
                        <div class="input-group">
                            <span class="input-group-addon"><i class="glyphicon glyphicon-user"></i></span>
                            <input v-model="book.name" type="text"  class="form-control"  id="name" name="name" required pattern="^[А-Яа-яa-zA-Z\s]+$"  placeholder="Назва кижки" >
                        </div>
                    </div>
                </div>
                <div class="form-group">
                    <label class="col-md-4 control-label" >Ім'я автора</label> 
                    <div class="col-md-4 inputGroupContainer">
                        <div class="input-group">
                            <span class="input-group-addon"><i class="glyphicon glyphicon-user"></i></span>
                            <input class="form-control" v-model="book.authorname" data-error="Введіть прізвище" id="authorname" name="authorname" v-validate="'required|alpha','regex:^[А-Яа-яa-zA-Z\s]+$'" data-vv-delay="500" :class="{'input': true, 'is-danger': errors.has('authorname') }"  type="text" placeholder="Ім'я автора" required/>
                            <i v-show="errors.has('authorname')" class="fa fa-warning"></i>
                        </div>
                    </div>
                    <div class="col-md-4">
                        <span v-show="errors.has('authorname')" class="help is-danger" style="color:red;">Введіть коректне ім'я</span>   
                    </div>                        
                </div>
                <div class="form-group">
                    <label class="col-md-4 control-label">Прізвище автора</label>  
                    <div class="col-md-4 inputGroupContainer">
                        <div class="input-group">
                            <span class="input-group-addon"><i class="glyphicon glyphicon-user"></i></span>
                            <input class="form-control" v-model="book.authorSurname" data-error="Введіть прізвище" id="authorSurname" name="authorSurname" v-validate="'required|alpha','regex:^[А-Яа-яa-zA-Z\s]+$'" data-vv-delay="500" :class="{'input': true, 'is-danger': errors.has('authorname') }"  type="text" placeholder="Прізвище автора" required/>
                            <i v-show="errors.has('authorname')" class="fa fa-warning"></i>
                        </div>
                    </div>
                    <div class="col-md-4">
                        <span v-show="errors.has('authorSurname')" class="help is-danger" style="color:red;">Введіть коректне прізвище</span>   
                    </div>  
                </div>
                <div class="form-group"> 
                    <label class="col-md-4 control-label">Мова</label>
                    <div class="col-md-4 selectContainer">
                        <div class="input-group">
                            <span class="input-group-addon"><i class="glyphicon glyphicon-list"></i></span>
                            <select v-model="book.language" class="form-control" id="language" name="language"> 
                            <option value="" disabled="" selected="" required>Виберіть мову</option>
                                <option value="Англійська">Англійська</option>
                                <option value="Українська">Українська</option>
                                <option value="Російська">Російська</option>
                                <option value="Китайська">Китайська</option>
                            </select>
                        </div>
                    </div>
                </div>
                <div class="form-group"> 
                    <label class="col-md-4 control-label">Рік видання</label>
                    <div class="col-md-4 selectContainer">
                        <div class="input-group">
                            <span class="input-group-addon"><i class="glyphicon glyphicon-list"></i></span>
                            <input v-model="book.year"
                            v-validate="'required|numeric'" :class="{'input': true, 'is-danger': errors.has('year') }"
                            type="number" class="form-control"
                            min=1800
                            max=2017
                            id="year"
                            name="year"
                            required >
                        </div>
                    </div>
                    <div class="col-md-4">
                        <span v-show="errors.has('year')" class="help is-danger" style="color:red;">Введіть правильний рік</span>   
                    </div>  
                </div>
                <div class="form-group">
                    <label class="col-md-4 control-label">Кількість сторінок</label>  
                    <div class="col-md-4 inputGroupContainer">
                        <div class="input-group">
                            <span class="input-group-addon"><i class="glyphicon glyphicon-book"></i></span>
                                <input v-model="book.pages" type="number"  class="form-control" min=0 id="pages" name="pages" required>            
                        </div>
                    </div>
                </div>
                <div class="form-group">
                    <label class="col-md-4 control-label">Інформація про книгу</label>
                    <div class="col-md-4 inputGroupContainer">
                        <div class="input-group">
                            <span class="input-group-addon"><i class="glyphicon glyphicon-pencil"></i></span>
                            <textarea v-model="book.content" id="comment"  name="content" class="form-control" required  rows="5"></textarea>
                        </div>
                    </div>
                </div>
                <div class="form-group">
                    <label class="col-md-4 control-label">Ціна оренди за 1 місяць</label>  
                    <div class="col-md-4 inputGroupContainer">
                        <div class="input-group">
                            <span class="input-group-addon"><i class="glyphicon glyphicon-shopping-cart"></i></span>
                            <input v-model="book.price"
                                v-validate="'required|numeric'" :class="{'input': true, 'is-danger': errors.has('year') }"
                                type="number" class="form-control"
                                min=0
                                id="price"
                                name="price"
                                required >
                            
                        </div>                      
                    </div>
                    <div class="col-md-4">
                        <span v-show="errors.has('price')" class="help is-danger" style="color:red;">Введіть коректну ціну</span>   
                    </div>  
                </div>
                <div class="form-group">
                    <label class="col-md-4 control-label">Виберіть картинку</label>
                    <div class="col-md-4 inputGroupContainer">
                        <div class="form-group">
                            <input @change="uploadImage"  type="file" name="image" required accept="image/*">
                        </div>
                    </div>
                </div>
                <div class="form-group">
                    <label class="col-md-4 control-label"></label>
                    <div class="col-md-4">
                        <button type="submit" class="btn btn-warning" >Добавити <span class="glyphicon glyphicon-send"></span></button>
                    </div>
                </div>
            </fieldset>
        </form>
        
    </div>


     

</div>

</template>



<script>
import BookService from '@/services/BookService'
import PageHeader from '../Header'

export default {
    data() {
        return {
            book: {
                name: null,
                authorname: null,
                authorSurname: null,
                year: null,
                pages: null,
                language: null,
                content: null,
                price: null
            },
            data: null,
            error: null   
        }
    },
    components: {
        PageHeader
    },
    methods:{
        async formSubmit(){
            this.data.append('name', this.book.name);
            this.data.append('authorname', this.book.authorname);
            this.data.append('authorSurname', this.book.authorSurname);
            this.data.append('year', this.book.year);
            this.data.append('pages', this.book.pages);
            this.data.append('language', this.book.language);
            this.data.append('content', this.book.content);
            this.data.append('price', this.book.price);
            this.data.append('id', this.$store.state.user._id);
            try{
                await BookService.post(this.data);
                this.$router.push({
                    name: 'BooksPage'
                });
            } catch(err){
                console.log(err);
            }
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
        }

    }

   


};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

    
</style>
