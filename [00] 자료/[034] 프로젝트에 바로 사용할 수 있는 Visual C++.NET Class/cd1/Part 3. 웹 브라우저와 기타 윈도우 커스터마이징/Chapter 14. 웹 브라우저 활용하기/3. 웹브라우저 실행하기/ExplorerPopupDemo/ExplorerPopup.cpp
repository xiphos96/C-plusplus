#include "stdafx.h"
#include "ExplorerPopup.h"

// 웹브라우저 클래스에 대한 헤더
#include "WebBrowser2.h"


// 생성자
CExplorerPopup::CExplorerPopup()
{
	// 웹브라우저 윈도우 핸들 초기화
	m_hExplorer = NULL;
}

// 소멸자
CExplorerPopup::~CExplorerPopup()
{
	// OpenNewWindowEx()로 생성된 웹브라우저가 아직 안 닫혔으면 
	if(m_hExplorer)
	{
		if(::IsWindow(m_hExplorer))
		{
			// WM_CLOSE 메시지를 보내서 종료시킨다
			::PostMessage(m_hExplorer, WM_CLOSE, 0, 0);
		}
	}
}

// ShellExecute()를 사용하여 사이트를 여는 함수
BOOL CExplorerPopup::OpenByShellExecute(LPCTSTR pAddress)
{
	// ShellExecute()의 "open" 명령을 통해 사이트를 연다
	return ((int)::ShellExecute(NULL, "open", pAddress, NULL, NULL, SWP_SHOWWINDOW) > 32);
}

// IWebBrowser2를 사용하여 사이트를 여는 함수
BOOL CExplorerPopup::OpenNewWindow(LPCTSTR pAddress)
{
	IWebBrowser2 *pWebBrowser;
	HRESULT hr;

	// 웹브라우저 객체를 생성한다.
	hr = ::CoCreateInstance(CLSID_InternetExplorer, NULL, CLSCTX_LOCAL_SERVER, IID_IWebBrowser2, (void**)&pWebBrowser);
	if(FAILED(hr) || pWebBrowser == NULL)	return FALSE;

	CString strAddress = pAddress;

	// Navigate()에 필요한 인자들을 초기화한다
	VARIANT vtFlags, vtTarget, vtPostData, vtHeader;
	::VariantInit(&vtFlags);
	::VariantInit(&vtTarget);
	::VariantInit(&vtPostData);
	::VariantInit(&vtHeader);

	// 웹브라우저를 화면에 보이게 한다
	pWebBrowser->put_Visible(VARIANT_TRUE);
	// 사이트를 연다
	hr = pWebBrowser->Navigate(strAddress.AllocSysString(), &vtFlags, &vtTarget, &vtPostData, &vtHeader);

	// 웹브라우저 인터페이스의 참조 횟수를 줄인다
	pWebBrowser->Release();

	return SUCCEEDED(hr);
}

// CWebBrowser2 클래스를 사용하여 사이트를 여는 함수
BOOL CExplorerPopup::OpenNewWindow(LPCTSTR pAddress, CWebBrowser2 *pBrowser)
{
	// 새창으로 열기 옵션을 설정한다
	VARIANT vtFlags;
	vtFlags.vt			= VT_I4;
	vtFlags.lVal		= navOpenInNewWindow;

	// 웹브라우저 컨트롤에게 사이트를 열게 한다
	pBrowser->Navigate(pAddress, &vtFlags, NULL, NULL, NULL);

	return TRUE;
}

// IWebBrowser2를 사용하여 웹브라우저를 생성하고 옵션 설정 후 사이트를 여는 함수
BOOL CExplorerPopup::OpenNewWindowEx(LPCTSTR pAddress, BOOL bMenu, BOOL bToolBar,
		BOOL bAddressBar, BOOL bStatusBar, BOOL bResize,
		int x, int y, int cx, int cy)
{
	// OpenNewWindowEx()에 의해 생성된 웹브라우저 있다면 리턴한다
	if(m_hExplorer)			return FALSE;

	IWebBrowser2 *pWebBrowser;
	HRESULT hr;

	// 웹브라우저 객체를 생성한다.
	hr = ::CoCreateInstance(CLSID_InternetExplorer, NULL, CLSCTX_LOCAL_SERVER, IID_IWebBrowser2, (void**)&pWebBrowser);
	if(FAILED(hr) || pWebBrowser == NULL)	return FALSE;

	// 메뉴바를 출력할지 설정한다
	pWebBrowser->put_MenuBar(bMenu ? VARIANT_TRUE : VARIANT_FALSE);
	// 툴바를 출력할지 설정한다
	pWebBrowser->put_ToolBar(bToolBar ? VARIANT_TRUE : VARIANT_FALSE);
	// 주소창을 출력할지 설정한다
	pWebBrowser->put_AddressBar(bAddressBar ? VARIANT_TRUE : VARIANT_FALSE);
	// 상태바를 출력할지 설정한다
	pWebBrowser->put_StatusBar(bStatusBar ? VARIANT_TRUE : VARIANT_FALSE);
	// 크기 조절을 가능하게 할지 설정한다
	pWebBrowser->put_Resizable(bResize ? VARIANT_TRUE : VARIANT_FALSE);

	// 웹브라우저의 위치와 크기를 설정한다
	if(x >= 0)		pWebBrowser->put_Left(x);
	if(y >= 0)		pWebBrowser->put_Top(y);
	if(cx >= 0)		pWebBrowser->put_Width(cx);
	if(cy >= 0)		pWebBrowser->put_Height(cy);

	CString strAddress = pAddress;

	// Navigate()에 필요한 인자들을 초기화한다
	VARIANT vtFlags, vtTarget, vtPostData, vtHeader;
	::VariantInit(&vtFlags);
	::VariantInit(&vtTarget);
	::VariantInit(&vtPostData);
	::VariantInit(&vtHeader);

	// 웹브라우저를 화면에 보이게 한다
	pWebBrowser->put_Visible(VARIANT_TRUE);
	// 사이트를 연다
	hr = pWebBrowser->Navigate(strAddress.AllocSysString(), &vtFlags, &vtTarget, &vtPostData, &vtHeader);
	if(FAILED(hr))		return FALSE;

	// 웹브라우저의 윈도우 핸들을 얻는다
	hr = pWebBrowser->get_HWND((long*)&m_hExplorer);
	// 웹브라우저 인터페이스의 참조 횟수를 줄인다
	pWebBrowser->Release();

	return SUCCEEDED(hr);
}

BOOL CExplorerPopup::CloseExplorer()
{
	BOOL bSuccess = FALSE;

	// OpenNewWindowEx()로 생성된 웹브라우저가 존재하고 아직 윈도우라면 
	if(m_hExplorer)
	{
		if(::IsWindow(m_hExplorer))
		{
			// WM_CLOSE 메시지를 보내서 종료시킨다
			::PostMessage(m_hExplorer, WM_CLOSE, 0, 0);
			bSuccess = TRUE;
		}
	}

	// 웹브라우저 윈도우 핸들 변수를 초기화한다
	m_hExplorer = NULL;

	return bSuccess;
}
