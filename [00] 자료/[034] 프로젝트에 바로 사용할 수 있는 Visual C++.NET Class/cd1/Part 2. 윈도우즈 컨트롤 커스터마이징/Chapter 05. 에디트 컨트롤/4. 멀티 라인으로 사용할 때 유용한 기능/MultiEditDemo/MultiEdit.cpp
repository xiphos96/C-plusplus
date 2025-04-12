// MultiEdit.cpp : implementation file
//

#include "stdafx.h"
#include "multieditdemo.h"
#include "MultiEdit.h"
#include ".\multiedit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiEdit

CMultiEdit::CMultiEdit()
{
	// ��Ŀ���� ���� ���� ���� ���� ����
	m_clrBkgndNormal	= RGB(220, 220, 220);
	// ��Ŀ���� ���� ���� ���� ����
	m_clrBkgndHot		= ::GetSysColor(COLOR_WINDOW);

	// ��Ŀ���� ���� ���� ���� ���� ���� �귯��
	m_brsBkgndNormal.CreateSolidBrush(m_clrBkgndNormal);
	// ��Ŀ���� ���� ���� ���� ���� �귯��
	m_brsBkgndHot.CreateSolidBrush(m_clrBkgndHot);
}

CMultiEdit::~CMultiEdit()
{
	// �귯�� ��ü �Ҹ�
	m_brsBkgndNormal.DeleteObject();
	m_brsBkgndHot.DeleteObject();
}


BEGIN_MESSAGE_MAP(CMultiEdit, CEdit)
	//{{AFX_MSG_MAP(CMultiEdit)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_CONTROL_REFLECT(EN_VSCROLL, OnEnVscroll)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiEdit message handlers

void CMultiEdit::PreSubclassWindow() 
{
	// ��Ƽ���� �Ӽ��� ����Ű �Է� �Ӽ�, ���� ��ũ�ѹ� �Ӽ��� �����Ѵ�
	ModifyStyle(WS_VSCROLL, ES_MULTILINE | ES_WANTRETURN, SWP_FRAMECHANGED);

	// ���� �������� ��Ʈ�� ����ؼ� ������ ���̸� ���Ѵ�
	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());

	CSize szText = pDC->GetTextExtent("A", 1);
	m_nLineHeight = szText.cy;

	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// ��� �������� �ʱ�ȭ�Ѵ�
	m_nLastLine = -1;
	m_bFocus = FALSE;

	GetClientRect(&m_rcClient);

	CEdit::PreSubclassWindow();
}

BOOL CMultiEdit::PreTranslateMessage(MSG* pMsg) 
{
	// ���� TAB Ű�� ��������
	// ��Ŀ�� �̵��� ���� �ʰ� TAB ���ڸ� �Է��Ѵ�
	if((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_TAB))
	{
		ReplaceSel("\t", TRUE);

		Invalidate(FALSE);

		return TRUE;
	}
	
	return CEdit::PreTranslateMessage(pMsg);
}

// ���� ĳ���� ��ġ�� ���� ��ȣ�� �����ϴ� �Լ�
int CMultiEdit::GetLineNo()
{
	// ���� ������ ���� ��´�
	int nStart, nEnd;
	GetSel(nStart, nEnd);

	// ���� ���� �����Ǿ� �ִٸ�
	if(nStart != nEnd)
	{
		CPoint ptEnd, ptCaret;

		// ���� �� ��ġ�� ���� ��ǥ�� ��´�
		ptEnd = PosFromChar(nEnd);
		// ���� ĳ���� ��ǥ�� ��´�
		ptCaret = GetCaretPos();

		// ���� ����ġ�� ���� �� ���� ��� - ����Ʈ ��Ʈ���� ���� �� ��ġ�� �ִ� ���
		// ���� �� ��ġ�� ĳ�� ���� ��ġ�� �����Ѵ�
		if(ptEnd.x < 0 && ptEnd.y < 0)	nStart = nEnd;
		// ���� �� ��ǥ�� ĳ���� ��ǥ�� ���� ���
		// ���� �� ��ġ�� ĳ�� ���� ��ġ�� �����Ѵ�
		if(ptEnd.y == ptCaret.y)		nStart = nEnd;
	}

	// ��(ĳ��)�� ���� ��ġ�κ��� ���� ��ȣ�� ȹ���Ͽ� �����Ѵ�
	return LineFromChar(nStart);
}

// Ư�� ������ �簢 ������ ���/�����ϴ� �Լ�
void CMultiEdit::GetLineRect(int nLine, CRect &rcRect)
{
	// �ش� ������ ù ���� ��ġ�� ���Ѵ�
	int nPos = LineIndex(nLine);

	// ù ������ ��ǥ�� ���Ѵ�
	CPoint ptLine = PosFromChar(nPos);

	// ���� ��ǥ�� ��� -1�̶��
	// ����Ʈ ��Ʈ���� ���� �������̹Ƿ�, ���� ĳ���� ��ǥ�� ���Ѵ�
	if(ptLine.x < 0 && ptLine.y < 0)
		ptLine = GetCaretPos();

	// ���� ���� ������ ���Ѵ�
	GetRect(&rcRect);
	// y ��ǥ�� �ش��ϴ� top�� bottom�� ���� ������ ��ġ�� �����Ѵ�
	rcRect.top		= ptLine.y;
	rcRect.bottom	= ptLine.y + m_nLineHeight;
}

void CMultiEdit::OnPaint() 
{
	// �⺻���� ����Ʈ ��Ʈ���� �׸���
	CEdit::OnPaint();
	
	CRect rcLine, rcRect;

	// ���� ĳ���� �ִ� ������ �簢 ������ ���Ѵ�
	GetRect(&rcRect);
	GetLineRect(m_nLastLine, rcLine);

	// ���� ���� ����Ʈ ��Ʈ���� ��Ŀ���� ���� ���� �ʰų�,
	// ���� ���̴� ���� �ۿ� �����Ѵٸ� ����
	if(!m_bFocus || rcRect.top > rcLine.bottom || rcRect.bottom < rcLine.top)
		return;

	// ĳ���� ȭ�鿡�� �����
	HideCaret();

	// ���� ȿ���� ����� ���� �޸� ���۸� �����Ѵ�
	CDC *pDC = GetDC();
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	// ���� ���� ������ŭ �޸� ��Ʈ���� �����Ѵ�
	CBitmap LineBmp, *pOldBmp;
	LineBmp.CreateCompatibleBitmap(pDC, rcLine.Width(), rcLine.Height());
	pOldBmp = MemDC.SelectObject(&LineBmp);

	// ��Ʈ���� �Ķ������� ĥ�Ѵ�
	rcRect = rcLine;
	rcRect.OffsetRect(-rcLine.left, -rcLine.top);
	MemDC.FillSolidRect(&rcRect, RGB(0, 0, 255));

	// ȭ�鿡 ���� ���� ����Ѵ�
	pDC->BitBlt(rcLine.left, rcLine.top, rcLine.Width(), rcLine.Height(),
		&MemDC, 0, 0, SRCINVERT);

	// GDI ��ü ��ȯ
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	LineBmp.DeleteObject();

	// ĳ���� �ٽ� ȭ�鿡 ����Ѵ�
	ShowCaret();
}

void CMultiEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);

	// Ű���尡 �������� ���� ������ ���� ��Ű�� ���� ����Ʈ ��Ʈ���� �ٽ� �׸���
	m_nLastLine = GetLineNo();
	Invalidate(FALSE);
}

void CMultiEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CEdit::OnChar(nChar, nRepCnt, nFlags);

	// ���ڰ� �ԷµǸ� ���� ������ ���� ��Ű�� ���� ����Ʈ ��Ʈ���� �ٽ� �׸���
	m_nLastLine = GetLineNo();
	Invalidate(FALSE);
}

void CMultiEdit::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CEdit::OnLButtonDown(nFlags, point);

	// ���콺 ���� ��ư�� �������� ���� ������ ���� ��Ű�� ���� ����Ʈ ��Ʈ���� �ٽ� �׸���
	m_nLastLine = GetLineNo();
	Invalidate(FALSE);
}

void CMultiEdit::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CEdit::OnLButtonUp(nFlags, point);

	// ���콺 ���� ��ư�� �������� ���� ������ ���� ��Ű�� ���� ����Ʈ ��Ʈ���� �ٽ� �׸���
	m_nLastLine = GetLineNo();
	Invalidate(FALSE);
}

void CMultiEdit::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���� ���콺 ���� ��ư�� ���� ä�� �巡���ϴ� ���̸�
	// ���� ��Ŀ���� ���� �ִٸ�
	if(nFlags & MK_LBUTTON && m_bFocus)
	{
		// ���� ������ ���� ��Ű�� ���� ����Ʈ ��Ʈ���� �ٽ� �׸���

		m_nLastLine = GetLineNo();
		Invalidate(FALSE);
	}
	
	CEdit::OnMouseMove(nFlags, point);
}

void CMultiEdit::OnEnVscroll()
{
	// ���� Ŀ���� ��ġ�� ���� ��ȣ�� ��´�
	m_nLastLine = GetLineNo();

	// ���� ��ũ�ѹٸ� ����������� �Ǵ��Ѵ�
	BOOL bShowVScrollBar = FALSE;
	
	int nFirstLine = GetFirstVisibleLine();

	// ���� ù��° �������� ���� ��ȣ�� 0���� ũ�ٸ� ���� ��ũ�ѹٸ� ������� �Ѵ�
	if(nFirstLine > 0)		bShowVScrollBar = TRUE;
	else
	{
		// ����Ʈ ��Ʈ���� �� ���� ������ ��´�
		int nLastLine = GetLineCount();

		// �� ���� ������ ����Ʈ ��Ʈ�ѿ��� �ѹ��� ������ �� �ִ� ���� �������� ���ٸ� ��ũ�ѹٸ� ������� �Ѵ�
		if((m_rcClient.Height() / m_nLineHeight) < nLastLine)
			bShowVScrollBar = TRUE;
	}

	// ��ũ�ѹٸ� ����������� ���ο� ���� ��ũ�ѹ� �Ӽ��� �����ϰ�
	// ����Ʈ ��Ʈ���� ������ ������ �����ϰ� ������ϵ��� ���ڸ� �����Ѵ�
	if(bShowVScrollBar)		ModifyStyle(0, WS_VSCROLL, SWP_FRAMECHANGED | SWP_DRAWFRAME);
	else					ModifyStyle(WS_VSCROLL, 0, SWP_FRAMECHANGED | SWP_DRAWFRAME);

	// Ŭ���̾�Ʈ ������ �ٽ� ��´�
	GetClientRect(&m_rcClient);
}

void CMultiEdit::OnSetFocus(CWnd* pOldWnd) 
{
	CEdit::OnSetFocus(pOldWnd);

	// ����Ʈ ��Ʈ���� ��Ŀ���� ������ ȭ���� �ٽ� �׸���
	m_bFocus = TRUE;
	Invalidate(TRUE);
}

void CMultiEdit::OnKillFocus(CWnd* pNewWnd) 
{
	CEdit::OnKillFocus(pNewWnd);

	// ����Ʈ ��Ʈ���� ��Ŀ���� ������ ȭ���� �ٽ� �׸���
	m_bFocus = FALSE;
	Invalidate(TRUE);
}

HBRUSH CMultiEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// ���� ��Ŀ�� ���ο� ���� ����� ĥ�� �귯���� ���� �����Ѵ�
	// �� �귯���� ������� �Էµ� �������� ������ ���� ��µȴ�
	if(m_bFocus)		return m_brsBkgndHot;
	else				return m_brsBkgndNormal;
}

BOOL CMultiEdit::OnEraseBkgnd(CDC* pDC) 
{
	BOOL bRet = CEdit::OnEraseBkgnd(pDC);

	// ���� ��Ŀ�� ���ο� ���� ����� ĥ�Ѵ�
	// ���⼭ ĥ�ϴ� ����� ������ ���� �̿ܿ� ȿ���� �ִ�
	if(m_bFocus)	pDC->FillSolidRect(&m_rcClient, m_clrBkgndHot);
	else			pDC->FillSolidRect(&m_rcClient, m_clrBkgndNormal);

	return bRet;
}
