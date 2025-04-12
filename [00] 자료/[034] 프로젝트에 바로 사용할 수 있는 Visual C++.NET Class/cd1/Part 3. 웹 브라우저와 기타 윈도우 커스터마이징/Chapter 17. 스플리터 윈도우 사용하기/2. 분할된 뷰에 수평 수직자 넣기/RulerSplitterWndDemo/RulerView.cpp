// RulerView.cpp : implementation file
//

#include "stdafx.h"
#include "rulersplitterwnddemo.h"
#include "RulerView.h"

#include "RulerSplitterWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRulerView

// ����/�������� ���� ũ��
#define CONST_SCALE_5		3			// 5�ȼ� ������ ���� ũ��
#define CONST_SCALE_10		6			// 10�ȼ� ������ ���� ũ��

IMPLEMENT_DYNCREATE(CRulerView, CView)

CRulerView::CRulerView()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	m_bHorz			= TRUE;
	m_pScrollHint	= NULL;

	HDC hDC = ::GetDC(NULL);
	// �����ڿ� ��Ʈ�� �����Ѵ�
	m_HorzFont.CreateFont(-MulDiv(7, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0,
		FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "����");
	// �����ڿ� ��Ʈ�� �����Ѵ�
	m_VertFont.CreateFont(-MulDiv(7, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 900, 0,
		FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "����");
	::ReleaseDC(NULL, hDC);
}

CRulerView::~CRulerView()
{
	// ��Ʈ ��ü���� �Ҹ��Ų��
	m_HorzFont.DeleteObject();
	m_VertFont.DeleteObject();
}


BEGIN_MESSAGE_MAP(CRulerView, CView)
	//{{AFX_MSG_MAP(CRulerView)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRulerView drawing

void CRulerView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();

	// ���� Ŭ���̾�Ʈ ������ ���Ѵ�
	CRect rcClient;
	GetClientRect(&rcClient);

	CDC MemDC;
	CBitmap MemBmp, *pOldBmp;
	CFont *pOldFont;

	// �޸� DC�� �����Ѵ�
	MemDC.CreateCompatibleDC(pDC);
	// ��Ʈ���� �����Ѵ�
	MemBmp.CreateCompatibleBitmap(pDC, rcClient.Width(), rcClient.Height());
	// �޸� DC�� ��Ʈ���� �����Ѵ�
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// ����� ������� ĥ�Ѵ�
	MemDC.FillSolidRect(&rcClient, RGB(255, 255, 255));
	// ���� ��ũ�� ������ �����Ѵٸ�
	if(m_pScrollHint)
	{
		int i, nScale;
		CString strScale;

		// �������� ���
		if(m_bHorz)
		{
			// �����ڿ� ��Ʈ�� �����Ѵ�
			pOldFont = MemDC.SelectObject(&m_HorzFont);

			// �ʱ� 5���� ������ ���� ��ġ�� ����Ѵ�
			i = 5 - m_pScrollHint->m_nScrollX % 5;
			if(i == 5)		i = 0;
			// 5������ ������ ����Ѵ�
			for(; i < rcClient.right; i += 5)
			{
				// ������ ���� ��ǥ���� ����Ѵ�
				nScale = i + m_pScrollHint->m_nScrollX;
				// ���� 100 ������� �������� ���̿� ���� ũ��� ������ ����Ѵ�
				if(nScale % 100 == 0)
				{
					MemDC.MoveTo(i, rcClient.top);
					// ������ ��ǥ���� ����Ѵ�
					strScale.Format("%d", nScale);
					MemDC.TextOut(i + 1, rcClient.top, strScale);
				}
				else
				{
					// ���� 10 �������
					if(nScale % 10 == 0)
						// 10���� �β���ŭ ������ ����Ѵ�
						MemDC.MoveTo(i, rcClient.bottom - CONST_SCALE_10);
					else
						// 5���� �β���ŭ ������ ����Ѵ�
						MemDC.MoveTo(i, rcClient.bottom - CONST_SCALE_5);
				}
				MemDC.LineTo(i, rcClient.bottom);
			}
		}
		else
		{
			// �������� ���
			CSize szText;
			// �����ڿ� ��Ʈ�� �����Ѵ�
			pOldFont = MemDC.SelectObject(&m_VertFont);

			// �ʱ� 5���� ������ ���� ��ġ�� ����Ѵ�
			i = 5 - m_pScrollHint->m_nScrollY % 5;
			if(i == 5)		i = 0;
			// 5������ ������ ����Ѵ�
			for(; i < rcClient.bottom; i += 5)
			{
				// ������ ���� ��ǥ���� ����Ѵ�
				nScale = i + m_pScrollHint->m_nScrollY;
				// ���� 100 ������� �������� ���� ���� ũ��� ������ ����Ѵ�
				if(nScale % 100 == 0)
				{
					MemDC.MoveTo(rcClient.left, i);
					strScale.Format("%d", nScale);
					// ������ ��ǥ�� ��¿� �ʿ��� ������ ���Ѵ�
					szText = MemDC.GetTextExtent(strScale);
					// ������ ��ǥ���� ����Ѵ�
					MemDC.TextOut(rcClient.left, i + szText.cx + 2, strScale);
				}
				else
				{
					// ���� 10 �������
					if(nScale % 10 == 0)
						// 10���� �β���ŭ ������ ����Ѵ�
						MemDC.MoveTo(rcClient.right - CONST_SCALE_10, i);
					else
						// 5���� �β���ŭ ������ ����Ѵ�
						MemDC.MoveTo(rcClient.right - CONST_SCALE_5, i);
				}
				MemDC.LineTo(rcClient.right, i);
			}
		}

		// �޸� DC���� ���� ��Ʈ�� �����Ѵ�
		MemDC.SelectObject(pOldFont);

		// Ŀ�� ��ġ ǥ������ ����Ѵ�
		DrawCursorLine(&MemDC, (m_bHorz ? m_pScrollHint->m_nCursorX : m_pScrollHint->m_nCursorY));
	}

	// �޸� DC�� ������ ȭ�鿡 ����Ѵ�
	pDC->BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &MemDC, 0, 0, SRCCOPY);

	// �޸� DC�� ���� ��Ʈ���� �����Ѵ�
	MemDC.SelectObject(pOldBmp);
	// �޸� DC�� �Ҹ��Ų��
	MemDC.DeleteDC();
	// ��Ʈ���� �Ҹ��Ų��
	MemBmp.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CRulerView diagnostics

#ifdef _DEBUG
void CRulerView::AssertValid() const
{
	CView::AssertValid();
}

void CRulerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRulerView message handlers

void CRulerView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();

	// �ʱ� Ŀ�� ��ġ�� -1�� �����Ѵ�
	m_nLastCursor = -1;
}

BOOL CRulerView::OnEraseBkgnd(CDC* pDC) 
{
	// ����� ������ �ʴ´�
	return TRUE;
}

// ���� Ŀ�� ��ġ�� ǥ���ϴ� �Լ�
void CRulerView::DrawCursorLine(CDC *pDC, int nCursor)
{
	// ������ ���۷��̼��� NOTXORPEN���� �����Ѵ�
	int nROP = pDC->SetROP2(R2_NOTXORPEN), i;

	// Ŭ���̾�Ʈ ������ ��´�
	CRect rcClient;
	GetClientRect(&rcClient);

	// ���� �����ڶ��
	if(m_bHorz)
	{
		// ���콺�� ���� ��ġ�� ���� ������ ����Ѵ�
		for(i = rcClient.top; i < rcClient.bottom; i += 2)
			pDC->SetPixel(nCursor, i, RGB(0, 0, 0));
	}
	else
	{
		// ���� �����ڶ�� ���콺�� ���� ��ġ�� ���� ������ ����Ѵ�
		for(i = rcClient.left; i < rcClient.right; i += 2)
			pDC->SetPixel(i, nCursor, RGB(0, 0, 0));
	}

	// ������ ���۷��̼� �Ӽ��� �ǵ�����
	pDC->SetROP2(nROP);
}

// ���� ������Ʈ�� �ʿ��� ��� ȣ��Ǵ� �Լ�
void CRulerView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// ������Ʈ ������ ��´�
	m_pScrollHint = (CScrollHint*)pHint;
	switch(lHint)
	{
	case UPDATE_HSCROLL:
		// ���� �������� ��ũ�ѵǾ��ٸ�
		// ���� ���� �䰡 ������ ���� �並 �ٽ� �׸���
		if(m_bHorz)			InvalidateRect(FALSE);
		break;
	case UPDATE_VSCROLL:
		// ���� �������� ��ũ�ѵǾ��ٸ�
		// ���� ���� �䰡 ������ ���� �並 �ٽ� �׸���
		if(!m_bHorz)		InvalidateRect(FALSE);
		break;
	case UPDATA_CURSOR:
		// ���� Ŀ�� ��ġ�� �̵��Ǿ��ٸ�
		{
			CDC *pDC = GetDC();

			// ������ Ŀ�� ��ġ�� ������ �����
			if(m_nLastCursor >= 0)		DrawCursorLine(pDC, m_nLastCursor);
			// ���� ������ ���� Ŀ���� X ��ǥ�� �����Ѵ�
			if(m_bHorz)		m_nLastCursor = m_pScrollHint->m_nCursorX;
			// ���� ������ ���� Ŀ���� Y ��ǥ�� �����Ѵ�
			else			m_nLastCursor = m_pScrollHint->m_nCursorY;
			// Ŀ���� ��ġ�� ������ �ٽ� �׸���
			DrawCursorLine(pDC, m_nLastCursor);

			ReleaseDC(pDC);
		}
		break;
	}
}
