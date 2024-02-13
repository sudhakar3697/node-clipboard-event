# node-clipboard-event 
Clipboard change event for Node.js, Electron.js, NW.js. **[It's not being polled. This implementation is based on child_process. A native node module using N-API is being developed.](https://github.com/sudhakar3697/node-clipboard-event/tree/v2)**

## Motivation
The motivation for creating this open project was these: 

**1.** [Add Clipboard change event to clipboard API](https://github.com/electron/electron/issues/2280)

**2.** [Clipboard-master](https://github.com/DoumanAsh/clipboard-master)

**3.** [Discussion: feasibility for clipboard change events](https://github.com/aweinstock314/rust-clipboard/issues/48)

## Usage

```js
import ClipboardListener from 'EventClipboard'

// In case of CommonJS
// const ClipboardListener = require('ClipboardEvent');

// To start listening
ClipboardListener.startListening();

ClipboardListener.on('change', () => {
    console.log('Clipboard changed');
});

// To stop listening
ClipboardListener.stopListening();
```

- Access `node_modules/clipboard-event/plataform` and run the following command to give execution permission for files from your OS:
```bash
chmod +x <filename>
```


## Credits

#### MAC
* [apple/NSPasteboard](https://developer.apple.com/documentation/appkit/nspasteboard?language=occ)
* [alecjacobson/Accessing clipboard (copy paste) from C++ program on Mac OS X](http://www.alecjacobson.com/weblog/?p=2376)
* [Daemon-Devarshi/PasteboardWatcher.swift](https://gist.github.com/Daemon-Devarshi/13efd24f027a775ee862)
  
#### Linux:
* [stackoverflow/X11 Wait for and Get Clipboard Text](https://stackoverflow.com/a/44992967)

#### Windows
* [glombard/ClipboardNotification.cs](https://gist.github.com/glombard/7986317)
* [stackoverflow/"Current thread must be set to single thread apartment (STA)" error in copy string to clipboard](https://stackoverflow.com/questions/17762037/error-while-trying-to-copy-string-to-clipboard)
