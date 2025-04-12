#include "stdafx.h"
#include "HelloFactory.h"

BOOL OpenFactory(void);
BOOL CloseFactory(void);
DWORD g_dwRegister;
CHelloFactory* g_pFactory;

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

	if (lstrcmpiA(lpCmdLine, "-Embedding") == 0 ||
		lstrcmpiA(lpCmdLine, "/Embedding") == 0)
		OpenFactory();

	// �޽��� ����
	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	CloseFactory();
	// COM ���̺귯���� �����Ѵ�.
	::CoUninitialize();

	return 0;
}

BOOL OpenFactory(void)
{
	BOOL bOK = FALSE;
	HRESULT hr;

	g_pFactory = new CHelloFactory;
	if(g_pFactory != NULL) {
		g_pFactory->AddRef();
		hr = ::CoRegisterClassObject(CLSID_Hello,
								  g_pFactory,
								  CLSCTX_LOCAL_SERVER,
								  REGCLS_MULTIPLEUSE,
								  &g_dwRegister);
		bOK = SUCCEEDED(hr);
		if(!bOK) {
			g_pFactory->Release();
			delete g_pFactory;
		}
	}
	else
		bOK = FALSE;
	return bOK;
}

BOOL CloseFactory(void)
{
	BOOL bOK = TRUE;
	HRESULT hr;

	if (g_dwRegister != 0) {
		hr = ::CoRevokeClassObject(g_dwRegister);
		if (FAILED(hr))
			bOK = FALSE;
	}
	if(g_pFactory)
		g_pFactory->Release();

	return bOK;
}

void CloseExe (void)
{
	if (g_cObjects == 0 && g_cLocks == 0)
		PostQuitMessage(0);
}

