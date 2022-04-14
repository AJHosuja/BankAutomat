const db = require('../database');

const bank_account = {
    get: function (callback) {
        return db.query(
            'SELECT * FROM bank_account',
             callback);
    },
    get_id: function (id_account, callback) {
        return db.query(
            'SELECT * FROM bank_account WHERE id_account = ? ',
            [id_account], callback);
    },
    update_credit: function (id, data, callback) {
        return db.query(
            'UPDATE bank_account SET debit_credit = ? , credit_limit = ?, debit_balance = ?,  credit_balance = ?  WHERE id_account = ? ',
            [data.debit_credit,data.credit_limit, data.debit_balance,data.credit_balance, data.id_account, id ], callback);
    },
    update_debit: function (id, data, callback) {
        return db.query(
            'UPDATE bank_account SET debit_credit = ? , debit_balance = ?  WHERE id_account = ? ',
            [data.debit_credit, data.debit_balance, credit_balance, id ], callback);
    },
    add_debit: function (data, callback) {
        return db.query(
            'INSERT INTO bank_account (debit_credit, debit_balance) values (?,?) ',
            [data.debit_credit, data.debit_balance], callback)
    },
    add_credit: function (data, callback) {
        return db.query(
            'INSERT INTO bank_account (debit_credit, credit_limit, debit_balance, credit_balance) values (?,?,?,?) ',
            [data.debit_credit, data.credit_limit, data.debit_balance, data.credit_balance], callback)
    },
    delete: function (data, callback) {
        return db.query(
            'DELETE from bank_account WHERE id_account = ? ',
            [data], callback)
    }

};

module.exports = bank_account;