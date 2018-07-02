<template>
<div>
    <PageHeader> </PageHeader>
    <div class="container-fluid">
        <div class="row ">
            <div class="col-md-3  hidden-xs">
                <search-panel/>
            </div>
            <div class="col-md-9 col-xs-12">
            <books-list/>
            </div>
        </div>
    </div>
    <div class="container-fluid text-center">
    <pagination> </pagination>
    </div>
</div>

</template>



<script>
import PageHeader from '../Header'
import SearchPanel from './SearchPanel'
import BooksList from './BooksList'
import Pagination from './Pagination'
import BookService from '@/services/BookService'
export default {
    data () {
        return {
            bpages:null,
        }
    },
    components: {
        PageHeader,
        SearchPanel,
        BooksList,
        Pagination
    },
     async mounted(){
        let response = (await BookService.getuserbooks(1));
        console.log(response);
        this.$store.dispatch('setBookmarksFlag', false);
        this.$store.dispatch('setBooks', {});
        this.$store.dispatch('setPages', {})
        this.$store.dispatch('setBooks', response.data.books);
        this.$store.dispatch('setPages', response.data.pages);
        this.$store.dispatch('setMyBooksFlag', true);
        this.$store.dispatch('setSearch', {});
        // console.log(response.data.books);
        // this.books = response.data.books;
        //this.bpages = response.data.pages;
    },



};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

    
</style>
