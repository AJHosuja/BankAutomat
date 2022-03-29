var mysql = require('mysql');

var connection = mysql.createConnection({
    host: 'sql11.freemysqlhosting.net',
    user: 'sql11482188',
    password: 'uJFk3bnCdA',
    database: 'sql11482188'
});

connection.connect(function(error){
    if(!!error){
        console.log(error);
    } else{
        console.log('connected...!');

    }
});


module.exports = connection;