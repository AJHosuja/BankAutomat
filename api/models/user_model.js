const db = require('../database');

const user = {
  getById: function(id, callback) {
    return db.query('select * from user where user_id=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from user', callback);
  },
  add: function(user, callback) {
    return db.query(
      'insert into user (fname,lname,ssn,user_number,phone_number) values(?,?,?,?,?)',
      [user.fname, user.lname, user.ssn, user.user_number, user.phone_number],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from user where user_id=?', [id], callback);
  },
  update: function(id, user, callback) {
    return db.query(
      'update user set fname=?,lname=?, ssn=?, user_number=?, phone_number=? where user_id=?',
      [user.fname, user.lname, user.ssn, user.user_number, user.phone_number, id],
      callback
    );
  }
};
module.exports = user;