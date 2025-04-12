#include "StdAfx.h"
#include ".\maindlg.h"

LRESULT CAddFrontDlg::OnBnClickedButton1(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DoDataExchange(TRUE);
	m_pIAddBack->Add(m_addend);
	m_sum = m_pIAddBack->getSum();
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFrontDlg::OnBnClickedButton2(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DoDataExchange(TRUE);
	m_sum = m_pIAddBack_Stateless->Add(m_addend, m_sum);
	DoDataExchange(FALSE);
	return 0;
}
