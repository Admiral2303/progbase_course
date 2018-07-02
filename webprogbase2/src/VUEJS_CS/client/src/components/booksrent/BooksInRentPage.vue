<template>
<div>  
    <page-header/> 
    
    <h1 class="text-center"> Книги в оренді </h1>
    <select v-model="option" @change="optionchange"> 
        <option>Книги за які отримали гроші</option>
        <option>Книги платежі, яких опрацьовуються адміністратором</option>
        <option>Всі книги</option>
    </select>
    <div class="row">
        <div class="col-md-3">
            <h4>Введіть Webmoney гаманець</h4>
        </div>
        <div class="col-md-2">
            <input v-model="wallet" type="text">
        </div>
        <div class="col-md-1">
            <button @click="sendWallet" class="btn btn-success">ОК</button>
        </div>
    </div>
    <div v-for="book in sortbooks" :key="book._id">  
        <div v-if="book.payment.status == 'true'" class="takemoney">
             <book-in-rent @sendbook="sendBook" @returnbook="returnBook" :book="book"> </book-in-rent>
        </div>
        <div v-else-if="book.payment.returnflag == 'true' && book.payment.sendflag == 'true' && book.payment.takeflag == 'true' && book.payment.status != 'true'" class="paybook">
            <book-in-rent @sendbook="sendBook" @returnbook="returnBook" :book="book"> </book-in-rent>
        </div>
        <div v-else>
            <book-in-rent @sendbook="sendBook" @returnbook="returnBook" :book="book"> </book-in-rent>
        </div>
    </div>
</div>

</template>



<script>
import BookService from '@/services/BookService'
import PaymentService from '@/services/PaymentService'
import {mapState} from 'vuex'
import PageHeader from '../Header'
import BookInRent from './BookInRent'
import UserService from '@/services/UserService'
export default {
    
    data () {
        return {
            books: null,
            sortbooks: null,
            option: null,
            wallet: null
        }
    },
    async mounted(){
        let response = (await BookService.getbooksinrent(this.user._id));
        if(!response.data.error){
             this.books = response.data.books; 
             this.sortbooks = response.data.books;
        } else{
            this.$store.dispatch('setError', response.data.error);
            this.$store.dispatch('setErrorCode', response.data.errorcode);
             this.$router.push({
                    name: 'ErrorPage'
            });
        }
        this.wallet = this.user.wallet;
        
      
    },
    computed: {
        ...mapState([
            'isUserLoggedIn',
            'user',
            'route'
        ])
    },
    components:{
        PageHeader,
        BookInRent
    },
    methods:{
       async sendbook(id){
            await PaymentService.sendbook({id: id});
            let response = (await BookService.getbooksinrent(this.user._id));
            this.books = response.data.books; 
            
       },
       async returnbook(id){
            await PaymentService.returnbook({id: id});
            let response = (await BookService.getbooksinrent(this.user._id));
            this.books = response.data.books; 
       },
       async sendBook(){
            let response = (await BookService.getbooksinrent(this.user._id));
            if(!response.data.error){
                this.books = response.data.books; 
            } else{
                this.$store.dispatch('setError', response.data.error);
                this.$store.dispatch('setErrorCode', response.data.errorcode);
                this.$router.push({
                        name: 'ErrorPage'
                });
            }
       },
       async returnBook(){
            let response = (await BookService.getbooksinrent(this.user._id));
            if(!response.data.error){
                this.books = response.data.books; 
            } else{
                this.$store.dispatch('setError', response.data.error);
                this.$store.dispatch('setErrorCode', response.data.errorcode);
                this.$router.push({
                        name: 'ErrorPage'
                });
            }
        },
        optionchange(){
            if(this.option == 'Книги за які отримали гроші'){
                let sortBooks =[];
                for(let b of this.books){
                    if(b.payment.status == 'true'){
                        sortBooks.push(b);
                    }
                }
                this.sortbooks = sortBooks;
                console.log("------------")  
           } else if(this.option =='Книги платежі, яких опрацьовуються адміністратором'){
                let sortBooks =[];
                for(let book of this.books){
                   if(book.payment.returnflag == 'true' && book.payment.sendflag == 'true' && book.payment.takeflag == 'true' && book.payment.status != 'true' ){
                       sortBooks.push(book);
                   }
               }
               this.sortbooks = sortBooks;
           }  else{
              this.sortbooks = this.books; 
           }
       },
       async sendWallet(){
           let data = {
               user_id: this.user._id,
               wallet: this.wallet
           }
           await UserService.setWallet(data);
           let userAfterUpdate = await UserService.user(this.user._id);
            this.$store.dispatch('setUser', userAfterUpdate.data.user);
       }

    }


};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.book-info{
    font-family: 'Oswald', sans-serif;
    font-weight: normal;
    text-transform: uppercase;
    margin-top: 1%;
}

.takemoney{
    background-color: seagreen;
}

.totalprice{
    margin-top: 2%;
}

.pay{
    margin-top: 2%;
}

.butsuccess{
    margin-top: 2%;
}
.paybook{
    background-color: yellowgreen;
}

.final{
    color: green;
}


.form-control {
    border-radius: 25px;
}



.line {
    border-right: 2px solid #6D6969;
    /* Параметры линии */
    margin-right: 20px;
    /* Отступ слева */
    padding-right: 10px;
    /* Расстояние от линии до текста */
}

.img {
    margin-top:30%;
    width: 120px;
    height: 110px;
    border-radius: 30px;
    
}

.userimg{
    margin-top:50%;
    width: 80px;
    height: 80px;
    border-radius: 30px;
}

.linel { 
    border-left: 2px solid black; /* Параметры линии */ 
    margin-left: 20px; /* Отступ слева */
    padding-left: 10px; /* Расстояние от линии до текста */ 
}

.book-info {
    color: black;
    font-family: Helvetica, Arial, Verdana, sans-serif;
    font-style: normal;
    font-size: 17px;
    line-height: 15px;
    font-size-adjust: none;
}

.book-name {
    border-takemoneybottom: 1px dotted #a9a9a9;
    border-top: 1px dotted #a9a9a9;
    background: #f8f8f8;
    text-shadow: 1px 1px 0 #fdfdfd, 2px 2px 0 rgba(81, 81, 81, 0.5), 0 0 1px #fdfdfd;
    font-family: "Oswald", sans-serif;
    font-weight: normal;
    text-transform: uppercase;
}
.book-to-rent{
     border: 4px double gray;
}
    
</style>
