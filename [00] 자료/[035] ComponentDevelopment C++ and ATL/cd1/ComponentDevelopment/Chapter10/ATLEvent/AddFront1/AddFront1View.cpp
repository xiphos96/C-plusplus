#include "StdAfx.h"
#include ".\AddFront1view.h"
#include <atlmisc.h>
#include "EventHandler.h"

LRESULT CAddFront1View::OnInitDialog(UINT, WPARAM, LPARAM, BOOL&)
{
	m_pAddBack = IAddBackPtr(__uuidof(AddBack));

	HRESULT hr;
	CComObject<CEventHandler>* pHandler;
	CComObject<CEventHandler>::CreateInstance(&pHandler);
	hr = AtlAdvise(m_pAddBack,
				   pHandler->GetUnknown(),
				   IID_IAddBackEvents,
				   &m_Cookie);
	if(FAILED(hr)) {
		MessageBox("이벤트를 받을 수 없습니다.", "이벤트 에러");
		return 0;
	}

	m_AddEnd = m_pAddBack->AddEnd;
	m_Sum = m_pAddBack->Sum;
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFront1View::OnDestroy(UINT, WPARAM, LPARAM, BOOL&)
{
	AtlUnadvise(m_pAddBack, IID_IAddBackEvents, m_Cookie);
	return 0;
}

LRESULT CAddFront1View::OnBnClickedAdd(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
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

LRESULT CAddFront1View::OnBnClickedAddten(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	m_pAddBack->AddTen();
	m_Sum = m_pAddBack->Sum;
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CAddFront1View::OnBnClickedClear(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	m_pAddBack->Clear();
	m_Sum = m_pAddBack->Sum;
	DoDataExchange(FALSE);
	return 0;
}
