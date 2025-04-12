// UpDownCtl.cpp : CUpDownCtl의 구현입니다.
#include "stdafx.h"
#include "UpDownCtl.h"
#include ".\updownctl.h"


// CUpDownCtl

STDMETHODIMP CUpDownCtl::get_MinValue(short* pVal)
{
	*pVal = m_minvalue;
	return S_OK;
}

STDMETHODIMP CUpDownCtl::put_MinValue(short newVal)
{
	if(newVal <= m_maxvalue) {
		m_minvalue = newVal;
		SetRange(m_minvalue, m_maxvalue);
	}
	return S_OK;
}

STDMETHODIMP CUpDownCtl::get_MaxValue(short* pVal)
{
	*pVal = m_maxvalue;
	return S_OK;
}

STDMETHODIMP CUpDownCtl::put_MaxValue(short newVal)
{
	if(newVal > m_minvalue) {
		m_maxvalue = newVal;
		SetRange(m_minvalue, m_maxvalue);
	}
	return S_OK;
}

STDMETHODIMP CUpDownCtl::get_Value(short* pVal)
{
	*pVal = m_value;
	return S_OK;
}

STDMETHODIMP CUpDownCtl::put_Value(short newVal)
{
	m_value = newVal;
	SetDlgItemInt(IDC_TEXT, m_value);
	return S_OK;
}

LRESULT CUpDownCtl::OnChangeValue(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	__raise Changed((short)GetDlgItemInt(IDC_TEXT));
	return 0;
}
