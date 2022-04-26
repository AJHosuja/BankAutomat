const express = require('express');
const router = express.Router();
const user = require('../models/user_model');
const vaihdaPin = require('../models/vaihdaPin');
const bank_card = require('../models/vaihdaPin');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
   vaihdaPin.userId(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      user.getById(dbResult[0].owner_id, function(err, dbResult) {
        if (err) {
          response.json(err);
        } else {
          response.json(dbResult);
        }
      });
    }
   });
  }
   
   else {
    user.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});


router.post('/', 
function(request, response) {
  user.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  user.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  user.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;