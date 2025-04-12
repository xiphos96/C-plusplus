// DefFontDialog.cpp : implementation file
//

#include "stdafx.h"
#include "changefont.h"
#include "DefFontDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDefFontDialog dialog

// 컴파일을 위해 반드시 인크루드 해야 하는 파일
#include <afxpriv.h>

CDefFontDialog::CDefFontDialog(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CDefFontDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// 기본 값 설정
	m_nResourceID = nResourceID;
	m_strFontName = "굴림체";
	m_nFontSize = 10;
}


void CDefFontDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDefFontDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDefFontDialog, CDialog)
	//{{AFX_MSG_MAP(CDefFontDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDefFontDialog message handlers

int CDefFontDialog::DoModal() 
{
	CDialogTemplate DlgTemplate;
	INT_PTR             nResult;

	// 기본 다이얼로그 리소스를 로드한다.
	if (!DlgTemplate.Load(MAKEINTRESOURCE(m_nResourceID))) return -1;

	// 새로운 폰트를 설정한다.
	DlgTemplate.SetFont(m_strFontName, m_nFontSize);

	// 메모리 위치를 잠근다
	LPSTR pData = (LPSTR)GlobalLock(DlgTemplate.m_hTemplate);

	m_lpszTemplateName = NULL;
	// 새로 설정한 다이얼로그 리소스를 사용해 모달 다이얼로그를 초기화한다
	InitModalIndirect(pData);

	// 다이얼로그를 모달로 띄운다
	nResult = CDialog::DoModal();

	// 메모리 위치를 푼다
	GlobalUnlock(DlgTemplate.m_hTemplate);

	return nResult;	
}

LPCTSTR CDefFontDialog::GetFontName()
{
	return LPCTSTR(m_strFontName);
}

void CDefFontDialog::SetFontName(CString strFontName)
{
	m_strFontName = strFontName;
}

int CDefFontDialog::GetFontSize()
{
	return m_nFontSize;
}

void CDefFontDialog::SetFontSize(int nSize)
{
	m_nFontSize = nSize;
}
