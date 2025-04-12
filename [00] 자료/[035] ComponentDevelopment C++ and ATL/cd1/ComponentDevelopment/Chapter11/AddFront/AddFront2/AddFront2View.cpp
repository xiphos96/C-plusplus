#include "StdAfx.h"
#include ".\AddFront2view.h"

LRESULT CAddFront2View::OnInitDialog(UINT, WPARAM, LPARAM, BOOL&)
{
	m_pAddBack = IAddBackPtr(__uuidof(CAddBack));
    m_pAddEnd = m_pAddBack;
	m_AddEnd = m_pAddEnd->AddEnd;
	m_Sum = m_pAddEnd->Sum;
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFront2View::OnBnClickedAdd(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DoDataExchange(TRUE);
	m_pAddEnd->AddEnd = m_AddEnd;
	m_pAddBack->Add();
	m_Sum = m_pAddEnd->Sum;
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFront2View::OnBnClickedAddten(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	m_pAddBack->AddTen();
	m_Sum = m_pAddEnd->Sum;
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFront2View::OnBnClickedClear(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	m_pAddEnd->Clear();
	m_Sum = m_pAddEnd->Sum;
	DoDataExchange(FALSE);
	return 0;
}
