const db = require('../database');

const transactions = {
  getById: function(id, callback) {
    return db.query('select * from transactions where id_transaction=?', [id], callback);
  },
  getByAccount: function(id, account_number, callback) {
    return db.query('select * from transactions where account_number=?', [account_number], callback);
  },
  getAll: function(callback) {
    return db.query('select * from transactions', callback);
  },
  add: function(transactions, callback) {
    return db.query(
      'insert into transactions (id_transaction,id_receiver,account_number,card_rfid,transaction,ammount,date_time) values(?,?,?,?,?,?,?)',
      [transactions.id_transaction, transactions.id_receiver, transactions.account_number, transactions.card_rfid, transactions.transaction, transactions.ammount, transactions.date_time],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from transactions where id_transaction=?', [id], callback);
  },
  update: function(id, user, callback) {
    return db.query(
      'update user set id_transaction=?,id_receiver=?, account_number=?, card_rfid=?, transaction=?, ammount=?, date_time=? where user_id=?',
      [transactions.id_transaction, transactions.id_receiver, transactions.account_number, transactions.card_rfid, transactions.transaction, transactions.ammount, transactions.date_time, id],
      callback
    );
  }
};
module.exports = transactions;