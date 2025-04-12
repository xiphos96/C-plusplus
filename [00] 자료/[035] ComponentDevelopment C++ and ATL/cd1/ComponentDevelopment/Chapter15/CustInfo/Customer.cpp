// Customer.cpp : CCustomer의 구현입니다.
#include "stdafx.h"
#include "Customer.h"
#include ".\customer.h"


// CCustomer

LRESULT CCustomer::OnChangedCustName(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	char name[128];
	GetDlgItemText(IDC_CUSTNAME, name, 127);
	m_name = name;
	__raise ChangedCustName(m_name);
	return 0;
}

LRESULT CCustomer::OnChangedCustAddr(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	char addr[128];
	GetDlgItemText(IDC_CUSTADDR, addr, 127);
	m_addr = addr;
	__raise ChangedCustAddr(m_addr);
	return 0;
}

LRESULT CCustomer::OnChangedCustTelno(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	char telno[128];
	GetDlgItemText(IDC_CUSTTELNO, telno, 127);
	m_telno = telno;
	__raise ChangedCustTelno(m_telno);
	return 0;
}

STDMETHODIMP CCustomer::get_CustName(BSTR* pVal)
{
	*pVal = m_name.copy();
	return S_OK;
}

STDMETHODIMP CCustomer::put_CustName(BSTR newVal)
{
	m_name = newVal;
	SetDlgItemText(IDC_CUSTNAME, m_name);
	return S_OK;
}

STDMETHODIMP CCustomer::get_CustAddr(BSTR* pVal)
{
	*pVal = m_addr.copy();
	return S_OK;
}

STDMETHODIMP CCustomer::put_CustAddr(BSTR newVal)
{
	m_addr = newVal;
	SetDlgItemText(IDC_CUSTADDR, m_addr);
	return S_OK;
}

STDMETHODIMP CCustomer::get_CustTelno(BSTR* pVal)
{
	*pVal = m_telno.copy();
	return S_OK;
}

STDMETHODIMP CCustomer::put_CustTelno(BSTR newVal)
{
	m_telno = newVal;
	SetDlgItemText(IDC_CUSTTELNO, m_telno);
	return S_OK;
}
