<template>


   <div>
            <div class="col-md-2">
                <div class="form-group ">
                    <label for="name" class="control-label">Назва кижки</label>
                    <input v-model="book.name" type="text" class="form-control"  id="name" name="name" required pattern="^[А-Яа-яa-zA-Z\s]+$"   placeholder="Назва кижки" >
                </div>
                <div class="form-group">
                    <label for="authorname">Ім'я автора</label>
                    <input v-model="book.authorname" type="text" class="form-control"  id="authorname" name="authorname" required pattern="^[А-Яа-яa-zA-Z\s]+$" placeholder="Ім'я автора">
                </div>
                <div class="form-group">
                    <label for="authorSurname">Прізвище автора</label>
                    <input  v-model="book.authorSurname" type="text" class="form-control"  id="authorSurname" name="authorSurname" required pattern="^[А-Яа-яa-zA-Z\s]+$" placeholder="Прізвище автора">
                </div>
                
                <div class="form-group" >
                    <select  v-model="book.language"  class="form-control" id="language" name="language" > 
                        <option value="" disabled="" selected="">Виберіть мову</option>
                        <option value="Англійська">Англійська</option>
                        <option value="Українська">Українська</option>
                        <option value="Російська">Російська</option>
                        <option value="Китайська">Китайська</option>
                    </select>     
                </div>
                <div class="form-group">
                    <label for="year">Рік видання</label>
                    <input v-model="book.year" type="number" class="form-control"  id="year" name="year" required >
                </div>
                <div class="form-group">
                    <label for="pages">Кількість сторінок</label>
                    <input v-model="book.pages" type="number" class="form-control" min=0 max=1500 id="pages" name="pages" require>
                </div>
                <div class="form-group">
                    <label for="content">Інформація про книгу</label>
                    <textarea v-model="book.content" id="comment" name="content" class="form-control" required  rows="5"></textarea>
                </div>
                <div class="form-group">
                    <div style="display:flex; flex-direction: column;">
                        <span class="btn btn-default btn-file">
                            Browse <input @change="uploadImage" type="file" name="image" required accept="image/*">
                        </span>
                    </div>
                </div>

                <div class="form-group">
                    <button @click="create"  class="btn btn-primary"> OK </button>
                   
                </div>
                <div class="form-group danger-alert" v-if="error">
                    {{error}}
                </div>
            </div>
           
    

</div>


</template>

<script>
import BookService from '@/services/BookService'
import PictureInput from 'vue-picture-input'

import axios from 'axios'
export default {
    props: ['bookadd'],
    data () {
    return {
        book: {
        name: null,
        authorname: null,
        authorSurname: null,
        year: null,
        pages: null,
        language: null,
        content: null
        },
        data: null,
        error: null,
    }
  },
  components: {
       PictureInput
  },
  methods: {
    changeMessage(event){
        this.message = event.target.value;
        this.$emit('messageChanged', this.message);
    },
    async create(event){
        this.error = null
        const areAllFieldsFilledIn = Object
            .keys(this.book)
            .every(key => !!this.book[key])
        if (!areAllFieldsFilledIn) {
            this.error = 'Please fill in all the required fields.'
            return;
        }
        this.data.append('name', this.book.name);
        this.data.append('authorname', this.book.authorname);
        this.data.append('authorSurname', this.book.authorSurname);
        this.data.append('year', this.book.year);
        this.data.append('pages', this.book.pages);
        this.data.append('language', this.book.language);
        this.data.append('content', this.book.content);
        let newbook = await BookService.post(this.data);
        this.$emit('newBookAdd', newbook);       
    },
    uploadImage: function(e) {
        let files = e.target.files;
        if(!files[0]) {
            return;
        }
        let data = new FormData();
        data.append('image', files[0]);
        this.data = data;
    }
   }
}
</script>


<style scoped>


</style>
