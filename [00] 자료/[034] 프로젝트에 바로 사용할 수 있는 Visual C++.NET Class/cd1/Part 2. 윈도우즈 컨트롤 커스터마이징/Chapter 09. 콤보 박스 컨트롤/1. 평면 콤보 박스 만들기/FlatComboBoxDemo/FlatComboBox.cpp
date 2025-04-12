// FlatComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "flatcomboboxdemo.h"
#include "FlatComboBox.h"

// �ѱ� �Է� ���¸� ��� ���� �ʿ��� API ���� ��� ����
#include <Imm.h>
#include ".\flatcombobox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlatComboBox

// �޺� �ڽ��� ��� ����Ʈ���� �׸� ����
#define CONST_ITEM_GAP			6
// ���콺�� �޺� �ڽ� ���� �ִ��� Ȯ���ϱ� ���� Ÿ�̸�
#define CONST_HOVER_TIMER		1

CFlatComboBox::CFlatComboBox()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
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
	// �ܰ��� �ɼ��� �����Ѵ�
	ModifyStyleEx(WS_EX_CLIENTEDGE | WS_EX_STATICEDGE, 0, SWP_FRAMECHANGED);

	// Ŭ���̾�Ʈ ������ �����Ѵ�
	GetClientRect(&m_rcClient);

	CComboBox::PreSubclassWindow();
}

// �׸��� ũ�� ��� �Լ�
void CFlatComboBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	CDC *pDC = GetDC();
	// �޺� �ڽ��� ��Ʈ�� �����Ѵ�
	CFont *pOldFont = pDC->SelectObject(GetFont());

	// �⺻ �׸� ũ�⸦ �����Ѵ�
	CRect rcText(0, 0, lpMeasureItemStruct->itemWidth, lpMeasureItemStruct->itemHeight);

	// �ؽ�Ʈ ��½� �ʿ��� ���̸� ���Ѵ�
	lpMeasureItemStruct->itemHeight = pDC->DrawText("����", -1, &rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_EXPANDTABS);
	// �׸� ������ ���Ѵ�
	lpMeasureItemStruct->itemHeight += CONST_ITEM_GAP;

	// ��Ʈ�� DC�� ��ȯ�Ѵ�
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);
}

void CFlatComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	CRect rcItem(&(lpDrawItemStruct->rcItem));

	// ���� �׸��� ��ȣ�� ���ٸ�
	if((int)lpDrawItemStruct->itemID < 0)
	{
		// ����� �⺻ �������� ����� �����Ѵ�
		dc.FillSolidRect(rcItem, m_clrBkgnd);
		dc.Detach();
		return;
	}

	// ���� �׸� ���¸� ��´�
	BOOL bIsSelected	= (lpDrawItemStruct->itemState & ODS_SELECTED);
	BOOL bIsDisabled	= (lpDrawItemStruct->itemState & ODS_DISABLED);

	// ���� ���õ� ���°� �ƴϰ�, �ڵ� �ϼ� ��ɿ� ���� ���õ� �׸��̶��
	// ���� ���·� �����Ѵ�
	if(!bIsSelected && m_nAutoSel == (int)lpDrawItemStruct->itemID)
	{
		bIsSelected = TRUE;
	}

	// ���õ� ���¿� ���� �ٸ� �������� ����� ĥ�Ѵ�
	if(bIsSelected)		dc.FillSolidRect(rcItem, m_clrSelected);
	else				dc.FillSolidRect(rcItem, m_clrBkgnd);

	// �׸��� �ؽ�Ʈ�� ��´�
	CString strText;
	GetLBText(lpDrawItemStruct->itemID, strText);

	// �޺� �ڽ��� ��Ʈ�� �����Ѵ�
	CFont *pOldFont = dc.SelectObject(GetFont());

	// �ؽ�Ʈ ����� �����ϰ� �����Ѵ�
	dc.SetBkMode(TRANSPARENT);
	// Ȱ��ȭ ���ο� ���� �ؽ�Ʈ ������ �����Ѵ�
	if(bIsDisabled)			dc.SetTextColor(m_clrTextDisabled);
	else					dc.SetTextColor(m_clrText);
	// �ؽ�Ʈ�� ���� �߾ӿ� ����Ѵ�
	dc.DrawText(strText, rcItem, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	
	// ��Ʈ�� ��ȯ�Ѵ�
	dc.SelectObject(pOldFont);
	dc.Detach();
}

void CFlatComboBox::OnPaint() 
{
	// �⺻ �޺� �ڽ� ����� ����Ѵ�
	Default();

	// ��� �׵θ��� �׸���
	DrawFlatCombo();
}

// ��� �޺� �ڽ� �׵θ��� �׸��� �Լ�
void CFlatComboBox::DrawFlatCombo()
{
	// DC�� ��� Ŭ���̾�Ʈ ������ ��´�
	CDC* pDC = GetDC();
	CRect rcClient = m_rcClient;
	BOOL bEnabled = IsWindowEnabled();

	// ���� ���콺�� ��ġ�ߴ����� ��Ŀ���� ���� �ִ����� ����
	// ���� �ٱ��� �ܰ����� ĥ�Ѵ�
	if(m_bHover || m_bFocus)
		pDC->Draw3dRect(rcClient, m_clrShadow, m_clrHighlight);
	else
		pDC->Draw3dRect(rcClient, m_clrFace, m_clrFace);

	// �������� �� �ȼ� ������ ������
	rcClient.DeflateRect(1,1);
	// ���� Ȱ��ȭ ���ο� ���� �ܰ����� ĥ�Ѵ�
	if(bEnabled)
		pDC->Draw3dRect(rcClient, m_clrFace, m_clrFace);
	else
		pDC->Draw3dRect(rcClient, m_clrHighlight, m_clrHighlight);

	// �������� �� �ȼ� ������ ������
	rcClient.DeflateRect(1,1);
	// ��� �ٿ� ��ư�� ���� ��ǥ�� ���Ѵ�
	rcClient.left = rcClient.right - m_nDropArrowWidth;

	// ��� �ٿ� ��ư�� �ܰ��� �Ϲ� �������� ĥ�Ѵ�
	pDC->Draw3dRect(rcClient, m_clrFace, m_clrFace);
	// �������� �� �ȼ� ������ ������
	rcClient.DeflateRect(1,1);
	// ��� �ٿ� ��ư�� �ܰ��� �Ϲ� �������� ĥ�Ѵ�
	pDC->Draw3dRect(rcClient, m_clrFace, m_clrFace);

	// ���� ��Ȱ��ȭ �Ǿ� �ִٸ� �����Ѵ�
	if(!bEnabled)
	{
		ReleaseDC(pDC);
		return;
	}

	// �������� �� �ȼ� ������ ������
	rcClient.top -= 1;
	rcClient.bottom += 1;
	// ���� ���콺�� ��ġ�� �ְų� ��Ŀ���� ���� �ִٸ�
	if(m_bHover || m_bFocus)
	{
		// ���� ���� ���� ���¶��
		if(m_bPress)
		{
			// ������ �ϴ����� 1�ȼ� �̵��Ѵ�
			rcClient.OffsetRect(1,1);
			// ���� ����� �������� �׵θ��� �׸���
			pDC->Draw3dRect(rcClient, m_clrShadow, m_clrHighlight);
		}
		else
		{
			// Ƣ��� ����� �������� �׵θ��� �׸���
			pDC->Draw3dRect(rcClient, m_clrHighlight, m_clrShadow);
		}
	}
	else
	{
		// ��� �ٿ� ��ư�� �����ϱ� ���� ���� �������� �׵θ��� �׸���
		pDC->Draw3dRect(rcClient, m_clrHighlight, m_clrHighlight);
		rcClient.left -= 1;
		pDC->Draw3dRect(rcClient, m_clrHighlight, m_clrHighlight);
	}

	ReleaseDC(pDC);
}

void CFlatComboBox::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���� ���콺�� ��ġ���� ���� ���¶��
	if(!m_bHover)
	{
		// ���콺�� ��ġ������ �����Ѵ�
		m_bHover = TRUE;

		// ���콺�� ��� ��ġ�ϰ� �ִ��� Ȯ���ϱ� ���� Ÿ�̸Ӹ� �����Ѵ�
		SetTimer(CONST_HOVER_TIMER, 100, NULL);

		// �޺� �ڽ� �׵θ��� �ٽ� �׸���
		DrawFlatCombo();
	}

	CComboBox::OnMouseMove(nFlags, point);
}

void CFlatComboBox::OnTimer(UINT nIDEvent) 
{
	// ���� ���콺�� ��ġ�� �ִ� ���¶��
	if(m_bHover)
	{
		// ���콺�� ��ǥ�� ���Ѵ�
		CPoint ptCursor;
		::GetCursorPos(&ptCursor);
		ScreenToClient(&ptCursor);
		// ���콺�� �޺� �ڽ� ���� �ȿ� �ִ��� Ȯ���Ѵ�
		if(!m_rcClient.PtInRect(ptCursor))
		{
			// ���� ���콺�� �޺� �ڽ� ������ ����ٸ� Ÿ�̸Ӹ� �����Ѵ�
			KillTimer(CONST_HOVER_TIMER);

			// ���콺�� ��ġ�� ���� ������ �����Ѵ�
			m_bHover = FALSE;
			// �޺� �ڽ� �׵θ��� �ٽ� �׸���
			DrawFlatCombo();
		}
	}
	
	CComboBox::OnTimer(nIDEvent);
}

void CFlatComboBox::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// ���콺 ���� ��ư�� ���� �������� �����Ѵ�
	m_bPress = TRUE;
	// �޺� �ڽ� �׵θ��� �ٽ� �׸���
	DrawFlatCombo();
	
	CComboBox::OnLButtonDown(nFlags, point);
}

void CFlatComboBox::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// ���콺 ���� ��ư�� ������ �������� �����Ѵ�
	m_bPress = FALSE;
	// �޺� �ڽ� �׵θ��� �ٽ� �׸���
	DrawFlatCombo();
	
	CComboBox::OnLButtonUp(nFlags, point);
}

void CFlatComboBox::OnSetFocus(CWnd* pOldWnd) 
{
	CComboBox::OnSetFocus(pOldWnd);
	
	// ��Ŀ���� ���� �ִ� �������� �����Ѵ�
	m_bFocus = TRUE;
	// �޺� �ڽ� �׵θ��� �ٽ� �׸���
	DrawFlatCombo();
}

void CFlatComboBox::OnKillFocus(CWnd* pNewWnd) 
{
	CComboBox::OnKillFocus(pNewWnd);
	
	// ��Ŀ���� ���� ���� ������ �����Ѵ�
	m_bFocus = FALSE;
	// �޺� �ڽ� �׵θ��� �ٽ� �׸���
	DrawFlatCombo();
}

void CFlatComboBox::OnCBNKillFocus() 
{
	// ����Ʈ ��Ʈ���� ��Ŀ���� ���� ����
	// ��Ŀ���� ���� ���� ������ �����Ѵ�
	m_bFocus = FALSE;
	// �޺� �ڽ� �׵θ��� �ٽ� �׸���
	DrawFlatCombo();
}

BOOL CFlatComboBox::PreTranslateMessage(MSG* pMsg) 
{
	// ���� Ű���� �Է��̰� �ڵ� �ϼ� ����� ����ϰ� �ִٸ�
	if(pMsg->message == WM_KEYDOWN && m_bAutoComplete)
	{
		// DELŰ�� Back Space Ű�� �������� ��� ������ �����Ѵ�
		if(pMsg->wParam == VK_DELETE || pMsg->wParam == VK_BACK)
			m_bDelBack = TRUE;
		else
			m_bDelBack = FALSE;
	}
	
	return CComboBox::PreTranslateMessage(pMsg);
}

void CFlatComboBox::OnEditupdate() 
{
	// ���� �ڵ� �ϼ� ����� ����ϰ� ���� �ʴٸ� ����
	if(!m_bAutoComplete)				return;
	// ���� ��� �ٿ� ������ �ƴ϶�� ����
	if(!(GetStyle() & CBS_DROPDOWN))	return;
	// ���� ���� �ѱ� �Է� ����� ����
	if(IsHangleMode())					return;
	// ���� DelŰ�� Back SpaceŰ�� ������ ���̶�� ����
	if(m_bDelBack)						return;

	// ���� �� ���� ���¸� ��´�
	DWORD nCurSel = GetEditSel();
	// ���� �� ������ ��µ� ������ �߻��ϸ�
	if(nCurSel == CB_ERR)				return;

	// ���� ���� ��ġ�� �� ��ġ�� ��´�
	int nStart	= LOWORD(nCurSel);
	int nEnd	= HIWORD(nCurSel);

	// ���� ����Ʈ �ڽ��� �Էµ� �ؽ�Ʈ�� ��´�
	CString strText;
	GetWindowText(strText);

	// �ؽ�Ʈ�� ���̸� ��´�
	int nLength = strText.GetLength();
	// �Էµ� �ؽ�Ʈ�� �����ϴ� �׸��� ã�� �����Ѵ�
	m_nAutoSel = SelectString(-1, strText);
	// ���� ã���� �׸��� ���ٸ�
	if(m_nAutoSel == CB_ERR)
	{
		// ���� �Էµ� ������ �ٽ� �����Ѵ�
		SetWindowText(strText);
		// ���� ������ ���� �ٽ� �����Ѵ�
		SetEditSel(nStart, nEnd);
		return;
	}

	// ���� �Էµ� ���� ������ ������ �����Ѵ�
	SetEditSel(nLength, -1);
}

BOOL CFlatComboBox::IsHangleMode()
{
	// ���� �������� IME �ڵ��� ��´�
	HIMC hIMC = ::ImmGetContext(m_hWnd);
	DWORD dwConv;

	// ���� �Է� ��带 ��´�
	::ImmGetConversionStatus(hIMC, &dwConv, NULL);
	// IME �ڵ��� ��ȯ�Ѵ�
	::ImmReleaseContext(m_hWnd, hIMC);

	// ���� �Է� ��带 �����Ѵ�
	return dwConv;
}

void CFlatComboBox::OnCbnCloseup()
{
	m_nAutoSel = -1;
}
