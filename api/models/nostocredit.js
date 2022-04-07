const db = require('../database');

const nostocredit = {
    callnostocredit: function (value, callback) {
        return db.query(
            'call nosto_credit(?,?,?); ',
            [value.id_account, value.amount, value.cardnumber], callback);
        
    },
    checkcredit: function (value,callback) {
        return db.query(
            'select credit_limit,credit_balance from bank_account WHERE id_account=?; ',
            [value], callback);
    }
};

module.exports = nostocredit;