#include "stdafx.h"
#include "ExplorerPopup.h"

// �������� Ŭ������ ���� ���
#include "WebBrowser2.h"


// ������
CExplorerPopup::CExplorerPopup()
{
	// �������� ������ �ڵ� �ʱ�ȭ
	m_hExplorer = NULL;
}

// �Ҹ���
CExplorerPopup::~CExplorerPopup()
{
	// OpenNewWindowEx()�� ������ ���������� ���� �� �������� 
	if(m_hExplorer)
	{
		if(::IsWindow(m_hExplorer))
		{
			// WM_CLOSE �޽����� ������ �����Ų��
			::PostMessage(m_hExplorer, WM_CLOSE, 0, 0);
		}
	}
}

// ShellExecute()�� ����Ͽ� ����Ʈ�� ���� �Լ�
BOOL CExplorerPopup::OpenByShellExecute(LPCTSTR pAddress)
{
	// ShellExecute()�� "open" ����� ���� ����Ʈ�� ����
	return ((int)::ShellExecute(NULL, "open", pAddress, NULL, NULL, SWP_SHOWWINDOW) > 32);
}

// IWebBrowser2�� ����Ͽ� ����Ʈ�� ���� �Լ�
BOOL CExplorerPopup::OpenNewWindow(LPCTSTR pAddress)
{
	IWebBrowser2 *pWebBrowser;
	HRESULT hr;

	// �������� ��ü�� �����Ѵ�.
	hr = ::CoCreateInstance(CLSID_InternetExplorer, NULL, CLSCTX_LOCAL_SERVER, IID_IWebBrowser2, (void**)&pWebBrowser);
	if(FAILED(hr) || pWebBrowser == NULL)	return FALSE;

	CString strAddress = pAddress;

	// Navigate()�� �ʿ��� ���ڵ��� �ʱ�ȭ�Ѵ�
	VARIANT vtFlags, vtTarget, vtPostData, vtHeader;
	::VariantInit(&vtFlags);
	::VariantInit(&vtTarget);
	::VariantInit(&vtPostData);
	::VariantInit(&vtHeader);

	// ���������� ȭ�鿡 ���̰� �Ѵ�
	pWebBrowser->put_Visible(VARIANT_TRUE);
	// ����Ʈ�� ����
	hr = pWebBrowser->Navigate(strAddress.AllocSysString(), &vtFlags, &vtTarget, &vtPostData, &vtHeader);

	// �������� �������̽��� ���� Ƚ���� ���δ�
	pWebBrowser->Release();

	return SUCCEEDED(hr);
}

// CWebBrowser2 Ŭ������ ����Ͽ� ����Ʈ�� ���� �Լ�
BOOL CExplorerPopup::OpenNewWindow(LPCTSTR pAddress, CWebBrowser2 *pBrowser)
{
	// ��â���� ���� �ɼ��� �����Ѵ�
	VARIANT vtFlags;
	vtFlags.vt			= VT_I4;
	vtFlags.lVal		= navOpenInNewWindow;

	// �������� ��Ʈ�ѿ��� ����Ʈ�� ���� �Ѵ�
	pBrowser->Navigate(pAddress, &vtFlags, NULL, NULL, NULL);

	return TRUE;
}

// IWebBrowser2�� ����Ͽ� ���������� �����ϰ� �ɼ� ���� �� ����Ʈ�� ���� �Լ�
BOOL CExplorerPopup::OpenNewWindowEx(LPCTSTR pAddress, BOOL bMenu, BOOL bToolBar,
		BOOL bAddressBar, BOOL bStatusBar, BOOL bResize,
		int x, int y, int cx, int cy)
{
	// OpenNewWindowEx()�� ���� ������ �������� �ִٸ� �����Ѵ�
	if(m_hExplorer)			return FALSE;

	IWebBrowser2 *pWebBrowser;
	HRESULT hr;

	// �������� ��ü�� �����Ѵ�.
	hr = ::CoCreateInstance(CLSID_InternetExplorer, NULL, CLSCTX_LOCAL_SERVER, IID_IWebBrowser2, (void**)&pWebBrowser);
	if(FAILED(hr) || pWebBrowser == NULL)	return FALSE;

	// �޴��ٸ� ������� �����Ѵ�
	pWebBrowser->put_MenuBar(bMenu ? VARIANT_TRUE : VARIANT_FALSE);
	// ���ٸ� ������� �����Ѵ�
	pWebBrowser->put_ToolBar(bToolBar ? VARIANT_TRUE : VARIANT_FALSE);
	// �ּ�â�� ������� �����Ѵ�
	pWebBrowser->put_AddressBar(bAddressBar ? VARIANT_TRUE : VARIANT_FALSE);
	// ���¹ٸ� ������� �����Ѵ�
	pWebBrowser->put_StatusBar(bStatusBar ? VARIANT_TRUE : VARIANT_FALSE);
	// ũ�� ������ �����ϰ� ���� �����Ѵ�
	pWebBrowser->put_Resizable(bResize ? VARIANT_TRUE : VARIANT_FALSE);

	// ���������� ��ġ�� ũ�⸦ �����Ѵ�
	if(x >= 0)		pWebBrowser->put_Left(x);
	if(y >= 0)		pWebBrowser->put_Top(y);
	if(cx >= 0)		pWebBrowser->put_Width(cx);
	if(cy >= 0)		pWebBrowser->put_Height(cy);

	CString strAddress = pAddress;

	// Navigate()�� �ʿ��� ���ڵ��� �ʱ�ȭ�Ѵ�
	VARIANT vtFlags, vtTarget, vtPostData, vtHeader;
	::VariantInit(&vtFlags);
	::VariantInit(&vtTarget);
	::VariantInit(&vtPostData);
	::VariantInit(&vtHeader);

	// ���������� ȭ�鿡 ���̰� �Ѵ�
	pWebBrowser->put_Visible(VARIANT_TRUE);
	// ����Ʈ�� ����
	hr = pWebBrowser->Navigate(strAddress.AllocSysString(), &vtFlags, &vtTarget, &vtPostData, &vtHeader);
	if(FAILED(hr))		return FALSE;

	// ���������� ������ �ڵ��� ��´�
	hr = pWebBrowser->get_HWND((long*)&m_hExplorer);
	// �������� �������̽��� ���� Ƚ���� ���δ�
	pWebBrowser->Release();

	return SUCCEEDED(hr);
}

BOOL CExplorerPopup::CloseExplorer()
{
	BOOL bSuccess = FALSE;

	// OpenNewWindowEx()�� ������ ���������� �����ϰ� ���� �������� 
	if(m_hExplorer)
	{
		if(::IsWindow(m_hExplorer))
		{
			// WM_CLOSE �޽����� ������ �����Ų��
			::PostMessage(m_hExplorer, WM_CLOSE, 0, 0);
			bSuccess = TRUE;
		}
	}

	// �������� ������ �ڵ� ������ �ʱ�ȭ�Ѵ�
	m_hExplorer = NULL;

	return bSuccess;
}
