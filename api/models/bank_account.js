const db = require('../database');

const bank_account = {
    get: function (id_account, callback) {
        return db.query(
            'SELECT * FROM bank_account WHERE id_account = ? ',
            [card_number], callback);
    },
    update: function (data, callback) {
        return db.query(
            'UPDATE bank_account SET debit_credit = ? , credit_limit = ?, debit_balance = ?,  credit_balance = ?  WHERE id_account = ? ',
            [data.debit_credit,data.credit_limit, data.debit_balance,credit_balance, data.id_account ], callback);
    },
    add_debit: function (data, callback) {
        return db.query(
            'INSERT INTO bank_account (debit_credit, debit_balance) values (?,?) ',
            [data.debit_credit, data.debit_balance], callback)
    },
    credit: function (data, callback) {
        return db.query(
            'INSERT INTO bank_account (debit_credit, credit_limit, debit_balance, credit_balance) values (?,?,?,?) ',
            [data.debit_credit, data.credit_limit, data.debit_balance, data.credit_balance], callback)
    },
    delete: function (data, callback) {
        return db.query(
            'DELETE from bank_account WHERE id_account = ? ',
            [data.id_account], callback)
    }

};

module.exports = bank_account;