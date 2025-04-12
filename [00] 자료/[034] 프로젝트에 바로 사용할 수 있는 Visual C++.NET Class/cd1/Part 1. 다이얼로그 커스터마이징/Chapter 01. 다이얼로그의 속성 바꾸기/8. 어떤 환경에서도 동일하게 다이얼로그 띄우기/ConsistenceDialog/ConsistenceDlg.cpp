// ConsistenceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "consistencedialog.h"
#include "ConsistenceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConsistenceDlg dialog

// 화면 해상도 96 DPI에서의 굴림 9포인트 폰트 크기
#define BASE_HORZ_UNIT		7				// 가로 픽셀 크기
#define BASE_VERT_UNIT		12				// 세로 픽셀 크기

// 자식 윈도우들에 대한 크기 조절 힌트 구조체
struct SResizeHint 
{ 
	CWnd *pParent;							// 다이얼로그에 대한 윈도우 포인터
	CFont *pFont;							// 기준 폰트 포인터
	int nHorz;								// 현재 다이얼로그 폰트의 평균 폭
	int nVert;								// 현재 다이얼로그 폰트의 높이
}; 


CConsistenceDlg::CConsistenceDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CConsistenceDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// 기준 폰트를 생성한다
	// 기준 폰트는 굴림 9포인트 폰트이다
	HDC hDC = ::GetDC(NULL);
	m_BaseFont.CreateFont(-MulDiv(9, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, 0, 0, 0, 0,
		DEFAULT_CHARSET, 0, 0, 0, 0, _T("굴림"));
	::ReleaseDC(NULL, hDC);
}


void CConsistenceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConsistenceDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConsistenceDlg, CDialog)
	//{{AFX_MSG_MAP(CConsistenceDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConsistenceDlg message handlers

// 자식 윈도우들의 크기와 위치를 보정하는 함수
BOOL CALLBACK EnumChildProc(HWND hWndChild, LPARAM lParam) 
{ 
	SResizeHint *pHint = (SResizeHint*)lParam; 
	CRect rcItem; 

	CWnd wndChild;
	wndChild.Attach(hWndChild);

	// 자식 윈도우의 클라이언트 영역에서의 위치와 크기를 얻는다
	wndChild.GetWindowRect(&rcItem);
	pHint->pParent->ScreenToClient(&rcItem); 

	// 힌트 내용에 따라 좌표와 크기를 보정한다
	rcItem.left = (4 * rcItem.left + 2) / pHint->nHorz;
	rcItem.left = (rcItem.left * BASE_HORZ_UNIT + 2) / 4;

	rcItem.top = (8 * rcItem.top + 4) / pHint->nVert;
	rcItem.top = (rcItem.top * BASE_VERT_UNIT + 4) / 8;

	rcItem.right = (4 * rcItem.right + 2) / pHint->nHorz;
	rcItem.right = (rcItem.right * BASE_HORZ_UNIT + 2) / 4;

	rcItem.bottom = (8 * rcItem.bottom + 4) / pHint->nVert;
	rcItem.bottom = (rcItem.bottom * BASE_VERT_UNIT + 4) / 8;

	// 자식 윈도우의 위치와 크기를 조정하고 폰트를 기준 폰트로 설정한다
	wndChild.MoveWindow(&rcItem, TRUE); 
	wndChild.SetFont(pHint->pFont);

	wndChild.Detach();

	return TRUE; 
} 

BOOL CConsistenceDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 현재 다이얼로그의 기준 폰트를 통해,
	// 현재 다이얼로그의 DLU에 대한 가로/세로 픽셀 크기를 구한다
	CDC *pDC = GetDC();
	CFont *pFont = GetFont();
	CFont *pFontOld = pDC->SelectObject(pFont);

	CSize size;
	GetTextExtentPoint(pDC->GetSafeHdc(),
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
		52, &size);

	int nHorz = (size.cx / 26 + 1) / 2;		// 현재 다이얼로그 폰트의 평균 폭
	int nVert = size.cy;					// 현재 다이얼로그 폰트의 높이

	pDC->SelectObject(pFontOld);
	ReleaseDC(pDC);

	CRect rcWindow, rcClient; 
	int nWidth, nHeight; 
	int nFrameHorz, nFrameVert; 

	GetWindowRect(&rcWindow); 
	GetClientRect(&rcClient); 

	// 윈도우 영역과 클라이언트 영역의 차이값을 계산하여 프레임의 가로/세로 두께를 구한다
	nFrameHorz = rcWindow.Width() - rcClient.Width(); 
	nFrameVert = rcWindow.Height() - rcClient.Height(); 

	// 현재 클라이언트 영역의 픽셀 값을 DLU 픽셀 값으로 나누어,
	// 클라이언트의 DLU 단위 크기를 구한다
	nWidth = rcClient.Width(); 
	nHeight = rcClient.Height(); 

	nWidth = (4 * nWidth + 2) / nHorz;
	nHeight = (8 * nHeight + 4) / nVert;

	// 클라이언트 DLU 크기를 96DPI 굴림 9포인트에서의 DLU 픽셀 값으로 곱하여,
	// 96DPI 굴림 9포인트일 때의 클라이언트 크기를 구한다
	nWidth = (nWidth * BASE_HORZ_UNIT + 2) / 4;
	nHeight = (nHeight * BASE_VERT_UNIT + 4) / 8;

	// 프레임 두께를 더한다
	nWidth += nFrameHorz;
	nHeight += nFrameVert;

	// 새로운 픽셀 크기로 다이얼로그의 크기를 조정한다
	SetWindowPos(NULL, 0, 0, nWidth, nHeight, SWP_NOMOVE | SWP_NOZORDER); 

	// 기준 폰트를 다이얼로그에게 설정한다
	SetFont(&m_BaseFont);

	// 자식 윈도우들의 크기와 위치를 같은 방식으로 보정하도록 한다
	SResizeHint Hint; 
	Hint.pParent = this;
	Hint.pFont = &m_BaseFont;
	Hint.nHorz = nHorz;
	Hint.nVert = nVert;

	EnumChildWindows(m_hWnd, EnumChildProc, (LPARAM)&Hint); 
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
