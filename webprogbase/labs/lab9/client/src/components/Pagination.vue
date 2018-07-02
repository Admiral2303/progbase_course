<template>
    <div>
        <div class="col-md-1">
            <div v-for="page in booksPages" :key="page">
            <!-- <footer id="footer" class="footer navbar-bottom text-center"> -->
                   <button @click="changepage(page)"  class="btn btn-primary"> {{page}} </button> 
            <!-- </footer> -->
            </div>  
            </div>    
    </div>   
</template>

<script>
export default {
    props: ['booksPages'],
    methods: {
        async changepage(page){
           // console.log("+++");
            this.$emit('changePage', page); 

        }
    }
}   
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style >

 
</style>
