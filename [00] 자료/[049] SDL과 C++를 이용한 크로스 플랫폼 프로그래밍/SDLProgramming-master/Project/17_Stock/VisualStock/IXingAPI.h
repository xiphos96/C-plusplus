#ifndef _IXINGAPI_H_
#define _IXINGAPI_H_
#include "IXingDefine.h"

class IXingAPI  
{
public:
	IXingAPI () { ZeroMemory( this, sizeof( IXingAPI ) ); }
	~IXingAPI() { Uninit(); }

	inline	HMODULE	GetSafeHandle			()											{ return m_hModule; }

public:
	// �ʱ�ȭ ����
	inline	BOOL	Init					( LPCSTR szPath=NULL );
	inline	BOOL	IsInit					()											{ return m_hModule != NULL; }
	inline	void	Uninit					();

	// ��������
	inline	BOOL	Connect					( HWND hWnd, LPCSTR pszSvrIP, int nPort, int nStartMsgID, int nTimeOut=-1, int nSendMaxPacketSize=-1 );
	inline	BOOL	IsConnected				();
	inline	BOOL	Disconnect				();
	
	// �α���
	inline	BOOL	Login					( HWND hWnd, LPCSTR pszID, LPCSTR pszPwd, LPCSTR pszCertPwd, int nType, BOOL bShowCertErrDlg=TRUE );
	inline	BOOL	Logout					( HWND hWnd );

	inline	int		GetLastError			();
	inline	CString	GetErrorMessage			( int nErrorCode );
	
	// ��ȸ��TR ����
	inline	int		Request					( HWND hWnd, LPCSTR pszCode, LPVOID lpData, int nDataSize, BOOL bNext=FALSE, LPCSTR pszNextKey="", int nTimeOut=30 );
	inline	BOOL	ReleaseRequestData		( int nRequestID );
	inline	BOOL	ReleaseMessageData		( LPARAM lp );

	// �ǽð�TR ����
	inline	BOOL	AdviseRealData			( HWND hWnd, LPCSTR pszTrNo, LPCSTR pszData, int nDataUnitLen );
	inline	BOOL	UnadviseRealData		( HWND hWnd, LPCSTR pszTrNo, LPCSTR pszData, int nDataUnitLen );
	inline	BOOL	UnadviseWindow			( HWND hWnd );

	// ���� ����
	inline	int		GetAccountListCount		();
	inline	BOOL	GetAccountList			( int nIndex, LPSTR pszAcc, int nAccSize );

	// �������
	inline	CString	GetCommMedia			();			// ��Ÿ�ü�� ���Ѵ�.
	inline	CString	GetETKMedia				();			// ����ü�� ���Ѵ�.
	inline	CString	GetClientIP				();			// ����IP�� ���Ѵ�.
	inline	CString	GetServerName			();			// �������� ���Ѵ�.

	inline	void	SetHeaderInfo			( LPCSTR szType, LPCSTR szValue );

	inline	CString	GetProcBranchNo			();			// ó������ ���Ѵ�.
	inline	BOOL	GetUseOverFuture		();			// �ؿܼ��� ������	
	inline	BOOL	GetUseFX				();			// FX ������

	inline	int		GetTRCountPerSec		( LPCSTR pszCode );	// �ʴ� ���� ���� Ƚ��

	inline	void	SetNotifyFlag			( BOOL bNotifyFlag );	// ��޸޽���, �������� �������� ���� �뺸 ���� (���� ����)

	//------------------------------------------------------------------------------
	// �ΰ� ���� TR ��ȸ
	//     ��ȯ��       - Request() �Լ��� ����
	//     hWnd			- ��ȸ ����� ���� �������� �ڵ�
	//
	// [1] ���� �˻�        
	//     pszCode		- "t1807" (HTS '[1807] ����˻�' ���� 'API �� ��������' ������ ������ ������ �˻��ϴ� TR)
    //     lpData		- 'API�� ��������' �� ������ ��ü ��� ����, NULL �Է½� ���ϴ��̾�α� ǥ��
	//
	//     ex)  HTS '[1807] ����˻�' ���� 'API �� ��������' ������ ������ "D:\test.adf"
	//          pszCode = "t1833", pszData = "D:\test.adf"   

	inline	int		RequestService			( HWND hWnd, LPCSTR pszCode, LPCSTR pszData );	

	// �ΰ� ���� ��ȸ TR ����
	inline	int		RemoveService			( HWND hWnd, LPCSTR pszCode, LPCSTR pszData );

	//------------------------------------------------------------------------------
	// API ���� HTS�� ���� (API -> HTS) : ������ ���Ҷ����� ��û�Ѵ�
	//     ��ȯ��       - ���� ���� ����
	//     hWnd			- ������ ��û�� �������� �ڵ�
	//     
	// [1] ���� ����
    //     pszLinkKey	- &STOCK_CODE				: �ֽ� �����ڵ�
    //                    &ETF_CODE					: ETF �����ڵ�
    //                    &ELW_CODE					: ELW �����ڵ�
    //                    &KONEX_CODE				: �ڳؽ� �����ڵ�
    //                    &FREEBOARD_CODE			: �������� �����ڵ�
    //                    &KSPI_CODE				: �ڽ��� ���� �ڵ�
    //                    &KSQI_CODE				: �ڽ��� ���� �ڵ�
    //                    &FUTURE_CODE				: ���������ڵ�
    //                    &OPTION_CODE				: �ɼ������ڵ�
    //                    &FUTOPT_CODE				: ����/�ɼ� �����ڵ� 
    //                    &FUTSP_CODE				: ������������ �����ڵ�
    //                    &STOCK_FUTURE_CODE		: �ֽ� ���� �����ڵ�
    //                    &STOCK_OPTION_CODE		: �ֽ� �ɼ� �����ڵ�
    //                    &STOCK_FUTOPT_CODE		: �ֽ� �����ɼ� �����ڵ� 
    //                    &STOCK_FUTSP_CODE			: �ֽ� ������������ �����ڵ�
    //                    &FUTOPT_STOCK_FUTOPT_CODE : �����ɼ� & �ֽ� �����ɼ� �����ڵ�
    //                    &US_CODE					: �ؿ������ڵ�
    //                    &COMMODITY_FUTOPT_CODE	: ��ǰ����/�����ɼ�
    //                    &COMMODITY_FUTURE_CODE	: ��ǰ����
    //                    &COMMODITY_STAR_CODE		: ��Ÿ����
    //                    &CME_FUTURE_CODE			: CME�߰�����
    //                    &EUREX_OPTION_CODE		: EUREX�߰��ɼ�
    //                    &NIGHT_FUTOPT_CODE		: �߰������ɼ�
    //     pszData    	- ��ǰ�� �����ڵ�  
	//
	//     ex) �ֽ� ���� ���� : pszLinkKey = "&STOCK_CODE", pszData = "078020"
	//         ���� ���� ���� : pszLinkKey = "&FUTURE_CODE", pszData = "101HC000"
	//     
	// [2] HTS ȭ�� ���� 
    //     pszLinkKey	- &OPEN_SCREEN : ȭ�� ����
	//     pszData    	- ���� ���� ȭ�� ��ȣ
	//
	//     ex) HTS�� '[6602]���ɿ��� �̰����ܰ�' ����
	//         pszLinkKey = &OPEN_SCREEN, pszData = "6602"	

	inline	int		RequestLinkToHTS        ( HWND hWnd, LPCSTR pszLinkKey, LPCSTR pszData, LPCSTR pszFiller=NULL );

	//------------------------------------------------------------------------------
	// HTS ���� API�� ���� (HTS -> API) : ����ϸ� �����Ҷ����� �����ȴ�
	//     hWnd			- ������ ���ϴ� �������� �ڵ�
	// 
	// �� HTS���� ���� �߻� ��, XM_RECEIVE_LINK_DATA �� �޽����� �߻�
	//	  WPARAM = LINK_DATA, 
	//	  LPARAM = LINKDATA_RECV_MSG ����ü ������ 
	//    �ڡڡ�  ������� Real ���Ű� ����, LPARAM �޸� ���� �� �ݵ�� ���� �ʿ�

	inline	void	AdviseLinkFromHTS		( HWND hWnd );
	inline	void	UnAdviseLinkFromHTS		( HWND hWnd );

	//------------------------------------------------------------------------------
	// �������� ������ �����Ѵ� : ƽíƮ ������ ��� ������·� ���Ź��� ��� ���
	//     ��ȯ��       - ������ ������ ������(pszDest)�� ����
	//
	//     pszSrc		- ������� ������
	//     pszDest		- ������ ������ �����͸� ������ �޸� (Outblock ����ü ������ �ִ� 2000��)
	//	   nSrcLen	    - pszSrc �������� ����
	// 
	// ��� ��� 
	//     ex) t8411 TR �̿��, InBlock�� comp_yn(���࿩��) �ʵ忡 "Y" �Է� �� ��ȸ
	//          ReceiveData() ���� Occurs ��(t8411OutBlock1)�� ����Ǿ� ���ŵǹǷ�, �ش� �� ������ ����
	// 
	//			LRESULT t8411_Wnd::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
	//			{
	//				//-------------------------------------------------------------------------------------
	//				// Data�� ����
	//				if( wParam == REQUEST_DATA )
	//				{
	//					LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;
	//
	//					if( strcmp( pRpData->szBlockName, NAME_t8411OutBlock ) == 0 )
	//					{
	//					}
	//					else if( strcmp( pRpData->szBlockName, NAME_t8411OutBlock1 ) == 0 )
	//					{
	//						LPt8411OutBlock1 pOutBlock1 = (LPt8411OutBlock1)pRpData->lpData;
    //
	//						t8411OutBlock1 szOutBlock1[2000];		// ���� ������ �ִ� 2000�� ����
	//						int nDestSize = g_iXingAPI.Decompress((char *)pOutBlock1, (char *)&szOutBlock1[0], pRpData->nDataLength);
    //
	//						// Occurs �� ���
	//						// Header�� 'A' �̸� ��ü���̿��� OutBlock�� ���̸� ������ ������ ���Ѵ�.
	//						if (nDestSize > 0)
	//						{
	//							int nCount = nDestSize / sizeof( t8411OutBlock1 );
	//
	//							for( int i=0; i<nCount; i++ )
	//							{
	//								������ ǥ�� 
	//							}
	//						}
	//					}
	//				}
	//			}
	// 
	inline	int		Decompress				( LPCSTR pszSrc, LPCSTR pszDest, int nSrcLen );

	//------------------------------------------------------------------------------

protected:
	inline	int		LoadLibHelper		( LPCSTR szPath );

protected:
	HMODULE			m_hModule;

	typedef BOOL	( __stdcall *FP_CONNECT					) ( HWND, LPCSTR, int, int, int, int );
	typedef BOOL	( __stdcall *FP_ISCONNECTED				) ( );
	typedef BOOL	( __stdcall *FP_DISCONNECT				) ( );
	typedef BOOL	( __stdcall *FP_LOGIN					) ( HWND, LPCSTR, LPCSTR, LPCSTR, int, BOOL );
	typedef BOOL	( __stdcall *FP_LOGOUT					) ( HWND );
	typedef int		( __stdcall *FP_GETLASTERROR			) ( );
	typedef int		( __stdcall *FP_GETERRORMESSAGE			) ( int, LPSTR, int );
	
	typedef int		( __stdcall *FP_REQUEST					) ( HWND, LPCSTR, LPVOID, int, BOOL, LPCSTR, int );
	typedef void	( __stdcall *FP_RELEASEREQUESTDATA		) ( int );
	typedef void	( __stdcall *FP_RELEASEMESSAGEDATA		) ( LPARAM );
	
	typedef BOOL	( __stdcall *FP_ADVISEREALDATA			) ( HWND, LPCSTR, LPCSTR, int );
	typedef BOOL	( __stdcall *FP_UNADVISEREALDATA		) ( HWND, LPCSTR, LPCSTR, int );
	typedef BOOL	( __stdcall *FP_UNADVISEWINDOW			) ( HWND );
	
	typedef int		( __stdcall *FP_GETACCOUNTLISTCOUNT		) ( );
	typedef BOOL	( __stdcall *FP_GETACCOUNTLIST			) ( int, LPSTR, int );
	typedef void	( __stdcall *FP_GETCOMMMEDIA			) ( LPTSTR );
	typedef void	( __stdcall *FP_GETETKMEDIA				) ( LPTSTR );
	typedef void	( __stdcall *FP_GETCLIENTIP				) ( LPTSTR );
	typedef void	( __stdcall *FP_GETSERVERNAME			) ( LPTSTR );
	typedef void	( __stdcall *FP_SETHEADERINFO			) ( LPCSTR, LPCSTR );

	typedef void	(__stdcall *FP_GETPROCBRANCHNO			) ( LPTSTR );
	typedef BOOL	(__stdcall *FP_GETUSEOVERFUTURE			) ( );
	typedef BOOL	(__stdcall *FP_GETUSEFX					) ( );

	typedef int		(__stdcall *FP_GETTRCOUNTPERSEC			) ( LPCSTR );

	typedef void	(__stdcall *FP_SETNOTIFYFLAG			) ( BOOL );

	typedef int		( __stdcall *FP_REQUESTSERVICE			) ( HWND, LPCSTR, LPCSTR );
	typedef int		( __stdcall *FP_REMOVESERVICE			) ( HWND, LPCSTR, LPCSTR );

	typedef int		( __stdcall *FP_REQUESTLINKTOHTS    	) ( HWND, LPCSTR, LPCSTR, LPCSTR );
	typedef void	( __stdcall *FP_ADVISELINKFROMHTS    	) ( HWND );
	typedef void	( __stdcall *FP_UNADVISELINKFROMHTS    	) ( HWND );

	typedef int		( __stdcall *FP_DECOMPRESS				) ( LPCSTR, LPCSTR, int );

	FP_CONNECT					m_fpConnect;
	FP_ISCONNECTED				m_fpIsConnected;
	FP_DISCONNECT				m_fpDisconnect;
	FP_LOGIN					m_fpLogin;
	FP_LOGOUT					m_fpLogout;

	FP_GETLASTERROR				m_fpGetLastError;
	FP_GETERRORMESSAGE			m_fpGetErrorMessage;

	FP_REQUEST					m_fpRequest;
	FP_ADVISEREALDATA			m_fpAdviseRealData;
	FP_UNADVISEREALDATA			m_fpUnadviseRealData;
	FP_UNADVISEWINDOW			m_fpUnadviseWindow;
	FP_RELEASEREQUESTDATA		m_fpReleaseRequestData;
	FP_RELEASEMESSAGEDATA		m_fpReleaseMessageData;

	FP_GETACCOUNTLISTCOUNT		m_fpGetAccountListCount;
	FP_GETACCOUNTLIST			m_fpGetAccountList;
	FP_GETCOMMMEDIA				m_fpGetCommMedia;
	FP_GETETKMEDIA				m_fpGetETKMedia;
	FP_GETCLIENTIP				m_fpGetClientIP;
	FP_GETSERVERNAME			m_fpGetServerName;

	FP_SETHEADERINFO			m_fpSetHeaderInfo;

	FP_GETPROCBRANCHNO			m_fpGetProcBranchNo;
	FP_GETUSEOVERFUTURE			m_fpGetUseOverFuture;
	FP_GETUSEFX					m_fpGetUseFX;

	FP_GETTRCOUNTPERSEC			m_fpGetTRCountPerSec;

	FP_SETNOTIFYFLAG			m_fpSetNotifyFlag;

	FP_REQUESTSERVICE			m_fpRequestService;
	FP_REMOVESERVICE			m_fpRemoveService;

	FP_REQUESTLINKTOHTS			m_fpRequestLinkToHTS;
	FP_ADVISELINKFROMHTS		m_fpAdviseLinkFromHTS;
	FP_UNADVISELINKFROMHTS		m_fpUnAdviseLinkFromHTS;

	FP_DECOMPRESS				m_fpDecompress;
};

BOOL IXingAPI::Init(LPCSTR szPath)
{
	if( IsInit() ) return TRUE;

	return LoadLibHelper( szPath );
}

BOOL IXingAPI::LoadLibHelper( LPCSTR szPath )
{
	CHAR szCommLib[MAX_PATH] = { 0 };

	if( szPath == NULL || strlen( szPath ) == 0 )
	{
		lstrcpyA( szCommLib, "XingAPI.dll" );
	}
	else
	{
		sprintf( szCommLib, "%s\\XingAPI.dll", szPath );
	}

	CHAR szCurrentDir[MAX_PATH] = { 0 };
	GetCurrentDirectoryA( MAX_PATH, szCurrentDir );
	SetCurrentDirectoryA( szPath );
	m_hModule = ::LoadLibraryA( szCommLib );
	SetCurrentDirectoryA( szCurrentDir );

	return NULL == m_hModule ? FALSE : TRUE;
}

void IXingAPI::Uninit()
{
	if( IsInit() ) ::FreeLibrary( m_hModule );
	m_hModule = NULL;
}

BOOL IXingAPI::Connect( HWND hWnd, LPCSTR pszSvrIP, int nPort, int nStartMsgID, int nTimeOut, int nSendMaxPacketSize )
{
	ASSERT( m_hModule );
	if( NULL == m_hModule   ) return FALSE;
	if( NULL == m_fpConnect ) m_fpConnect = (FP_CONNECT)GetProcAddress(m_hModule, "ETK_Connect");
	ASSERT( m_fpConnect );
	if( NULL == m_fpConnect ) return FALSE;
	return m_fpConnect( hWnd, pszSvrIP, nPort, nStartMsgID, nTimeOut, nSendMaxPacketSize );
}

BOOL IXingAPI::IsConnected()
{
	ASSERT( m_hModule );
	if( NULL == m_hModule		) return FALSE;
	if( NULL == m_fpIsConnected ) m_fpIsConnected = (FP_ISCONNECTED)GetProcAddress(m_hModule, "ETK_IsConnected");
	ASSERT( m_fpIsConnected );
	if( NULL == m_fpIsConnected ) return FALSE;
	return m_fpIsConnected();
}

BOOL IXingAPI::Disconnect()
{
	ASSERT( m_hModule );
	if( NULL == m_hModule		) return FALSE;
	if( NULL == m_fpDisconnect	) m_fpDisconnect = (FP_DISCONNECT)GetProcAddress(m_hModule, "ETK_Disconnect");
	ASSERT( m_fpDisconnect );
	if( NULL == m_fpDisconnect	) return FALSE;
	return m_fpDisconnect();
}

BOOL IXingAPI::Login( HWND hWnd, LPCSTR pszID, LPCSTR pszPwd, LPCSTR pszCertPwd, int nType, BOOL bShowCertErrDlg )
{
	ASSERT( m_hModule );
	if( NULL == m_hModule )	return FALSE;
	if( NULL == m_fpLogin )	m_fpLogin = (FP_LOGIN)GetProcAddress(m_hModule, "ETK_Login");
	ASSERT( m_fpLogin );
	if( NULL == m_fpLogin )	return FALSE;
	return m_fpLogin( hWnd, pszID, pszPwd, pszCertPwd, nType, bShowCertErrDlg );
}

BOOL IXingAPI::Logout( HWND hWnd )
{
	ASSERT( m_hModule );
	if( NULL == m_hModule  ) return FALSE;
	if( NULL == m_fpLogout ) m_fpLogout = (FP_LOGOUT)GetProcAddress(m_hModule, "ETK_Logout");
	ASSERT( m_fpLogout );
	if( NULL == m_fpLogout ) return FALSE;
	return m_fpLogout( hWnd );
}

int	IXingAPI::GetLastError()
{
	ASSERT( m_hModule );
	if( NULL == m_hModule  ) return FALSE;
	if( NULL == m_fpGetLastError ) m_fpGetLastError = (FP_GETLASTERROR)GetProcAddress(m_hModule, "ETK_GetLastError");
	ASSERT( m_fpGetLastError );
	if( NULL == m_fpGetLastError ) return FALSE;
	return m_fpGetLastError();
}

CString	IXingAPI::GetErrorMessage( int nErrorCode )
{
	ASSERT( m_hModule );
	if( NULL == m_hModule  ) return "";
	if( NULL == m_fpGetErrorMessage ) m_fpGetErrorMessage = (FP_GETERRORMESSAGE)GetProcAddress(m_hModule, "ETK_GetErrorMessage");
	ASSERT( m_fpGetErrorMessage );
	if( NULL == m_fpGetErrorMessage ) return "";

	char szData[1024] = { 0 };
	m_fpGetErrorMessage( nErrorCode, szData, sizeof( szData ) );
	return szData;
}

int IXingAPI::Request( HWND hWnd, LPCSTR pszCode, LPVOID lpData, int nDataSize, BOOL bNext, LPCSTR pszNextKey, int nTimeOut )
{
	if( NULL == m_hModule )	return -1;
	
	if( NULL == m_fpRequest )	
		m_fpRequest = (FP_REQUEST)GetProcAddress(m_hModule, "ETK_Request");
	
	if( NULL == m_fpRequest )	return -1;
	
	return m_fpRequest(hWnd, pszCode, lpData, nDataSize, bNext, pszNextKey, nTimeOut);
}

BOOL IXingAPI::AdviseRealData ( HWND hWnd, LPCSTR pszTrNo, LPCSTR pszData, int nDataUnitLen )
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpAdviseRealData )	
		m_fpAdviseRealData = (FP_ADVISEREALDATA)GetProcAddress(m_hModule, "ETK_AdviseRealData");

	if( NULL == m_fpAdviseRealData )	return FALSE;

	return m_fpAdviseRealData( hWnd, pszTrNo, pszData, nDataUnitLen );
}

BOOL IXingAPI::UnadviseRealData( HWND hWnd, LPCSTR pszTrNo, LPCSTR pszData, int nDataUnitLen )
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpUnadviseRealData )	
		m_fpUnadviseRealData = (FP_UNADVISEREALDATA)GetProcAddress(m_hModule, "ETK_UnadviseRealData");

	if( NULL == m_fpUnadviseRealData )	return FALSE;

	return m_fpUnadviseRealData( hWnd, pszTrNo, pszData, nDataUnitLen );
}

BOOL IXingAPI::UnadviseWindow( HWND hWnd )
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpUnadviseWindow )	
		m_fpUnadviseWindow = (FP_UNADVISEWINDOW)GetProcAddress(m_hModule, "ETK_UnadviseWindow");

	if( NULL == m_fpUnadviseWindow )	return FALSE;

	return m_fpUnadviseWindow(hWnd);
}

BOOL IXingAPI::ReleaseRequestData( int nRequestID )
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpReleaseRequestData )	
		m_fpReleaseRequestData = (FP_RELEASEREQUESTDATA)GetProcAddress(m_hModule, "ETK_ReleaseRequestData");

	if( NULL == m_fpReleaseRequestData )	return FALSE;

	m_fpReleaseRequestData(nRequestID);
	return TRUE;
}

BOOL IXingAPI::ReleaseMessageData(LPARAM lp)
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpReleaseMessageData )	
		m_fpReleaseMessageData = (FP_RELEASEMESSAGEDATA)GetProcAddress(m_hModule, "ETK_ReleaseMessageData");

	if( NULL == m_fpReleaseMessageData )	return FALSE;

	m_fpReleaseMessageData(lp);
	return TRUE;
}

int	IXingAPI::GetAccountListCount()
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpGetAccountListCount )	
		m_fpGetAccountListCount = (FP_GETACCOUNTLISTCOUNT)GetProcAddress(m_hModule, "ETK_GetAccountListCount");

	if( NULL == m_fpGetAccountListCount )	return 0;

	return m_fpGetAccountListCount();
}

BOOL IXingAPI::GetAccountList( int nIndex, LPSTR pszAcc, int nAccSize )
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpGetAccountList )	
		m_fpGetAccountList = (FP_GETACCOUNTLIST)GetProcAddress(m_hModule, "ETK_GetAccountList");

	if( NULL == m_fpGetAccountList )	return FALSE;

	return m_fpGetAccountList( nIndex, pszAcc, nAccSize );
}

CString	IXingAPI::GetCommMedia()
{
	if( NULL == m_hModule )	return "";
	
	if( NULL == m_fpGetCommMedia )	
		m_fpGetCommMedia = (FP_GETCOMMMEDIA)GetProcAddress( m_hModule, "ETK_GetCommMedia" );

	if( NULL == m_fpGetCommMedia )	return "";

	TCHAR szMedia[256] = { 0 };
	m_fpGetCommMedia( szMedia );
	return szMedia;
}

CString	IXingAPI::GetETKMedia()
{
	if( NULL == m_hModule )	return "";
	
	if( NULL == m_fpGetETKMedia )	
		m_fpGetETKMedia = (FP_GETETKMEDIA)GetProcAddress( m_hModule, "ETK_GetETKMedia" );

	if( NULL == m_fpGetETKMedia )	return "";

	TCHAR szMedia[256] = { 0 };
	m_fpGetETKMedia( szMedia );
	return szMedia;
}

CString	IXingAPI::GetClientIP()
{
	if( NULL == m_hModule )	return "";
	
	if( NULL == m_fpGetClientIP )	
		m_fpGetClientIP = (FP_GETCLIENTIP)GetProcAddress( m_hModule, "ETK_GetClientIP" );

	if( NULL == m_fpGetClientIP )	return "";

	TCHAR szIP[256] = { 0 };
	m_fpGetClientIP( szIP );
	return szIP;
}

CString	IXingAPI::GetServerName()
{
	if( NULL == m_hModule )	return "";
	
	if( NULL == m_fpGetServerName )	
		m_fpGetServerName = (FP_GETSERVERNAME)GetProcAddress( m_hModule, "ETK_GetServerName" );

	if( NULL == m_fpGetServerName )	return "";

	TCHAR szName[256] = { 0 };
	m_fpGetServerName( szName );
	return szName;
}

void IXingAPI::SetHeaderInfo( LPCSTR szType, LPCSTR szValue )
{
	if( NULL == m_hModule )	return;
	
	if( NULL == m_fpSetHeaderInfo )	
		m_fpSetHeaderInfo = (FP_SETHEADERINFO)GetProcAddress( m_hModule, "ETK_SetHeaderInfo" );
	
	if( NULL == m_fpSetHeaderInfo )	return;
	
	m_fpSetHeaderInfo( szType, szValue );
}

CString	IXingAPI::GetProcBranchNo()
{
	if( NULL == m_hModule )	return "";
	
	if( NULL == m_fpGetProcBranchNo )	
		m_fpGetProcBranchNo = (FP_GETPROCBRANCHNO)GetProcAddress( m_hModule, "ETK_GetProcBranchNo" );

	if( NULL == m_fpGetProcBranchNo )	return "";

	TCHAR szProcBranchNo[256] = { 0 };
	m_fpGetProcBranchNo( szProcBranchNo );
	return szProcBranchNo;
}

BOOL IXingAPI::GetUseOverFuture()
{
	ASSERT( m_hModule );
	if( NULL == m_hModule		) return FALSE;
	if( NULL == m_fpGetUseOverFuture ) m_fpGetUseOverFuture = (FP_GETUSEOVERFUTURE)GetProcAddress( m_hModule, "ETK_GetUseOverFuture" );
	ASSERT( m_fpGetUseOverFuture );
	if( NULL == m_fpGetUseOverFuture ) return FALSE;
	return m_fpGetUseOverFuture();
}

BOOL IXingAPI::GetUseFX()
{
	ASSERT( m_hModule );
	if( NULL == m_hModule		) return FALSE;
	if( NULL == m_fpGetUseFX ) m_fpGetUseFX = (FP_GETUSEFX)GetProcAddress( m_hModule, "ETK_GetUseFX" );
	ASSERT( m_fpGetUseFX );
	if( NULL == m_fpGetUseFX ) return FALSE;
	return m_fpGetUseFX();
}

int IXingAPI::GetTRCountPerSec( LPCSTR pszCode )
{
	if( NULL == m_hModule )	return -1;
	
	if( NULL == m_fpGetTRCountPerSec )	
		m_fpGetTRCountPerSec = (FP_GETTRCOUNTPERSEC)GetProcAddress( m_hModule, "ETK_GetTRCountPerSec" );
	
	if( NULL == m_fpGetTRCountPerSec )	return -1;
	
	return m_fpGetTRCountPerSec( pszCode );
}

void IXingAPI::SetNotifyFlag( BOOL bNotifyFlag )
{
	ASSERT( m_hModule );
	if( NULL == m_hModule		) return;

	if( NULL == m_fpSetNotifyFlag ) m_fpSetNotifyFlag = (FP_SETNOTIFYFLAG)GetProcAddress( m_hModule, "ETK_SetNotifyFlag" );
	ASSERT( m_fpSetNotifyFlag );
	if( NULL == m_fpSetNotifyFlag ) return;
	
	m_fpSetNotifyFlag( bNotifyFlag );
}

int IXingAPI::RequestService( HWND hWnd, LPCSTR pszCode, LPCSTR pszData )
{
	if( NULL == m_hModule )	return -1;
	
	if( NULL == m_fpRequestService )	
		m_fpRequestService = (FP_REQUESTSERVICE)GetProcAddress( m_hModule, "ETK_RequestService" );
	
	if( NULL == m_fpRequestService )	return -1;
	
	return m_fpRequestService( hWnd, pszCode, pszData );
}

int IXingAPI::RemoveService( HWND hWnd, LPCSTR pszCode, LPCSTR pszData )
{
	if( NULL == m_hModule )	return -1;
	
	if( NULL == m_fpRemoveService )	
		m_fpRemoveService = (FP_REMOVESERVICE)GetProcAddress( m_hModule, "ETK_RemoveService" );
	
	if( NULL == m_fpRemoveService )	return -1;
	
	return m_fpRemoveService( hWnd, pszCode, pszData );
}

int IXingAPI::RequestLinkToHTS( HWND hWnd, LPCSTR pszLinkKey, LPCSTR pszData, LPCSTR pszFiller )
{
	if( NULL == m_hModule )	return -1;
	
	if( NULL == m_fpRequestLinkToHTS )	
		m_fpRequestLinkToHTS = (FP_REQUESTLINKTOHTS)GetProcAddress( m_hModule, "ETK_RequestLinkToHTS" );
	
	if( NULL == m_fpRequestLinkToHTS )	return -1;
	
	return m_fpRequestLinkToHTS( hWnd, pszLinkKey, pszData, pszFiller );
}

void IXingAPI::AdviseLinkFromHTS( HWND hWnd )
{
	if( NULL == m_hModule )	return;
	
	if( NULL == m_fpAdviseLinkFromHTS )	
		m_fpAdviseLinkFromHTS = (FP_ADVISELINKFROMHTS)GetProcAddress( m_hModule, "ETK_AdviseLinkFromHTS" );
	
	if( NULL == m_fpAdviseLinkFromHTS )	return;
	
	m_fpAdviseLinkFromHTS( hWnd );
}

void IXingAPI::UnAdviseLinkFromHTS( HWND hWnd )
{
	if( NULL == m_hModule )	return;
	
	if( NULL == m_fpUnAdviseLinkFromHTS )	
		m_fpUnAdviseLinkFromHTS = (FP_UNADVISELINKFROMHTS)GetProcAddress( m_hModule, "ETK_UnAdviseLinkFromHTS" );
	
	if( NULL == m_fpUnAdviseLinkFromHTS )	return;
	
	m_fpUnAdviseLinkFromHTS( hWnd );
}

int IXingAPI::Decompress( LPCSTR pszSrc, LPCSTR pszDest, int nSrcLen )
{
	if( NULL == m_hModule )	return -1;
	
	if( NULL == m_fpDecompress )	
		m_fpDecompress = (FP_DECOMPRESS)GetProcAddress( m_hModule, "ETK_Decompress" );
	
	if( NULL == m_fpDecompress )	return -1;
	
	return m_fpDecompress( pszSrc, pszDest, nSrcLen );
}

#endif // _IXINGAPI_H_
