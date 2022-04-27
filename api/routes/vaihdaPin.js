var express = require('express');
var router =express.Router();
const bank_card = require('../models/vaihdaPin');
const dotenv = require('dotenv');
const bcrypt = require('bcrypt');


router.post('/', function(request, response) 
{
    if (request.body.id && request.body.old_pin && request.body.new_pin){

        bank_card.getById(request.body.id, function(dberr, dbresult) {
            if(dberr){
                console.log(dberr);
                response.json(dberr);
            } else {
                console.log(dbresult[0].pin_code);
                bcrypt.compare(request.body.old_pin,dbresult[0].pin_code, function(err,compareresult) {
                    console.log('pääsi');
                    if (compareresult) {
                        bank_card.insert(request.body, function(dberr, dbresult) {
                            if (dbresult){
                                response.send(true);
                            }
                        });
                            } else {
                                response.send(false);
                            }
                        });
                    }
                });
            }
        });


module.exports = router;