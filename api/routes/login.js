var express = require('express');
var router =express.Router();
const login = require('../models/login');
const bcrypt = require('bcrypt');


router.post('/', function(request, response) 
{
    if (request.body.card_number && request.body.pin_code){
        const card_number = request.body.card_number;
        const pin_code = request.body.pin_code;
        
            console.log(card_number);
            console.log(pin_code);
          login.locked_status(card_number, function(dberr, dbresult){
            var lockedStatus = parseInt(dbresult[0].locked);
            console.log(lockedStatus);
            if (lockedStatus==1) {
             response.send('tilisi on jo aiemmin lukittu');
            }else{
            login.password(card_number, function(dberr, dbresult){
            console.log(dbresult[0].pin_code);
            if(dberr){
                console.log(dberr);
                response.json(dberr);
            } else {
                bcrypt.compare(pin_code,dbresult[0].pin_code, function(err,compareresult) {
                    if (compareresult) {
                        console.log("success");
                        response.send(true);
                        login.locked_clear(card_number, function(dberr, dbresult){
                            if (dberr){
                                response.send(err);
                            }
                        });

                    }else{
                            login.false_count(card_number, function(dberr, dbresult) {

                            var false_countti = parseInt(dbresult[0].false_count);

                             if (false_countti < 2){
                                response.send(false);
                                false_countti++;
                                login.false_count_add(card_number, false_countti, function(dberr, dbresult){
                                 if (dberr){
                                     response.send(err);
                                 }
                             });
                            } else {
                                login.locked(card_number, function(dberr, dbresult){
                                    if (dberr){
                                        response.send(err);
                                    }
                                    response.send('locked');
                                });

                            }
                             
                            
                        });
                    }


                });

            }

          });
        }
        });     
    

    }

});

module.exports = router;