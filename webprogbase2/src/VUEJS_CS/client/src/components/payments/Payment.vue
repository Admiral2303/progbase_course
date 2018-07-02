<template>
    <div class="row payment">
        <div class="col-md-1">
            <h6>Орендар</h6>
            <a :href="'/#/profile/'+ payment.payment.renter._id">
                <img :src="payment.payment.renter.image" alt="img" class="imgus">
            </a>
        </div>
        <div class="col-md-1">
            <h6>Власник</h6>
            <a :href="'/#/profile/'+ payment.payment.owner._id">
                <img :src="payment.payment.owner.image" alt="img" class="imgus">
            </a>
        </div>
        <div class="col-md-2">
            <h6>Дата закінчення оренди</h6>
            <h4>{{payment.payment.datetoreturn}} </h4>
        </div>
        <div class="col-md-1 book">
            <h6>{{payment.payment.book.name}} </h6>
            <a :href="'/#/books/'+ payment.payment.book._id">
                <img :src="payment.payment.book.image" alt="img" class="imgus">
            </a>
        </div>
        <div class="col-md-1">
            <div class="row">
                <h6>Рахунок власника</h6>
                <h4>{{payment.payment.owner.wallet}} </h4>
            </div>
            <div v-if="payment.payment.status != 'true'" class="row">
                <form v-on:submit.prevent="pay"  > 
                    <p>
                    <input class="btn btn-success" type="submit" value="Оплатити">
                    </p> 
                </form>  
            </div>
        </div>
        <div class="col-md-2" style="margin-left: 5%;">
            <div class="row">
                <h6>Сума для переведення</h6>
                <h4>{{payment.payment.payment_amount}} </h4>
            </div>
            
            <div v-if="payment.dayflag == true && payment.payment.status != 'true'" class="row">
                <!-- <button @click="paymentok(payment.payment._id)" class="btn btn-danger">Видалити</button> -->
                <a href="#" data-toggle="modal" data-target="#delpay"> <button class="btn btn-danger" type="submit">Видалити</button></a>
                <div class="modal fade" id="delpay" tabindex="-1" role="dialog">
                    <div class="modal-dialog">
                        <div class="modal-content">
                            <div class="modal-header">
                                <button type="button" class="close" data-dismiss="modal">×</button>
                                <h4 class="modal-title" id="myModalLabel">Ви точно опрацювали платіж</h4>
                            </div>
                            <div class="modal-body">
                                <div class="modal-footer">
                                    <button type="button" class="btn btn-default" data-dismiss="modal">Отмена</button>
                                    <button @click="paymentok(payment.payment._id)" data-dismiss="modal" class="btn btn-success ">Підтвердити</button>
                                </div>
                            </div>
                        </div>
                    </div>
                </div> 
            </div>
        </div>
        <div class="col-md-3">
            <div class="row">
                <div class="col-md-4">
                    <h4>Відправив</h4>
                </div>
                <div class="col-md-4">
                    <h4>Отримав</h4>
                </div>
                <div class="col-md-4">
                    <h4>Повернув</h4>
                </div>
            </div>
            <div class="row">
                <div class="col-md-4">
                    <div v-if="payment.payment.sendflag == 'true'">
                        <i class="glyphicon glyphicon-ok"></i>
                    </div>
                    <div v-else>
                        <i class="glyphicon glyphicon-remove"></i>
                    </div>
                </div>
                <div class="col-md-4">
                    <div v-if="payment.payment.takeflag == 'true'">
                        <i class="glyphicon glyphicon-ok"></i>
                    </div>
                    <div v-else>
                        <i class="glyphicon glyphicon-remove"></i>
                    </div>
                </div>
                <div class="col-md-4">
                    <div v-if="payment.payment.returnflag == 'true'">
                        <i class="glyphicon glyphicon-ok"></i>
                    </div>
                    <div v-else>
                        <i class="glyphicon glyphicon-remove"></i>
                    </div>
                </div>
            </div>
        </div>
    </div>

</template>



<script>
import PaymentService from '@/services/PaymentService'
import {mapState} from 'vuex'
import PageHeader from '../Header'
import Payment from './Payment'
export default {
    props: ['payment'],
    data() {
       return {
          
       }
    },
    computed: {
        ...mapState([
            'isUserLoggedIn',
            'user',
            'route'
        ])
    },
    async mounted(){

    },
    methods:{
       pay(){
            //action="https://mini.webmoney.ua/SendWebMoney.aspx"
            window.open("https://mini.webmoney.ua/SendWebMoney.aspx", '_blank');
        },
        async paymentok(id){
            console.log(id);
            await PaymentService.sendstatus({id: id});
            this.$emit('paymentOk');
      
        }
    }



};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.glyphicon-remove{
    color: red;
}
.glyphicon-ok{
    color: green;
}
.daytopay{
    background-color: greenyellow;
}

.payment{
     border: 4px double gray;
}
.imgus{
    max-height: 50px;
    max-width: 50px;
    border-radius: 50%;
}
.book{
    margin-left: 2%;
}
.payok{
    background-color: green;
}
</style>
