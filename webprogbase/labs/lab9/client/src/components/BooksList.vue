<template>

<div >
    <page-header @newSearchreq="searchreq"> </page-header>
   
   
    <create-book  @newBookAdd="hello"> </create-book> 
  
  <pagination @changePage="goToPage" :booksPages="bpages"> </pagination>
    <div class="col-md-8">
    <div v-for="book in books" :key="book._id">
        <div class="container">  
            <div class="raw">     
                <div class="col-md-1"></div>
                    <div class="col-md-2">
                        <img  :src="book.image" style=" width: 220px; height: 250px; border-radius: 30px;" />
                    </div>
                    <div class="col-md-4 ">
                        <h1 style="color: #110E0E;font-family: 'Century Schoolbook L', bold;font-size: 40px;font-weight: 600">
                        {{book.name}}
                        </h1>
                        <h3 style="font-family: 'Century Schoolbook L', bold;font-size: 20px;font-weight: 600;border: 2px solid #333;border: 2px solid #333; padding-left:10%;">
                            Автор - {{book.authorname}} {{book.authorSurname}}<br> 
                            Язык издания - {{book.language}}<br>
                            Количество страниц - {{book.pages}}<br>
                            Год выпуска - {{book.year}}<br>
                            Дата добавления - {{book.date}}<br>
                        </h3>
                    </div>
                </div>   
            </div>  
        </div>   
    </div>
    
   
</div>
</template>

<script>
import BookService from '@/services/BookService'
import CreateBook from './CreateBook.vue'
import PageHeader from './Header.vue'
import Pagination from './Pagination.vue'

export default {
 
    data () {
        return {
        books: null,
        bpages: null,
        search: null
        }
    },
    methods:{
        hello(value){
            console.log(value.data);
            this.books.push(value.data);
        },
        async searchreq(value){
            
            this.search = value;

            let searchbooks = (await BookService.search(value)).data;
            this.books = searchbooks.books;
            this.bpages = searchbooks.pages;
            //console.log(b);
        },
        async goToPage(value){
            console.log(this.search);
            console.log(value);
            if(this.search != null || this.search != ""){
                let searchbooks = (await BookService.searchPage(this.search, value)).data;
                this.books = searchbooks.books;
                this.pages = searchbooks.pages; 
            }
            else{
                let searchbooks = (await BookService.getpageBooks(value)).data;
                console.log(searchbooks);
                // console.log(value);
                this.books = searchbooks.books;
                this.pages = searchbooks.pages;  
            }   
        }

    },

    async mounted(){
        let responce = (await BookService.index());
        console.log(responce);
        this.books = responce.data.books;
        this.bpages = responce.data.pages;
    },
        components: {
            CreateBook,
            PageHeader,
            Pagination
        }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style s>


</style>
