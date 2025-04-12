// DialogStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "dialogstatusbardemo.h"
#include "DialogStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogStatusBar

// 상태바의 높이를 정의하는 상수
#define	CONST_STATUSBAR_HEIGHT		24


CDialogStatusBar::CDialogStatusBar()
{
}

CDialogStatusBar::~CDialogStatusBar()
{
}


BEGIN_MESSAGE_MAP(CDialogStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CDialogStatusBar)
	ON_WM_MENUSELECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogStatusBar message handlers

// 상태바 생성 함수
BOOL CDialogStatusBar::Create(CWnd* pParentWnd, DWORD dwStyle, UINT nID)
{
	// 기본 상태바 생성 함수를 실행한다
	if(!CStatusBar::Create(pParentWnd, dwStyle, nID))	return FALSE;

	// 부모 윈도우의 클라이언트 영역을 얻는다
	CRect rcStatus;
	pParentWnd->GetClientRect(&rcStatus);

	// 상태바의 영역을 클라이언트 아래쪽으로 설정한다
	rcStatus.top = rcStatus.bottom - CONST_STATUSBAR_HEIGHT;

	// 상태바의 위치를 옮긴다
	MoveWindow(rcStatus);

	return TRUE;
}

// 페인 설정 함수
BOOL CDialogStatusBar::SetIndicators(const UINT* lpIDArray, int nIDCount)
{
	// 기본 상태바 페인 설정 함수를 실행한다
	if(!CStatusBar::SetIndicators(lpIDArray, nIDCount))	return FALSE;

	// 페인 중에서 ID_SEPARATOR를 ID로 갖는 페인을 찾는다
	int i;
	for(i = 0; i < nIDCount; i++)
	{
		// 만약 ID가 ID_SEPARATOR라면 기본 메뉴 상태를 텍스트로 출력한다
		if(lpIDArray[i] == ID_SEPARATOR)	SetPaneText(i, "준비");
	}

	return TRUE;
}

// 부모 윈도우의 크기 변화에 따른 상태바 위치/크기 변화 함수
void CDialogStatusBar::OnResize(int cx, int cy)
{
	// 만약 상태바가 생성된 상태라면
	if(m_hWnd)
	{
		CRect rcStatus;

		// 새로운 부모 윈도우의 아래쪽으로 상태바를 옮긴다
		rcStatus.SetRect(0, cy - CONST_STATUSBAR_HEIGHT, cx, cy);
		MoveWindow(&rcStatus);
	}
}

// 부모 윈도우의 메뉴 선택시 메뉴 텍스트 출력 함수
void CDialogStatusBar::OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu) 
{
	CString strText;

	// 해당 메뉴의 텍스트를 얻는다
	if(nItemID > 0)			strText.LoadString(nItemID);
	// 만약 텍스트가 없다면 기본 메뉴 상태 텍스트를 설정한다
	if(strText.IsEmpty())	strText = "준비";

	// 모든 페인에 대해서 ID가 ID_SEPARATOR인 페인을 찾는다
	int nPanes = GetStatusBarCtrl().GetParts(0, NULL), i;
	for(i = 0; i < nPanes; i++)
	{
		if(GetItemID(i) == ID_SEPARATOR)
		{
			// ID가 ID_SEPARATOR인 페인의 텍스트를 메뉴 텍스트로 설정한다
			SetPaneText(i, strText);
		}
	}
}
