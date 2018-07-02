<template>
<div>  
    
    <div class="container-fluid">
            <div class="row book-to-rent"> 
                <div class="col-md-1 col-xs-12">
                    <a :href="'/#/profile/'+ book.renter._id">
                            <img :src="book.renter.image" alt="img" class="userimg">
                    </a>   
                </div>
                <div class="col-md-1 col-xs-12">
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
                <div class="col-md-1">
                </div>
                <div class="col-md-2 pay ">
                    <div class="row">
                        <h4>Статус оплати</h4>
                    </div>  
                    <div class="row">  
                        <div v-if=" book.book.payflag == 'true'">
                           <h4> Оплачено</h4>
                        </div>
                        <div v-else >
                            <h5 style="color: yelow;">Очікується оплата</h5>
                        </div>
                    </div>
                </div>
                <div class="col-md-2 pay ">
                    <div class="row">
                        <h4>Адреса Доставки</h4>
                        
                    </div>
                    <div class="row">
                        <h4>{{book.payment.adress}}</h4>    
                    </div>        
                </div>
                <div class="col-md-1 totalprice">
                    <div class="row">
                        <h4>Ціна</h4>
                    </div>
                    <div class="row">
                        <h4>{{book.payment.payment_amount}}</h4>
                    </div>
                </div>
                <div class="col-md-1 butsuccess">
                    <div v-if=" book.payment.sendflag != 'true' && book.payment.adress">
                        <h4>Підтвердіть відправку книги</h4>
                        <a href="#" data-toggle="modal" data-target="#sendbook"> <button class="btn btn-success" type="submit">Відправив</button></a>
                        <div class="modal fade" id="sendbook" tabindex="-1" role="dialog">
                            <div class="modal-dialog">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <button type="button" class="close" data-dismiss="modal">×</button>
                                        <h4 class="modal-title" id="myModalLabel">Підтвердіть відправку книги</h4>
                                    </div>
                                    <div class="modal-body">
                                        <div class="modal-footer">
                                            <button type="button" class="btn btn-default" data-dismiss="modal">Отмена</button>
                                            <button @click="sendbook(book.book._id)" data-dismiss="modal" class="btn btn-success ">Відправив</button>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div> 
                    </div>
                    <div v-else-if="book.payment.returnflag != 'true' && book.payment.sendflag == 'true'">
                        <h4>Отримав назад книгу</h4>
                        <a href="#" data-toggle="modal" data-target="#sendbook"> <button class="btn btn-success" type="submit">Отримав</button></a>
                        <div class="modal fade" id="sendbook" tabindex="-1" role="dialog">
                            <div class="modal-dialog">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <button type="button" class="close" data-dismiss="modal">×</button>
                                        <h4 class="modal-title" id="myModalLabel">Підтвердіть те, що ви отримали книгу назад</h4>
                                    </div>
                                    <div class="modal-body">
                                        <div class="modal-footer">
                                            <button type="button" class="btn btn-default" data-dismiss="modal">Отмена</button>
                                            <button @click="returnbook(book.book._id)" data-dismiss="modal" class="btn btn-success ">Отримав</button>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div> 
                    </div>
                    <div v-else-if="book.payment.returnflag == 'true' && book.payment.sendflag == 'true'" class="final">
                        <h4>Обмін завершено</h4>
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
    props: ['book'],
    data () {
        return {
            books: null,
            month: '',
        }
    },
    async mounted(){
        
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
       async sendbook(id){
            await PaymentService.sendbook({id: id});
            let response = (await BookService.getbooksinrent(this.user._id));
            this.books = response.data.books; 
            this.$emit('sendbook');
       },
       async returnbook(id){
            await PaymentService.returnbook({id: id});
            let response = (await BookService.getbooksinrent(this.user._id));
            this.books = response.data.books; 
            this.$emit('returnbook');
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

.totalprice{
    margin-top: 2%;
}

.pay{
    margin-top: 2%;
}

.butsuccess{
    margin-top: 2%;
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
    border-bottom: 1px dotted #a9a9a9;
    border-top: 1px dotted #a9a9a9;
    text-shadow: 1px 1px 0 #fdfdfd, 2px 2px 0 rgba(81, 81, 81, 0.5), 0 0 1px #fdfdfd;
    font-family: "Oswald", sans-serif;
    font-weight: normal;
    text-transform: uppercase;
}
.book-to-rent{
     border: 4px double gray;
}
    
</style>
