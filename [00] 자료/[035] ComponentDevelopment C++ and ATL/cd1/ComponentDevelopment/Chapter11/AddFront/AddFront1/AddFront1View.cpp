#include "StdAfx.h"
#include ".\AddFront1view.h"

LRESULT CAddFront1View::OnInitDialog(UINT, WPARAM, LPARAM, BOOL&)
{
	m_pAddBack = IAddBackPtr(__uuidof(CAddBack));
	m_pAddEnd = m_pAddBack;
	m_AddEnd = m_pAddEnd->AddEnd;
	m_Sum = m_pAddEnd->Sum;
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFront1View::OnBnClickedAdd(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DoDataExchange(TRUE);
	m_pAddEnd->AddEnd = m_AddEnd;
	m_pAddBack->Add();
	m_Sum = m_pAddEnd->Sum;

	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFront1View::OnBnClickedAddten(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	m_pAddBack->AddTen();
	m_Sum = m_pAddEnd->Sum;
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFront1View::OnBnClickedClear(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	m_pAddEnd->Clear();
	m_Sum = m_pAddEnd->Sum;
	DoDataExchange(FALSE);
	return 0;
}
