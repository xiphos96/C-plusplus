// FontEffect.cpp : implementation file
//

#include "stdafx.h"
#include "fonteffectdemo.h"
#include "FontEffect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontEffect

CFontEffect::CFontEffect()
{
	// �ؽ�Ʈ ��¿� ��Ʈ�� �����Ѵ�
	HDC hDC = ::GetDC(NULL);
	m_TextFont.CreateFont(-MulDiv(30, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_BOLD,
		0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("�ü�ü"));
	::ReleaseDC(NULL, hDC);

	// ��� �������� �ʱ�ȭ�Ѵ�
	m_bOutLine = FALSE;
	m_nPointSize = 0;
	m_pPointArray = NULL;
	m_pTypeArray = NULL;
	m_pProcessFunc = NULL;
}

CFontEffect::~CFontEffect()
{
	// ��Ʈ�� �����Ѵ�
	m_TextFont.DeleteObject();
	// �޸𸮸� �����Ѵ�
	if(m_pPointArray)		delete[] m_pPointArray;
	if(m_pTypeArray)		delete[] m_pTypeArray;
}


BEGIN_MESSAGE_MAP(CFontEffect, CStatic)
	//{{AFX_MSG_MAP(CFontEffect)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontEffect message handlers

// �ؽ�Ʈ�� �����ϴ� �Լ�
void CFontEffect::SetText(LPCTSTR pText, BOOL bRebuild)
{
	if(pText == NULL)		return;

	m_strText = pText;

	// �ɼǿ� ���� ��θ� �ٽ� �����Ѵ�
	if(bRebuild)	BuildEffect();
}

// �߰� ȿ�� �Լ��� �����ϴ� �Լ�
void CFontEffect::SetFunction(LPPROCESSFUNC pFunc, BOOL bRebuild)
{
	if(pFunc == NULL)		return;

	m_pProcessFunc = pFunc;

	// �ɼǿ� ���� ��θ� �ٽ� �����Ѵ�
	if(bRebuild)	BuildEffect();
}

// �ܰ��� ��� ���θ� �����ϴ� �Լ�
void CFontEffect::SetOutLine(BOOL bOutLine)
{
	if(m_bOutLine != bOutLine)
	{
		m_bOutLine = bOutLine;
		Invalidate(FALSE);
	}
}

// �ؽ�Ʈ�� ���� ��θ� ����ϴ� �Լ�
void CFontEffect::BuildEffect()
{
	// ���� ��� �����͵��� �����Ѵ�
	if(m_pPointArray)		delete[] m_pPointArray;
	// ���� ��� ���ĵ��� �����Ѵ�
	if(m_pTypeArray)		delete[] m_pTypeArray;
	m_pPointArray = NULL;
	m_pTypeArray = NULL;
	m_nPointSize = 0;

	// ��θ� �����ϱ� ���� �޸� DC�� �����Ѵ�
	CDC *pDC = GetDC(), MemDC;
	MemDC.CreateCompatibleDC(pDC);

	// �ؽ�Ʈ ��¿� ��Ʈ�� �����Ѵ�
	CFont *pOldFont = MemDC.SelectObject(&m_TextFont);
	// ��Ʈ�� ����� �⺻ �ؽ�Ʈ ��� ũ�⸦ ���Ѵ�
	m_TextSize = MemDC.GetTextExtent(m_strText);

	// ���� ��µǴ� ũ�Ⱑ 0��� �����Ѵ�
	if(m_TextSize.cx == 0 || m_TextSize.cy == 0)
	{
		MemDC.SelectObject(pOldFont);
		MemDC.DeleteDC();
		ReleaseDC(pDC);
		return;
	}

	// �ؽ�Ʈ ����� ���� �ӽ� ��Ʈ���� �����Ѵ�
	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(pDC, m_TextSize.cx, m_TextSize.cy);
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// �ؽ�Ʈ ��� ����� �������� �����Ѵ�
	MemDC.SetBkMode(TRANSPARENT);

	// ��θ� �����ϱ� ���� Path ������ �˸���
	MemDC.BeginPath();
	// �ؽ�Ʈ�� ����Ѵ�
	MemDC.TextOut(0, 0, m_strText);
	// ��� ������ �����Ѵ�
	MemDC.EndPath();

	// �ؽ�Ʈ ��¿� ���� ��θ� �����ϴµ� �ʿ��� ����Ʈ ������ ���Ѵ�
	m_nPointSize = MemDC.GetPath(NULL, NULL, 0);
	// ���� ����Ʈ ������ ��ȿ���� ������ �����Ѵ�
	if(m_nPointSize == 0)
	{
		MemDC.SelectObject(pOldBmp);
		MemDC.SelectObject(pOldFont);
		MemDC.DeleteDC();
		MemBmp.DeleteObject();
		ReleaseDC(pDC);

		return;
	}

	// ��θ� �����ϴµ� �ʿ��� ����Ʈ �迭�� �����Ѵ�
	m_pPointArray = new CPoint[m_nPointSize];
	// ��θ� �����ϴµ� �ʿ��� ���� �迭�� �����Ѵ�
	m_pTypeArray = new BYTE[m_nPointSize];

	// �ؽ�Ʈ ��¿� ���� ��θ� ��´�
	MemDC.GetPath(m_pPointArray, m_pTypeArray, m_nPointSize);
	
	// ���ҽ��� ��ȯ�Ѵ�
	MemDC.SelectObject(pOldBmp);
	MemDC.SelectObject(pOldFont);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
	ReleaseDC(pDC);

	// ���� �߰� ȿ�� �Լ��� �����Ǿ� �ִٸ�
	if(m_pProcessFunc)
	{
		// �߰� ȿ�� �Լ��� ȣ���Ѵ�
		m_pProcessFunc(m_nPointSize, m_pPointArray, m_TextSize);

		// ȿ���� ����� ���� ��� ������ ����Ѵ�
		m_rcOutput.SetRect(m_pPointArray[0].x, m_pPointArray[0].y,
			m_pPointArray[0].x, m_pPointArray[0].y);

		for(int i = 0; i < m_nPointSize; i++)
		{
			if(m_pPointArray[i].x < m_rcOutput.left)
				m_rcOutput.left = m_pPointArray[i].x;
			if(m_pPointArray[i].x > m_rcOutput.right)
				m_rcOutput.right = m_pPointArray[i].x;

			if(m_pPointArray[i].y < m_rcOutput.top)
				m_rcOutput.top = m_pPointArray[i].y;
			if(m_pPointArray[i].y > m_rcOutput.bottom)
				m_rcOutput.bottom = m_pPointArray[i].y;
		}
	}
	else
		// �ؽ�Ʈ ũ�⸦ ��� �������� ����Ѵ�
		m_rcOutput.SetRect(0, 0, m_TextSize.cx, m_TextSize.cy);

	Invalidate(FALSE);
}

void CFontEffect::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// ���� ���۸��� �����Ѵ�
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);

	CRect rcClient;
	GetClientRect(&rcClient);

	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(&dc, rcClient.Width(), rcClient.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);
	
	// ����� �Ͼ������ ĥ�Ѵ�
	MemDC.FillSolidRect(0, 0, rcClient.Width(), rcClient.Height(), RGB(255, 255, 255));

	// �ؽ�Ʈ ��¿� ���� ��θ� ����Ѵ�
	DrawEffect(&MemDC, rcClient.Width(), rcClient.Height());

	// ȭ�鿡 ����Ѵ�
	dc.BitBlt(0, 0, rcClient.Width(), rcClient.Height(),
		&MemDC, 0, 0, SRCCOPY);

	// ���ҽ��� ��ȯ�Ѵ�
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

BOOL CFontEffect::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

// ��θ� ����ϴ� �Լ�
void CFontEffect::DrawEffect(CDC *pDC, int cx, int cy)
{
	if(pDC == NULL || m_pPointArray == NULL || m_pTypeArray == NULL)		return;

	int i;
	// ��� �׷����� ȭ���� �߾ӿ� ��Ÿ������ �������� ����Ѵ�
	int nOffsetX = (cx - m_rcOutput.Width()) / 2 - m_rcOutput.left;
	int nOffsetY = (cy - m_rcOutput.Height()) / 2 - m_rcOutput.top;

	CPoint pTempPoint[3];

	// FillPath()�� ����ϱ� ���ؼ� �켱 ��θ� �����Ѵ�
	pDC->BeginPath();

	// ȿ���� ����� ��� �����͵��� ����Ѵ�
	for(i = 0; i < m_nPointSize; i++)
	{
		// �� ��� ���Ŀ� ���� �����͵��� ����Ͽ� �� Ȥ�� ������ ��� �׸���
		switch(m_pTypeArray[i])
		{
		case PT_MOVETO : 
			pDC->MoveTo(m_pPointArray[i].x + nOffsetX,
				m_pPointArray[i].y + nOffsetY);
			break;

		case PT_LINETO | PT_CLOSEFIGURE:
		case PT_LINETO :
			pDC->LineTo(m_pPointArray[i].x + nOffsetX,
				m_pPointArray[i].y + nOffsetY);
			break;

		case PT_BEZIERTO | PT_CLOSEFIGURE:
		case PT_BEZIERTO :
			pTempPoint[0] = m_pPointArray[i];
			pTempPoint[1] = m_pPointArray[i + 1];
			pTempPoint[2] = m_pPointArray[i + 2];

			pTempPoint[0].Offset(nOffsetX, nOffsetY);
			pTempPoint[1].Offset(nOffsetX, nOffsetY);
			pTempPoint[2].Offset(nOffsetX, nOffsetY);

			pDC->PolyBezierTo(pTempPoint, 3);

			i += 2;
			break;
		}
	}

	// ��� �߿��� ������ �ƴ� ������ �������� �����
	pDC->CloseFigure();
	// ��� ������ �����Ѵ�
	pDC->EndPath();

	// ���� �ܰ��� ����̶�� StrokePath() �Լ��� ��θ� �׸���
	if(m_bOutLine)		pDC->StrokePath();
	else
	{
		// ���� �ܰ��� ����� �ƴ϶�� ��� ���θ� ĥ�� �귯���� �����Ѵ�
		CBrush BlackBrush, *pOldBrush;
		BlackBrush.CreateSolidBrush(RGB(0, 0, 0));
		pOldBrush = pDC->SelectObject(&BlackBrush);

		// FillPath() �Լ��� ���ΰ� ä���� ��θ� ����Ѵ�
		pDC->FillPath();

		// ���ҽ��� ��ȯ�Ѵ�
		pDC->SelectObject(pOldBrush);
		BlackBrush.DeleteObject();
	}
}
