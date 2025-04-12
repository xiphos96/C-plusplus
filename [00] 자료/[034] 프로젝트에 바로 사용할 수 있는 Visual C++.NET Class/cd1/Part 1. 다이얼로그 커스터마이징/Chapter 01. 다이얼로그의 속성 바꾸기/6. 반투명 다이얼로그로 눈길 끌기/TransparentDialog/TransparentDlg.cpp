// TransparentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "transparentdialog.h"
#include "TransparentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransparentDlg dialog


CTransparentDlg::CTransparentDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CTransparentDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTransparentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTransparentDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTransparentDlg, CDialog)
	//{{AFX_MSG_MAP(CTransparentDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransparentDlg message handlers

// 투명 설정을 위한 상수 정의
#define WS_EX_LAYERED		0x00080000
#define LWA_ALPHA			0x00000002

BOOL CTransparentDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 확장 스타일에 WS_EX_LAYERED를 추가한다
	ModifyStyleEx(0, WS_EX_LAYERED);

	// user32.dll에 있는 SetLayeredWindowAttributes()의 포인터를 얻는다
	HMODULE hUserDll = ::LoadLibrary(_T("USER32.dll"));
	typedef BOOL (WINAPI* LPSETTRANSPARENT)(HWND hWnd, COLORREF crKey, BYTE bAlpha, DWORD dwFlags);

	LPSETTRANSPARENT lpSetTransparent = NULL;
	lpSetTransparent  = (LPSETTRANSPARENT)::GetProcAddress(hUserDll, "SetLayeredWindowAttributes");

	if(lpSetTransparent)
		// SetLayeredWindowAttributes() 함수를 호출한다.
		// 세번째 투명도는 0 ~ 255까지의 값을 설정한다
		lpSetTransparent(m_hWnd, NULL, 200, LWA_ALPHA);

	// user32.dll을 닫는다
	::FreeLibrary(hUserDll);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
