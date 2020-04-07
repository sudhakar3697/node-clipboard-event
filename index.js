const { EventEmitter } = require('events');

class ClipboardEventListener extends EventEmitter {
  constructor() {
    super();
  }

  startListening() {
  }

  stopListening() {
  }
}

module.exports = new ClipboardEventListener();
