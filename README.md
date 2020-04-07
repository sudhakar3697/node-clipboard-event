# node-clipboard-event
Clipboard change event for Node.js/Electron.js/NW.js

Usage

```
const clipboardListener = require('clipboard-event');

// To start listening
clipboardListener.startListening();

clipboardListener.on('change', () => {
    console.log('Clipboard changed');
});

// To stop listening
clipboardListener.stopListening();

```
Motivation

* https://github.com/electron/electron/issues/2280
* https://github.com/DoumanAsh/clipboard-master
* https://github.com/aweinstock314/rust-clipboard/issues/48

## MAC Support (TO DO)

* http://www.alecjacobson.com/weblog/?p=2376
* https://gist.github.com/Daemon-Devarshi/13efd24f027a775ee862
* https://developer.apple.com/documentation/appkit/nspasteboard?language=occ

Credits

* Linux-  https://stackoverflow.com/a/44992967
* Windows- https://gist.github.com/glombard/7986317 & https://stackoverflow.com/questions/17762037/error-while-trying-to-copy-string-to-clipboard