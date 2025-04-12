// CustomSliderCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "customsliderctrldemo.h"
#include "CustomSliderCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomSliderCtrl

CCustomSliderCtrl::CCustomSliderCtrl()
{
	// 멤버 변수들의 값을 초기화한다
	m_clrThumb		= RGB(255, 255, 255);
	m_clrSelection	= RGB(150, 150, 150);
	m_clrChannel	= RGB(86, 86, 86);

	// 범위 출력용 브러쉬를 생성한다
	m_brsChannel.CreateSolidBrush(m_clrChannel);

	m_bHorz			= TRUE;
}

CCustomSliderCtrl::~CCustomSliderCtrl()
{
	// 브러쉬를 소멸시킨다
	m_brsChannel.DeleteObject();
}


BEGIN_MESSAGE_MAP(CCustomSliderCtrl, CSliderCtrl)
	//{{AFX_MSG_MAP(CCustomSliderCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomdraw)
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomSliderCtrl message handlers

void CCustomSliderCtrl::PreSubclassWindow() 
{
	// 수평인지 수직인지 슬라이더 스타일에서 알아낸다
	m_bHorz = !(GetStyle() & TBS_VERT);

	CSliderCtrl::PreSubclassWindow();
}

// 핸들 색상을 설정하는 함수
void CCustomSliderCtrl::SetThumbColor(COLORREF clrThumb)
{
	// 동일한 색상일 경우 리턴
	if(m_clrThumb == clrThumb)		return;

	// 새로운 색상을 설정한다
	m_clrThumb			= clrThumb;

	// 화면을 새로 그린다
	Invalidate(FALSE);
}

// 선택된 범위의 색상을 설정하는 함수
void CCustomSliderCtrl::SetSelectionColor(COLORREF clrSelection)
{
	// 동일한 색상일 경우 리턴
	if(m_clrSelection == clrSelection)		return;

	// 새로운 색상을 설정한다
	m_clrSelection		= clrSelection;

	// 화면을 새로 그린다
	Invalidate(FALSE);
}

// 선택되지 않은 범위의 색상을 설정하는 함수
void CCustomSliderCtrl::SetChannelColor(COLORREF clrChannel)
{
	// 동일한 색상일 경우 리턴
	if(m_clrChannel == clrChannel)		return;

	// 새로운 색상을 설정한다
	m_clrChannel		= clrChannel;

	// 새로운 색상으로 브러쉬를 다시 생성한다
	if(m_brsChannel.m_hObject)		m_brsChannel.DeleteObject();
	m_brsChannel.CreateSolidBrush(m_clrChannel);

	// 화면을 새로 그린다
	Invalidate(FALSE);
}

// 슬라이더 컨트롤 그리기 메시지
void CCustomSliderCtrl::OnCustomdraw(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LPNMCUSTOMDRAW pDraw = (LPNMCUSTOMDRAW)pNMHDR;

	// 현재 그리기 메시지의 단계
	switch(pDraw->dwDrawStage)
	{
	case CDDS_PREPAINT:
		// 그리기 메시지를 수신하도록 설정한다
		*pResult = CDRF_NOTIFYITEMDRAW;         
		break;
	case CDDS_ITEMPREPAINT:
		// 항목 그리기
		// 기본 루틴을 실행하지 않도록 설정한다
		*pResult = CDRF_SKIPDEFAULT;

		{
			CDC dc;
			dc.Attach(pDraw->hdc);

			switch(pDraw->dwItemSpec)
			{
			case TBCD_TICS:
				// 눈금의 경우는 기본 루틴을 실행하도록 설정한다
				*pResult = CDRF_DODEFAULT;
				break;
			case TBCD_THUMB:
				// 핸들을 그린다
				DrawThumb(&dc, pDraw->rc);
				break;
			case TBCD_CHANNEL:
				// 범위를 그린다
				DrawChannel(&dc, pDraw->rc);
				break;
			}

			dc.Detach();
		}
		break;
	default:
		*pResult = 0;
		break;
	}
}

// 핸들을 그리는 함수
void CCustomSliderCtrl::DrawThumb(CDC *pDC, CRect rcItem)
{
	// 핸들 이동시 범위가 잘 그려지지 않기 때문에,
	// 핸들을 그리기 전에 범위를 우선 한번 출력한다

	// 범위의 영역을 얻는다
	CRect rcChannel;
	GetChannelRect(&rcChannel);

	// 세로 슬라이더의 경우, 범위의 좌표가 가로 형태처럼 리턴되기 때문에 조정해줘야 한다
	if(!m_bHorz)
	{
		// 수직 좌표를 수평 좌표로, 수평 좌표를 수직 좌표로 조정한다
		int nTemp;
		nTemp = rcChannel.left;
		rcChannel.left = rcChannel.top;
		rcChannel.top = nTemp;
		nTemp = rcChannel.right;
		rcChannel.right = rcChannel.bottom;
		rcChannel.bottom = nTemp;
	}

	// 핸들 출력용 DC는 핸들 영역으로 클립핑 되어 있으므로
	// DC를 새로 얻어 범위를 출력한다
	CDC *pClientDC = GetDC();
	DrawChannel(pClientDC, rcChannel);
	ReleaseDC(pClientDC);

	// 핸들의 안쪽을 칠한다
	rcItem.DeflateRect(2, 2);
	pDC->FillSolidRect(rcItem, m_clrThumb);

	// 첫번째 오목한 외곽선을 출력한다
	rcItem.InflateRect(1, 1);
	pDC->Draw3dRect(&rcItem, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DLIGHT));

	// 두번재 볼록한 외곽선을 출력한다
	rcItem.InflateRect(1, 1);
	pDC->Draw3dRect(&rcItem, ::GetSysColor(COLOR_3DLIGHT), ::GetSysColor(COLOR_3DSHADOW));

	CRect rcLine;

	// 안쪽의 두줄 무뉘를 출력한다
	if(m_bHorz)
	{
		rcItem.DeflateRect(0, 5);

		rcLine = rcItem;
		rcLine.left = rcItem.left + rcItem.Width() / 2 - 2;
		rcLine.right = rcLine.left + 2;

		pDC->Draw3dRect(&rcLine, ::GetSysColor(COLOR_3DLIGHT), ::GetSysColor(COLOR_3DSHADOW));

		rcLine = rcItem;
		rcLine.left = rcItem.left + rcItem.Width() / 2 + 1;
		rcLine.right = rcLine.left + 2;

		pDC->Draw3dRect(&rcLine, ::GetSysColor(COLOR_3DLIGHT), ::GetSysColor(COLOR_3DSHADOW));
	}
	else
	{
		rcItem.DeflateRect(5, 0);

		rcLine = rcItem;
		rcLine.top = rcItem.top + rcItem.Height() / 2 - 2;
		rcLine.bottom = rcLine.top + 2;

		pDC->Draw3dRect(&rcLine, ::GetSysColor(COLOR_3DLIGHT), ::GetSysColor(COLOR_3DSHADOW));

		rcLine = rcItem;
		rcLine.top = rcItem.top + rcItem.Height() / 2 + 1;
		rcLine.bottom = rcLine.top + 2;

		pDC->Draw3dRect(&rcLine, ::GetSysColor(COLOR_3DLIGHT), ::GetSysColor(COLOR_3DSHADOW));
	}
}

// 범위를 그리는 함수
void CCustomSliderCtrl::DrawChannel(CDC *pDC, CRect rcItem)
{
	int nMin, nMax, nRangeMin, nRangeMax;

	// 현재 선택된 범위를 얻는다
	GetSelection(nMin, nMax);
	// 슬라이더의 전체 최대/최소값을 얻는다
	nRangeMin = GetRangeMin();
	nRangeMax = GetRangeMax();

	// 최소값을 0으로 바꾸어 최대값과 범위를 조정한다
	nRangeMax	-= nRangeMin;
	nMax		-= nRangeMin;
	nMin		-= nRangeMin;

	// 만약 수평 슬라이더라면
	if(m_bHorz)
	{
		// 범위의 위 아래 위치를 계산한다
		rcItem.top = rcItem.top + rcItem.Height() / 2 - 2;
		rcItem.bottom = rcItem.top + 4;
	}
	else
	{
		// 만약 수직 슬라이더라면 범위의 좌 우 위치를 계산한다
		rcItem.left = rcItem.left + rcItem.Width() / 2 - 2;
		rcItem.right = rcItem.left + 4;
	}

	// 범위를 선택되지 않은 상태의 브러쉬로 모두 칠한다
	CBrush *pOldBrush = pDC->SelectObject(&m_brsChannel);
	pDC->RoundRect(&rcItem, CPoint(6, 6));
	pDC->SelectObject(pOldBrush);

	// 범위 좌표를 모든 방향에서 1 감소 시킨다
	rcItem.DeflateRect(1, 1);

	// 만약 수평 슬라이더라면
	if(m_bHorz)
	{
		// 현재 선택된 범위의 좌/우 위치를 계산한다
		int nWidth = rcItem.Width() + 2;
		rcItem.right	= rcItem.left - 1 + (int)(nWidth * (double)nMax / nRangeMax);
		rcItem.left		= rcItem.left - 1 + (int)(nWidth * (double)nMin / nRangeMax);
	}
	else
	{
		// 현재 선택된 범위의 위/아래 위치를 계산한다
		int nHeight = rcItem.Height() + 2;
		rcItem.bottom	= rcItem.top - 1 + (int)(nHeight * (double)nMax / nRangeMax);
		rcItem.top		= rcItem.top - 1 + (int)(nHeight * (double)nMin / nRangeMax);
	}

	// 선택된 범위 영역을 선택 색상으로 칠한다
	pDC->FillSolidRect(&rcItem, m_clrSelection);
}

BOOL CCustomSliderCtrl::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// 핸들의 영역을 얻는다
	CRect rcThumb;
	GetThumbRect(&rcThumb);

	// 마우스 커서의 좌표를 얻는다
	CPoint ptCursor;
	::GetCursorPos(&ptCursor);
	ScreenToClient(&ptCursor);

	// 만약 핸들 영역에 마우스 커서가 있다면
	if(rcThumb.PtInRect(ptCursor))
	{
		// 수직/수평에 따라 마우스 커서를 설정한다
		if(m_bHorz)			SetCursor(AfxGetApp()->LoadCursor(IDC_HORZ_MOVE_CURSOR));
		else				SetCursor(AfxGetApp()->LoadCursor(IDC_VERT_MOVE_CURSOR));
		return TRUE;
	}
	
	return CSliderCtrl::OnSetCursor(pWnd, nHitTest, message);
}
