<template>
<div class="main">
    <update-book> </update-book>
    <send-message/>
    <div id="content" class="col-md-12 product_page">
        <div class="row product-content-columns">
            <div class="col-md-5 col-md-offset-1 product_page-left">
                <img :src="book.image" alt="img" class="img">
            </div>
            <div class="col-md-5 product_page-right">
                <div class="general_info product-info">
                    <h1 class="product-title">
                        {{book.name}}
                    </h1>
                    <div class="rating-section product-rating-status">
                        <div class="rating">
                        </div>
                    </div>
                    <div class="product-description">
                        <span>Автор: {{book.authorname}} {{book.authorSurname}}  </span><br>
                        <span>Рік: {{book.year}}</span><br>
                        <span>Мова: {{book.language}}</span><br>
                        <span>Кількість сторінок: {{book.pages}}</span><br> <br>
                    </div>
                    
                    <div v-if="(book.user_id == this.user._id || this.user.role == 'admin') && book.rentflag != 'true'">
                        <a href="#" data-toggle="modal" data-target="#delbook"> <button class="btn btn-danger" type="submit">Видалити</button></a>
                        <div class="modal fade" id="delbook" tabindex="-1" role="dialog">
                            <div class="modal-dialog">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <button type="button" class="close" data-dismiss="modal">×</button>
                                        <h4 class="modal-title" id="myModalLabel">Ви точно бажаєте видалити книгу</h4>
                                    </div>
                                    <div class="modal-body">
                                        <div class="modal-footer">
                                            <button type="button" class="btn btn-default" data-dismiss="modal">Отмена</button>
                                            <button @click="deleteBook" class="btn btn-danger" data-dismiss="modal" >Видалити </button>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div> 
                        <a href="#" data-toggle="modal" data-target="#myModal3"> <button class="btn btn-primary" type="submit">Обновити інформацію</button></a>
                    </div>
                    <div v-else-if="book.payflag != 'true'">
                        <a href="#" data-toggle="modal" data-target="#retbook"> <button class="btn btn-danger" type="submit">Видалити книгу з оренди</button></a>
                        <div class="modal fade" id="retbook" tabindex="-1" role="dialog">
                            <div class="modal-dialog">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <button type="button" class="close" data-dismiss="modal">×</button>
                                        <h4 class="modal-title" id="myModalLabel">Ви точно бажаєте видалити книгу з оренди</h4>
                                    </div>
                                    <div class="modal-body">
                                        <div class="modal-footer">
                                            <button type="button" class="btn btn-default" data-dismiss="modal">Отмена</button>
                                            <button @click="retbooktorent" class="btn btn-danger" data-dismiss="modal" >Повернути </button>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div> 
                    </div>
                    
                </div>
                <div>
                    <p> АВТОР: </p>
                    <a :href="'/#/profile/' + postcreator._id"><img :src="postcreator.image" alt="img" class="img1"></a>
                    <span>{{postcreator.name}}</span>
                    <a href="#" data-toggle="modal" data-target="#myModal2"> <button class="btn btn-success" type="submit">Написати автору</button></a> 
                    <div v-if="bookmark == false">
                            <div class="bookmark">
                                Добавити в закладки:
                                <a href="#" type="submit" @click="BookmarkAdd">
                                    <span class="glyphicon glyphicon-star-empty"></span>
                                </a>
                            </div>
                            
                    </div>
                    <div v-else>
                        <form v-on:submit.prevent="BookmarkDelete">
                            <div class="bookmark">
                                Видалити з закладок:
                                <a href="#" type="submit" @click="BookmarkDelete">
                                    <span class="glyphicon glyphicon-star"></span>
                                </a>
                            </div>
                        </form>
                    </div>
                    <div v-if="book.user_id != user._id">
                        <form v-on:submit.prevent="takeToRent">    
                            <button class="btn btn-success" type="submit">  Взяти в оренду</button>
                        </form>
                    </div>
                            </div>
                        </div>
                    </div>
                    <h3 class="product-section_title">Опис книги</h3>
                    <p class="content">
                        {{book.content}}
                    </p>
                </div>  
            </div>
        </div>
    </div>  


      
</div>

</template>

 
<script>
import {mapState} from 'vuex'
import BookService from '@/services/BookService'
import UpdateBook from './UpdateBook'
import SendMessage from './SendMessage'
import UserService from '@/services/UserService'

export default {
  //  props: ["postcreator"],
    data(){
        return {
            postcreator: {},
            bookmark: null,
        //    coment_users: null
        }
    },
    computed: {
        book() {
            return this.$store.getters.book
        },
        ...mapState([
            'isUserLoggedIn',
            'user',
            'route'
        ])
    },
    components: {
        UpdateBook,
        SendMessage
    },
    async mounted(){
         let response = (await BookService.getById(this.route.params.bookId));
         //console.log(this.postcreator);
         this.postcreator =  response.data.postcreator;
         this.bookmark = response.data.bookmark;
         console.log(this.book.user_id );
         console.log(this.postcreator._id);

    },
   
    methods:{
        async deleteBook(){  
            await BookService.deleteBook(this.book._id);
            this.$router.push({
                name: 'BooksPage'
            })
        },
        async BookmarkAdd(){
            await UserService.addBookmarktoUser(this.book._id);
            let userAfterUpdate = await UserService.user(this.user._id);
            this.$store.dispatch('setUser', userAfterUpdate.data.user);
            let response = (await BookService.getById(this.route.params.bookId));
            this.bookmark = response.data.bookmark;
           // this.bookmark = false;
        },
        async BookmarkDelete(){
            await UserService.deleteUserBookmark(this.book._id);
            let userAfterUpdate = await UserService.user(this.user._id);
            this.$store.dispatch('setUser', userAfterUpdate.data.user);
            let response = (await BookService.getById(this.route.params.bookId));
            this.bookmark = response.data.bookmark;
            // this.bookmark = true;
        },
        async takeToRent(){
            let data ={
                book_id: this.book._id,
                rentuser_id: this.user._id,
                book_owner_id: this.book.user_id
                
            }
            await UserService.rentBook(data);
            this.$router.push({
                    name: 'Rentbooks'
            });
        },
        async retbooktorent(){
            let booktodel = {
                book_id: this.book._id,
                user_id: this.user._id
            }
            console.log(booktodel);
            try{
                await BookService.returnBooktoRent(booktodel);
            } catch(err){
                console.log(err);
            }
            this.$router.push({
                name: 'MybooksPage'
            });
        }
    }



};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.glyphicon-star-empty{
    color: orange;
    font-size: 40px;
}
.glyphicon-star{
    margin-top: 1%;
    color: orange;
    font-size: 40px;
}

img {
  max-width: 100%; }

.content{
    
    word-wrap: break-word;
	overflow-wrap: break-word;
	
	width: 80%;
}
.product-section_title{
    margin-left: 30%;
}

.product-title, .price, .sizes, .colors {
  text-shadow: 0.25cm 0.25cm 0.25cm gainsboro;
  text-transform: UPPERCASE;
  font-weight: bold; }

.product-description{
    font-family: 'Century Schoolbook L', bold;font-size: 20px;font-weight: 580
}

.main {
    font: 300 15px/23px "Roboto Slab", sans-serif;
    color: #2D2B2B;
    margin-left: 15%;
}

h1 {
    font: 300 15px/23px "Roboto Slab", sans-serif;
    font-family: inherit;
    font-weight: 500;
    line-height: 1.1;
    color: inherit;
    font-size: 33px;
    line-height: normal;
}

.line {
    color: black;
}

.img {
    height: 70%;
    width:70%;
    max-height: 450px;
    max-width: 450px;
    border-radius: 25px;
}

.img1{
    max-height: 50px;
    max-width: 50px;
    border-radius: 50%;
}

    
</style>
