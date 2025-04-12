// MsnNotifyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "msnnotifydialog.h"
#include "MsnNotifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsnNotifyDlg dialog

// 손 모양의 마우스 커서 ID
#define IDC_HAND            MAKEINTRESOURCE(32649)


CMsnNotifyDlg::CMsnNotifyDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CMsnNotifyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// 손모양 마우스 커서 로딩
	m_hCursor	= ::LoadCursor(NULL, MAKEINTRESOURCE(IDC_HAND));

	// 폰트 생성
	HDC hDC = ::GetDC(NULL);
	m_MessageFont.CreateFont(-MulDiv(9, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "굴림");
	m_HotFont.CreateFont(-MulDiv(9, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_BOLD,
		0, TRUE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "굴림");
	::ReleaseDC(NULL, hDC);

	// 각종 변수 초기화
	m_clrText		= RGB(0, 0, 0);

 	m_nTimeUp		= 20;
	m_nTimeShow		= 3000;
	m_nTimeDown		= 20;

	m_nTimerID		= 0;

	m_bHover		= FALSE;
}

CMsnNotifyDlg::~CMsnNotifyDlg()
{
	// 손모양 마우스 커서 소멸
	::DeleteObject(m_hCursor);
	// 배경 이미지 소멸
	if(m_bmpBkgnd.m_hObject)		m_bmpBkgnd.DeleteObject();
	// 폰트 소멸
	if(m_MessageFont.m_hObject)		m_MessageFont.DeleteObject();
	if(m_HotFont.m_hObject)			m_HotFont.DeleteObject();
}

void CMsnNotifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMsnNotifyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMsnNotifyDlg, CDialog)
	//{{AFX_MSG_MAP(CMsnNotifyDlg)
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsnNotifyDlg message handlers

BOOL CMsnNotifyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 다이얼로그 생성시 아직 배경 이미지가 설정되어 있지 않으면
	if(m_rcMessage.IsRectEmpty())
	{
		// 현재 다이얼로그 크기를 메시지 출력 영역으로 하고
		// 이에 따른 영역들을 설정한다
		GetClientRect(&m_rcMessage);
		m_bmpInfo.bmWidth	= m_rcMessage.Width();
		m_bmpInfo.bmHeight	= m_rcMessage.Height();

		InitPosition();
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// 마우스가 알림 창에 들어올 경우 마우스 커서를 변경해주는 함수
BOOL CMsnNotifyDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	::SetCursor(m_hCursor);
	return TRUE;
}

void CMsnNotifyDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// 설정된 폰트와 색상으로 메시지를 출력
	dc.SetTextColor(m_clrText);
	dc.SetBkMode(TRANSPARENT); 

	CFont *pOldFont;

	// 마우스가 알림 창 위에 있는지 여부에 따라 폰트 설정
	if(m_bHover)	pOldFont = dc.SelectObject(&m_HotFont);
	else			pOldFont = dc.SelectObject(&m_MessageFont);

	dc.DrawText(m_strMessage, m_rcMessage,
		DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_WORDBREAK | DT_END_ELLIPSIS | DT_EXPANDTABS);
	dc.SelectObject(pOldFont);
}

BOOL CMsnNotifyDlg::OnEraseBkgnd(CDC* pDC) 
{
	// 알림 창의 배경에 배경 이미지 출력
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	CBitmap *pOldBmp = MemDC.SelectObject(&m_bmpBkgnd);

	pDC->BitBlt(0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);

	MemDC.SelectObject(pOldBmp);

	return TRUE;
}

void CMsnNotifyDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 마우스가 알림 창 위에서 이동 중이면,
	// 시스템에게 마우스의 알림 창 진입과 탈출에 대한 메시지를 보내줄 것을 요청
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags		= TME_LEAVE | TME_HOVER;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);
	
	CDialog::OnMouseMove(nFlags, point);
}

LRESULT CMsnNotifyDlg::OnMouseHover(WPARAM wParam, LPARAM lParam)
{
	// 마우스가 알림 창에 진입했으므로 화면 다시 그림
	m_bHover = TRUE;
	Invalidate();

	return 0;
}

LRESULT CMsnNotifyDlg::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// 마우스가 알림 창에서 탈출했으므로 화면 다시 그림
	m_bHover = FALSE;
	Invalidate();

	return 0;
}

void CMsnNotifyDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// 마우스 좌측 버튼 클릭(정확히는 좌측 버튼 떼임)시
	// 부모 윈도우에게 메시지 전달
	if(GetParent())
	{
		GetParent()->PostMessage(WM_NOTIFY_CLICKED, 0, 0);
	}
	
	CDialog::OnLButtonUp(nFlags, point);
}

void CMsnNotifyDlg::OnTimer(UINT nIDEvent) 
{
	CRect rcWindow;

	GetWindowRect(&rcWindow);

	switch(nIDEvent)
	{
	case CONST_TIMER_UP:
		// 알림 창이 나타나는 중이라면
		// 알림 창의 위치를 옮기고
		rcWindow.OffsetRect(m_szTerm);
		// 알림 창이 이동할 끝 위치까지 왔다면
		if(rcWindow.left == m_ptEnd.x && rcWindow.top == m_ptEnd.y)
		{
			// 나타나는 타이머를 멈추고, 보여주기 위한 타이머를 시작
			KillTimer(nIDEvent);
			m_nTimerID = SetTimer(CONST_TIMER_SHOW, m_nTimeShow, NULL);
		}
		break;
	case CONST_TIMER_SHOW:
		// 알림 창을 보여주는 시간이 지났다면
		// 보여주기 위한 타이머를 멈추고, 사라지는 타이머를 시작
		KillTimer(nIDEvent);
		m_nTimerID = SetTimer(CONST_TIMER_DOWN, m_nTimeDown, NULL);
		break;
	case CONST_TIMER_DOWN:
		// 알림 창이 사라지는 중이라면
		// 알림 창의 위치를 옮기고
		rcWindow.OffsetRect(-1 * m_szTerm.cx, -1 * m_szTerm.cy);
		// 알림 창의 원래 시작 위치까지 왔다면
		if(rcWindow.left == m_ptStart.x && rcWindow.top == m_ptStart.y)
		{
			// 사라지는 타이머 멈춤
			KillTimer(nIDEvent);
		}
		break;
	}

	// 알림 창 위치 옮김
	SetWindowPos(NULL, rcWindow.left, rcWindow.top,
		m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, SWP_NOZORDER | SWP_NOACTIVATE | SWP_SHOWWINDOW);
	
	CDialog::OnTimer(nIDEvent);
}

// 배경 이미지 설정 함수
void CMsnNotifyDlg::SetBitmap(UINT nBitmap)
{
	if(m_bmpBkgnd.m_hObject)		m_bmpBkgnd.DeleteObject();
	m_bmpBkgnd.LoadBitmap(nBitmap);
	m_bmpBkgnd.GetBitmap(&m_bmpInfo);

	// 메시지 텍스트 출력 영역을 배경 이미지 크기로 설정
	m_rcMessage.SetRect(0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight);

	// 배경 이미지에 따른 영역 설정
	InitPosition();
}

// 배경 이미지 설정 함수
void CMsnNotifyDlg::SetBitmap(LPCTSTR pFileName)
{
	if(m_bmpBkgnd.m_hObject)		m_bmpBkgnd.DeleteObject();

	// 배경 비트맵을 파일에서 읽음
	HBITMAP hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			LPCTSTR(pFileName), IMAGE_BITMAP,
			0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	m_bmpBkgnd.Attach(hBitmap);
	m_bmpBkgnd.GetBitmap(&m_bmpInfo);

	// 메시지 텍스트 출력 영역을 배경 이미지 크기로 설정
	m_rcMessage.SetRect(0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight);

	// 배경 이미지에 따른 영역 설정
	InitPosition();
}

// 배경 이미지에 따른 영역 설정 함수
void CMsnNotifyDlg::InitPosition()
{
	// 작업표시줄을 제외한 작업 영역 획득
	CRect rcWorkArea;
	::SystemParametersInfo(SPI_GETWORKAREA, 0, &rcWorkArea, 0);

	// 화면 크기 획득
	int nScreenWidth	= ::GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight	= ::GetSystemMetrics(SM_CYSCREEN);

	if(rcWorkArea.left > 0)
	{
		// 작업 표시줄이 왼쪽에 있다면, 알림 창이 왼쪽에서 나타나도록 위치 설정
		m_ptStart.x = rcWorkArea.left - m_bmpInfo.bmWidth;
		m_ptStart.y = rcWorkArea.bottom - m_bmpInfo.bmHeight;
		m_ptEnd.x = rcWorkArea.left;
		m_ptEnd.y = m_ptStart.y;
		m_szTerm.cx = CONST_INCREMENT;
		m_szTerm.cy = 0;
	}
	if(rcWorkArea.right < nScreenWidth)
	{
		// 작업 표시줄이 오른쪽에 있다면, 알림 창이 오른쪽에서 나타나도록 위치 설정
		m_ptStart.x = rcWorkArea.right;
		m_ptStart.y = rcWorkArea.bottom - m_bmpInfo.bmHeight;
		m_ptEnd.x = rcWorkArea.right - m_bmpInfo.bmWidth;
		m_ptEnd.y = m_ptStart.y;
		m_szTerm.cx = -CONST_INCREMENT;
		m_szTerm.cy = 0;
	}
	if(rcWorkArea.top > 0)
	{
		// 작업 표시줄이 윗쪽에 있다면, 알림 창이 위쪽에서 나타나도록 위치 설정
		m_ptStart.x = rcWorkArea.right - m_bmpInfo.bmWidth;
		m_ptStart.y = rcWorkArea.top - m_bmpInfo.bmHeight;
		m_ptEnd.x = m_ptStart.x;
		m_ptEnd.y = rcWorkArea.top;
		m_szTerm.cx = 0;
		m_szTerm.cy = CONST_INCREMENT;
	}
	if(rcWorkArea.bottom < nScreenHeight)
	{
		// 작업 표시줄이 아랫쪽에 있다면, 알림 창이 아래쪽에서 나타나도록 위치 설정
		m_ptStart.x = rcWorkArea.right - m_bmpInfo.bmWidth;
		m_ptStart.y = rcWorkArea.bottom;
		m_ptEnd.x = m_ptStart.x;
		m_ptEnd.y = rcWorkArea.bottom - m_bmpInfo.bmHeight;
		m_szTerm.cx = 0;
		m_szTerm.cy = -CONST_INCREMENT;
	}

	// 알림 창이 보이고 있는 상태라면 
	if(::IsWindow(m_hWnd))
	{
		// 알림 창의 위치/크기 재조정
		SetWindowPos(NULL, 0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, SWP_NOZORDER | SWP_NOMOVE);
	}
}

// 메시지 텍스트 출력용 폰트 설정 함수
void CMsnNotifyDlg::SetTextFont(LPCTSTR pFontName, int nPoint)
{
	// 기존 폰트들 소멸
	if(m_MessageFont.m_hObject)		m_MessageFont.DeleteObject();
	if(m_HotFont.m_hObject)			m_HotFont.DeleteObject();

	// 새로운 폰트 이름과 크기로 폰트 재 생성
	HDC hDC = ::GetDC(NULL);
	m_MessageFont.CreateFont(-MulDiv(nPoint, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, pFontName);
	m_HotFont.CreateFont(-MulDiv(nPoint, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_BOLD,
		0, TRUE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, pFontName);
	::ReleaseDC(NULL, hDC);
}

// 알림 창 출력 함수
void CMsnNotifyDlg::Show()
{
	// 현재 진행 중인 타이머가 있다면 정지
	if(m_nTimerID)		KillTimer(m_nTimerID);

	// 알림 창을 화면에 출력
	SetWindowPos(NULL, m_ptStart.x, m_ptStart.y,
		m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, SWP_NOZORDER | SWP_NOACTIVATE | SWP_SHOWWINDOW);

	// 알림 창이 나타나는 타이머 시작
	m_nTimerID = SetTimer(CONST_TIMER_UP, m_nTimeUp, NULL);
}

// 알림 창 감추는 함수
void CMsnNotifyDlg::Hide()
{
	// 현재 진행 중인 타이머가 있다면 정지
	if(m_nTimerID)		KillTimer(m_nTimerID);

	// 알림 창이 사라지는 타이머 시작
	m_nTimerID = SetTimer(CONST_TIMER_DOWN, m_nTimeDown, NULL);
}
