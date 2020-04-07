#include <napi.h>
#include <iostream>
#include <thread> 
#include <Windows.h>

// MSDN
// https://github.com/waitingsong/node-win32-api/blob/master/demo/create_window.ts
// https://stackoverflow.com/a/4081383/5337845

HWND hWnd = NULL;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLIPBOARDUPDATE:
	std::cout<<"CLIPBOARD_CHANGE\n";
		// MessageBox(
		// 	NULL, "Clipboard changed",
		// 	"Clipboard notifications",
		// 	0x00000000L);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void monitorClipboard(){
	WNDCLASSEXW wx = {};
	wx.cbSize = sizeof(WNDCLASSEXW);
	wx.lpfnWndProc = WndProc;
	HINSTANCE hInst = NULL;
	GetModuleHandleExW(0, NULL, &hInst);
	wx.hInstance = hInst;
	wx.lpszClassName = (LPCWSTR) "CEL_CLASS";
	if (RegisterClassExW(&wx))
	{
		hWnd = CreateWindowExW(0, (LPCWSTR) "CEL_CLASS", (LPCWSTR) "ClipboardEventListener", 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, NULL);
	}
	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);
	AddClipboardFormatListener(hWnd);
	HACCEL hAccelTable = LoadAccelerators(hInst, MAKEINTRESOURCE(109));
	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

Napi::Boolean startMonitoring(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();
	monitorClipboard();
	return Napi::Boolean::New(env, true);
}

Napi::Boolean stopMonitoring(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();
	BOOL res = RemoveClipboardFormatListener(hWnd) && DestroyWindow(hWnd);
	return Napi::Boolean::New(env, res);
}

Napi::Object init(Napi::Env env, Napi::Object exports)
{
	exports.Set(Napi::String::New(env, "startMonitoring"), Napi::Function::New(env, startMonitoring));
	exports.Set(Napi::String::New(env, "stopMonitoring"), Napi::Function::New(env, stopMonitoring));
	return exports;
};

NODE_API_MODULE(clipboard_event, init);
