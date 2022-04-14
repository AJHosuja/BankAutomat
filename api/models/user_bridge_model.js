const db = require('../database');

const user_bridge = {
  getById: function(id, callback) {
    return db.query('select * from user_bridge where user_bridge_id=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from user_bridge', callback);
  },
  add: function(user_bridge, callback) {
    return db.query(
      'insert into user_bridge (user_id,id_account) values(?,?)',
      [user_bridge.user_id, user_bridge.id_account],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from user_bridge where user_bridge_id=?', [id], callback);
  },
  update: function(id, user_bridge, callback) {
    return db.query(
      'update user_bridge set user_id=?,id_account=?',
      [user_bridge.user_id, user_bridge.id_account, id],
      callback
    );
  }
};


module.exports = user_bridge;