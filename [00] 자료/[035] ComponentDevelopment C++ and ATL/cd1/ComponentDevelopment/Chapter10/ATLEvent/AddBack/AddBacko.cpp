// AddBacko.cpp : CAddBack�� �����Դϴ�.

#include "stdafx.h"
#include "AddBacko.h"
#include ".\addbacko.h"


// CAddBack

STDMETHODIMP CAddBack::Add(void)
{
	m_Sum += m_AddEnd;
	FireChangedSum();
	return S_OK;
}

STDMETHODIMP CAddBack::AddTen(void)
{
	m_Sum += 10;
	FireChangedSum();
	return S_OK;
}

STDMETHODIMP CAddBack::Clear(void)
{
	m_Sum = 0;
	FireChangedSum();
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
	FireChangedAddEnd();
	return S_OK;
}

STDMETHODIMP CAddBack::get_Sum(SHORT* pVal)
{
	*pVal = m_Sum;
	return S_OK;
}
