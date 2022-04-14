const express = require('express');
const router = express.Router();
const bank = require('../models/bank_account');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    bank.get_id(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    bank.get(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});


router.post('/credit', 
function(request, response) {
  bank.add_credit(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.post('/debit', 
function(request, response) {
  bank.add_debit(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  bank.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
    if(request.body.credit_balance){
  bank.update_credit(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
} else {
    bank.update(request.params.id, request.body, function(err, dbResult) {
        if (err) {
          response.json(err);
        } else {
          response.json(dbResult);
        }
  });
}
});

module.exports = router;