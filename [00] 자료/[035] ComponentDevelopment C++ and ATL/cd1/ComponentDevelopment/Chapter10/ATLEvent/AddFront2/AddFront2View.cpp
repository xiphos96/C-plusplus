#include "StdAfx.h"
#include <atlmisc.h>
#include "EventHandler.h"
#include ".\AddFront2view.h"

LRESULT CAddFront2View::OnInitDialog(UINT, WPARAM, LPARAM, BOOL&)
{
	m_pAddBack = IAddBackPtr(__uuidof(AddBack));

	CComObject<CEventHandler>::CreateInstance(&m_pHandler);
	m_pHandler->HookEvent(m_pAddBack);

	m_AddEnd = m_pAddBack->AddEnd;
	m_Sum = m_pAddBack->Sum;
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFront2View::OnDestroy(UINT, WPARAM, LPARAM, BOOL&)
{
	m_pHandler->UnHookEvent(m_pAddBack);
	return 0;
}

LRESULT CAddFront2View::OnBnClickedAdd(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DoDataExchange(TRUE);
	try {
		m_pAddBack->AddEnd = m_AddEnd;
		m_pAddBack->Add();
		m_Sum = m_pAddBack->Sum;
	}
	catch(_com_error &e) {
		_bstr_t bstrSource(e.Source());
		_bstr_t bstrDescription(e.Description());
		CString szMsg = "에러가 발생했습니다!\n";
		CString szTemp;
			
		szTemp.Format("에러 코드 : %081x\n", e.Error());
		szMsg += szTemp;
		szTemp.Format("에러 내용 : %s\n", e.ErrorMessage());
		szMsg += szTemp;
		szTemp.Format("에러 소스 : %s\n",
			bstrSource.length() ? (LPCTSTR)bstrSource : _T("없음"));
		szMsg += szTemp;
		szTemp.Format("에러 설명 : %s\n",
			bstrDescription.length() ? (LPCTSTR)bstrDescription : _T("없음"));
		szMsg += szTemp;
		MessageBox(szMsg.GetBuffer(szMsg.GetLength()), "에러 발생");
	}
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFront2View::OnBnClickedAddten(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	m_pAddBack->AddTen();
	m_Sum = m_pAddBack->Sum;
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFront2View::OnBnClickedClear(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	m_pAddBack->Clear();
	m_Sum = m_pAddBack->Sum;
	DoDataExchange(FALSE);
	return 0;
}
