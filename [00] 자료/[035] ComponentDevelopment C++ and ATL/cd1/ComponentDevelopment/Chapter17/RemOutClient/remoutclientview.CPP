#include "StdAfx.h"
#include ".\remoutclientview.h"
#include <atlmisc.h>

LRESULT CRemOutClientView::OnCreateServer(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	HRESULT hr;

	memset(&svrInfo, 0, sizeof(svrInfo));
	svrInfo.pwszName = L"NTSERVER";

	mqi[0].pIID = &IID_IAddEnd;
	mqi[0].pItf = NULL;
	mqi[0].hr = S_OK;
	mqi[1].pIID = &IID_IAdd;
	mqi[1].pItf = NULL;
	mqi[1].hr = S_OK;

	DoDataExchange(TRUE);

	try {
		if(m_nInterfaceType == 0) { // 하나씩 요청
			m_pAddEnd = IAddEndPtr(__uuidof(RemOutServer));
			m_pAdd = m_pAddEnd;
		}
		else {	// 한꺼번에 요청
			hr = ::CoCreateInstanceEx(
						__uuidof(RemOutServer),
						NULL,
						CLSCTX_REMOTE_SERVER,
						&svrInfo,
						2,
						&mqi[0]);
			if(FAILED(hr)) {
				_com_issue_error(hr);
			}
			m_pAddEnd = mqi[0].pItf;
			m_pAdd = mqi[1].pItf;
		}
		m_nAddEnd = m_pAddEnd->AddEnd;
		m_nSum = m_pAddEnd->Sum;
	}
	catch(_com_error& e) {
		ShowMessage(e);
	}

	DoDataExchange(FALSE);
	return 0;
}

LRESULT CRemOutClientView::OnReleaseServer(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	for(int i = 0; i < 2; i++) {
		if(mqi[i].pItf != NULL && SUCCEEDED(mqi[i].hr)) {
			mqi[i].pItf->Release();
			mqi[i].pItf = NULL;
		}
	}
	m_pAddEnd = 0;
	m_pAdd = 0;
	return 0;
}

LRESULT CRemOutClientView::OnAdd(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DoDataExchange(TRUE);
	try {
		m_pAddEnd->AddEnd = m_nAddEnd;
		m_pAdd->Add();
		m_nSum = m_pAddEnd->Sum;
	}
	catch(_com_error& e) {
		ShowMessage(e);
	}
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CRemOutClientView::OnAddTen(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DoDataExchange(TRUE);
	try {
		m_pAddEnd->AddEnd = m_nAddEnd;
		m_pAdd->AddTen();
		m_nSum = m_pAddEnd->Sum;
	}
	catch(_com_error& e) {
		ShowMessage(e);
	}
	DoDataExchange(FALSE);
	return 0;
}

LRESULT CRemOutClientView::OnClear(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DoDataExchange(TRUE);
	try {
		m_pAddEnd->AddEnd = m_nAddEnd;
		m_pAddEnd->Clear();
		m_nSum = m_pAddEnd->Sum;
	}
	catch(_com_error& e) {
		ShowMessage(e);
	}
	DoDataExchange(FALSE);
	return 0;
}

void CRemOutClientView::ShowMessage(_com_error & e)
{
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
