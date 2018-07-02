<template>
  
<section id="wrapper" class="container-fluid">
        <div class="error-box">
            <div class="error-body text-center">
                <h1 class="text-danger">{{errorcode}}</h1>
                <h3>{{error}}</h3>  
                <a href="/#/books" class="btn btn-danger btn-rounded m-b-40">Back to home</a> </div>
        </div>
</section>


</template>



<script>

export default {
 computed: {
        error() {
            return this.$store.getters.error
        },
        errorcode(){ 
            return this.$store.getters.errorcode
        }
        
    },
    async mounted(){
        // if(this.error == null && this.errorcode == null){
        //     this.$store.dispatch('setError', 'Not Found');
        //     this.$store.dispatch('setErrorCode', '404');
            
        // }
        // this.$store.dispatch('setError', 'Not Found');
        // this.$store.dispatch('setErrorCode', '404');
        // console.log(this.$store.getters.errorcode +"---")
    },

    methods: {
    
  
    }
};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
/*        
Author: http://bootstraptema.ru/
*/
@import url(https://fonts.googleapis.com/css?family=Rubik:300,400,500,700,900);
body{font-family:Rubik,sans-serif;margin:0;overflow-x:hidden;font-weight:300}
#wrapper{width:100%}error-box{height:100%;position:fixed;top:20%;width:100%}
.error-box .footer{width:100%;left:0;right:0}
.error-body{padding-top:5%}
.error-body h1{font-size:210px;
    font-weight:900;
    line-height:210px
}
.text-danger{color:#f33155}
.text-muted{color:#8d9ea7}
.m-b-40{margin-bottom:40px!important}
.m-t-30{margin-top:30px!important}
.m-b-30{margin-bottom:30px!important}
@media only screen and (max-width: 520px){
    .error-body h1{
        font-size:110px;
        font-weight:700;
        line-height:110px
    }
}
    
</style>
