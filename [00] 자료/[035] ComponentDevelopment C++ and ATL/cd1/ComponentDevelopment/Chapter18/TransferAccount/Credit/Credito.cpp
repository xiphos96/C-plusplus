// Credito.cpp : Implementation of CCredit

#include "stdafx.h"
#include "Credito.h"
#include "Account.h"

// CCredit


STDMETHODIMP CCredit::ChangeAccount(long accountID, long amount)
{
	// TODO: Add your implementation code here
/*
		USES_CONVERSION;
		HANDLE hFile = ::CreateFile("Credit_Log.log", 
							 GENERIC_WRITE, 
							 FILE_SHARE_WRITE,
							 NULL,
							 OPEN_ALWAYS,
							 FILE_FLAG_SEQUENTIAL_SCAN,
							 NULL);
		DWORD dwBytes;
		::WriteFile(hFile, "시작", 5, &dwBytes, NULL);
*/

	HRESULT hr;
	IObjectContext* pIContext = NULL;
	::CoGetObjectContext(IID_IObjectContext, (LPVOID*)&pIContext);

	CAccount rs;
	rs.OpenAll();
	hr = rs.MoveFirst();
	while(hr == S_OK) {
		if(rs.m_AccountID == accountID)
			break;
		hr = rs.MoveNext();
	}
	if(hr == S_OK) {
		rs.m_Balance += amount;
		rs.SetData();
		rs.Update();
		pIContext->SetComplete();
/*
		::WriteFile(hFile, "성공", 5, &dwBytes, NULL);
*/
	}
	else {
		pIContext->SetAbort();
/*
		::WriteFile(hFile, "실패", 5, &dwBytes, NULL);
*/
	}
	rs.CloseAll();
	pIContext->Release();


/*
		::WriteFile(hFile, "끝", 5, &dwBytes, NULL);
		::CloseHandle(hFile);
*/

	return S_OK;
}
