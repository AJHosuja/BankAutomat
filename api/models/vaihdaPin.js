const db = require('../database');
const bcrypt = require('bcrypt');

const vaihdaPin = {
  getById: function(id, callback) {
    return db.query('select pin_code from bank_card where card_id=?', [id], callback);
  },
  insert: function(data, callback) {
    bcrypt.hash(data.new_pin ,10 , function(err, hash) {
        if (err){
            console.log('hash failed');
        }else {
    return db.query('update bank_card set pin_code=? where card_id=?', [hash, data.id], callback);
        }});
    },
    userId: function(id, callback) {
        return db.query('select owner_id from bank_card where card_id=?', [id], callback);
      }
};
module.exports = vaihdaPin;