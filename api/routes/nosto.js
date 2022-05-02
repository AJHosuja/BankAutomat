var express = require('express');
var router =express.Router();
const nosto = require('../models/nosto');
const dotenv = require('dotenv');


router.post('/', function(request, response) 
{
    if (request.body.id_account && request.body.amount && request.body.cardnumber){
        console.log(request.body.id_account);
        console.log(request.body.amount);
        console.log(request.body.cardnumber);
        nosto.checkdebit(request.body.id_account, function(dberr, dbresult){
            if(dberr){
                response.send(dberr);
            } else{
                console.log(dbresult[0].debit_balance);
                if (dbresult[0].debit_balance-request.body.amount > -1){
                    nosto.callnosto(request.body, function(dberr, dbresult) {
                        if(dberr){
                            response.send(false)
                        } else{
                            console.log(dbresult);
                            response.send(true);
                        }
                    });
                }   else{
                    response.send('ei katetta');
                }
            }
        });
        
    }
});

module.exports = router;