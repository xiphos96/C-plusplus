// ImageProgressCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProgressCtrlDemo.h"
#include "ImageProgressCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageProgressCtrl

CImageProgressCtrl::CImageProgressCtrl()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	m_nTextType		= TEXT_PERCENT;
	m_strFormat		= "%%d";
	m_bHorz			= TRUE;

	m_clrLight		= ::GetSysColor(COLOR_3DHIGHLIGHT);
	m_clrShadow		= ::GetSysColor(COLOR_3DSHADOW);
	m_clrBkgnd		= ::GetSysColor(COLOR_3DFACE);
	m_clrPos		= ::GetSysColor(COLOR_ACTIVECAPTION);
	m_clrText		= ::GetSysColor(COLOR_HIGHLIGHTTEXT);

	m_nFontSize		= 8;
	m_strFontName	= "����ü";

	HDC hDC = ::GetDC(NULL);
	m_TextFont.CreateFont(-MulDiv(m_nFontSize, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, m_strFontName);
	::ReleaseDC(NULL, hDC);
}

CImageProgressCtrl::~CImageProgressCtrl()
{
	// ���� �Ǿ��� ��Ʈ�ʰ� ��Ʈ ��ü�� �Ҹ��Ų��
	if(m_bmpBorderLeft.m_hObject)	m_bmpBorderLeft.DeleteObject();
	if(m_bmpBorderCenter.m_hObject)	m_bmpBorderCenter.DeleteObject();
	if(m_bmpBorderRight.m_hObject)	m_bmpBorderRight.DeleteObject();

	if(m_bmpPosLeft.m_hObject)		m_bmpPosLeft.DeleteObject();
	if(m_bmpPosCenter.m_hObject)	m_bmpPosCenter.DeleteObject();
	if(m_bmpPosRight.m_hObject)		m_bmpPosRight.DeleteObject();

	m_TextFont.DeleteObject();
}


BEGIN_MESSAGE_MAP(CImageProgressCtrl, CProgressCtrl)
	//{{AFX_MSG_MAP(CImageProgressCtrl)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_NCPAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageProgressCtrl message handlers

void CImageProgressCtrl::PreSubclassWindow() 
{
	// ���α׷����ٰ� �������� �������� �˾Ƴ���
	m_bHorz = !(GetStyle() & PBS_VERTICAL);

	// Ŭ���̾�Ʈ ������ �����Ѵ�
	GetClientRect(&m_rcClient);

	CProgressCtrl::PreSubclassWindow();
}

// ���� ���� ��� ������ �����ϴ� �Լ�
void CImageProgressCtrl::SetTextType(TEXT_TYPE nType)
{
	// ���� ���� ���� ��� ����
	if(m_nTextType == nType)					return;

	// ���ο� ���� ����
	m_nTextType = nType;

	// ȭ�� �ٽ� �׸�
	Invalidate(FALSE);
}

// ���ڿ� ������ �����ϴ� �Լ�
void CImageProgressCtrl::SetTextFormat(LPCTSTR pFormat)
{
	// ���� ���� ���� ��� ����
	if(m_strFormat.Compare(pFormat) == 0)		return;

	// ���ο� ���� ����
	m_strFormat = pFormat;

	// ȭ�� �ٽ� �׸�
	Invalidate(FALSE);
}

// �׵θ� ���� ���� ���� �Լ�
void CImageProgressCtrl::SetLightColor(COLORREF clrLight)
{
	// ���� ���� ���� ��� ����
	if(m_clrLight == clrLight)					return;

	// ���ο� ���� ����
	m_clrLight = clrLight;

	// ���� ��Ʈ���� ������� �ʴ´ٸ� ȭ�� �ٽ� �׸�
	if(m_bmpBorderLeft.m_hObject == NULL
		|| m_bmpBorderCenter.m_hObject == NULL
		|| m_bmpBorderRight.m_hObject == NULL)		Invalidate(FALSE);
}

// �׵θ� ��ο� ���� ���� �Լ�
void CImageProgressCtrl::SetShadowColor(COLORREF clrShadow)
{
	// ���� ���� ���� ��� ����
	if(m_clrShadow == clrShadow)				return;

	// ���ο� ���� ����
	m_clrShadow = clrShadow;

	// ���� ��Ʈ���� ������� �ʴ´ٸ� ȭ�� �ٽ� �׸�
	if(m_bmpBorderLeft.m_hObject == NULL
		|| m_bmpBorderCenter.m_hObject == NULL
		|| m_bmpBorderRight.m_hObject == NULL)		Invalidate(FALSE);
}

// ���� ���� �Լ�
void CImageProgressCtrl::SetBkgndColor(COLORREF clrBkgnd)
{
	// ���� ���� ���� ��� ����
	if(m_clrBkgnd == clrBkgnd)					return;

	// ���ο� ���� ����
	m_clrBkgnd = clrBkgnd;

	// ���� ��Ʈ���� ������� �ʴ´ٸ� ȭ�� �ٽ� �׸�
	if(m_bmpBorderLeft.m_hObject == NULL
		|| m_bmpBorderCenter.m_hObject == NULL
		|| m_bmpBorderRight.m_hObject == NULL)		Invalidate(FALSE);
}

// ����� ���� ���� �Լ�
void CImageProgressCtrl::SetPosColor(COLORREF clrPos)
{
	// ���� ���� ���� ��� ����
	if(m_clrPos == clrPos)					return;

	// ���ο� ���� ����
	m_clrPos = clrPos;

	// ���� ��Ʈ���� ������� �ʴ´ٸ� ȭ�� �ٽ� �׸�
	if(m_bmpPosLeft.m_hObject == NULL
		|| m_bmpPosCenter.m_hObject == NULL
		|| m_bmpPosRight.m_hObject == NULL)		Invalidate(FALSE);
}

// �ؽ�Ʈ ���� ���� �Լ�
void CImageProgressCtrl::SetTextColor(COLORREF clrText)
{
	// ���� ���� ���� ��� ����
	if(m_clrText == clrText)					return;

	// ���ο� ���� ����
	m_clrText = clrText;

	// ȭ�� �ٽ� �׸�
	Invalidate(FALSE);
}

// ��Ʈ ���� �Լ�
void CImageProgressCtrl::SetTextFont(int nSize, LPCTSTR pFontName)
{
	// ���� ���� ���� ��� ����
	if(m_nFontSize == nSize && m_strFontName == pFontName)	return;

	// ���ο� ���� ����
	m_nFontSize		= nSize;
	m_strFontName	= pFontName;

	// ���� ��Ʈ�� �����Ѵ�
	if(m_TextFont.m_hObject)		m_TextFont.DeleteObject();

	// ���ο� ��Ʈ�� �����Ѵ�
	HDC hDC = ::GetDC(NULL);
	m_TextFont.CreateFont(-MulDiv(m_nFontSize, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, m_strFontName);
	::ReleaseDC(NULL, hDC);

	// ȭ�� �ٽ� �׸�
	Invalidate(FALSE);
}

// ��� �׵θ� ��Ʈ�� ���� �Լ�
HBITMAP CImageProgressCtrl::GetBorderBitmap(BMP_TYPE nType)
{
	// ��Ʈ���� ������ ���� �ش� ��Ʈ�� �ڵ��� �����Ѵ�
	switch(nType)
	{
	case BMP_LEFT:
		return (HBITMAP)m_bmpBorderLeft;
	case BMP_CENTER:
		return (HBITMAP)m_bmpBorderCenter;
	case BMP_RIGHT:
		return (HBITMAP)m_bmpBorderRight;
	}

	return NULL;
}

// ��� �׵θ� ��Ʈ�� ���� �Լ�
void CImageProgressCtrl::SetBorderBitmap(BMP_TYPE nType, UINT nBmpID)
{
	// ��Ʈ���� ������ ���� �ش� ��Ʈ���� �����ϰ� ��Ʈ���� �ε��Ѵ�
	// �׸��� ��Ʈ���� ������ ���Ѵ�
	switch(nType)
	{
	case BMP_LEFT:
		if(m_bmpBorderLeft.m_hObject)	m_bmpBorderLeft.DeleteObject();
		m_bmpBorderLeft.LoadBitmap(nBmpID);
		m_bmpBorderLeft.GetBitmap(&m_infoBorderLeft);
		break;
	case BMP_CENTER:
		if(m_bmpBorderCenter.m_hObject)	m_bmpBorderCenter.DeleteObject();
		m_bmpBorderCenter.LoadBitmap(nBmpID);
		m_bmpBorderCenter.GetBitmap(&m_infoBorderCenter);
		break;
	case BMP_RIGHT:
		if(m_bmpBorderRight.m_hObject)	m_bmpBorderRight.DeleteObject();
		m_bmpBorderRight.LoadBitmap(nBmpID);
		m_bmpBorderRight.GetBitmap(&m_infoBorderRight);
		break;
	}
}

// ��� �׵θ� ��Ʈ�� ���� �Լ�
void CImageProgressCtrl::SetBorderBitmap(BMP_TYPE nType, HBITMAP hBmp)
{
	// ��Ʈ���� ������ ���� �ش� ��Ʈ���� �����ϰ� ��Ʈ���� Attach�Ѵ�
	// �׸��� ��Ʈ���� ������ ���Ѵ�
	switch(nType)
	{
	case BMP_LEFT:
		if(m_bmpBorderLeft.m_hObject)	m_bmpBorderLeft.DeleteObject();
		m_bmpBorderLeft.Attach(hBmp);
		m_bmpBorderLeft.GetBitmap(&m_infoBorderLeft);
		break;
	case BMP_CENTER:
		if(m_bmpBorderCenter.m_hObject)	m_bmpBorderCenter.DeleteObject();
		m_bmpBorderCenter.Attach(hBmp);
		m_bmpBorderCenter.GetBitmap(&m_infoBorderCenter);
		break;
	case BMP_RIGHT:
		if(m_bmpBorderRight.m_hObject)	m_bmpBorderRight.DeleteObject();
		m_bmpBorderRight.Attach(hBmp);
		m_bmpBorderRight.GetBitmap(&m_infoBorderRight);
		break;
	}
}

// ����� ��Ʈ�� ���� �Լ�
HBITMAP CImageProgressCtrl::GetPosBitmap(BMP_TYPE nType)
{
	// ��Ʈ���� ������ ���� �ش� ��Ʈ�� �ڵ��� �����Ѵ�
	switch(nType)
	{
	case BMP_LEFT:
		return (HBITMAP)m_bmpPosLeft;
	case BMP_CENTER:
		return (HBITMAP)m_bmpPosCenter;
	case BMP_RIGHT:
		return (HBITMAP)m_bmpPosRight;
	}

	return NULL;
}

// ����� ��Ʈ�� ���� �Լ�
void CImageProgressCtrl::SetPosBitmap(BMP_TYPE nType, UINT nBmpID)
{
	// ��Ʈ���� ������ ���� �ش� ��Ʈ���� �����ϰ� ��Ʈ���� �ε��Ѵ�
	// �׸��� ��Ʈ���� ������ ���Ѵ�
	switch(nType)
	{
	case BMP_LEFT:
		if(m_bmpPosLeft.m_hObject)		m_bmpPosLeft.DeleteObject();
		m_bmpPosLeft.LoadBitmap(nBmpID);
		m_bmpPosLeft.GetBitmap(&m_infoPosLeft);
		break;
	case BMP_CENTER:
		if(m_bmpPosCenter.m_hObject)	m_bmpPosCenter.DeleteObject();
		m_bmpPosCenter.LoadBitmap(nBmpID);
		m_bmpPosCenter.GetBitmap(&m_infoPosCenter);
		break;
	case BMP_RIGHT:
		if(m_bmpPosRight.m_hObject)		m_bmpPosRight.DeleteObject();
		m_bmpPosRight.LoadBitmap(nBmpID);
		m_bmpPosRight.GetBitmap(&m_infoPosRight);
		break;
	}
}

// ����� ��Ʈ�� ���� �Լ�
void CImageProgressCtrl::SetPosBitmap(BMP_TYPE nType, HBITMAP hBmp)
{
	// ��Ʈ���� ������ ���� �ش� ��Ʈ���� �����ϰ� ��Ʈ���� Attach�Ѵ�
	// �׸��� ��Ʈ���� ������ ���Ѵ�
	switch(nType)
	{
	case BMP_LEFT:
		if(m_bmpPosLeft.m_hObject)		m_bmpPosLeft.DeleteObject();
		m_bmpPosLeft.Attach(hBmp);
		m_bmpPosLeft.GetBitmap(&m_infoPosLeft);
		break;
	case BMP_CENTER:
		if(m_bmpPosCenter.m_hObject)	m_bmpPosCenter.DeleteObject();
		m_bmpPosCenter.Attach(hBmp);
		m_bmpPosCenter.GetBitmap(&m_infoPosCenter);
		break;
	case BMP_RIGHT:
		if(m_bmpPosRight.m_hObject)		m_bmpPosRight.DeleteObject();
		m_bmpPosRight.Attach(hBmp);
		m_bmpPosRight.GetBitmap(&m_infoPosRight);
		break;
	}
}

void CImageProgressCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// �ε巯�� ȭ�� ������ ���� ������۸��� �����Ѵ�
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	CBitmap MemBmp;
	MemBmp.CreateCompatibleBitmap(&dc, m_rcClient.Width(), m_rcClient.Height());
	CBitmap *pOldBitmap = MemDC.SelectObject(&MemBmp);

	// �̹����� ũ�Ⱑ ���α׷������� ũ�⺸�� ���� �� �ֱ� ������,
	// ���� ȭ���� ������ �޸� DC�� �����Ѵ�
	MemDC.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(),
		&dc, 0, 0, SRCCOPY);

	CDC BmpDC;
	CBitmap *pOldBmp;
	CRect rcTemp, rcTemp2;

	// ��Ʈ�� ��¿� DC�� �����Ѵ�
	BmpDC.CreateCompatibleDC(&dc);

	// ���� ��� �׵θ� ��Ʈ���� �������� �ʾҴٸ�
	if(m_bmpBorderLeft.m_hObject == NULL
		|| m_bmpBorderCenter.m_hObject == NULL
		|| m_bmpBorderRight.m_hObject == NULL)
	{
		// Ŭ���̾�Ʈ ������ŭ 3���� �׵θ��� ����Ѵ�
		rcTemp = m_rcClient;
		MemDC.Draw3dRect(&rcTemp, m_clrShadow, m_clrLight);

		// �׵θ� ������ ��� �������� ĥ�Ѵ�
		rcTemp.DeflateRect(1, 1);
		MemDC.FillSolidRect(&rcTemp, m_clrBkgnd);
	}
	else
	{
		// Ŭ���̾�Ʈ ������ ������ �׵θ� �̹��� ��� ������ ����Ѵ�
		rcTemp = m_rcClient;
		if(m_bHorz)
		{
			rcTemp.right	= rcTemp.left + m_infoBorderLeft.bmWidth;
			rcTemp.top		= (rcTemp.top + rcTemp.bottom - m_infoBorderLeft.bmHeight) / 2;
			rcTemp.bottom	= rcTemp.top + m_infoBorderLeft.bmHeight;

			rcTemp2			= rcTemp;
			rcTemp2.left	= rcTemp.right;
		}
		else
		{
			rcTemp.top		= rcTemp.bottom - m_infoBorderLeft.bmHeight;
			rcTemp.left		= (rcTemp.left + rcTemp.right - m_infoBorderLeft.bmWidth) / 2;
			rcTemp.right	= rcTemp.left + m_infoBorderLeft.bmWidth;

			rcTemp2			= rcTemp;
			rcTemp2.bottom	= rcTemp.top;
		}

		// ���� �׵θ� �̹����� ����Ѵ�
		pOldBmp = BmpDC.SelectObject(&m_bmpBorderLeft);
		MemDC.BitBlt(rcTemp.left, rcTemp.top, m_infoBorderLeft.bmWidth, m_infoBorderLeft.bmHeight,
			&BmpDC, 0, 0, SRCCOPY);

		// Ŭ���̾�Ʈ ������ ������ �׵θ� �̹��� ��� ������ ����Ѵ�
		if(m_bHorz)
		{
			rcTemp.right	= m_rcClient.right;
			rcTemp.left		= m_rcClient.right - m_infoBorderRight.bmWidth;

			rcTemp2.right	= rcTemp.left;
		}
		else
		{
			rcTemp.top		= m_rcClient.top;
			rcTemp.bottom	= m_rcClient.top + m_infoBorderRight.bmHeight;

			rcTemp2.top		= rcTemp.bottom;
		}

		// ���� �׵θ� �̹����� ����Ѵ�
		BmpDC.SelectObject(&m_bmpBorderRight);
		MemDC.BitBlt(rcTemp.left, rcTemp.top, m_infoBorderRight.bmWidth, m_infoBorderRight.bmHeight,
			&BmpDC, 0, 0, SRCCOPY);

		// ������ ���� �׵θ� �̹��� ���̿� �׵θ� �߾� �̹����� ����Ѵ�
		BmpDC.SelectObject(&m_bmpBorderCenter);
		MemDC.StretchBlt(rcTemp2.left, rcTemp2.top, rcTemp2.Width(), rcTemp2.Height(),
			&BmpDC, 0, 0, m_infoBorderCenter.bmWidth, m_infoBorderCenter.bmHeight, SRCCOPY);

		BmpDC.SelectObject(pOldBmp);
	}

	// ���� ����� ��ġ�� ��ü ������ ��´�
	int nPos = GetPos(), nMin, nMax;
	GetRange(nMin, nMax);

	// 0�� ���������� ��ġ�� �ִ밪�� ����Ѵ�
	nPos -= nMin;
	nMax -= nMin;

	// ���� ��ġ�� �ۼ��������� ����Ѵ�
	double dRate = (double)nPos / nMax;

	// ���� ����� ��Ʈ���� �������� �ʾҴٸ�
	if(m_bmpPosLeft.m_hObject == NULL
		|| m_bmpPosCenter.m_hObject == NULL
		|| m_bmpPosRight.m_hObject == NULL)
	{
		// Ŭ���̾�Ʈ �������� �������� 2�ȼ� ���δ�
		rcTemp = m_rcClient;
		rcTemp.DeflateRect(2, 2);

		// ���� ������� ���� ����� �� ��ǥ�� ���Ѵ�
		if(m_bHorz)		rcTemp.right	= rcTemp.left + (int)(rcTemp.Width() * dRate);
		else			rcTemp.top		= rcTemp.bottom - (int)(rcTemp.Height() * dRate);

		// ����ٸ� ����Ѵ�
		MemDC.FillSolidRect(&rcTemp, m_clrPos);
	}
	else
	{
		// Ŭ���̾�Ʈ �������� �������� 2�ȼ� ���δ�
		rcTemp = m_rcClient;
		rcTemp.DeflateRect(2, 2);

		// ����� ���� �̹��� ��� ������ ����Ѵ�
		if(m_bHorz)
		{
			rcTemp.right	= rcTemp.left + m_infoPosLeft.bmWidth;
			rcTemp.top		= (rcTemp.top + rcTemp.bottom - m_infoPosLeft.bmHeight) / 2;
			rcTemp.bottom	= rcTemp.top + m_infoPosLeft.bmHeight;

			rcTemp2			= rcTemp;
			rcTemp2.left	= rcTemp.right;
		}
		else
		{
			rcTemp.top		= rcTemp.bottom - m_infoPosLeft.bmHeight;
			rcTemp.left		= (rcTemp.left + rcTemp.right - m_infoPosLeft.bmWidth) / 2;
			rcTemp.right	= rcTemp.left + m_infoPosLeft.bmWidth;

			rcTemp2			= rcTemp;
			rcTemp2.bottom	= rcTemp.top;
		}

		// ����� ���� �̹����� ����Ѵ�
		pOldBmp = BmpDC.SelectObject(&m_bmpPosLeft);
		MemDC.BitBlt(rcTemp.left, rcTemp.top, m_infoPosLeft.bmWidth, m_infoPosLeft.bmHeight,
			&BmpDC, 0, 0, SRCCOPY);

		// ���� ������� ���� ����� �� ��ġ�� ����Ѵ�
		if(m_bHorz)
		{
			rcTemp.left		= rcTemp.right;
			rcTemp.right	= m_rcClient.right - 2 - m_infoPosRight.bmWidth;

			rcTemp.right	= rcTemp.left + (int)(rcTemp.Width() * dRate);
		}
		else
		{
			rcTemp.bottom	= rcTemp.top;
			rcTemp.top		= m_rcClient.top + 2 + m_infoPosRight.bmHeight;

			rcTemp.top		= rcTemp.bottom - (int)(rcTemp.Height() * dRate);
		}

		// ����� �� ��ġ�� �°� ����� �߾� �̹����� ����Ѵ�
		BmpDC.SelectObject(&m_bmpPosCenter);
		MemDC.StretchBlt(rcTemp.left, rcTemp.top, rcTemp.Width(), rcTemp.Height(),
			&BmpDC, 0, 0, m_infoPosCenter.bmWidth, m_infoPosCenter.bmHeight, SRCCOPY);

		// ����� �߾� �̹����� ���������� ����� ���� �̹��� ��� ������ ����Ѵ�
		rcTemp2 = rcTemp;
		if(m_bHorz)
		{
			rcTemp2.left	= rcTemp2.right;
			rcTemp2.right	= rcTemp2.left + m_infoPosRight.bmWidth;
		}
		else
		{
			rcTemp2.bottom	= rcTemp2.top;
			rcTemp2.top		= rcTemp2.bottom - m_infoPosRight.bmHeight;
		}

		// ����� ���� �̹����� ����Ѵ�
		BmpDC.SelectObject(&m_bmpPosRight);
		MemDC.BitBlt(rcTemp2.left, rcTemp2.top, m_infoPosRight.bmWidth, m_infoPosRight.bmHeight,
			&BmpDC, 0, 0, SRCCOPY);

		BmpDC.SelectObject(pOldBmp);
	}

	// ���� ���� ���¸� ����ؾ� �Ѵٸ�
	if(m_nTextType != TEXT_NONE)
	{
		CString strText;

		// �ۼ���������� ���� ������� ���ڿ��� �����Ѵ�
		if(m_nTextType == TEXT_PERCENT)		strText.Format("%d%%", (int)(dRate * 100));
		// ���� ���� ���ڿ��� ����Ѵٸ�, ���� ���ڿ��� ����Ͽ� ���ڿ��� �����Ѵ�
		if(m_nTextType == TEXT_FORMAT)		strText.Format(m_strFormat, GetPos());

		// �ؽ�Ʈ ��¿� ��Ʈ�� �����Ѵ�
		CFont *pOldFont = MemDC.SelectObject(&m_TextFont);

		// �ؽ�Ʈ ����� �������� �����Ѵ�
		MemDC.SetBkMode(TRANSPARENT);
		// �켱 ����� ������ �ؽ�Ʈ �������� �����Ѵ�
		MemDC.SetTextColor(m_clrPos);
		// ���� ���� ���ڿ��� ����Ѵ�
		MemDC.DrawText(strText, &m_rcClient, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		// ���� ������� ������ Ŭ���� �������� �����Ѵ�
		CRgn ClipRgn;
		ClipRgn.CreateRectRgn(rcTemp.left, rcTemp.top, rcTemp.right, rcTemp.bottom);
		MemDC.SelectClipRgn(&ClipRgn);

		// �ؽ�Ʈ ������ �����Ѵ�
		MemDC.SetTextColor(m_clrText);
		// ���� ���� ���ڿ��� ����Ѵ�
		MemDC.DrawText(strText, &m_rcClient, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		// Ŭ���� ������ �����Ѵ�
		MemDC.SelectClipRgn(NULL);
		// ���� ��ü�� �����Ѵ�
		ClipRgn.DeleteObject();
		// ��Ʈ�� ��ȯ�Ѵ�
		MemDC.SelectObject(pOldFont);
	}

	// ȭ�鿡 ������� �׸� ������ ����Ѵ�
	dc.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(),
		&MemDC, 0, 0, SRCCOPY);

	// ��Ʈ�� DC�� �����Ѵ�
	BmpDC.DeleteDC();

	// �޸� DC�� �����ϰ� ��Ʈ���� �����Ѵ�
	MemDC.SelectObject(pOldBitmap);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

BOOL CImageProgressCtrl::OnEraseBkgnd(CDC* pDC) 
{
	// ����� ������ �ʴ´�
	return TRUE;
//	return CProgressCtrl::OnEraseBkgnd(pDC);
}

void CImageProgressCtrl::OnNcPaint() 
{
	// ���α׷����� ��ü�� �׵θ��� ������� �ʱ� ���ؼ�
	// �ƹ� �۾��� ���ϰ� �����Ѵ�
}
