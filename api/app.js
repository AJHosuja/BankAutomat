var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const jwt = require('jsonwebtoken');

var indexRouter = require('./routes/index');
var userRouter = require('./routes/user');
var loginRouter = require('./routes/login');
var nostodebitRouter = require('./routes/nosto');
var nostoRouter = require('./routes/nostocredit');
var bankAccount = require('./routes/bank_account');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));


app.use('/login',loginRouter);

//app.use(authenticateToken);
app.use('/nostodebit', nostodebitRouter);
app.use('/nostodebit', nostodebitRouter);
app.use('/bankAccount', bankAccount);

app.use('/', indexRouter);
app.use('/user', userRouter); 


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