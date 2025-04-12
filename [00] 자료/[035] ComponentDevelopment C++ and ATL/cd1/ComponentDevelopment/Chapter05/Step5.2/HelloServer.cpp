#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	HRESULT hr;
	MSG msg;

	// COM 라이브러리를 초기화한다.
	hr = ::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if(FAILED(hr)) {
		MessageBox(NULL, "COM 라이브러리를 초기화할 수 없습니다!", NULL, MB_OK);
		return 0;
	}

	// 메시지 루프
	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// COM 라이브러리를 해제한다.
	::CoUninitialize();

	return 0;
}
