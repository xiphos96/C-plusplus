#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	HRESULT hr;
	MSG msg;

	// COM ���̺귯���� �ʱ�ȭ�Ѵ�.
	hr = ::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if(FAILED(hr)) {
		MessageBox(NULL, "COM ���̺귯���� �ʱ�ȭ�� �� �����ϴ�!", NULL, MB_OK);
		return 0;
	}

	// �޽��� ����
	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// COM ���̺귯���� �����Ѵ�.
	::CoUninitialize();

	return 0;
}
