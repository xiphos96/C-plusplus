// DialogSplitterWnd.cpp : implementation file
//

#include "stdafx.h"
#include "dialogsplitterwnddemo.h"
#include "DialogSplitterWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogSplitterWnd

// 스플리터와 컨트롤, 다이얼로그의 변 사이의 여백
#define CONST_SPLITTER_MARGIN	3


CDialogSplitterWnd::CDialogSplitterWnd()
{
	// 멤버 변수들의 값을 초기화한다
	m_nDirection	= DIR_HORZ;
	m_bCapture		= FALSE;

	m_nLeftRange	= -1;
	m_nRightRange	= -1;

	m_clrSplitter	= ::GetSysColor(COLOR_3DFACE);

	m_hHorzCursor	= NULL;
	m_hVertCursor	= NULL;
}

CDialogSplitterWnd::~CDialogSplitterWnd()
{
	int i, nSize;
	SControlInfo *pControl;

	// 스플리터 좌측 혹은 상단 컨트롤들에 대한 정보 구조체를 삭제한다
	nSize = m_LeftControls.GetSize();
	for(i = 0; i < nSize; i++)
	{
		pControl = m_LeftControls.GetAt(i);
		delete pControl;
	}
	m_LeftControls.RemoveAll();

	// 스프리터 우측 혹은 하단 컨트롤들에 대한 정보 구조체를 삭제한다
	nSize = m_RightControls.GetSize();
	for(i = 0; i < nSize; i++)
	{
		pControl = m_RightControls.GetAt(i);
		delete pControl;
	}
	m_RightControls.RemoveAll();

	// 스플리터의 커서들을 삭제한다
	if(m_hHorzCursor)		::DeleteObject(m_hHorzCursor);
	if(m_hVertCursor)		::DeleteObject(m_hVertCursor);
}


BEGIN_MESSAGE_MAP(CDialogSplitterWnd, CStatic)
	//{{AFX_MSG_MAP(CDialogSplitterWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_SETCURSOR()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogSplitterWnd message handlers

void CDialogSplitterWnd::PreSubclassWindow() 
{
	// 스태틱 컨트롤의 알림 메시지 속성을 설정한다
	ModifyStyle(0, SS_NOTIFY);

	// 수평 스플리터를 위한 커서를 로드한다
	m_hHorzCursor = ::LoadCursor(NULL, IDC_SIZENS);
	// 수직 스플리터를 위한 커서를 로드한다
	m_hVertCursor = ::LoadCursor(NULL, IDC_SIZEWE);

	CStatic::PreSubclassWindow();
}

// 스플리터의 방향을 설정하는 함수
void CDialogSplitterWnd::SetDirection(SPLITTER_DIR nDir)
{
	// 방향을 저장한다
	m_nDirection = nDir;

	CWnd *pParent = GetParent();

	// 스플리터의 윈도우 좌표를 구한다
	CRect rcSplitter;
	GetWindowRect(&rcSplitter);
	// 부모 다이얼로그 기준의 좌표로 변환한다
	pParent->ScreenToClient(&rcSplitter);

	// 만약 수평 스플리터라면 top 좌표를 초기 위치로 저장한다
	if(m_nDirection == DIR_HORZ)	m_nInitPos = rcSplitter.top;
	// 만약 수직 스플리터라면 left 좌표를 초기 위치로 저장한다
	else							m_nInitPos = rcSplitter.left;
}

// 스플리터의 이동 범위를 설정하는 함수
void CDialogSplitterWnd::SetRange(int nLeft, int nRight)
{
	// 스플리터의 이동 가능 범위를 저장한다
	m_nLeftRange = nLeft;
	m_nRightRange = nRight;
}

// 스플리터에 컨트롤을 추가하는 함수
int CDialogSplitterWnd::AddControl(CONTROL_POS nPos, CWnd *pControl, BOOL bStretch)
{
	// 부모 다이얼로그의 포인터를 얻는다
	CWnd *pParent = GetParent();

	// 스플리터의 다이얼로그 기준 좌표를 구한다
	CRect rcSplitter;
	GetWindowRect(&rcSplitter);
	pParent->ScreenToClient(&rcSplitter);

	// 컨트롤의 다이얼로그 기준 좌표를 구한다
	CRect rcControl;
	pControl->GetWindowRect(&rcControl);
	pParent->ScreenToClient(&rcControl);

	// 새로운 컨트롤 정보 구조체를 생성한다
	SControlInfo *pNewControl = new SControlInfo;
	// 컨트롤의 윈도우 포인터와 크기 늘림 여부를 저장한다
	pNewControl->pWnd		= pControl;
	pNewControl->bStretch	= bStretch;

	int nSize; 

	// 만약 좌측 혹은 상단의 컨트롤이라면
	if(nPos == POS_LEFT || nPos == POS_TOP)
	{
		// 좌측 혹은 상단 컨트롤 배열에 컨트롤 정보를 추가한다
		nSize = m_LeftControls.Add(pNewControl);

		// 만약 스플리터가 수평이라면
		if(m_nDirection == DIR_HORZ)
		{
			// 컨트롤의 bottom 좌표를 저장한다
			pNewControl->nPos = rcControl.bottom;

			// 만약 컨트롤이 스플리터보다 아래에 있다면 컨트롤을 감춘다
			if(rcControl.top > rcSplitter.top)			pControl->ShowWindow(SW_HIDE);
			else
				// 만약 컨트롤의 아래면이 스플리터를 넘어가면
				if(rcControl.bottom > rcSplitter.top)
				{
					// 컨트롤의 아래면이 스플리터를 넘지 않도록 조정한다
					rcControl.bottom = rcSplitter.top - CONST_SPLITTER_MARGIN;
					pControl->MoveWindow(&rcControl);
				}
		}
		else
		{
			// 만약 스플리터가 수직이라면
			// 컨트롤의 right 좌표를 저장한다
			pNewControl->nPos = rcControl.right;

			// 만약 컨트롤이 스플리터보다 오른쪽에 있다면 컨트롤을 감춘다
			if(rcControl.left > rcSplitter.left)		pControl->ShowWindow(SW_HIDE);
			else
				// 만약 컨트롤의 우측면이 스플리터를 넘어가면
				if(rcControl.right > rcSplitter.left)
				{
					// 컨트롤의 우측면이 스플리터를 넘지 않도록 조정한다
					rcControl.right = rcSplitter.left - CONST_SPLITTER_MARGIN;
					pControl->MoveWindow(&rcControl);
				}
		}
	}
	// 만약 우측 혹은 하단의 컨트롤이라면
	if(nPos == POS_RIGHT || nPos == POS_BOTTOM)
	{
		// 우측 혹은 하단 컨트롤 배열에 컨트롤 정보를 추가한다
		nSize = m_RightControls.Add(pNewControl);

		// 만약 스플리터가 수평이라면
		if(m_nDirection == DIR_HORZ)
		{
			// 컨트롤의 top 좌표를 저장한다
			pNewControl->nPos = rcControl.top;

			// 만약 컨트롤이 스플리터보다 위쪽에 있다면 컨트롤을 감춘다
			if(rcControl.bottom < rcSplitter.bottom)	pControl->ShowWindow(SW_HIDE);
			else
				// 만약 컨트롤의 위쪽면이 스플리터를 넘어가면
				if(rcControl.top < rcSplitter.bottom)
				{
					// 컨트롤의 위쪽면이 스플리터를 넘지 않도록 조정한다
					rcControl.top = rcSplitter.bottom + CONST_SPLITTER_MARGIN;
					pControl->MoveWindow(&rcControl);
				}
		}
		else
		{
			// 만약 스플리터가 수직이라면
			// 컨트롤의 left 좌표를 저장한다
			pNewControl->nPos = rcControl.left;

			// 만약 컨트롤이 스플리터보다 왼쪽에 있다면 컨트롤을 감춘다
			if(rcControl.right < rcSplitter.right)		pControl->ShowWindow(SW_HIDE);
			else
				// 만약 컨트롤의 왼쪽면이 스플리터를 넘어가면
				if(rcControl.left < rcSplitter.right)
				{
					// 컨트롤의 왼쪽면이 스플리터를 넘지 않도록 조정한다
					rcControl.left = rcSplitter.right + CONST_SPLITTER_MARGIN;
					pControl->MoveWindow(&rcControl);
				}
		}
	}

	return nSize;
}

void CDialogSplitterWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// 스플리터의 클라이언트 영역을 구한다
	CRect rcSplitter;
	GetClientRect(&rcSplitter);

	// 클라이언트를 배경색으로 칠한다
	dc.FillSolidRect(rcSplitter, m_clrSplitter);

	// 스플리터의 외곽에 버튼 모양 테두리를 출력한다
	dc.DrawEdge(rcSplitter, EDGE_RAISED, BF_RECT);
}

BOOL CDialogSplitterWnd::OnEraseBkgnd(CDC* pDC) 
{
	// 스플리터의 배경은 지우지 않는다
	return TRUE;
//	return CStatic::OnEraseBkgnd(pDC);
}

void CDialogSplitterWnd::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 마우스 이벤트를 캡춰한다
	SetCapture();
	m_bCapture = TRUE;
	
	CStatic::OnLButtonDown(nFlags, point);
}

void CDialogSplitterWnd::OnMouseMove(UINT nFlags, CPoint point) 
{
	//만약 마우스 좌측 버튼을 누른 상태로 이동이고 마우스 이벤트를 캡춰하고 있다면
	if(m_bCapture && nFlags == MK_LBUTTON)
	{
		CPoint ptCursor = point;
		CWnd *pParent = GetParent();

		// 부모 다이얼로그의 클라이언트 영역을 구한다
		CRect rcParent;
		pParent->GetClientRect(&rcParent);

		// 현재 커서 위치를 다이얼로그 기준 좌표로 변환한다
		ClientToScreen(&ptCursor);
		pParent->ScreenToClient(&ptCursor);

		// 스플리터의 좌표를 얻어 다이얼로그 기준 좌표로 변환한다
		CRect rcSplitter, rcOldSplitter;
		GetWindowRect(&rcSplitter);
		pParent->ScreenToClient(&rcSplitter);
		rcOldSplitter = rcSplitter;

		// 만약 수평 스플리터라면
		if(m_nDirection == DIR_HORZ)
		{
			// 스플리터의 높이를 구한다
			int nHeight = rcSplitter.Height();

			// 현재 마우스 위치를 수직 중앙으로 하는 스플리터 좌표를 계산한다
			rcSplitter.top = ptCursor.y - (nHeight / 2);
			rcSplitter.bottom = rcSplitter.top + nHeight;

			// 만약 상단 이동 범위가 지정되어 있다면
			if(m_nLeftRange >= 0)
			{
				// 초기 위치에서 이동 범위를 초과하였는지 검사한다
				if(m_nInitPos - m_nLeftRange > rcSplitter.top)
				{
					// 이동 범위 만큼의 좌표로 조정한다
					rcSplitter.top = m_nInitPos - m_nLeftRange;
					rcSplitter.bottom = rcSplitter.top + nHeight;
				}
			}
			// 만약 하단 이동 범위가 지정되어 있다면
			if(m_nRightRange >= 0)
			{
				// 초기 위치에서 이동 범위를 초과하였는지 검사한다
				if(m_nInitPos + m_nRightRange < rcSplitter.top)
				{
					// 이동 범위 만큼의 좌표로 조정한다
					rcSplitter.top = m_nInitPos + m_nRightRange;
					rcSplitter.bottom = rcSplitter.top + nHeight;
				}
			}

			// 만약 다이얼로그의 위쪽 면을 스플리터가 넘어서면
			if(rcParent.top + CONST_SPLITTER_MARGIN > rcSplitter.top)
			{
				// 다이얼로그의 상단 면까지의 좌표로 조정한다
				rcSplitter.top = rcParent.top + CONST_SPLITTER_MARGIN;
				rcSplitter.bottom = rcSplitter.top + nHeight;
			}
			// 만약 다이얼로그의 아래쪽 면을 스플리터가 넘어서면
			if(rcParent.bottom - CONST_SPLITTER_MARGIN < rcSplitter.bottom)
			{
				// 다이얼로그의 하단 면까지의 좌표로 조정한다
				rcSplitter.bottom = rcParent.bottom - CONST_SPLITTER_MARGIN;
				rcSplitter.top = rcSplitter.bottom - nHeight;
			}
		}
		else
		{
			// 만약 수직 스플리터라면 스플리터의 폭을 구한다
			int nWidth = rcSplitter.Width();

			// 현재 마우스 위치를 수평 중앙으로 하는 스플리터 좌표를 계산한다
			rcSplitter.left = ptCursor.x - (nWidth / 2);
			rcSplitter.right = rcSplitter.left + nWidth;

			// 만약 좌측 이동 범위가 지정되어 있다면
			if(m_nLeftRange >= 0)
			{
				// 추기 위치에서 이동 범위를 초과하였는지 검사한다
				if(m_nInitPos - m_nLeftRange > rcSplitter.left)
				{
					// 이동 범위 만큼의 좌표로 조정한다
					rcSplitter.left = m_nInitPos - m_nLeftRange;
					rcSplitter.right = rcSplitter.top + nWidth;
				}
			}
			// 만약 우측 이동 범위가 지정되어 있다면
			if(m_nRightRange >= 0)
			{
				// 초기 위치에서 이동 범위를 초과하였는지 검사한다
				if(m_nInitPos + m_nRightRange < rcSplitter.left)
				{
					// 이동 범위 만큼의 좌표로 조정한다
					rcSplitter.left = m_nInitPos + m_nRightRange;
					rcSplitter.right = rcSplitter.left + nWidth;
				}
			}

			// 만약 다이얼로그의 왼쪽 면을 스플리터가 넘어서면
			if(rcParent.left + CONST_SPLITTER_MARGIN > rcSplitter.left)
			{
				// 다이얼로그의 좌측 면까지의 좌표로 조정한다
				rcSplitter.left = rcParent.left + CONST_SPLITTER_MARGIN;
				rcSplitter.right = rcSplitter.left + nWidth;
			}
			// 만약 다이얼로그의 오른쪽 면을 스플리터가 넘어서면
			if(rcParent.right - CONST_SPLITTER_MARGIN < rcSplitter.right)
			{
				// 다이얼로그의 우측 면까지의 좌표로 조정한다
				rcSplitter.right = rcParent.right - CONST_SPLITTER_MARGIN;
				rcSplitter.left = rcSplitter.right - CONST_SPLITTER_MARGIN;
			}
		}

		if(rcSplitter.EqualRect(&rcOldSplitter))
		{
			CStatic::OnMouseMove(nFlags, point);
			return;
		}

		// 다이얼로그가 갱신되는 것을 중지한다
		pParent->LockWindowUpdate();

		// 스플리터를 이동시킨다
		MoveWindow(rcSplitter);

		CRect rcControl;
		int i, nSize, nGap;
		SControlInfo *pControl;

		// 모든 좌측 혹은 상단 컨트롤들에 대해
		nSize = m_LeftControls.GetSize();
		for(i = 0; i < nSize; i++)
		{
			// 좌측 혹은 상단 컨트롤에 대한 정보 구조체를 얻는다
			pControl = m_LeftControls.GetAt(i);

			// 컨트롤의 다이얼로그 기준 좌표를 구한다
			pControl->pWnd->GetWindowRect(&rcControl);
			pParent->ScreenToClient(&rcControl);

			// 스플리터와 컨트롤 사이의 간격을 정한다
			if(pControl->bStretch)		nGap = m_nInitPos - pControl->nPos;
			else						nGap = CONST_SPLITTER_MARGIN;

			// 만약 수평 스플리터라면
			if(m_nDirection == DIR_HORZ)
			{
				// 컨트롤의 bottom 좌표를 초기 bottom 좌표로 설정한다
				rcControl.bottom = pControl->nPos;

				// 만약 컨트롤의 아래쪽 면이 스플리터를 넘어선다면
				if(rcControl.bottom + nGap > rcSplitter.top)
				{
					// 만약 컨트롤의 위쪽 면도 스플리터를 넘어선다면
					if(rcControl.top + nGap > rcSplitter.top)
						// 컨트롤을 감춘다
						pControl->pWnd->ShowWindow(SW_HIDE);
					else
					{
						// 컨트롤의 아래쪽 면이 스플리터를 넘어서지 않도록 좌표를 조정한다
						rcControl.bottom = rcSplitter.top - nGap;
						// 만약 아래쪽면이 위쪽면보다 위가 된다면 조정한다
						if(rcControl.bottom < rcControl.top)	rcControl.bottom = rcControl.top;
						// 컨트롤을 이동시킨다
						pControl->pWnd->MoveWindow(&rcControl);
						pControl->pWnd->ShowWindow(SW_SHOW);
					}
				}
				else
				{
					// 만약 컨트롤의 크기가 늘려질 수 있다면
					if(pControl->bStretch)
					{
						// 스플리터와 컨트롤 사이의 간격이 초기 간격보다 커졌다면
						if(rcControl.bottom + nGap < rcSplitter.top)
						{
							// 초기 간격을 유지하도록 컨트롤의 크기를 늘린다
							rcControl.bottom = rcSplitter.top - nGap;
							pControl->pWnd->MoveWindow(&rcControl);
							pControl->pWnd->ShowWindow(SW_SHOW);
						}
					}
				}
			}
			else
			{
				// 만약 수직 스플리터라면 컨트롤의 right 좌표를 초기 right 좌표로 설정한다
				rcControl.right = pControl->nPos;

				// 만약 컨트롤의 오른쪽 면이 스플리터를 넘어선다면
				if(rcControl.right + nGap > rcSplitter.left)
				{
					// 만약 컨트롤의 왼쪽 면도 스플리터를 넘어선다면
					if(rcControl.left + nGap > rcSplitter.left)
						// 컨트롤을 감춘다
						pControl->pWnd->ShowWindow(SW_HIDE);
					else
					{
						// 컨트롤의 오른쪽 면이 스플리터를 넘어서지 않도록 좌표를 조정한다
						rcControl.right = rcSplitter.left - nGap;
						// 만약 오른쪽면이 왼쪽면보다 왼쪽에 있다면 조정한다
						if(rcControl.right < rcControl.left)	rcControl.right = rcControl.left;
						// 컨트롤을 이동시킨다
						pControl->pWnd->MoveWindow(&rcControl);
						pControl->pWnd->ShowWindow(SW_SHOW);
					}
				}
				else
				{
					// 만약 컨트롤의 크기가 늘려질 수 있다면
					if(pControl->bStretch)
					{
						// 스플리터와 컨트롤 사이의 간격이 초기 간격보다 커졌다면
						if(rcControl.right + nGap < rcSplitter.left)
						{
							// 초기 간격을 유지하도록 컨트롤의 크기를 늘린다
							rcControl.right = rcSplitter.left - nGap;
							pControl->pWnd->MoveWindow(&rcControl);
							pControl->pWnd->ShowWindow(SW_SHOW);
						}
					}
				}
			}
		}

		// 모든 우측 혹은 하단 컨트롤들에 대해
		nSize = m_RightControls.GetSize();
		for(i = 0; i < nSize; i++)
		{
			// 우측 혹은 하단 컨트롤에 대한 정보 구조체를 얻는다
			pControl = m_RightControls.GetAt(i);

			// 컨트롤의 다이얼로그 기준 좌표를 구한다
			pControl->pWnd->GetWindowRect(&rcControl);
			pParent->ScreenToClient(&rcControl);

			// 스플리터와 컨트롤 사이의 간격을 정한다
			if(pControl->bStretch)		nGap = pControl->nPos - m_nInitPos;
			else						nGap = CONST_SPLITTER_MARGIN;

			// 만약 수평 스플리터라면
			if(m_nDirection == DIR_HORZ)
			{
				// 컨트롤의 top 좌표를 초기 top 좌표로 설정한다
				rcControl.top = pControl->nPos;

				// 만약 컨트롤의 위쪽 면이 스플리터를 넘어선다면
				if(rcControl.top - nGap < rcSplitter.bottom)
				{
					// 만약 컨트롤의 아래쪽 면도 스플리터를 넘어선다면
					if(rcControl.bottom - nGap < rcSplitter.bottom)
						// 컨트롤을 감춘다
						pControl->pWnd->ShowWindow(SW_HIDE);
					else
					{
						// 컨트롤의 위쪽 면이 스플리터를 넘어서지 않도록 좌표를 조정한다
						rcControl.top = rcSplitter.bottom + nGap;
						// 만약 위쪽면이 아래쪽면보다 아래가 된다면 조정한다
						if(rcControl.top > rcControl.bottom)	rcControl.top = rcControl.bottom;
						// 컨트롤을 이동시킨다
						pControl->pWnd->MoveWindow(&rcControl);
						pControl->pWnd->ShowWindow(SW_SHOW);
					}
				}
				else
				{
					// 만약 컨트롤의 크기가 늘려질 수 있다면
					if(pControl->bStretch)
					{
						// 스플리터와 컨트롤 사이의 간격이 초기 간격보다 커졌다면
						if(rcControl.top - nGap > rcSplitter.top)
						{
							// 초기 간격을 유지하도록 컨트롤의 크기를 늘린다
							rcControl.top = rcSplitter.top + nGap;
							pControl->pWnd->MoveWindow(&rcControl);
							pControl->pWnd->ShowWindow(SW_SHOW);
						}
					}
				}
			}
			else
			{
				// 만약 수직 스플리터라면 컨트롤의 left 좌표를 초기 left 좌표로 설정한다
				rcControl.left = pControl->nPos;

				// 만약 컨트롤의 왼쪽 면이 스플리터를 넘어선다면
				if(rcControl.left - nGap < rcSplitter.right)
				{
					// 만약 컨트롤의 오른쪽 면도 스플리터를 넘어선다면
					if(rcControl.right - nGap < rcSplitter.right)
						// 컨트롤을 감춘다
						pControl->pWnd->ShowWindow(SW_HIDE);
					else
					{
						// 컨트롤의 왼쪽 면이 스플리터를 넘어서지 않도록 좌표를 조정한다
						rcControl.left = rcSplitter.right + nGap;
						// 만약 왼쪽면이 오른쪽면보다 오른쪽에 있다면 조정한다
						if(rcControl.left > rcControl.right)		rcControl.left = rcControl.right;
						// 컨트롤을 이동시킨다
						pControl->pWnd->MoveWindow(&rcControl);
						pControl->pWnd->ShowWindow(SW_SHOW);
					}
				}
				else
				{
					// 만약 컨트롤의 크기가 늘려질 수 있다면
					if(pControl->bStretch)
					{
						// 스플리터와 컨트롤 사이의 간격이 초기 간격보다 커졌다면
						if(rcControl.left - nGap > rcSplitter.left)
						{
							// 초기 간격을 유지하도록 컨트롤의 크기를 늘린다
							rcControl.left = rcSplitter.left + nGap;
							pControl->pWnd->MoveWindow(&rcControl);
							pControl->pWnd->ShowWindow(SW_SHOW);
						}
					}
				}
			}
		}

		// 다이얼로그가 갱신될 수 있도록 하고 새로 그린다
		pParent->UnlockWindowUpdate();
		pParent->RedrawWindow(NULL, NULL, 
			RDW_INVALIDATE | RDW_NOERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
	}
	
	CStatic::OnMouseMove(nFlags, point);
}

void CDialogSplitterWnd::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// 만약 현재 마우스 이벤트 캡춰 중이라면 캡춰를 멈춘다
	if(m_bCapture)
	{
		ReleaseCapture();
		m_bCapture = FALSE;
	}
	
	CStatic::OnLButtonUp(nFlags, point);
}

BOOL CDialogSplitterWnd::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// 스플리터의 방향에 따라 커서를 설정한다
	if(m_nDirection == DIR_HORZ)	::SetCursor(m_hHorzCursor);
	else							::SetCursor(m_hVertCursor);

	return FALSE;
}

void CDialogSplitterWnd::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);

	// 스플리터의 크기가 변경되었을 경우 스플리터를 다시 그린다
	Invalidate(FALSE);
}
