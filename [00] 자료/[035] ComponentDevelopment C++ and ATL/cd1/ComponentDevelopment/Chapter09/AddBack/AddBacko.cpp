// AddBacko.cpp : CAddBack의 구현입니다.

#include "stdafx.h"
#include "AddBacko.h"
#include ".\addbacko.h"


// CAddBack


STDMETHODIMP CAddBack::Add(void)
{
	m_Sum += m_AddEnd;
	return S_OK;
}

STDMETHODIMP CAddBack::AddTen(void)
{
	m_Sum += 10;
	return S_OK;
}

STDMETHODIMP CAddBack::Clear(void)
{
	m_Sum = 0;
	return S_OK;
}

STDMETHODIMP CAddBack::get_AddEnd(SHORT* pVal)
{
	*pVal = m_AddEnd;
	return S_OK;
}

STDMETHODIMP CAddBack::put_AddEnd(SHORT newVal)
{
	HRESULT hr;
	if(newVal < 1) {
		CComPtr<ICreateErrorInfo> pCreateErrInfo;
		CComQIPtr<IErrorInfo, &IID_IErrorInfo> pErrorInfo;

		hr = ::CreateErrorInfo(&pCreateErrInfo);
		if(SUCCEEDED(hr)) {
			pCreateErrInfo->SetSource(L"AddBack.AddBack.1");
			pCreateErrInfo->SetDescription(L"0 보다 큰 값을 입력하십시오!");
			pErrorInfo = pCreateErrInfo;
			::SetErrorInfo(0, pErrorInfo);
		}
		return E_INVALIDARG;
	}
	m_AddEnd = newVal;
	return S_OK;
}

STDMETHODIMP CAddBack::get_Sum(SHORT* pVal)
{
	*pVal = m_Sum;
	return S_OK;
}
