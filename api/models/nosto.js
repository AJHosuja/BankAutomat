const db = require('../database');

const nosto = {
    callnosto: function (value, callback) {
        return db.query(
            'call nosto_debit(?,?,?); ',
            [value.id_account, value.amount, value.cardnumber], callback);
        
    },
    checkdebit: function (value,callback) {
        return db.query(
            'select debit_balance from bank_account WHERE id_account=?; ',
            [value], callback);   
    }
};

module.exports = nosto;