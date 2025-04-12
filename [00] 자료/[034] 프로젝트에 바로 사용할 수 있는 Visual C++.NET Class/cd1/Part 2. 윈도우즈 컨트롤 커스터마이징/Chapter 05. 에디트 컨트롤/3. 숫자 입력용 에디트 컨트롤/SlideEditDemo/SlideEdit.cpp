// SlideEdit.cpp : implementation file
//

#include "stdafx.h"
#include "slideeditdemo.h"
#include "SlideEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSlideEdit

// 값 조정 버튼의 폭
#define CONST_BUTTON_WIDTH		10

CSlideEdit::CSlideEdit()
{
	// 변수들의 초기값을 설정한다
	m_nValue		= 0;
	m_nMax			= 100;
	m_nMin			= -100;
	m_nButtonState	= BUTTON_UP;

	m_hCursor		= ::LoadCursor(NULL, IDC_ARROW);
}

CSlideEdit::~CSlideEdit()
{
	::DeleteObject(m_hCursor);
}


BEGIN_MESSAGE_MAP(CSlideEdit, CEdit)
	//{{AFX_MSG_MAP(CSlideEdit)
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_WM_CHAR()
	ON_WM_ENABLE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SLIDE_POS_CHANGE, OnSlidePosChange)
	ON_MESSAGE(WM_SLIDE_END_SELECT, OnSlideEndSelect)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSlideEdit message handlers

// 슬라이드 에디트 컨트롤의 값을 설정하는 함수
BOOL CSlideEdit::SetValue(int nValue)
{
	// 범위를 확인한다
	if(nValue < m_nMin)		return FALSE;
	if(nValue > m_nMax)		return FALSE;

	m_nValue = nValue;

	// 만약 현재 윈도우로 생성된 상태라면
	if(m_hWnd)
	{
		CString strValue;

		strValue.Format("%d", m_nValue);

		// 윈도우의 텍스트로 설정한다
		SetWindowText(strValue);

		// 부모 윈도우에게 값의 변동을 알린다
		if(GetParent())
			GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)m_nValue, (LPARAM)m_hWnd);
	}

	return TRUE;
}

// 슬라이드 에디트 컨트롤의 범위를 설정하는 함수
void CSlideEdit::SetRange(int nMax, int nMin)
{
	if(nMax < nMin)		return;

	// 범위를 저장한다
	m_nMax = nMax;
	m_nMin = nMin;

	CString strValue;

	// 새로운 범위에 따른 값의 유효성을 검사한다
	if(m_nValue > m_nMax)
	{
		m_nValue = m_nMax;
		// 부모 윈도우에게 값의 변동을 알린다
		if(GetParent())
			GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)m_nValue, (LPARAM)m_hWnd);
	}
	if(m_nValue < m_nMin)
	{
		m_nValue = m_nMin;
		// 부모 윈도우에게 값의 변동을 알린다
		if(GetParent())
			GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)m_nValue, (LPARAM)m_hWnd);
	}

	// 윈도우의 텍스트로 설정한다
	strValue.Format("%d", m_nValue);
	SetWindowText(strValue);
}

void CSlideEdit::PreSubclassWindow() 
{
	// 에디트 컨트롤에서의 버튼의 위치를 계산한다
	CRect rcTemp;
	GetClientRect(&rcTemp);

	m_rcButton = rcTemp;
	m_rcButton.left = m_rcButton.right - CONST_BUTTON_WIDTH;

	// 에디트 컨트롤의 편집 영역을 설정한다
	rcTemp.right -= CONST_BUTTON_WIDTH + 1;
	SetRect(&rcTemp);

	CString strValue;

	// 현재 값의 유효성을 검사한다
	if(m_nValue > m_nMax)		m_nValue = m_nMax;
	if(m_nValue < m_nMin)		m_nValue = m_nMin;

	// 윈도우의 텍스트로 설정한다
	strValue.Format("%d", m_nValue);
	SetWindowText(strValue);

	// 부모 윈도우에게 값의 변동을 알린다
	if(GetParent())
		GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)m_nValue, (LPARAM)m_hWnd);

	CEdit::PreSubclassWindow();
}

void CSlideEdit::OnPaint() 
{
	CEdit::OnPaint();

	// 현재 버튼의 상태에 따라 버튼을 그린다
	DrawButton();
}

// 값 조정 버튼을 그리는 함수
void CSlideEdit::DrawButton()
{
	CDC *pDC = GetDC();

	// 현재 버튼의 상태에 따라 버튼을 그린다
	DWORD nStyle = DFCS_SCROLLDOWN;
	if(m_nButtonState == BUTTON_DISABLED)	nStyle |= DFCS_INACTIVE;
	if(m_nButtonState == BUTTON_DOWN)		nStyle |= DFCS_PUSHED;

	pDC->DrawFrameControl(&m_rcButton, DFC_SCROLL, nStyle);

	ReleaseDC(pDC);
}

void CSlideEdit::OnSetFocus(CWnd* pOldWnd) 
{
	CEdit::OnSetFocus(pOldWnd);

	// 슬라이드 에디트 컨트롤이 포커스를 받으면 텍스트에 블럭을 설정한다
	SetSel(0, -1);
}

void CSlideEdit::OnSize(UINT nType, int cx, int cy) 
{
	CEdit::OnSize(nType, cx, cy);

	// 에디트 컨트롤의 크기가 변경되면 버튼의 위치와 크기를 다시 계산한다
	CRect rcTemp;
	GetClientRect(&rcTemp);

	m_rcButton = rcTemp;
	m_rcButton.left = m_rcButton.right - CONST_BUTTON_WIDTH;

	// 편집 영역을 다시 계산한다
	rcTemp.right -= CONST_BUTTON_WIDTH + 1;
	SetRect(&rcTemp);
}

// 문자 입력에 대한 핸들러
void CSlideEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// 만약 버튼이 비활성화되어 있지 않고, 백 스페이스 키가 아니라면
	if(nChar != VK_BACK && m_nButtonState != BUTTON_DISABLED)
	{
		// 만약 숫자 혹은 '-'가 아니라면 리턴
		if(!::isdigit(nChar) && nChar != '-')		return;

		// 새로 입력된 숫자로 인해 범위를 벗어나는지 확인
		CString strValue;
		GetWindowText(strValue);

		int nStart, nEnd;
		GetSel(nStart, nEnd);

		if(nStart < nEnd)
			strValue.Delete(nStart, nEnd - nStart);

		strValue += (char)nChar;

		int nValue = ::atoi(strValue);

		// 만약 범위를 벗어나면 리턴
		if(nValue < m_nMin || nValue > m_nMax)		return;
	}
	
	CEdit::OnChar(nChar, nRepCnt, nFlags);
}

void CSlideEdit::OnChange() 
{
	// 슬라이드 에디트 컨트롤의 값이 변경되면
	// 새로운 값을 읽고
	CString strValue;
	GetWindowText(strValue);

	// 범위에 따라 조정한다
	m_nValue = ::atoi(strValue);

	if(m_nValue < m_nMin)		m_nValue = m_nMin;
	if(m_nValue > m_nMax)		m_nValue = m_nMax;

	// 부모 윈도우에게 값의 변동을 알린다
	if(GetParent())
		GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)m_nValue, (LPARAM)m_hWnd);
}

void CSlideEdit::OnEnable(BOOL bEnable) 
{
	CEdit::OnEnable(bEnable);

	// 슬라이드 에디트 컨트롤의 활성화 여부에 따라 버튼을 활성화 시킨다
	if(BOOL(m_nButtonState) != bEnable)
	{
		if(bEnable)		m_nButtonState = BUTTON_UP;
		else			m_nButtonState = BUTTON_DISABLED;

		DrawButton();
	}
}

void CSlideEdit::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_rcButton.PtInRect(point))
	{
		::SetCursor(m_hCursor);
	}

	CEdit::OnMouseMove(nFlags, point);
}

void CSlideEdit::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CEdit::OnLButtonDown(nFlags, point);

	// 만약 슬라이드 에디트 컨트롤의 버튼 영역에서 마우스 좌측 버튼이 눌려지면
	if(m_rcButton.PtInRect(point) && m_nButtonState != BUTTON_DISABLED)
	{
		// 버튼의 모양을 눌러진 모양으로 변경한다
		m_nButtonState = BUTTON_DOWN;
		DrawButton();

		// 슬라이드 윈도우를 띄운다
		PopupSlide();
	}
}

// 슬라이드 윈도우를 띄우는 함수
void CSlideEdit::PopupSlide()
{
	// 부모 윈도우가 다시 그려지지 않도록 설정한다
	CWnd* pParent = GetParent();
	if(pParent)		pParent->SetRedraw(FALSE);

	// 현재 버튼의 위치를 슬라이드 윈도우에게 전달한다
	CRect rcSlide = m_rcButton;

	ClientToScreen(&rcSlide);

	// 슬라이드 윈도우를 띄운다
	m_wndSlide.PopupSlide(this, rcSlide, m_nMax, m_nMin, m_nValue);

	// 부모 윈도우를 활성화 상태로 만들고 다시 그리기를 설정한다
	pParent->SendMessage(WM_NCACTIVATE, TRUE, 0);
	pParent->SetRedraw(TRUE);
}

// 슬라이드 윈도우에서 슬라이드의 이동에 따른 핸들러
LRESULT CSlideEdit::OnSlidePosChange(WPARAM wParam, LPARAM lParam)
{
	// 새로운 값을 저장한다
	m_nValue = (int)wParam;

	CString strTemp;
	strTemp.Format("%d", wParam);

	// 슬라이드 에디트 컨트롤의 텍스트로 설정한다
	SetWindowText(strTemp);
	SetSel(0, -1);

	// 부모 윈도우에게 값의 변동을 알린다
	if(GetParent())
		GetParent()->SendMessage(WM_SLIDE_POS_CHANGE, (WPARAM)wParam, (LPARAM)m_hWnd);

	return 1;
}

// 슬라이드 윈도우에서 값 변동에 대한 핸들러
LRESULT CSlideEdit::OnSlideEndSelect(WPARAM wParam, LPARAM lParam)
{
	// 새로운 값을 저장한다
	m_nValue = (int)wParam;

	CString strTemp;
	strTemp.Format("%d", wParam);

	// 슬라이드 에디트 컨트롤의 텍스트로 설정한다
	SetWindowText(strTemp);
	SetSel(0, -1);

	// 버튼의 모양을 일반 모양으로 다시 그린다
	m_nButtonState = BUTTON_UP;
	DrawButton();

	// 부모 윈도우에게 값의 변동을 알린다
	if(GetParent())
		GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)wParam, (LPARAM)m_hWnd);

	return 1;
}

void CSlideEdit::OnDestroy() 
{
	CEdit::OnDestroy();

	// 슬라이드 에디트 컨트롤이 소멸될 때 슬라이드 윈도우도 함께 소멸 시킨다
	if(m_wndSlide.m_hWnd)
		m_wndSlide.DestroyWindow();
}

// CSlideEdit를 사용하여 DDX/DDV를 실행하기 위한 함수
void AFXAPI DDX_SlideEdit(CDataExchange* pDX, int nIDC, CString& strText)
{
	// DDX/DDV를 실행하려는 컨트롤의 핸들을 얻는다
	HWND hWnd = pDX->PrepareEditCtrl(nIDC);

	CSlideEdit SlideEdit;
	CSlideEdit *pEdit;

	// 핸들을 통해 포인터를 얻는다
	CWnd *pWnd = CWnd::FromHandlePermanent(hWnd);

	// 포인터가 얻어졌다면
	if(pWnd)
	{
		// CSlideEdit 클래스 포인터로 변경한다
		pEdit = (CSlideEdit*)pWnd;
	}
	else
	{
		// 임시 CSlideEdit 클래스 변수에 Attach()한다
		SlideEdit.Attach(hWnd);
		// 임시 변수의 포인터를 설정한다
		pEdit = &SlideEdit;
	}

	// 만약 값을 넘겨주어야 한다면
	if(pDX->m_bSaveAndValidate)
	{
		// 윈도우 텍스트를 얻는다
		strText.Format("%d", pEdit->GetValue());
	}
	else
	{
		// 에디트 컨트롤에 설정한다
		pEdit->SetValue(::atoi(strText));
	}

	// 만약 임시 변수에 Attach()된 상태라면
	if(pWnd == NULL)
	{
		// Detach()한다
		SlideEdit.Detach();
	}
}
