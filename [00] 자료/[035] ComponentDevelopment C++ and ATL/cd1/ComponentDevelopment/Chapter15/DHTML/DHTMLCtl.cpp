// DHTMLCtl.cpp : CDHTMLCtl�� �����Դϴ�.
#include "stdafx.h"
#include "DHTMLCtl.h"
#include ".\dhtmlctl.h"


// CDHTMLCtl

STDMETHODIMP CDHTMLCtl::get_UrlPath(BSTR* pVal)
{
	m_urlpath.CopyTo(pVal);
	return S_OK;
}

STDMETHODIMP CDHTMLCtl::put_UrlPath(BSTR newVal)
{
	m_urlpath = newVal;
	return S_OK;
}

STDMETHODIMP CDHTMLCtl::GoToURL(void)
{
	m_spBrowser->Navigate(m_urlpath, NULL, NULL, NULL, NULL);
	return S_OK;
}

STDMETHODIMP CDHTMLCtlUI::GoTo(void)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_pCtrl->GoToURL();
	return S_OK;
}
