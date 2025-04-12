// CaptureWindow.cpp : implementation file
//

#include "stdafx.h"
#include "CaptureWindowdemo.h"
#include "CaptureWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCaptureWindow

CCaptureWindow::CCaptureWindow()
{
	// 멤버 변수들의 값을 초기화한다
	m_bmpSelector.LoadBitmap(IDB_SELECT);
	m_bmpSelectorButton.LoadBitmap(IDB_SELECT_BUTTON);

	m_hSelectorCursor = AfxGetApp()->LoadCursor(IDC_SELECT_CURSOR);
	m_hLastHWND		= NULL;
}

CCaptureWindow::~CCaptureWindow()
{
	// GDI 리소스들을 해제한다
	m_bmpSelector.DeleteObject();
	m_bmpSelectorButton.DeleteObject();

	::DeleteObject(m_hSelectorCursor);

	if(m_bmpCapture.m_hObject)	m_bmpCapture.DeleteObject();
}


BEGIN_MESSAGE_MAP(CCaptureWindow, CStatic)
	//{{AFX_MSG_MAP(CCaptureWindow)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCaptureWindow message handlers

void CCaptureWindow::PreSubclassWindow() 
{
	// 스태틱 컨트롤의 메시지를 수신하기 위해 SS_NOTIFY 속성을 설정한다
	ModifyStyle(0, SS_NOTIFY);

	// 초기 비트맵을 설정한다
	SetBitmap(m_bmpSelector); 
	
	CStatic::PreSubclassWindow();
}

void CCaptureWindow::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 마지막 마우스가 위치한 윈도우의 핸들을 저장하는 변수를 초기화한다
	m_hLastHWND = NULL;

	// 부모 윈도우에게 윈도우 선택이 시작됨을 알린다
	CWnd *pParent = GetParent();
	if(pParent)		pParent->SendMessage(WM_SELECT_START, 0, (LPARAM)this);

	// 애플리케이션을 최소화 한다
	AfxGetMainWnd()->ShowWindow(SW_SHOWMINNOACTIVE);

	// 윈도우 선택 상태의 비트맵을 설정한다
	SetBitmap(m_bmpSelectorButton);

	// 마우스 커서의 모양을 바꾼다
	::SetCursor(m_hSelectorCursor);
	// 마우스의 이벤트를 캡춰한다
	SetCapture();
	
	CStatic::OnLButtonDown(nFlags, point);
}

void CCaptureWindow::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 현재 마우스를 캡춰하는 중이라면
	if(GetCapture() == this)
	{
		// 마우스의 위치를 저장한다
		CPoint ptScreen = point;

		// 윈도우 좌표계로 변경한다
		ClientToScreen(&ptScreen);

		// 해당 좌표의 윈도우 핸들을 구한다
		HWND hWnd = ::WindowFromPoint(ptScreen);
		if(hWnd)
		{
			// 마지막 마우스가 위치했던 윈도우가 아니라면
			if(hWnd != m_hLastHWND)
			{ 
				// 이전 윈도우의 테두리 표시를 지운다
				if(m_hLastHWND)		InvertWindowEdge(m_hLastHWND);

				// 마지막 위치한 윈도우로 저장한다
				m_hLastHWND = hWnd; 

				// 윈도우의 외곽에 테두리를 그린다
				InvertWindowEdge(m_hLastHWND);
			} 
		}
	}
	
	CStatic::OnMouseMove(nFlags, point);
}

// 특정 윈도우의 외곽에 테두리를 그리는 함수
void CCaptureWindow::InvertWindowEdge(HWND hWnd)
{
	RECT stRect;

	// 해당 윈도우의 위치를 구한다
	::GetWindowRect(hWnd, &stRect);

	// 해당 윈도우의 윈도우 DC를 구한다
	HDC hDC = ::GetWindowDC(hWnd);

	// 역상 출력 속성을 설정한다
	SetROP2(hDC, R2_NOT);

	// 시스템의 테두리 두께의 5배 굵기로 검은색 펜을 생성한다
	HPEN hPen = CreatePen(PS_INSIDEFRAME, 5 * GetSystemMetrics(SM_CXBORDER), RGB(0,0,0));

	// 생성한 펜을 설정한다
	HPEN   hOldPen   = (HPEN)SelectObject(hDC, hPen);
	// 투명 브러쉬를 설정한다
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, GetStockObject(NULL_BRUSH));

	// 윈도우의 외곽에 사각 테두리를 출력한다
	Rectangle(hDC, 0, 0, stRect.right - stRect.left, stRect.bottom - stRect.top);

	// 이전 객체들을 되돌린다
	SelectObject(hDC, hOldBrush);
	SelectObject(hDC, hOldPen);

	// DC를 반환한다
	::ReleaseDC(hWnd, hDC);

	// 펜을 제거한다
	DeleteObject(hPen);
}

void CCaptureWindow::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// 현재 마우스를 캡춰하는 중이라면
	if(GetCapture() == this)
	{
		// 마우스 이벤트 캡춰를 종료한다
		ReleaseCapture(); 

		// 마지막 마우스가 위치했던 윈도우의 테두리를 지운다
		if(m_hLastHWND)		InvertWindowEdge(m_hLastHWND);

		// 윈도우 선택 전 상태의 비트맵을 설정한다
		SetBitmap(m_bmpSelector); 
		
		// 부모 윈도우에게 윈도우 선택이 끝났음을 알린다
		CWnd *pParent = GetParent();
		if(pParent)		pParent->SendMessage(WM_SELECT_END, 0, (LPARAM)this);

		// 만약 찾아진 윈도우가 없다면 메시지 박스를 출력한다
		if(m_hLastHWND == NULL)
		{
			MessageBox("선택한 윈도우가 없습니다.\n\n선택 버튼을 움직여서 윈도우를 선택하세요.");
		}
		else
		{
			// 이전에 캡춰된 비트맵을 제거한다
			if(m_bmpCapture.m_hObject)
				m_bmpCapture.DeleteObject();

			// 선택된 윈도우의 영역을 구한다
			CRect rcWindow;
			::GetWindowRect(m_hLastHWND, &rcWindow);

			// 선택된 윈도우의 DC를 구한다
			HDC hDC = ::GetWindowDC(m_hLastHWND);
			CDC dc, MemDC;

			// 메모리 DC를 생성한다
			dc.Attach(hDC);
			MemDC.CreateCompatibleDC(&dc);

			// 캡춰되는 화면을 저장할 비트맵을 생성한다
			m_bmpCapture.CreateCompatibleBitmap(&dc, rcWindow.Width(), rcWindow.Height());
			CBitmap *pOldBmp = MemDC.SelectObject(&m_bmpCapture);

			// 윈도우의 내용을 비트맵에 저장한다
			MemDC.BitBlt(0, 0, rcWindow.Width(), rcWindow.Height(),
				&dc, 0, 0, SRCCOPY);

			// 리소소를 반환한다
			MemDC.SelectObject(pOldBmp);
			MemDC.DeleteDC();
			dc.Detach();
		}

		m_hLastHWND = NULL; 

		// 애플리케이션의 크기를 원래대로 되돌린다
		AfxGetMainWnd()->ShowWindow(SW_SHOWNORMAL);

		// 부모 윈도우에게 캡춰를 완료하였음을 알린다
		if(pParent)
			pParent->SendMessage(WM_CAPTURE_FINISH, (WPARAM)m_hLastHWND, (LPARAM)this);
	}
	
	CStatic::OnLButtonUp(nFlags, point);
}
