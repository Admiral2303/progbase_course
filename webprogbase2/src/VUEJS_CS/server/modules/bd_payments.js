let fs = require('fs');

const mongoose = require('mongoose');
mongoose.Promise = require('bluebird');

let env = require('node-env-file');
env('./config' + '/.env');

let db = mongoose.connect(process.env.MLAB, {
    useMongoClient: true,
});




let Payment = db.model('Payment', {
    renter: String,
    owner: String,
    datetoreturn: Date,
    book: String,
    ownerWallet: String,
    payment_amount: String,
    adress: String,
    sendflag: String,
    returnflag: String,
    takeflag: String,
    status: String
});



async function setSendFlag(id, flag) {
    return await Payment.update({ book: id }, { $set: { sendflag: flag } }, function(err, data) {
        console.log(data);
        if (err) console.log(err);
    });
}

async function setReturnFlag(id, flag) {
    return await Payment.update({ book: id }, { $set: { returnflag: flag } }, function(err, data) {
        console.log(data);
        if (err) console.log(err);
    });
}
async function setTakeFlag(id, flag) {
    return await Payment.update({ book: id }, { $set: { takeflag: flag } }, function(err, data) {
        console.log(data);
        if (err) console.log(err);
    });
}

async function setStatus(id, flag) {
    return await Payment.findByIdAndUpdate(id, { $set: { status: flag } }, { new: true }, function(err, dat) {
        if (err) console.log("++++");
    });
}


async function getPayments() {
    try {
        let payments = await Payment.find().sort({ "datetoreturn": 1 });
        if (payments) return payments;
        else return null;
    } catch (err) {
        throw err;
    }
}

async function setAdress(id, adr) {
    return await Payment.update({ book: id }, { $set: { adress: adr } }, function(err, data) {
        console.log(data);
        if (err) console.log(err);
    });
}


async function addPayment(payment) {
    let rentPayment = new Payment({
        renter: payment.renter,
        owner: payment.owner,
        datetoreturn: payment.datetoreturn,
        book: payment.book,
        ownerWallet: payment.wallet,
        payment_amount: payment.payment_amount
    });
    try {
        await rentPayment.save();
    } catch (err) {
        throw err;
    }
}




module.exports = {
    addPayment,
    getPayments,
    setAdress,
    setSendFlag,
    setReturnFlag,
    setTakeFlag,
    setStatus
};