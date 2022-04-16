const db = require('../database');

const user_account_bridge = {
  getById: function(id, callback) {
    return db.query('select * from user_account_bridge where user_id=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from user_account_bridge', callback);
  },
  add: function(user_account_bridge, callback) {
    return db.query(
      'insert into user_account_bridge (user_id,id_account) values(?,?)',
      [user_account_bridge.user_id, user_account_bridge.id_account],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from user_account_bridge where user_id=?', [id], callback);
  },
  update: function(id, user_account_bridge, callback) {
    return db.query(
      'update user_account_bridge set user_id=?,id_account=?',
      [user_account_bridge.user_id, user_account_bridge.id_account, id],
      callback
    );
  }
};


module.exports = user_account_bridge;