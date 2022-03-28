var express = require('express');
var router =express.Router();
const login = require('../models/login');
const bcrypt = require('bcrypt');


router.post('/', function(request, response) 
{
    if (request.body.username && request.body.password){
        const username = request.body.username;
        const password = request.body.password;
        
        console.log(username);
        console.log(password);

          login.password(username, function(dberr, dbresult){
            
            if(dberr){
                console.log(dberr);
                response.json(dberr);
            } else {
                console.log(dbresult);
                response.send(true);

            }

          });     
    

    }

});

module.exports = router;