const db = require('../database');

const login = {
    password: function (username, callback) {
        return db.query(
            'SELECT lname FROM user WHERE fname = ? ',
            [username], callback);
        
    }};

module.exports = login;