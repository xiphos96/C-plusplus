// RemOutObj.cpp : CRemOutObj의 구현입니다.

#include "stdafx.h"
#include "RemOutObj.h"


// CRemOutServer

STDMETHODIMP CRemOutServer::get_AddEnd(SHORT* pVal)
{
	*pVal = m_addend;
	return S_OK;
}

STDMETHODIMP CRemOutServer::put_AddEnd(SHORT newVal)
{
	m_addend = newVal;
	return S_OK;
}

STDMETHODIMP CRemOutServer::get_Sum(SHORT* pVal)
{
	*pVal = m_sum;
	return S_OK;
}

STDMETHODIMP CRemOutServer::Clear(void)
{
	m_sum = 0;
	return S_OK;
}

STDMETHODIMP CRemOutServer::Add(void)
{
	m_sum += m_addend;
	return S_OK;
}

STDMETHODIMP CRemOutServer::AddTen(void)
{
	m_sum += 10;
	return S_OK;
}
