// AddBacko.cpp : CAddBack의 구현입니다.

#include "stdafx.h"
#include "AddBacko.h"
#include ".\addbacko.h"


// CAddBack


STDMETHODIMP CAddBack::Add(void)
{
	m_Sum += m_AddEnd;
	__raise ChangedSum(m_Sum);
	return S_OK;
}

STDMETHODIMP CAddBack::AddTen(void)
{
	m_Sum += 10;
	_IAddBackEvents_ChangedSum(m_Sum);
	return S_OK;
}

STDMETHODIMP CAddBack::Clear(void)
{
	m_Sum = 0;
	__raise ChangedSum(m_Sum);
	return S_OK;
}

STDMETHODIMP CAddBack::get_AddEnd(SHORT* pVal)
{
	*pVal = m_AddEnd;
	return S_OK;
}

STDMETHODIMP CAddBack::put_AddEnd(SHORT newVal)
{
	m_AddEnd = newVal;
	__raise ChangedAddEnd(m_AddEnd);
	return S_OK;
}

STDMETHODIMP CAddBack::get_Sum(SHORT* pVal)
{
	*pVal = m_Sum;
	return S_OK;
}
