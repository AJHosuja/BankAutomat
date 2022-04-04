var express = require('express');
var router =express.Router();
const nostocredit = require('../models/nostocredit');
const dotenv = require('dotenv');


router.post('/', function(request, response) 
{
    if (request.body.id_account && request.body.amount && request.body.cardnumber){
        console.log(request.body.id_account);
        console.log(request.body.amount);
        console.log(request.body.cardnumber);
        
        nostocredit.checkcredit(request.body.id_account, function(dberr, dbresult) {
            console.log(dbresult[0].credit_limit);
            console.log(dbresult[0].credit_balance);
            if (dbresult[0].credit_limit < dbresult[0].credit_balance-request.body.amount){
                
                nostocredit.callnostocredit(request.body, function(dberr, dbresult) {
                    if(dberr){
                        response.send(false)
                    } else{
                        console.log(dbresult);
                        response.send(true);
                    }
                });
            } else {   
                response.send('credit_limit');
            }
        });
    }
});

module.exports = router;