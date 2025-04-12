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

// �� ���� ��ư�� ��
#define CONST_BUTTON_WIDTH		10

CSlideEdit::CSlideEdit()
{
	// �������� �ʱⰪ�� �����Ѵ�
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

// �����̵� ����Ʈ ��Ʈ���� ���� �����ϴ� �Լ�
BOOL CSlideEdit::SetValue(int nValue)
{
	// ������ Ȯ���Ѵ�
	if(nValue < m_nMin)		return FALSE;
	if(nValue > m_nMax)		return FALSE;

	m_nValue = nValue;

	// ���� ���� ������� ������ ���¶��
	if(m_hWnd)
	{
		CString strValue;

		strValue.Format("%d", m_nValue);

		// �������� �ؽ�Ʈ�� �����Ѵ�
		SetWindowText(strValue);

		// �θ� �����쿡�� ���� ������ �˸���
		if(GetParent())
			GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)m_nValue, (LPARAM)m_hWnd);
	}

	return TRUE;
}

// �����̵� ����Ʈ ��Ʈ���� ������ �����ϴ� �Լ�
void CSlideEdit::SetRange(int nMax, int nMin)
{
	if(nMax < nMin)		return;

	// ������ �����Ѵ�
	m_nMax = nMax;
	m_nMin = nMin;

	CString strValue;

	// ���ο� ������ ���� ���� ��ȿ���� �˻��Ѵ�
	if(m_nValue > m_nMax)
	{
		m_nValue = m_nMax;
		// �θ� �����쿡�� ���� ������ �˸���
		if(GetParent())
			GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)m_nValue, (LPARAM)m_hWnd);
	}
	if(m_nValue < m_nMin)
	{
		m_nValue = m_nMin;
		// �θ� �����쿡�� ���� ������ �˸���
		if(GetParent())
			GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)m_nValue, (LPARAM)m_hWnd);
	}

	// �������� �ؽ�Ʈ�� �����Ѵ�
	strValue.Format("%d", m_nValue);
	SetWindowText(strValue);
}

void CSlideEdit::PreSubclassWindow() 
{
	// ����Ʈ ��Ʈ�ѿ����� ��ư�� ��ġ�� ����Ѵ�
	CRect rcTemp;
	GetClientRect(&rcTemp);

	m_rcButton = rcTemp;
	m_rcButton.left = m_rcButton.right - CONST_BUTTON_WIDTH;

	// ����Ʈ ��Ʈ���� ���� ������ �����Ѵ�
	rcTemp.right -= CONST_BUTTON_WIDTH + 1;
	SetRect(&rcTemp);

	CString strValue;

	// ���� ���� ��ȿ���� �˻��Ѵ�
	if(m_nValue > m_nMax)		m_nValue = m_nMax;
	if(m_nValue < m_nMin)		m_nValue = m_nMin;

	// �������� �ؽ�Ʈ�� �����Ѵ�
	strValue.Format("%d", m_nValue);
	SetWindowText(strValue);

	// �θ� �����쿡�� ���� ������ �˸���
	if(GetParent())
		GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)m_nValue, (LPARAM)m_hWnd);

	CEdit::PreSubclassWindow();
}

void CSlideEdit::OnPaint() 
{
	CEdit::OnPaint();

	// ���� ��ư�� ���¿� ���� ��ư�� �׸���
	DrawButton();
}

// �� ���� ��ư�� �׸��� �Լ�
void CSlideEdit::DrawButton()
{
	CDC *pDC = GetDC();

	// ���� ��ư�� ���¿� ���� ��ư�� �׸���
	DWORD nStyle = DFCS_SCROLLDOWN;
	if(m_nButtonState == BUTTON_DISABLED)	nStyle |= DFCS_INACTIVE;
	if(m_nButtonState == BUTTON_DOWN)		nStyle |= DFCS_PUSHED;

	pDC->DrawFrameControl(&m_rcButton, DFC_SCROLL, nStyle);

	ReleaseDC(pDC);
}

void CSlideEdit::OnSetFocus(CWnd* pOldWnd) 
{
	CEdit::OnSetFocus(pOldWnd);

	// �����̵� ����Ʈ ��Ʈ���� ��Ŀ���� ������ �ؽ�Ʈ�� ���� �����Ѵ�
	SetSel(0, -1);
}

void CSlideEdit::OnSize(UINT nType, int cx, int cy) 
{
	CEdit::OnSize(nType, cx, cy);

	// ����Ʈ ��Ʈ���� ũ�Ⱑ ����Ǹ� ��ư�� ��ġ�� ũ�⸦ �ٽ� ����Ѵ�
	CRect rcTemp;
	GetClientRect(&rcTemp);

	m_rcButton = rcTemp;
	m_rcButton.left = m_rcButton.right - CONST_BUTTON_WIDTH;

	// ���� ������ �ٽ� ����Ѵ�
	rcTemp.right -= CONST_BUTTON_WIDTH + 1;
	SetRect(&rcTemp);
}

// ���� �Է¿� ���� �ڵ鷯
void CSlideEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// ���� ��ư�� ��Ȱ��ȭ�Ǿ� ���� �ʰ�, �� �����̽� Ű�� �ƴ϶��
	if(nChar != VK_BACK && m_nButtonState != BUTTON_DISABLED)
	{
		// ���� ���� Ȥ�� '-'�� �ƴ϶�� ����
		if(!::isdigit(nChar) && nChar != '-')		return;

		// ���� �Էµ� ���ڷ� ���� ������ ������� Ȯ��
		CString strValue;
		GetWindowText(strValue);

		int nStart, nEnd;
		GetSel(nStart, nEnd);

		if(nStart < nEnd)
			strValue.Delete(nStart, nEnd - nStart);

		strValue += (char)nChar;

		int nValue = ::atoi(strValue);

		// ���� ������ ����� ����
		if(nValue < m_nMin || nValue > m_nMax)		return;
	}
	
	CEdit::OnChar(nChar, nRepCnt, nFlags);
}

void CSlideEdit::OnChange() 
{
	// �����̵� ����Ʈ ��Ʈ���� ���� ����Ǹ�
	// ���ο� ���� �а�
	CString strValue;
	GetWindowText(strValue);

	// ������ ���� �����Ѵ�
	m_nValue = ::atoi(strValue);

	if(m_nValue < m_nMin)		m_nValue = m_nMin;
	if(m_nValue > m_nMax)		m_nValue = m_nMax;

	// �θ� �����쿡�� ���� ������ �˸���
	if(GetParent())
		GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)m_nValue, (LPARAM)m_hWnd);
}

void CSlideEdit::OnEnable(BOOL bEnable) 
{
	CEdit::OnEnable(bEnable);

	// �����̵� ����Ʈ ��Ʈ���� Ȱ��ȭ ���ο� ���� ��ư�� Ȱ��ȭ ��Ų��
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

	// ���� �����̵� ����Ʈ ��Ʈ���� ��ư �������� ���콺 ���� ��ư�� ��������
	if(m_rcButton.PtInRect(point) && m_nButtonState != BUTTON_DISABLED)
	{
		// ��ư�� ����� ������ ������� �����Ѵ�
		m_nButtonState = BUTTON_DOWN;
		DrawButton();

		// �����̵� �����츦 ����
		PopupSlide();
	}
}

// �����̵� �����츦 ���� �Լ�
void CSlideEdit::PopupSlide()
{
	// �θ� �����찡 �ٽ� �׷����� �ʵ��� �����Ѵ�
	CWnd* pParent = GetParent();
	if(pParent)		pParent->SetRedraw(FALSE);

	// ���� ��ư�� ��ġ�� �����̵� �����쿡�� �����Ѵ�
	CRect rcSlide = m_rcButton;

	ClientToScreen(&rcSlide);

	// �����̵� �����츦 ����
	m_wndSlide.PopupSlide(this, rcSlide, m_nMax, m_nMin, m_nValue);

	// �θ� �����츦 Ȱ��ȭ ���·� ����� �ٽ� �׸��⸦ �����Ѵ�
	pParent->SendMessage(WM_NCACTIVATE, TRUE, 0);
	pParent->SetRedraw(TRUE);
}

// �����̵� �����쿡�� �����̵��� �̵��� ���� �ڵ鷯
LRESULT CSlideEdit::OnSlidePosChange(WPARAM wParam, LPARAM lParam)
{
	// ���ο� ���� �����Ѵ�
	m_nValue = (int)wParam;

	CString strTemp;
	strTemp.Format("%d", wParam);

	// �����̵� ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����Ѵ�
	SetWindowText(strTemp);
	SetSel(0, -1);

	// �θ� �����쿡�� ���� ������ �˸���
	if(GetParent())
		GetParent()->SendMessage(WM_SLIDE_POS_CHANGE, (WPARAM)wParam, (LPARAM)m_hWnd);

	return 1;
}

// �����̵� �����쿡�� �� ������ ���� �ڵ鷯
LRESULT CSlideEdit::OnSlideEndSelect(WPARAM wParam, LPARAM lParam)
{
	// ���ο� ���� �����Ѵ�
	m_nValue = (int)wParam;

	CString strTemp;
	strTemp.Format("%d", wParam);

	// �����̵� ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����Ѵ�
	SetWindowText(strTemp);
	SetSel(0, -1);

	// ��ư�� ����� �Ϲ� ������� �ٽ� �׸���
	m_nButtonState = BUTTON_UP;
	DrawButton();

	// �θ� �����쿡�� ���� ������ �˸���
	if(GetParent())
		GetParent()->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)wParam, (LPARAM)m_hWnd);

	return 1;
}

void CSlideEdit::OnDestroy() 
{
	CEdit::OnDestroy();

	// �����̵� ����Ʈ ��Ʈ���� �Ҹ�� �� �����̵� �����쵵 �Բ� �Ҹ� ��Ų��
	if(m_wndSlide.m_hWnd)
		m_wndSlide.DestroyWindow();
}

// CSlideEdit�� ����Ͽ� DDX/DDV�� �����ϱ� ���� �Լ�
void AFXAPI DDX_SlideEdit(CDataExchange* pDX, int nIDC, CString& strText)
{
	// DDX/DDV�� �����Ϸ��� ��Ʈ���� �ڵ��� ��´�
	HWND hWnd = pDX->PrepareEditCtrl(nIDC);

	CSlideEdit SlideEdit;
	CSlideEdit *pEdit;

	// �ڵ��� ���� �����͸� ��´�
	CWnd *pWnd = CWnd::FromHandlePermanent(hWnd);

	// �����Ͱ� ������ٸ�
	if(pWnd)
	{
		// CSlideEdit Ŭ���� �����ͷ� �����Ѵ�
		pEdit = (CSlideEdit*)pWnd;
	}
	else
	{
		// �ӽ� CSlideEdit Ŭ���� ������ Attach()�Ѵ�
		SlideEdit.Attach(hWnd);
		// �ӽ� ������ �����͸� �����Ѵ�
		pEdit = &SlideEdit;
	}

	// ���� ���� �Ѱ��־�� �Ѵٸ�
	if(pDX->m_bSaveAndValidate)
	{
		// ������ �ؽ�Ʈ�� ��´�
		strText.Format("%d", pEdit->GetValue());
	}
	else
	{
		// ����Ʈ ��Ʈ�ѿ� �����Ѵ�
		pEdit->SetValue(::atoi(strText));
	}

	// ���� �ӽ� ������ Attach()�� ���¶��
	if(pWnd == NULL)
	{
		// Detach()�Ѵ�
		SlideEdit.Detach();
	}
}
