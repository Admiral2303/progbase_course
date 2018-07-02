<template>
<div class="comentsend">
   
        <div class="form-group">
            <label class="control-label col-md-2" for="comment">Ваш коментар</label>
            <div class="col-md-5">
                <textarea v-model="comment" name="comment" rows="5" id="comment" class="form-control" required></textarea>
            </div>
            <div class="col-md-2 sendbutton">
                <button class="btn btn-success" @click="sendComent">Відправити </button>
            </div>
        </div>
    
</div>

</template>



<script>
import {mapState} from 'vuex'
import BookService from '@/services/BookService'
import _ from 'lodash'

export default {
    
    data() {
       return {
           comment: null
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
    async mounted(){
      // let response = (await BookService.getById(this.route.params.bookId));
      // this.book = response.data.book;
    },
    methods:{
       async sendComent(){
            let data ={
                book_id: this.book._id,
                comment: comment._value
            }
            await BookService.addComment(data);
            let response = (await BookService.getById(this.route.params.bookId));
            console.log(response);
            this.$store.dispatch('setBookComents', response.data.coments);
       }
    }



};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.comentsend{
    margin-left: 15%;
}
.sendbutton{
    margin-top: 0.5%;
}
</style>
