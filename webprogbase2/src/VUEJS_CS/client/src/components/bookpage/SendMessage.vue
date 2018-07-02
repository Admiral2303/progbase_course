<template>
<div>
  
<div class="modal fade" id="myModal2" tabindex="-1" role="dialog">
	    <div class="modal-dialog">
		<div class="modal-content">
		    <div class="modal-header">
		        <button type="button" class="close" data-dismiss="modal">×</button>
		        <h4 class="modal-title" id="myModalLabel">Написати повідомлення</h4>
		    </div>
		    <div class="modal-body">
		        <form v-on:submit.prevent="sendMessage">
		            <div class="form-group has-feedback">
		                <label for="login" class="control-label col-xs-3">Введіть:</label>
		                <div class="col-xs-6">
		                    <div class="input-group">
		                        <span class="input-group-addon"><i class="glyphicon glyphicon-user"></i></span>
		                        <textarea v-model="message" class="form-control" data-error="error" id="message" name="message" required></textarea>
		                    </div>
		                    <span class="glyphicon form-control-feedback"></span>
		                </div>
		            </div>
		            
		            <div class="modal-footer">
		                <button type="button" class="btn btn-default" data-dismiss="modal">Отмена</button>
		                <button id="save" type="submit" class="btn btn-primary" data-dismiss="modal" >Відправити</button>
		            </div>
		        </form>
		    </div>
		</div>
	</div>
</div>  

</div>  

</template>



<script>

import BookService from '@/services/BookService'
import ChatService from '@/services/ChatService'
export default {
    data () {
        return {
            message: null
        }
    },
    computed: {
   
  },
    components: {
       
    },
    async mounted(){
        
    },
		                        
    
    methods: {
       async sendMessage(){
           let id = this.$store.getters.book.user_id;
           console.log(id);
           let data = {
               receiver_id: id,
               message: this.message
           }
           
           await ChatService.sendmessage(data);
       }
    }



};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

    
</style>
