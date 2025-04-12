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
	// ��� �������� ���� �ʱ�ȭ�Ѵ�
	m_clrThumb		= RGB(255, 255, 255);
	m_clrSelection	= RGB(150, 150, 150);
	m_clrChannel	= RGB(86, 86, 86);

	// ���� ��¿� �귯���� �����Ѵ�
	m_brsChannel.CreateSolidBrush(m_clrChannel);

	m_bHorz			= TRUE;
}

CCustomSliderCtrl::~CCustomSliderCtrl()
{
	// �귯���� �Ҹ��Ų��
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
	// �������� �������� �����̴� ��Ÿ�Ͽ��� �˾Ƴ���
	m_bHorz = !(GetStyle() & TBS_VERT);

	CSliderCtrl::PreSubclassWindow();
}

// �ڵ� ������ �����ϴ� �Լ�
void CCustomSliderCtrl::SetThumbColor(COLORREF clrThumb)
{
	// ������ ������ ��� ����
	if(m_clrThumb == clrThumb)		return;

	// ���ο� ������ �����Ѵ�
	m_clrThumb			= clrThumb;

	// ȭ���� ���� �׸���
	Invalidate(FALSE);
}

// ���õ� ������ ������ �����ϴ� �Լ�
void CCustomSliderCtrl::SetSelectionColor(COLORREF clrSelection)
{
	// ������ ������ ��� ����
	if(m_clrSelection == clrSelection)		return;

	// ���ο� ������ �����Ѵ�
	m_clrSelection		= clrSelection;

	// ȭ���� ���� �׸���
	Invalidate(FALSE);
}

// ���õ��� ���� ������ ������ �����ϴ� �Լ�
void CCustomSliderCtrl::SetChannelColor(COLORREF clrChannel)
{
	// ������ ������ ��� ����
	if(m_clrChannel == clrChannel)		return;

	// ���ο� ������ �����Ѵ�
	m_clrChannel		= clrChannel;

	// ���ο� �������� �귯���� �ٽ� �����Ѵ�
	if(m_brsChannel.m_hObject)		m_brsChannel.DeleteObject();
	m_brsChannel.CreateSolidBrush(m_clrChannel);

	// ȭ���� ���� �׸���
	Invalidate(FALSE);
}

// �����̴� ��Ʈ�� �׸��� �޽���
void CCustomSliderCtrl::OnCustomdraw(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LPNMCUSTOMDRAW pDraw = (LPNMCUSTOMDRAW)pNMHDR;

	// ���� �׸��� �޽����� �ܰ�
	switch(pDraw->dwDrawStage)
	{
	case CDDS_PREPAINT:
		// �׸��� �޽����� �����ϵ��� �����Ѵ�
		*pResult = CDRF_NOTIFYITEMDRAW;         
		break;
	case CDDS_ITEMPREPAINT:
		// �׸� �׸���
		// �⺻ ��ƾ�� �������� �ʵ��� �����Ѵ�
		*pResult = CDRF_SKIPDEFAULT;

		{
			CDC dc;
			dc.Attach(pDraw->hdc);

			switch(pDraw->dwItemSpec)
			{
			case TBCD_TICS:
				// ������ ���� �⺻ ��ƾ�� �����ϵ��� �����Ѵ�
				*pResult = CDRF_DODEFAULT;
				break;
			case TBCD_THUMB:
				// �ڵ��� �׸���
				DrawThumb(&dc, pDraw->rc);
				break;
			case TBCD_CHANNEL:
				// ������ �׸���
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

// �ڵ��� �׸��� �Լ�
void CCustomSliderCtrl::DrawThumb(CDC *pDC, CRect rcItem)
{
	// �ڵ� �̵��� ������ �� �׷����� �ʱ� ������,
	// �ڵ��� �׸��� ���� ������ �켱 �ѹ� ����Ѵ�

	// ������ ������ ��´�
	CRect rcChannel;
	GetChannelRect(&rcChannel);

	// ���� �����̴��� ���, ������ ��ǥ�� ���� ����ó�� ���ϵǱ� ������ ��������� �Ѵ�
	if(!m_bHorz)
	{
		// ���� ��ǥ�� ���� ��ǥ��, ���� ��ǥ�� ���� ��ǥ�� �����Ѵ�
		int nTemp;
		nTemp = rcChannel.left;
		rcChannel.left = rcChannel.top;
		rcChannel.top = nTemp;
		nTemp = rcChannel.right;
		rcChannel.right = rcChannel.bottom;
		rcChannel.bottom = nTemp;
	}

	// �ڵ� ��¿� DC�� �ڵ� �������� Ŭ���� �Ǿ� �����Ƿ�
	// DC�� ���� ��� ������ ����Ѵ�
	CDC *pClientDC = GetDC();
	DrawChannel(pClientDC, rcChannel);
	ReleaseDC(pClientDC);

	// �ڵ��� ������ ĥ�Ѵ�
	rcItem.DeflateRect(2, 2);
	pDC->FillSolidRect(rcItem, m_clrThumb);

	// ù��° ������ �ܰ����� ����Ѵ�
	rcItem.InflateRect(1, 1);
	pDC->Draw3dRect(&rcItem, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DLIGHT));

	// �ι��� ������ �ܰ����� ����Ѵ�
	rcItem.InflateRect(1, 1);
	pDC->Draw3dRect(&rcItem, ::GetSysColor(COLOR_3DLIGHT), ::GetSysColor(COLOR_3DSHADOW));

	CRect rcLine;

	// ������ ���� ������ ����Ѵ�
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

// ������ �׸��� �Լ�
void CCustomSliderCtrl::DrawChannel(CDC *pDC, CRect rcItem)
{
	int nMin, nMax, nRangeMin, nRangeMax;

	// ���� ���õ� ������ ��´�
	GetSelection(nMin, nMax);
	// �����̴��� ��ü �ִ�/�ּҰ��� ��´�
	nRangeMin = GetRangeMin();
	nRangeMax = GetRangeMax();

	// �ּҰ��� 0���� �ٲپ� �ִ밪�� ������ �����Ѵ�
	nRangeMax	-= nRangeMin;
	nMax		-= nRangeMin;
	nMin		-= nRangeMin;

	// ���� ���� �����̴����
	if(m_bHorz)
	{
		// ������ �� �Ʒ� ��ġ�� ����Ѵ�
		rcItem.top = rcItem.top + rcItem.Height() / 2 - 2;
		rcItem.bottom = rcItem.top + 4;
	}
	else
	{
		// ���� ���� �����̴���� ������ �� �� ��ġ�� ����Ѵ�
		rcItem.left = rcItem.left + rcItem.Width() / 2 - 2;
		rcItem.right = rcItem.left + 4;
	}

	// ������ ���õ��� ���� ������ �귯���� ��� ĥ�Ѵ�
	CBrush *pOldBrush = pDC->SelectObject(&m_brsChannel);
	pDC->RoundRect(&rcItem, CPoint(6, 6));
	pDC->SelectObject(pOldBrush);

	// ���� ��ǥ�� ��� ���⿡�� 1 ���� ��Ų��
	rcItem.DeflateRect(1, 1);

	// ���� ���� �����̴����
	if(m_bHorz)
	{
		// ���� ���õ� ������ ��/�� ��ġ�� ����Ѵ�
		int nWidth = rcItem.Width() + 2;
		rcItem.right	= rcItem.left - 1 + (int)(nWidth * (double)nMax / nRangeMax);
		rcItem.left		= rcItem.left - 1 + (int)(nWidth * (double)nMin / nRangeMax);
	}
	else
	{
		// ���� ���õ� ������ ��/�Ʒ� ��ġ�� ����Ѵ�
		int nHeight = rcItem.Height() + 2;
		rcItem.bottom	= rcItem.top - 1 + (int)(nHeight * (double)nMax / nRangeMax);
		rcItem.top		= rcItem.top - 1 + (int)(nHeight * (double)nMin / nRangeMax);
	}

	// ���õ� ���� ������ ���� �������� ĥ�Ѵ�
	pDC->FillSolidRect(&rcItem, m_clrSelection);
}

BOOL CCustomSliderCtrl::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// �ڵ��� ������ ��´�
	CRect rcThumb;
	GetThumbRect(&rcThumb);

	// ���콺 Ŀ���� ��ǥ�� ��´�
	CPoint ptCursor;
	::GetCursorPos(&ptCursor);
	ScreenToClient(&ptCursor);

	// ���� �ڵ� ������ ���콺 Ŀ���� �ִٸ�
	if(rcThumb.PtInRect(ptCursor))
	{
		// ����/���� ���� ���콺 Ŀ���� �����Ѵ�
		if(m_bHorz)			SetCursor(AfxGetApp()->LoadCursor(IDC_HORZ_MOVE_CURSOR));
		else				SetCursor(AfxGetApp()->LoadCursor(IDC_VERT_MOVE_CURSOR));
		return TRUE;
	}
	
	return CSliderCtrl::OnSetCursor(pWnd, nHitTest, message);
}
