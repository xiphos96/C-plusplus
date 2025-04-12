// AddBack.cpp : CAddBack의 구현입니다.

#include "stdafx.h"
#include "AddBack.h"
#include ".\addback.h"


// CAddBack


STDMETHODIMP CAddBack::Add(void)
{
	SHORT sum, addend;
	m_pAddEnd->get_AddEnd(&addend);
	m_pAddEnd->get_Sum(&sum);
	sum += addend;
	m_pAddEnd->put_Sum(sum);
	return S_OK;
}

STDMETHODIMP CAddBack::AddTen(void)
{
	SHORT sum;
	m_pAddEnd->get_Sum(&sum);
	sum += 10;
	m_pAddEnd->put_Sum(sum);
	return S_OK;
}

STDMETHODIMP CAddBack::get_AddEnd(SHORT* pVal)
{
	m_pAddEnd->get_AddEnd(pVal);
	return S_OK;
}

STDMETHODIMP CAddBack::put_AddEnd(SHORT newVal)
{
	m_pAddEnd->put_AddEnd(newVal);
	return S_OK;
}

STDMETHODIMP CAddBack::get_Sum(SHORT* pVal)
{
	m_pAddEnd->get_Sum(pVal);
	return S_OK;
}

STDMETHODIMP CAddBack::Clear(void)
{
	m_pAddEnd->Clear();
	return S_OK;
}