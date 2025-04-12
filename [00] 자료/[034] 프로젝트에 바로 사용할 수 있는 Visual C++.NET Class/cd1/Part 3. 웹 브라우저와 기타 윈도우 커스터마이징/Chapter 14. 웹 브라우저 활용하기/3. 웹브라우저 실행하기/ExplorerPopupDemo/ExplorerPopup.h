#pragma once

// 웹브라우저 클래스에 대한 선언
class CWebBrowser2;


// 웹브라우저 제어 클래스
class CExplorerPopup
{
	// OpenNewWindowEx()로 생성된 웹브라우저의 윈도우 핸들 저장 변수
	HWND	m_hExplorer;

public:
	// 생성자
	CExplorerPopup();
	// 소멸자
	virtual ~CExplorerPopup();

	// ShellExecute()를 사용하여 사이트를 여는 함수
	BOOL OpenByShellExecute(LPCTSTR pAddress);
	// IWebBrowser2를 사용하여 사이트를 여는 함수
	BOOL OpenNewWindow(LPCTSTR pAddress);
	// CWebBrowser2 클래스를 사용하여 사이트를 여는 함수
	BOOL OpenNewWindow(LPCTSTR pAddress, CWebBrowser2 *pBrowser);
	// IWebBrowser2를 사용하여 웹브라우저를 생성하고 옵션 설정 후 사이트를 여는 함수
	BOOL OpenNewWindowEx(LPCTSTR pAddress, BOOL bMenu = TRUE, BOOL bToolBar = TRUE,
		BOOL bAddressBar = TRUE, BOOL bStatusBar = TRUE, BOOL bResize = TRUE,
		int x = -1, int y = -1, int cx = -1, int cy = -1);
	// OpenNewWindowEx()를 사용하여 생성한 웹브라우저를 닫는 함수
	BOOL CloseExplorer();
};