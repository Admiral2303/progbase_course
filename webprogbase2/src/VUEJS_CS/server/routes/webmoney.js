const express = require('express');
const router = express.Router();
let storage = require('./../modules/bd_books');
let isAuthenticated = require('./../modules/isAuthenticated');
let isAdmin = require('./../modules/isAdmin');
let payments = require('./../modules/bd_payments');
let test = require('./../modules/bd_test');
let user = require('./../modules/bd_user');
const fs = require('fs');






router.post("/", async(req, res) => {
    console.log(req.body);
    let Test = {
        test: req.body
    }
    res.send({ status: req.body });
    await test.addTest(req.body);
});



router.get("/payments", isAdmin, async(req, res) => {
    try {
        let allpayments = await payments.getPayments();
        let paymentstosend = [];
        let paymentPay = [];
        for (let payment of allpayments) {
            let Payment = {
                _id: payment._id,
                renter: await user.getUserById(payment.renter),
                owner: await user.getUserById(payment.owner),
                datetoreturn: payment.datetoreturn,
                book: await storage.getById(payment.book),
                ownerWallet: payment.ownerWallet,
                payment_amount: payment.payment_amount,
                adress: payment.adress,
                sendflag: payment.sendflag,
                returnflag: payment.returnflag,
                takeflag: payment.takeflag,
                status: payment.status
            }
            if (payment.status != 'true') {
                paymentstosend.push(Payment);
            } else {
                paymentPay.push(Payment);
            }
        }
        paymentstosend = paymentstosend.concat(paymentPay);
        res.send({ payments: paymentstosend })
    } catch (err) {
        res.send({ error: "Forbidden", errorcode: '403' })
    }
})

router.post("/payments/addadress", async(req, res) => {
    try {
        console.log(req.body);

        await payments.setAdress(req.body.book, req.body.adress);
        res.send({ status: true });
    } catch (err) {
        console.log(err);
    }
});



router.post("/payments/setstatus", async(req, res) => {
    try {
        console.log(req.body);
        await payments.setStatus(req.body.id, 'true');
        res.send({ status: true });
    } catch (err) {
        console.log(err);
    }
});

router.post("/payments/sendbook", async(req, res) => {
    try {
        //console.log(req.body);
        await payments.setSendFlag(req.body.id, 'true');
        res.send({ status: true });
    } catch (err) {
        console.log(err);
    }
});



router.post("/payments/returnbook", async(req, res) => {
    try {

        await payments.setReturnFlag(req.body.id, 'true');
        res.send({ status: true });
    } catch (err) {
        console.log(err);
    }
});

router.post("/payments/takebook", async(req, res) => {
    try {
        await payments.setTakeFlag(req.body.id, 'true');
        res.send({ status: true });
    } catch (err) {
        console.log(err);
    }
});





module.exports = router;