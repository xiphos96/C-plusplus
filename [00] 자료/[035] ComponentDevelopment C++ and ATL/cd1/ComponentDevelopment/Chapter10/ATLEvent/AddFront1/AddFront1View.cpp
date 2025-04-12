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
		MessageBox("�̺�Ʈ�� ���� �� �����ϴ�.", "�̺�Ʈ ����");
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
		CString szMsg = "������ �߻��߽��ϴ�!\n";
		CString szTemp;
			
		szTemp.Format("���� �ڵ� : %081x\n", e.Error());
		szMsg += szTemp;
		szTemp.Format("���� ���� : %s\n", e.ErrorMessage());
		szMsg += szTemp;
		szTemp.Format("���� �ҽ� : %s\n",
			bstrSource.length() ? (LPCTSTR)bstrSource : _T("����"));
		szMsg += szTemp;
		szTemp.Format("���� ���� : %s\n",
			bstrDescription.length() ? (LPCTSTR)bstrDescription : _T("����"));
		szMsg += szTemp;
		MessageBox(szMsg.GetBuffer(szMsg.GetLength()), "���� �߻�");
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
