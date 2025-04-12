// AddEndo.cpp : CAddEnd의 구현입니다.

#include "stdafx.h"
#include "AddEndo.h"
#include ".\addendo.h"


// CAddEnd


STDMETHODIMP CAddEnd::get_AddEnd(SHORT* pVal)
{
	*pVal = m_AddEnd;
	return S_OK;
}

STDMETHODIMP CAddEnd::put_AddEnd(SHORT newVal)
{
	m_AddEnd = newVal;
	return S_OK;
}

STDMETHODIMP CAddEnd::put_Sum(SHORT newVal)
{
	m_Sum = newVal;
	return S_OK;
}

STDMETHODIMP CAddEnd::get_Sum(SHORT* pVal)
{
	*pVal = m_Sum;
	return S_OK;
}

STDMETHODIMP CAddEnd::Clear(void)
{
	m_Sum = 0;
	return S_OK;
}
