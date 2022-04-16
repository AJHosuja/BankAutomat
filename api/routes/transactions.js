const express = require('express');
const router = express.Router();
const transactions = require('../models/transactions_model');

router.get('/:id?/:account?',
 function(request, response) {
  if(request.params.account) {
    transactions.getByAccount(request.params.id, request.params.account, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } 
  else if(request.params.id) {
    transactions.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
  else {
    transactions.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});

/*
router.get('/:account_number?',
if (request.params.account_number) {
  transactions.getByAccount(request.params.account_number, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  }
  }
);
*/


router.post('/', 
function(request, response) {
  transactions.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  transactions.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  transactions.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;