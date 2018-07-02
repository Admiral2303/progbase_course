<template>
<div>      
    <div v-for="book in books" :key="book._id">  
            <div class="col-md-6 col-xs-12 bookcontainer product">
                <a :href="'/#/books/'+ book._id">
                    <img :src="book.image" alt="img" class="img product-img">
                </a> 
                <div class="row"> 
                    <div class="col-md-10 text-center" style="margin-top:-5%; margin-left: 5%; font-family: 'Oswald', sans-serif;font-weight: normal;text-transform: uppercase;">
                        <h2 class="book-name">{{book.name}} </h2>
                        <h3 class="book-info product-title" >
                                Автор - {{book.authorname }} {{ book.authorSurname }}<br> 
                                Год выпуска - {{ book.year }}<br> 
                        </h3>
                        <div class="row">
                            <p class="product-price">Price: ₴{{book.price}}</p>
                        </div>
                    </div> 
                    
                </div> 
            </div>
    </div>
     

</div>

</template>



<script>
import BookService from '@/services/BookService'

export default {
    computed: {
        books() {
            return this.$store.getters.books
        },
        pages(){ 
            return this.$store.getters.pages
        }
        
    },
    // data () {
    //     return {
    //         books: null,
    //         pages: null,
    //         search: null
    //     }
    // },
    // async mounted(){
    //     let response = (await BookService.index(1));
    //     console.log(response.data.books);
    //     // for(let b in response.data.books){
    //     //     console.log(b);
    //     // }
    //     this.books = response.data.books;
    //     this.pages = response.data.pages;
    // },


};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style >






body{
 background: #ececec;
}
.img {
 height: auto;
 max-width: 100%;
 margin-right: 19%;
}
.content{
 margin-top: 50px;
}
.product {
 background: #fff none repeat scroll 0 0;
 border: 1px solid #c0c0c0;
 height: 390px;
 overflow: hidden;
 padding: 25px 15px;
 position: relative;
 text-align: center;
 transition: all 0.5s ease 0s;
 margin-bottom: 20px;
}
.product:hover {
 box-shadow: 0 0 16px rgba(0, 0, 0, 0.5);
}

.product-title a {
 color: #000;
 font-weight: 500;
 text-transform: uppercase;
}
.product-desc {
 max-height: 60px;
 overflow: hidden;
}
.product-price {
 bottom: 15px;
 left: 0;
 position: relative;
 width: 100%;
 color: #d51e08;
 font-size: 18px;
 font-weight: 500;
}





















.form-control {
    border-radius: 25px;
}

.bookcontainer{
    margin-right: -1%;
}

select {
    -webkit-appearance: none;
    -moz-appearance: none;
    appearance: none;
    /* remove default arrow */
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
    margin-left: 17%;
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
    
</style>
