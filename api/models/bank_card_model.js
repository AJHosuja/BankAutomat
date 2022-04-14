const db = require('../database');

const bank_card = {
  getById: function(id, callback) {
    return db.query('select * from bank_card where card_id=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from bank_card', callback);
  },
  add: function(bank_card, callback) {
    return db.query(
      'insert into bank_card (card_id, owner_id, card_numer, pin_code, false_count, locked) values(?,?,?,?,?,?)',
      [bank_card.card_id, bank_card.owner_id, bank_card.card_numer, bank_card.pin_code, bank_card.false_count, bank_card.locked],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from bank_card where card_id=?', [id], callback);
  },
  update: function(id, bank_card, callback) {
    return db.query(
      'update bank_card set owner_id=?, card_numer=?, pin_code=?, false_count=?, locked=? where card_id=?',
      [bank_card.owner_id, bank_card.card_numer, bank_card.pin_code, bank_card.false_count, bank_card.locked, id],
      callback
    );
  }
};
module.exports = bank_card;