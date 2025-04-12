// DHTMLCtl.cpp : CDHTMLCtl의 구현입니다.
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
	// TODO: 여기에 구현 코드를 추가합니다.

	m_pCtrl->GoToURL();
	return S_OK;
}
