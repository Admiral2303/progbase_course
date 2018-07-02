<template>
<div class="com">
    
    <div v-for="coment of coments" :key="coment.name">
                <div class="review-item">
                    <div class="row">
                        <div class="col-md-1">
                            <div class="review-author"><strong> Коментар</strong>
                            </div>
                        </div>
                        <div class="col-md-1 ">
                            <img :src="coment.image" alt="img" class="img">
                        </div>
                        <div class="col-md-1 ">
                            <div class="review-date" >
                                {{coment.name}}
                            </div>
                        </div>
                        <div class="col-md-9 text-center">
                            {{coment.text}}
                        </div>
                    </div>
                </div>
                <hr class="line">
            </div>
</div>

</template>



<script>
import {mapState} from 'vuex'
import BookService from '@/services/BookService'
import _ from 'lodash'

export default {  
    computed: {
        coments() {
            return this.$store.getters.coments
        },
        ...mapState([
            'isUserLoggedIn',
            'user',
            'route'
        ])
    },
    async mounted(){
       
         
         
       //  console.log("------------------------");
         //console.log(this.coments);
      // this.book = response.data.book;
    },
    methods:{
       async sendComent(){
           //console.log(this.book);
           let data ={
               book_id: this.book._id,
               comment: comment
           }
           await BookService.addComment(data);
       }
    }



};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.com{
    margin-left: 16%;
}

.h1 {
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
    max-height: 50px;
    max-width: 50px;
    border-radius: 50%;
}
    
</style>
