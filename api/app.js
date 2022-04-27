var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const jwt = require('jsonwebtoken');

var indexRouter = require('./routes/index');
var userRouter = require('./routes/user');
var loginRouter = require('./routes/login');
var nostodebitRouter = require('./routes/nosto');
var nostoCreditRouter = require('./routes/nostocredit');
var user_bridgeRouter = require('./routes/user_bridge');

var bankAccount = require('./routes/bank_account');

var bank_cardRouter = require('./routes/bank_card');

var transactionsRouter = require('./routes/transactions');
var vaihdaPin = require('./routes/vaihdaPin');


var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/login',loginRouter);

app.use(authenticateToken);
app.use('/nostodebit', nostodebitRouter);
app.use('/nostoCredit', nostoCreditRouter);
app.use('/bankAccount', bankAccount);
app.use('/', indexRouter);
app.use('/user', userRouter); 
app.use('/user_bridge', user_bridgeRouter);
app.use('/bank_card', bank_cardRouter);
app.use('/transactions', transactionsRouter); 
app.use('/vaihdapin', vaihdaPin); 



function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = user
  
      next()
    })
  }

module.exports = app;