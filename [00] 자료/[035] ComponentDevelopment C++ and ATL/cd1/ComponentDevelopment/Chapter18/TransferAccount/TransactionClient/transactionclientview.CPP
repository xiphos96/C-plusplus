#include "StdAfx.h"
#include ".\transactionclientview.h"
#include <atlmisc.h>

#import "progid:Transfer.Transfer.1" no_namespace

LRESULT CTransactionClientView::TransferMoney(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DoDataExchange(TRUE);
	try {
		ITransferPtr pITransfer = ITransferPtr(__uuidof(Transfer));
		pITransfer->MoveMoney(m_srcAccount, m_destAccount, m_amount);
		MessageBox("계좌 이체가 성공적으로 이루어졌습니다.", "계좌 이체 성공");
	}
	catch(_com_error& e) {
		CString str;
		str.Format("%s", e.ErrorMessage());
		MessageBox(str.GetBuffer(str.GetLength()), "에러 발생");
	}

	return 0;
}
