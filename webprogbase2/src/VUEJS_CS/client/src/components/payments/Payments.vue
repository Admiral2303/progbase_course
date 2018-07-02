<template>
<div>  
    <page-header/> 
    <h1 class="text-center"> Опрацювання платежів </h1>
    <div class="container-fluid">
        <div v-for="payment in payments" :key="payment._id">  
            <div v-if="payment.dayflag == true">
                <div class="row payment daytopay">
                    <div class="col-md-1">
                        <h6>Орендар</h6>
                        <img :src="payment.payment.renter.image" alt="img" class="imgus">
                    </div>
                    <div class="col-md-1">
                        <h6>Власник</h6>
                        <img :src="payment.payment.owner.image" alt="img" class="imgus">
                    </div>
                    <div class="col-md-2">
                        <h6>Дата закінчення оренди</h6>
                        <h4>{{payment.payment.datetoreturn}} </h4>
                    </div>
                    <div class="col-md-1 book">
                        <h6>{{payment.payment.book.name}} </h6>
                        <img :src="payment.payment.book.image" alt="img" class="imgus">
                    </div>
                    <div class="col-md-1">
                        <div class="row">
                            <h6>Рахунок власника</h6>
                            <h4>{{payment.payment.ownerWallet}} </h4>
                        </div>
                        <div class="row">
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
                        
                        <div v-if="payment.dayflag == true" class="row">
                            <button @click="paymentok(payment.payment._id)" class="btn btn-danger">Видалити</button>
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
            </div>
            <div v-else>
                <div class="row payment nodaytopay">
                    <div class="col-md-1">
                        <h6>Орендар</h6>
                        <img :src="payment.payment.renter.image" alt="img" class="imgus">
                    </div>
                    <div class="col-md-1">
                        <h6>Власник</h6>
                        <img :src="payment.payment.owner.image" alt="img" class="imgus">
                    </div>
                    <div class="col-md-2">
                        <h6>Дата закінчення оренди</h6>
                        <h4>{{payment.payment.datetoreturn}} </h4>
                    </div>
                    <div class="col-md-1 book">
                        <h6>{{payment.payment.book.name}} </h6>
                        <img :src="payment.payment.book.image" alt="img" class="imgus">
                    </div>
                    <div class="col-md-1">
                        <div class="row">
                            <h6>Рахунок власника</h6>
                            <h4>{{payment.payment.ownerWallet}} </h4>
                        </div>
                        <div class="row">
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
            </div>
        </div>
    </div>
   



</div>

</template>



<script>
import PaymentService from '@/services/PaymentService'
import {mapState} from 'vuex'
import PageHeader from '../Header'
export default {
    data () {
        return {
            payments: {},
        }
    },
    async mounted(){
        let allpayments = await  PaymentService.payments();
        //this.payments = allpayments.data.payments;
        //  console.log(this.payments)

        let Payments = [];
        for(let p of  allpayments.data.payments){
            let date = new Date(p.datetoreturn);
            let datenow = new Date();
            let month = parseInt(date.getMonth());
            let monthnow = parseInt(datenow.getMonth());                                                                                     
            let day =  parseInt(date.getDay());
            let daynow =  parseInt(datenow.getDay());
            let year =  parseInt(date.getYear());
            let yearnow =  parseInt(datenow.getYear());
            console.log(datenow)
           // console.log(year + "---" + yearnow + "----" + month + "----" + monthnow + "----" + day + "----" + daynow)
            if((day == daynow && month == monthnow && year == yearnow) || (year == yearnow && month == monthnow && daynow > day) || (year == yearnow && month < monthnow)){
                console.log("++++")
                p.dayflag == true;
                Payments.push({payment:p,dayflag: true});
            } else{
                Payments.push({payment:p,dayflag: false});
            }
        }
        // console.log(datenow);
        this.payments = Payments;
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
        pay(){
            //action="https://mini.webmoney.ua/SendWebMoney.aspx"
            window.open("https://mini.webmoney.ua/SendWebMoney.aspx", '_blank');
        },
        async paymentok(id){
            console.log(id);
            await PaymentService.sendstatus({id: id});
            let allpayments = await  PaymentService.payments();
            let Payments = [];
            for(let p of  allpayments.data.payments){
                let date = new Date(p.datetoreturn);
                let datenow = new Date();
                let month = parseInt(date.getMonth());
                let monthnow = parseInt(datenow.getMonth());                                                                                     
                let day =  parseInt(date.getDay());
                let daynow =  parseInt(datenow.getDay());
                let year =  parseInt(date.getYear());
                let yearnow =  parseInt(datenow.getYear());
                console.log(datenow)
            // console.log(year + "---" + yearnow + "----" + month + "----" + monthnow + "----" + day + "----" + daynow)
                if((day == daynow && month == monthnow && year == yearnow) || (year == yearnow && month == monthnow && daynow > day) || (year == yearnow && month < monthnow)){
                    console.log("++++")
                    p.dayflag == true;
                    Payments.push({payment:p,dayflag: true});
                } else{
                    Payments.push({payment:p,dayflag: false});
                }
        }
        console.log(Payments);
        this.payments = Payments;
        }
    }
};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style>
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
    
</style>
