if (process.platform === 'linux') {
    const clipboard = require('./build/Release/clipboard-event.node');
    console.log(clipboard.listenToClipboard());
}
else {
    const clipboardEvents = require('./build/Release/clipboard-event.node');
    clipboardEvents.startMonitoring();
}
