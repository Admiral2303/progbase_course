let user = require('./../modules/bd_user');


$(document).ready(function() {
    $('#name_form').bootstrapValidator({

        })
        .on('success.form.bv', function(e) {
            $('#contact_form').data('bootstrapValidator').resetForm();



            // Use Ajax to submit form data
            $.post($form.attr('action'), $form.serialize(), function(result) {
                console.log(result);
            }, 'json');
        });
});