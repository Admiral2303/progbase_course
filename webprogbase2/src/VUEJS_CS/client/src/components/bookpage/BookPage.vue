<template>
<div class="bookpage">
    <page-header/>
    <div id="content" class="col-md-12 product_page">
        <div class="row product-content-columns">
            <book-info ></book-info>
        </div>
    </div> 
    <hr class="line">
    <div class="container">
        <div class="row">
            <div class="form-horizontal">
            <add-coment > </add-coment>
            <view-coments> </view-coments>
            </div>
        </div>
    </div>
</div>

</template>



<script>
import {mapState} from 'vuex'
import PageHeader from '../Header'
import BookInfo from './BookInfo'
import AddComent from './AddComent'
import ViewComents from './ViewComents'
import BookService from '@/services/BookService'

export default {
    data () {
        return {
         //   coment_users: null,
          //  coments: null
            // postCreater: null
        }
    },
    computed: {
    ...mapState([
      'isUserLoggedIn',
      'user',
      'route'
    ])
  },
    components: {
        PageHeader,
        BookInfo,
        AddComent,
        ViewComents
    },
    async mounted(){

        let response = (await BookService.getById(this.route.params.bookId));
        if(!response.data.error){
            this.$store.dispatch('setBook', response.data.book)
            this.$store.dispatch('setBookComents', response.data.coments);
        } else{
            this.$store.dispatch('setError', response.data.error);
            this.$store.dispatch('setErrorCode', response.data.errorcode);
             this.$router.push({
                    name: 'ErrorPage'
            });
        }
       
    },
    methods: {
       
    }



};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.bookpage{
    overflow-x  : hidden;
    background-image: url(" http://res.cloudinary.com/booka-herokuapp-com/image/upload/v1513274285/page-bg-1_pnfci4.jpg");
}
.line {
    color: black;
}
    
</style>
