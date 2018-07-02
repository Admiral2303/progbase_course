<template>
<div>  
    <page-header/> 
    
    <h1 class="text-center"> Взяти книжку в оренду </h1>
    <div class="container-fluid">
        <div v-for="book in books" :key="book.book._id">  
            <div class="row book-to-rent"> 
                <div class="col-md-2 col-xs-12">
                <a :href="'/#/books/'+ book.book._id">
                        <img :src="book.book.image" alt="img" class="img">
                    </a>      
                </div>
                <div class="col-md-2 text-center book-info" >
                    <h2 class="book-name">{{book.book.name}} </h2>
                    <h3 class="book-info" >
                        Автор - {{book.book.authorname }} {{ book.book.authorSurname }}<br> 
                        Год выпуска - {{ book.book.year }}<br> 
                    </h3>
                </div> 
                <div class="col-md-8">  
                    <div class="row">
                        <div class="col-md-5"> 
                            <div class="col-md-2  text-center boook-price">
                                <h4>Вартість</h4>
                                <b >{{book.book.price}}₴ </b>
                            </div>
                            <div v-if="book.book.payflag != 'true'">
                                <div class="col-md-6 text-center select-month">
                                    <h4>К-сть місяців</h4>
                                    <select @change="changePay(book.book.price, book.book._id)" v-model="month">
                                        <option selected="selected">1</option>
                                        <option>2</option>
                                        <option>3</option>
                                        <option>4</option>
                                        <option>5</option>
                                        <option>6</option>
                                        <option>7</option>
                                        <option>8</option>
                                        <option>9</option>
                                        <option>10</option>
                                        <option>11</option>
                                        <option>12</option>
                                      </select>
                                </div>
                                <div class="col-md-2 text-center boook-price">
                                    <h4>Ціна</h4>
                                    <h4>{{book.book.totalprice}} </h4>
                                </div>
                            </div> 
                            <div v-else>
                                <div class="col-md-7 col-md-offset-2 datereturn">
                                    <div class="row">
                                        <h4>Дата повернення</h4>
                                    </div>
                                    <div class="row">
                                        <h4>{{book.payment.datetoreturn}}</h4>
                                    </div>
                                </div>
                            </div> 
                        </div>
                        <div class="col-md-3 pay">
                            <div v-if="book.book.payflag == 'true'">
                                <h4> Статус оплати</h4>
                                <h4 style="color: green;">Cплачено</h4>
                            </div>
                            <div v-else>
                                <h4 > Статус оплати</h4>
                                <h4 style="color: red;">Очікується оплата</h4>
                            </div>
                        </div>    
                        <div v-if="book.book.payflag == 'false' && book.book.totalprice"> 
                            <div class="col-md-2 take-torent">
                                <form id=pay name=pay method="POST" action="https://merchant.webmoney.ru/lmi/payment.asp"> 
                                    <input type="hidden" name="LMI_PAYMENT_AMOUNT" v-bind:value="book.book.totalprice">
                                    <input type="hidden" name="LMI_PAYMENT_DESC" value="тестовый платеж">
                                    <input type="hidden" name="LMI_PAYMENT_NO" value="1">
                                    <input type="hidden" name="LMI_PAYEE_PURSE" value="U242456229571">
                                    <input type="hidden" name="LMI_SIM_MODE" value="0"> 
                                    <input type="hidden" name="user_id" v-bind:value="user._id">
                                    <input type="hidden" name="book_id" v-bind:value="book.book._id">
                                    <input type="hidden" name="book_creator_id" v-bind:value="book.book.user_id">
                                    <input type="hidden" name="date_to_return" v-bind:value="date_to_return">
                                    </p> 
                                    <p>
                                    <input class="btn btn-success" type="submit" value="Оплатити">
                                    </p> 
                                </form>       
                            </div> 
                        </div> 
                        <div v-if="book.book.payflag != 'true'">
                            <div class="col-md-2 del-torent">

                                <a href="#" data-toggle="modal" data-target="#deletebook"> <button class="btn btn-danger" type="submit">Видалити</button></a>
                                <div class="modal fade" id="deletebook" tabindex="-1" role="dialog">
                                    <div class="modal-dialog">
                                        <div class="modal-content">
                                            <div class="modal-header">
                                                <button type="button" class="close" data-dismiss="modal">×</button>
                                                <h4 class="modal-title" id="myModalLabel">Ви точно бажаєте видалити книгу з оренди</h4>
                                            </div>
                                            <div class="modal-body">
                                                <div class="modal-footer">
                                                    <button type="button" class="btn btn-default" data-dismiss="modal">Отмена</button>
                                                    <button @click="delbookrent(book.book._id, book.book.user_id)" data-dismiss="modal" class="btn btn-success ">Видалити</button>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div> 
                           
                           
                            </div>
                        </div>
                        <div v-if="book.book.payflag == 'true' && book.payment.sendflag == 'true' && book.payment.takeflag != 'true'  ">
                            <div class="col-md-4 text-center takebook">
                                
                                <a href="#" data-toggle="modal" data-target="#takebook"> <button class="btn btn-success" type="submit">Підтвердити отримання</button></a>
                                <div class="modal fade" id="takebook" tabindex="-1" role="dialog">
                                    <div class="modal-dialog">
                                        <div class="modal-content">
                                            <div class="modal-header">
                                                <button type="button" class="close" data-dismiss="modal">×</button>
                                                <h4 class="modal-title" id="myModalLabel">Ви точно бажаєте видалити книгу з оренди</h4>
                                            </div>
                                            <div class="modal-body">
                                                <div class="modal-footer">
                                                    <button type="button" class="btn btn-default" data-dismiss="modal">Отмена</button>
                                                    <button @click="takeBooksuccess(book.book._id)" data-dismiss="modal" class="btn btn-success ">Підтвердити</button>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div> 
                           
                            </div>   
                        </div> 
                    </div>
                    <div class="row ">
                        <hr/>
                        <div class="container-fluid">
                            <div v-if="book.book.payflag == 'true'">
                                <div class="col-md-3 text-center">
                                    <h4>Вкажіть вашу адресу</h4>
                                </div>  
                                <div class="col-md-3">
                                    <input v-model="book.payment.adress"  type="text" >
                                </div>  
                                <div class="col-md-1">
                                    <button @click="sendadress(book.book._id, book.payment.adress)" class="btn btn-success del-button">ОК</button>
                                </div> 
                            </div>  
                        </div>  
                    </div>
                </div>
            </div>    
        </div>
    </div>

   




</div>

</template>



<script>
import BookService from '@/services/BookService'
import PaymentService from '@/services/PaymentService'
import {mapState} from 'vuex'
import PageHeader from '../Header'
export default {
    data () {
        return {
            books: null,
            month: '',
            totalprice: "",
            date_to_return: ""
            //pages: null,
            //search: null
        }
    },
    async mounted(){
        let response = (await BookService.getrentbooks(this.user._id));
        this.books = response.data.books;
        for(let b of this.books){
            console.log(b.payment);
            
        }
        let date = new Date();
        if(this.month + date.getMonth() > 12){
            console.log("----")
        }
        console.log(response);
    },
    computed: {
        ...mapState([
            'isUserLoggedIn',
            'user',
            'route'
        ])
    },
    components:{
        PageHeader
    },
    methods:{
        async delbookrent(book_id, owner_id){
            let booktodel = {
                book_id: book_id,
                user_id: this.user._id,
                owner_id: owner_id
            }
            try{
                await BookService.deleteRentBook(booktodel);
                await BookService.deleteBookInRent(booktodel);
            } catch(err){
                console.log(err);
            }
            let response = (await BookService.getrentbooks(this.user._id));
            if(response.data.books.length != 0){
                console.log(response.data.books)
                this.books = response.data.books;
            } else{
                this.$router.push({
                    name: 'BooksPage'
                });
            }
        },
        changePay(price, id){
            for(let book of this.books){
                if(book.book._id == id){
                    let Price = price * this.month;
                    book.book.totalprice = Price.toString();
                   // console.log(book.book.totalprice)
                } else{
                    book.book.totalprice = "";
                }
            }
              for(let book of this.books){
               
                   console.log(book.book.totalprice)
              
            }
            
            let date = new Date();
            let month = parseInt(this.month);
            let monthnow =  parseInt(date.getMonth());
            let rentmonth = month + monthnow;
            if(rentmonth > 12){
                date.setYear(date.getYear() + 1901);
                let months = rentmonth - 12;
                date.setMonth(months);
            } else{
                date.setMonth(rentmonth);
            }
            this.date_to_return = date.toISOString();
        },
        async sendadress(id, adress){
            let data = {
                book: id,
                adress: adress
            }
            await PaymentService.sendadress(data);
            let response = (await BookService.getrentbooks(this.user._id));
            this.books = response.data.books;
        },
        async takeBooksuccess(id){
            await PaymentService.takebook({id: id});
            let response = (await BookService.getrentbooks(this.user._id));
            this.books = response.data.books;
        }
    }


};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style>
.book-info{
    font-family: 'Oswald', sans-serif;
    font-weight: normal;
    text-transform: uppercase;
    margin-top: 5%;
}

.take-torent{
    margin-top: 8%;
}
.del-button{
    margin-left: 15%;
}

.select-month{
    margin-left:5%;
    margin-top: 15.5%;
}
.del-torent{
    margin-top: 9.2%;
}

.pay{
    margin-top: 6%;
}

.takebook{
    margin-top:8%;
}

.boook-price{
    padding: 12px 15px 8px;
    font-family: 'Roboto Condensed','Segoe UI',Tahoma,Arial,sans-serif;
    font-size: 17px;
    margin-top: 12%;
    
}
.datereturn{
    margin-top: 15.2%;
}

.book-to-rent{
     border: 4px double gray;
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
    width: 220px;
    height: 250px;
    border-radius: 30px;
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
    border-bottom: 1px dotted #a9a9a9;
    border-top: 1px dotted #a9a9a9;
    background: #f8f8f8;
    text-shadow: 1px 1px 0 #fdfdfd, 2px 2px 0 rgba(81, 81, 81, 0.5), 0 0 1px #fdfdfd;
    font-family: "Oswald", sans-serif;
    font-weight: normal;
    text-transform: uppercase;
}

hr {
    width: 100%;
    color: grey;
    height: 1px;
    background-color:grey;}
    
</style>
