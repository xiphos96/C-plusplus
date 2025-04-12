// RemInObj.cpp : CRemInServer의 구현입니다.

#include "stdafx.h"
#include "RemInObj.h"


// CRemInServer

STDMETHODIMP CRemInServer::get_AddEnd(SHORT* pVal)
{
	*pVal = m_addend;
	return S_OK;
}

STDMETHODIMP CRemInServer::put_AddEnd(SHORT newVal)
{
	m_addend = newVal;
	return S_OK;
}

STDMETHODIMP CRemInServer::get_Sum(SHORT* pVal)
{
	*pVal = m_sum;
	return S_OK;
}

STDMETHODIMP CRemInServer::Clear(void)
{
	m_sum = 0;
	return S_OK;
}

STDMETHODIMP CRemInServer::Add(void)
{
	m_sum += m_addend;
	return S_OK;
}

STDMETHODIMP CRemInServer::AddTen(void)
{
	m_sum += 10;
	return S_OK;
}

