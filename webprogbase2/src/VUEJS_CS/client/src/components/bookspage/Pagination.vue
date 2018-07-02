<template>
  <paginate
    :page-count=pages
    :page-range="3"
    :margin-pages="2"
    :click-handler="clickCallback"
    :prev-text="'<'"
    :next-text="'>'"
    :container-class="'pagination'"
    :page-class="'page-item'">
  </paginate>
</template>
 
<script src="https://unpkg.com/vuejs-paginate@latest"></script>
<script>
import Paginate from 'vuejs-paginate'
import BookService from '@/services/BookService'
export default {
    computed: {
        pages(){ 
            return this.$store.getters.pages
        }   
    },
    //   props: ['booksPages'],
    methods: {
        async clickCallback (pageNum){
            if(this.$store.getters.mybooksflag == false && this.$store.getters.bookmarksflag == false){
                if(this.$store.getters.searchflag == false){
                    let response = (await BookService.index(pageNum));
                    this.$store.dispatch('setBooks', response.data.books);
                    this.$store.dispatch('setPages', response.data.pages);   
                } else{
                    let search = this.$store.getters.search
                    let response = await BookService.search(search, pageNum);
                    this.$store.dispatch('setBooks', response.data.books);
                    this.$store.dispatch('setPages', response.data.pages);          
                }
            } else if(this.$store.getters.mybooksflag == true && this.$store.getters.bookmarksflag == false){
                if(this.$store.getters.searchflag == false){
                    let response = (await BookService.getuserbooks(pageNum));
                    this.$store.dispatch('setBooks', response.data.books);
                    this.$store.dispatch('setPages', response.data.pages);   
                } else{
                    let search = this.$store.getters.search
                    let response = await BookService.mybookssearch(search, pageNum);
                    this.$store.dispatch('setBooks', response.data.books);
                    this.$store.dispatch('setPages', response.data.pages);          
                }

            }else if(this.$store.getters.bookmarksflag == true && this.$store.getters.mybooksflag == false){
                if(this.$store.getters.searchflag == false){
                    let response = (await BookService.getuserbookmarks(pageNum));
                    this.$store.dispatch('setBooks', response.data.books);
                    this.$store.dispatch('setPages', response.data.pages);   
                } else{
                    let search = this.$store.getters.search
                    let response = await BookService.bookmarkssearch(search, pageNum);
                    this.$store.dispatch('setBooks', response.data.books);
                    this.$store.dispatch('setPages', response.data.pages);          
                }
            }

        }
     //this.$emit('changePage', pageNum); 
       
    }
}
</script> 
 
<style lang="css">
.pagination {
}
.page-item {
}
</style> 