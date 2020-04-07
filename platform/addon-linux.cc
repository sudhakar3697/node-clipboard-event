#include <napi.h>
#include <X11/extensions/Xfixes.h>
#include <stdio.h>
#include <assert.h>

void WatchSelection(Display *display, Window window, const char *bufname)
{
  int event_base, error_base;
  XEvent event;
  Atom bufid = XInternAtom(display, bufname, False);

  assert( XFixesQueryExtension(display, &event_base, &error_base) );
  XFixesSelectSelectionInput(display, DefaultRootWindow(display), bufid, XFixesSetSelectionOwnerNotifyMask);

  while (True)
  {
    XNextEvent(display, &event);

    if (event.type == event_base + XFixesSelectionNotify &&
        ((XFixesSelectionNotifyEvent*)&event)->selection == bufid)
    {
      printf("CLIPBOARD_CHANGE\n");
      fflush(stdout);
    }
  }
}

Napi::Boolean listenToClipboard(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Display *display = XOpenDisplay(NULL);
  Window window = DefaultRootWindow(display);
  WatchSelection(display,window,"CLIPBOARD");
  XDestroyWindow(display, window);
  XCloseDisplay(display);
  return Napi::Boolean::New(env,true);
}

Napi::Object init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "listenToClipboard"), Napi::Function::New(env, listenToClipboard));
    return exports;
};

NODE_API_MODULE(myAddon, init);

// https://stackoverflow.com/a/44992967
// https://github.com/cdown/clipnotify
// https://stackoverflow.com/a/28020536