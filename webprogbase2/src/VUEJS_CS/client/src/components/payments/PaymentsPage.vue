<template>
<div>
    <page-header/>
    <h1 class="text-center"> Опрацювання платежів </h1>
    <select v-model="option" @change="optionchange"> 
        <option>Обробленні платежі</option>
        <option>Платежі, які потрібно оробити</option>
        <option>Всі платежі</option>
    </select>
    <div class="container-fluid">
        <div v-for="payment in sortpayments" :key="payment._id"> 
            <div v-if="payment.payment.status == 'true'"> 
                    <div class="payok">
                        <payment @paymentOk="paymentok" :payment="payment"> </payment>
                    </div>
            </div>
            <div v-else-if="payment.dayflag == true && payment.payment.status != 'true'"> 
                <div class="daytopay">
                <payment @paymentOk="paymentok" :payment="payment"> </payment>
                </div>
            </div>
            <div v-else>
                <payment @paymentOk="paymentok" :payment="payment"> </payment>                
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
    data () {
        return {
            payments: {},
            sortpayments: {},
            option:''
        }
    },
    async mounted(){
        let allpayments = await  PaymentService.payments();
        let Payments = [];
         if(!allpayments.data.error){
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
            if((day == daynow && month == monthnow && year == yearnow) || (year == yearnow && month == monthnow && daynow > day) || (year == yearnow && month < monthnow)){
                console.log("++++")
                p.dayflag == true;
                Payments.push({payment:p,dayflag: true});
            } else{
                Payments.push({payment:p,dayflag: false});
            }
        }
        this.payments = Payments;
        this.sortpayments = Payments;
        } else{
            this.$store.dispatch('setError', allpayments.data.error);
            this.$store.dispatch('setErrorCode', allpayments.data.errorcode);
            this.$router.push({
                    name: 'ErrorPage'
            });
        }
        
    },
    computed: {
        ...mapState([
            'isUserLoggedIn',
            'user',
            'route'
        ])
    },
    methods:{
        async paymentok(){
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
            if((day == daynow && month == monthnow && year == yearnow) || (year == yearnow && month == monthnow && daynow > day) || (year == yearnow && month < monthnow)){
                console.log("++++")
                p.dayflag == true;
                Payments.push({payment:p,dayflag: true});
            } else{
                Payments.push({payment:p,dayflag: false});
            }
        }

        this.payments = Payments;
        this.sortpayments = Payments;
       },
       optionchange(){
           if(this.option == 'Обробленні платежі'){
               let sortPayments =[];
               for(let p of this.payments){
                   if(p.payment.status == 'true'){
                       sortPayments.push(p);
                       
                   }
                   console.log(p.status);
               }
               this.sortpayments = sortPayments;

           } else if(this.option =='Платежі, які потрібно оробити'){
                let sortPayments =[];
                for(let p of this.payments){
                   if(p.payment.status != 'true'){
                       sortPayments.push(p);
                   }
               }
               this.sortpayments = sortPayments;
           } else{
              this.sortpayments = this.payments; 
           }
       }
    },
    components:{
        PageHeader,
        Payment
    }



};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.daytopay{
    background-color: greenyellow;
}
.payok{
    background-color: green;
}
</style>
