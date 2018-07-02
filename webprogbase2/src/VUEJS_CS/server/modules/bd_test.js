let fs = require('fs');

const mongoose = require('mongoose');
mongoose.Promise = require('bluebird');

let env = require('node-env-file');
env('./config' + '/.env');

let db = mongoose.connect(process.env.MLAB, {
    useMongoClient: true,
});




let Test = db.model('Test', {
    test: Object,
    processing: String

});


async function addTest(tests) {
    let mes = new Test({
        test: tests
    });
    try {
        await mes.save();
    } catch (err) {
        throw err;
    }
}


async function SetPayProcessing(id, flag) {
    try {
        return await Test.findByIdAndUpdate(id, { $set: { processing: flag } }, { new: true }, function(err, dat) {
            if (err) console.log("++++");
        });
    } catch (err) {
        throw err;
    }
}

async function takeWebmoneypay(id) {
    try {
        //console.log(id);
        let allPayments = await Test.find();
        let pay = false;
        for (let payment of allPayments) {
            if (payment.test != undefined) {
                //console.log(payment.test);
                if (payment.test.book_id == id) {
                    pay = payment;
                }
            }
        }
        return pay;
    } catch (err) {
        throw err;
    }
}



module.exports = {
    addTest,
    takeWebmoneypay,
    SetPayProcessing
};