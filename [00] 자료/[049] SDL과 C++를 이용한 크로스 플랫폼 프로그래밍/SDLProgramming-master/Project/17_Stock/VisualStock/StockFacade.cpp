#include "stdafx.h"
#include <Windows.h>
#include "StockFacade.h"
#include "IXingAPI.h"
#include "IRequestCallback.h"
//Xing�� ����ϱ� ���Ͽ� ���Ǵ� ����� Packet ������ ����
#include "./Packet/t8407.h"		
#include "./Packet/t8413.h"
#include "./Packet/t8430.h"
#include "./Packet/t1302.h"
#include "Company.h"
#include "StockManager.h"

StockFacade* StockFacade::m_pStockFacade = NULL;

StockFacade* StockFacade::GetInstance()
{
	if (m_pStockFacade == NULL)
		m_pStockFacade = new StockFacade();

	return m_pStockFacade;
}

StockFacade::StockFacade()
: m_pCallback(NULL)
{
	m_pXingAPI = new IXingAPI();
	m_hWnd = 0;
	m_bFirstT8430Req = false;
	m_pStockManager = new StockManager();

	CTime curTime;
	curTime  = CTime::GetCurrentTime();
	m_date = curTime.Format("%Y%m%d");
}

StockFacade::~StockFacade()
{
}


bool StockFacade::Initialize()
{

	return true;
}

bool StockFacade::Connect(HWND hWnd, char* szID, char* szPassword)
{
	m_hWnd = hWnd;

	if (m_pXingAPI->Init() == FALSE) {
		CStringA strPath;
		int nLen = (int)GetModuleFileNameA(GetModuleHandle(NULL), strPath.GetBuffer(MAX_PATH), MAX_PATH);
		strPath.ReleaseBuffer(nLen);
		int nFind = strPath.ReverseFind('\\');
		if (nFind > 0) strPath = strPath.Left(nFind);
		if (m_pXingAPI->Init(strPath) == FALSE) {
			::AfxMessageBox(_T("xingAPI DLL�� Load �� �� �����ϴ�."));
		}
	}


	if (m_pXingAPI->IsConnected() == TRUE)
		m_pXingAPI->Disconnect();
	
	BOOL bResult = m_pXingAPI->Connect(hWnd, "demo.etrade.co.kr", 20001, WM_USER, 3000, 512);

	if (bResult == FALSE)
	{
		int nErrorCode = m_pXingAPI->GetLastError();
		CString strMsg = m_pXingAPI->GetErrorMessage(nErrorCode);

		strMsg = "�������ӽ��� ���� = " + strMsg;

		::AfxMessageBox(strMsg);

		return FALSE; // ���� ������.
	}

	//////////////// 3. �α��� ////////////////
	if (FALSE == m_pXingAPI->Login(hWnd, szID, szPassword, szPassword, 0, TRUE))	{// �α���
		CString strMsg = m_pXingAPI->GetErrorMessage(m_pXingAPI->GetLastError());
		::AfxMessageBox(_T("�α��� ���� : ") + strMsg);
		return false;
	}

	return true;
	
}

bool StockFacade::Disconnect()
{
	//////////////// 4. �α׾ƿ� ////////////////
	if (FALSE == m_pXingAPI->Logout(m_hWnd))	{// �α���
		CString strMsg = m_pXingAPI->GetErrorMessage(m_pXingAPI->GetLastError());
		::AfxMessageBox(_T("�α׾ƿ� ���� : ") + strMsg);
	}

	m_pXingAPI->Disconnect();

	SendMessage(m_hWnd, WM_CLOSE, 0, 0);

	return true;
}

bool StockFacade::GetCompanyData(char* pCompanyCode)
{
	t8407InBlock	pckInBlock;
	FillMemory(&pckInBlock, sizeof(pckInBlock), ' ');
	memcpy(pckInBlock.nrec, "001", sizeof(pckInBlock.nrec));
	memcpy(pckInBlock.shcode, pCompanyCode, sizeof(pckInBlock.shcode));			//���� �ڵ带 �Է��Ѵ�.
	
	int retId = 0;
	if ((retId = m_pXingAPI->Request(m_hWnd, "t8407", &pckInBlock, sizeof(pckInBlock), 0, " ", -1)) < 0)// ������ ����
	{
		CString str;
		str.Format(_T("[%d] %s"), retId, m_pXingAPI->GetErrorMessage(retId));
		::AfxMessageBox(str);
		return false;
	}

	return true;
}

bool StockFacade::RequestT1302(char* szStockCode)
{
	szSelectedCompany = szStockCode;
	t1302InBlock	pckInBlock;
	FillMemory(&pckInBlock, sizeof(pckInBlock), ' ');
	strcpy(pckInBlock.shcode, szStockCode);

	//memcpy(pckInBlock.gubun, "1", 1);
	memcpy(pckInBlock.cnt, "700", 3);
	int retId = 0;
	if ((retId = m_pXingAPI->Request(m_hWnd, "t1302", &pckInBlock, sizeof(pckInBlock), 0, " ", -1)) < 0)// ������ ����
	{
		CString str;
		str.Format(_T("[%d] %s"), retId, m_pXingAPI->GetErrorMessage(retId));
		//::AfxMessageBox(str);
		return false;
	}

	return true;
}

bool StockFacade::ProcessReceiveData(WPARAM wParam, LPARAM lParam)
{

	switch (wParam)
	{
	case REQUEST_DATA: //������ ��û�� ���� ���� 
	{
						   LPRECV_PACKET lpRecvPacket = (LPRECV_PACKET)lParam;
						   if (strcmp(lpRecvPacket->szTrCode, "t8407") == 0) //�����ڵ忡 ���� ����� ��û
						   {
							   LPt8407OutBlock1 pOutBlock1 = (LPt8407OutBlock1)lpRecvPacket->lpData;
						   }
						   else if (strcmp(lpRecvPacket->szTrCode, "t5201") == 0) //�����ڵ忡 ���� ����� ��û
						   {
							   CStringA strMsg = "�������� �α��� ����";

							   if (m_pCallback)
							   m_pCallback->OnResult((char*)strMsg.GetString());
						   }
						   else if (!strcmp(lpRecvPacket->szTrCode, "t1302"))
						   {
							   ProcessT1302(lParam);
						   }

	}
		break;
	case MESSAGE_DATA:
	{
				/*		 LPMSG_PACKET pMsg = (LPMSG_PACKET)lParam;
						 CStringA strMsg((char*)pMsg->lpszMessageData, pMsg->nMsgLength);

						 if (m_pCallback)						
							 m_pCallback->OnResult((char*)strMsg.GetString());*/
				
						 //m_pXingAPI->ReleaseMessageData(lParam);
	}
		break;
	case  SYSTEM_ERROR_DATA:
	{
							   LPMSG_PACKET pMsg = (LPMSG_PACKET)lParam;
							   CString strMsg((char*)pMsg->lpszMessageData, pMsg->nMsgLength);

							   if (m_pCallback)
							   m_pCallback->OnResult((char*)strMsg.GetString());
							   m_pXingAPI->ReleaseMessageData(lParam);
	}
	case RELEASE_DATA:
	{
						 m_pXingAPI->ReleaseRequestData((int)lParam);
	}
		break;
	}

	return true;
}

bool StockFacade::XingRequest(char* szDirective, LPVOID pData, int size)
{
	int retId = m_pXingAPI->Request(m_hWnd, szDirective, pData, size, 0, " ", -1);

	if (retId < 0)
	{
		CString str;
		str.Format(_T("[%d] %s"), retId, m_pXingAPI->GetErrorMessage(retId));
		//::AfxMessageBox(str);

		return false;
	}

	return true;
}

long changeStringToLong(char * strLong, int length)
{
	int multiply = 1;
	long result = 0;

	for (int i = length - 1; i >= 0; i--) {
		result += ((UINT)(strLong[i] - '0') * multiply);
		multiply *= 10;
	}

	return result;
}

bool StockFacade::ProcessT1302(LPARAM lParam)
{
	LPRECV_PACKET lpRecvPacket = (LPRECV_PACKET)lParam;
	LPt1302OutBlock1 pOutBlock1;

	Company* pCompany = m_pStockManager->FindCompany(szSelectedCompany.GetBuffer());

	int quantity = (int)(lpRecvPacket->nDataLength / sizeof(t1302OutBlock1));

	if (quantity == 0)
	{
		LPt1302OutBlock pOutBlock = (LPt1302OutBlock)lpRecvPacket->lpData;
		CStringA ctsTime((char*)pOutBlock->cts_time, sizeof(pOutBlock->cts_time));

		
		if (pCompany == NULL)
		{
			pCompany = new Company();

			pCompany->m_szCode = szSelectedCompany;
			m_pStockManager->AddCompany(pCompany);
		}
		
			
		return true;
	}

	pCompany->Init();
	
	for (int i = 0; i<quantity; i++)
	{

		pOutBlock1 = (LPt1302OutBlock1)(lpRecvPacket->lpData + (sizeof(t1302OutBlock1)* i));	//�����͸� �������� ���� Block�� �����Ѵ�.
		t1302OutBlock1 stockMinData;
		memcpy(&stockMinData, pOutBlock1, sizeof(stockMinData));


		pCompany->AddDayStockDataPerMinute(stockMinData);
	}

	return true;
}

Company* StockFacade::GetCompany(char* szStockCode)
{
	return m_pStockManager->FindCompany(szStockCode);
}

bool StockFacade::Update()
{
	return true;
}