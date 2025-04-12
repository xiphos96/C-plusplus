// FlatComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "flatcomboboxdemo.h"
#include "FlatComboBox.h"

// 한글 입력 상태를 얻기 위해 필요한 API 정의 헤더 파일
#include <Imm.h>
#include ".\flatcombobox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlatComboBox

// 콤보 박스의 드롭 리스트에서 항목간 간격
#define CONST_ITEM_GAP			6
// 마우스가 콤보 박스 위에 있는지 확인하기 위한 타이머
#define CONST_HOVER_TIMER		1

CFlatComboBox::CFlatComboBox()
{
	// 멤버 변수들을 초기화한다
	m_clrBkgnd			= RGB(255, 255, 255);
	m_clrSelected		= RGB(220, 230, 245);
	m_clrText			= ::GetSysColor(COLOR_BTNTEXT);
	m_clrTextDisabled	= ::GetSysColor(COLOR_GRAYTEXT);

	m_clrFace			= ::GetSysColor(COLOR_BTNFACE);
	m_clrHighlight		= ::GetSysColor(COLOR_BTNHILIGHT);
	m_clrShadow			= ::GetSysColor(COLOR_BTNSHADOW);

	m_bHover			= FALSE;
	m_bPress			= FALSE;
	m_bFocus			= FALSE;
	m_bAutoComplete		= TRUE;
	m_bDelBack			= FALSE;
	m_nDropArrowWidth	= ::GetSystemMetrics(SM_CXHTHUMB);
	m_nAutoSel			= -1;
}

CFlatComboBox::~CFlatComboBox()
{
}


BEGIN_MESSAGE_MAP(CFlatComboBox, CComboBox)
	//{{AFX_MSG_MAP(CFlatComboBox)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_CONTROL_REFLECT(CBN_EDITUPDATE, OnEditupdate)
	ON_CONTROL_REFLECT(CBN_KILLFOCUS, OnCBNKillFocus)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_CONTROL_REFLECT(CBN_CLOSEUP, OnCbnCloseup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlatComboBox message handlers

void CFlatComboBox::PreSubclassWindow() 
{
	// 외곽선 옵션을 제거한다
	ModifyStyleEx(WS_EX_CLIENTEDGE | WS_EX_STATICEDGE, 0, SWP_FRAMECHANGED);

	// 클라이언트 영역을 저장한다
	GetClientRect(&m_rcClient);

	CComboBox::PreSubclassWindow();
}

// 항목의 크기 계산 함수
void CFlatComboBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	CDC *pDC = GetDC();
	// 콤보 박스의 폰트를 설정한다
	CFont *pOldFont = pDC->SelectObject(GetFont());

	// 기본 항목 크기를 설정한다
	CRect rcText(0, 0, lpMeasureItemStruct->itemWidth, lpMeasureItemStruct->itemHeight);

	// 텍스트 출력시 필요한 높이를 구한다
	lpMeasureItemStruct->itemHeight = pDC->DrawText("글자", -1, &rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_EXPANDTABS);
	// 항목간 간격을 더한다
	lpMeasureItemStruct->itemHeight += CONST_ITEM_GAP;

	// 폰트와 DC를 반환한다
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);
}

void CFlatComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	CRect rcItem(&(lpDrawItemStruct->rcItem));

	// 만약 항목의 번호가 없다면
	if((int)lpDrawItemStruct->itemID < 0)
	{
		// 배경을 기본 색상으로 지우고 리턴한다
		dc.FillSolidRect(rcItem, m_clrBkgnd);
		dc.Detach();
		return;
	}

	// 현재 항목 상태를 얻는다
	BOOL bIsSelected	= (lpDrawItemStruct->itemState & ODS_SELECTED);
	BOOL bIsDisabled	= (lpDrawItemStruct->itemState & ODS_DISABLED);

	// 만약 선택된 상태가 아니고, 자동 완성 기능에 의해 선택된 항목이라면
	// 선택 상태로 설정한다
	if(!bIsSelected && m_nAutoSel == (int)lpDrawItemStruct->itemID)
	{
		bIsSelected = TRUE;
	}

	// 선택된 상태에 따라 다른 배경색으로 배경을 칠한다
	if(bIsSelected)		dc.FillSolidRect(rcItem, m_clrSelected);
	else				dc.FillSolidRect(rcItem, m_clrBkgnd);

	// 항목의 텍스트를 얻는다
	CString strText;
	GetLBText(lpDrawItemStruct->itemID, strText);

	// 콤보 박스의 폰트를 설정한다
	CFont *pOldFont = dc.SelectObject(GetFont());

	// 텍스트 배경을 투명하게 설정한다
	dc.SetBkMode(TRANSPARENT);
	// 활성화 여부에 따라 텍스트 색상을 설정한다
	if(bIsDisabled)			dc.SetTextColor(m_clrTextDisabled);
	else					dc.SetTextColor(m_clrText);
	// 텍스트를 수직 중앙에 출력한다
	dc.DrawText(strText, rcItem, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	
	// 폰트를 반환한다
	dc.SelectObject(pOldFont);
	dc.Detach();
}

void CFlatComboBox::OnPaint() 
{
	// 기본 콤보 박스 모양을 출력한다
	Default();

	// 평면 테두리를 그린다
	DrawFlatCombo();
}

// 평면 콤보 박스 테두리를 그리는 함수
void CFlatComboBox::DrawFlatCombo()
{
	// DC를 얻고 클라이언트 영역을 얻는다
	CDC* pDC = GetDC();
	CRect rcClient = m_rcClient;
	BOOL bEnabled = IsWindowEnabled();

	// 현재 마우스가 위치했는지와 포커스를 갖고 있는지에 따라
	// 가장 바깥의 외곽선을 칠한다
	if(m_bHover || m_bFocus)
		pDC->Draw3dRect(rcClient, m_clrShadow, m_clrHighlight);
	else
		pDC->Draw3dRect(rcClient, m_clrFace, m_clrFace);

	// 안쪽으로 한 픽셀 영역을 좁힌다
	rcClient.DeflateRect(1,1);
	// 현재 활성화 여부에 따라 외곽선을 칠한다
	if(bEnabled)
		pDC->Draw3dRect(rcClient, m_clrFace, m_clrFace);
	else
		pDC->Draw3dRect(rcClient, m_clrHighlight, m_clrHighlight);

	// 안쪽으로 한 픽셀 영역을 좁힌다
	rcClient.DeflateRect(1,1);
	// 드롭 다운 버튼의 왼쪽 좌표를 구한다
	rcClient.left = rcClient.right - m_nDropArrowWidth;

	// 드롭 다운 버튼의 외곽을 일반 색상으로 칠한다
	pDC->Draw3dRect(rcClient, m_clrFace, m_clrFace);
	// 안쪽으로 한 픽셀 영역을 좁힌다
	rcClient.DeflateRect(1,1);
	// 드롭 다운 버튼의 외곽을 일반 색상으로 칠한다
	pDC->Draw3dRect(rcClient, m_clrFace, m_clrFace);

	// 만약 비활성화 되어 있다면 리턴한다
	if(!bEnabled)
	{
		ReleaseDC(pDC);
		return;
	}

	// 수직으로 한 픽셀 영역을 넓힌다
	rcClient.top -= 1;
	rcClient.bottom += 1;
	// 만약 마우스가 위치해 있거나 포커스를 갖고 있다면
	if(m_bHover || m_bFocus)
	{
		// 만약 현재 눌린 상태라면
		if(m_bPress)
		{
			// 오른쪽 하단으로 1픽셀 이동한다
			rcClient.OffsetRect(1,1);
			// 눌린 모양의 색상으로 테두리를 그린다
			pDC->Draw3dRect(rcClient, m_clrShadow, m_clrHighlight);
		}
		else
		{
			// 튀어나온 모양의 색상으로 테두리를 그린다
			pDC->Draw3dRect(rcClient, m_clrHighlight, m_clrShadow);
		}
	}
	else
	{
		// 드롭 다운 버튼을 구분하기 위해 밝은 색상으로 테두리를 그린다
		pDC->Draw3dRect(rcClient, m_clrHighlight, m_clrHighlight);
		rcClient.left -= 1;
		pDC->Draw3dRect(rcClient, m_clrHighlight, m_clrHighlight);
	}

	ReleaseDC(pDC);
}

void CFlatComboBox::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 만약 마우스가 위치하지 않은 상태라면
	if(!m_bHover)
	{
		// 마우스가 위치했음을 설정한다
		m_bHover = TRUE;

		// 마우스가 계속 위치하고 있는지 확인하기 위해 타이머를 실행한다
		SetTimer(CONST_HOVER_TIMER, 100, NULL);

		// 콤보 박스 테두리를 다시 그린다
		DrawFlatCombo();
	}

	CComboBox::OnMouseMove(nFlags, point);
}

void CFlatComboBox::OnTimer(UINT nIDEvent) 
{
	// 만약 마우스가 위치해 있는 상태라면
	if(m_bHover)
	{
		// 마우스의 좌표를 구한다
		CPoint ptCursor;
		::GetCursorPos(&ptCursor);
		ScreenToClient(&ptCursor);
		// 마우스가 콤보 박스 영역 안에 있는지 확인한다
		if(!m_rcClient.PtInRect(ptCursor))
		{
			// 만약 마우스가 콤보 박스 영역을 벗어났다면 타이머를 정지한다
			KillTimer(CONST_HOVER_TIMER);

			// 마우스가 위치해 있지 않음을 설정한다
			m_bHover = FALSE;
			// 콤보 박스 테두리를 다시 그린다
			DrawFlatCombo();
		}
	}
	
	CComboBox::OnTimer(nIDEvent);
}

void CFlatComboBox::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 마우스 좌측 버튼이 눌린 상태임을 설정한다
	m_bPress = TRUE;
	// 콤보 박스 테두리를 다시 그린다
	DrawFlatCombo();
	
	CComboBox::OnLButtonDown(nFlags, point);
}

void CFlatComboBox::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// 마우스 좌측 버튼이 떼어진 상태임을 설정한다
	m_bPress = FALSE;
	// 콤보 박스 테두리를 다시 그린다
	DrawFlatCombo();
	
	CComboBox::OnLButtonUp(nFlags, point);
}

void CFlatComboBox::OnSetFocus(CWnd* pOldWnd) 
{
	CComboBox::OnSetFocus(pOldWnd);
	
	// 포커스를 갖고 있는 상태임을 설정한다
	m_bFocus = TRUE;
	// 콤보 박스 테두리를 다시 그린다
	DrawFlatCombo();
}

void CFlatComboBox::OnKillFocus(CWnd* pNewWnd) 
{
	CComboBox::OnKillFocus(pNewWnd);
	
	// 포커스를 갖고 있지 않음을 설정한다
	m_bFocus = FALSE;
	// 콤보 박스 테두리를 다시 그린다
	DrawFlatCombo();
}

void CFlatComboBox::OnCBNKillFocus() 
{
	// 에디트 컨트롤이 포커스를 잃을 때도
	// 포커스를 갖고 있지 않음을 설정한다
	m_bFocus = FALSE;
	// 콤보 박스 테두리를 다시 그린다
	DrawFlatCombo();
}

BOOL CFlatComboBox::PreTranslateMessage(MSG* pMsg) 
{
	// 만약 키보드 입력이고 자동 완성 기능을 사용하고 있다면
	if(pMsg->message == WM_KEYDOWN && m_bAutoComplete)
	{
		// DEL키나 Back Space 키가 눌려지면 멤버 변수에 설정한다
		if(pMsg->wParam == VK_DELETE || pMsg->wParam == VK_BACK)
			m_bDelBack = TRUE;
		else
			m_bDelBack = FALSE;
	}
	
	return CComboBox::PreTranslateMessage(pMsg);
}

void CFlatComboBox::OnEditupdate() 
{
	// 만약 자동 완성 기능을 사용하고 있지 않다면 리턴
	if(!m_bAutoComplete)				return;
	// 만약 드롭 다운 형식이 아니라면 리턴
	if(!(GetStyle() & CBS_DROPDOWN))	return;
	// 만약 현재 한글 입력 모드라면 리턴
	if(IsHangleMode())					return;
	// 만약 Del키나 Back Space키가 눌려진 것이라면 리턴
	if(m_bDelBack)						return;

	// 현재 블럭 설정 상태를 얻는다
	DWORD nCurSel = GetEditSel();
	// 만약 블럭 설정을 얻는데 오류가 발생하면
	if(nCurSel == CB_ERR)				return;

	// 블럭의 시작 위치와 끝 위치를 얻는다
	int nStart	= LOWORD(nCurSel);
	int nEnd	= HIWORD(nCurSel);

	// 현재 에디트 박스에 입력된 텍스트를 얻는다
	CString strText;
	GetWindowText(strText);

	// 텍스트의 길이를 얻는다
	int nLength = strText.GetLength();
	// 입력된 텍스트로 시작하는 항목을 찾아 선택한다
	m_nAutoSel = SelectString(-1, strText);
	// 만약 찾아진 항목이 없다면
	if(m_nAutoSel == CB_ERR)
	{
		// 기존 입력된 내용을 다시 설정한다
		SetWindowText(strText);
		// 기존 설정된 블럭을 다시 설정한다
		SetEditSel(nStart, nEnd);
		return;
	}

	// 기존 입력된 내용 뒤쪽을 블럭으로 설정한다
	SetEditSel(nLength, -1);
}

BOOL CFlatComboBox::IsHangleMode()
{
	// 현재 윈도우의 IME 핸들을 얻는다
	HIMC hIMC = ::ImmGetContext(m_hWnd);
	DWORD dwConv;

	// 현재 입력 모드를 얻는다
	::ImmGetConversionStatus(hIMC, &dwConv, NULL);
	// IME 핸들을 반환한다
	::ImmReleaseContext(m_hWnd, hIMC);

	// 현재 입력 모드를 리턴한다
	return dwConv;
}

void CFlatComboBox::OnCbnCloseup()
{
	m_nAutoSel = -1;
}
