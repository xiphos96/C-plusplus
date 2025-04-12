// ImageDialog.cpp : implementation file
//

#include "stdafx.h"
#include "bitmapdialog.h"
#include "ImageDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageDialog dialog


CImageDialog::CImageDialog(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CImageDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// �������� �ʱ�ȭ�մϴ�.
	m_nBkgndMode = MODE_CENTER;
	m_NullBrush.CreateStockObject(NULL_BRUSH);
	m_clrBkgnd = ::GetSysColor(COLOR_ACTIVEBORDER);
}

CImageDialog::~CImageDialog()
{
	// ��ü���� �����մϴ�.
	m_bmpBkgnd.DeleteObject();
	m_NullBrush.DeleteObject();
}

void CImageDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImageDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImageDialog, CDialog)
	//{{AFX_MSG_MAP(CImageDialog)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageDialog message handlers

int CImageDialog::GetBkgndMode()
{
	return m_nBkgndMode;
}

void CImageDialog::SetBkgndMode(int nMode)
{
	// ��� ����� �߸��Ǿ��ٸ�, �⺻���� ��� ����� ����
	if(nMode < MODE_CENTER || nMode > MODE_STRETCH)	nMode = MODE_CENTER;

	m_nBkgndMode = nMode;

	// �����찡 ��� ���̶�� ȭ�� ����
	if(::IsWindowVisible(m_hWnd))		Invalidate();
}

BOOL CImageDialog::SetBitmap(UINT nResourceID)
{
	// �̹� ��Ʈ���� �ִٸ� �켱 �Ҹ��Ŵ
	if(m_bmpBkgnd.m_hObject)	m_bmpBkgnd.DeleteObject();

	// ��Ʈ�� �ε�
	if(m_bmpBkgnd.LoadBitmap(nResourceID))
	{
		m_bmpBkgnd.GetBitmap(&m_bmpInfo);
		return TRUE;
	}
	return FALSE;
}

BOOL CImageDialog::SetBitmap(LPCTSTR pFileName)
{
	ASSERT(pFileName);

	// �̹� ��Ʈ���� �ִٸ� �켱 �Ҹ��Ŵ
	if(m_bmpBkgnd.m_hObject)	m_bmpBkgnd.DeleteObject();

	// ��Ʈ�� ���� �ε�
	HBITMAP hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			LPCTSTR(pFileName), IMAGE_BITMAP,
			0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	if(hBitmap == NULL)			return FALSE;

	// ��Ʈ�� ��ü�� ����
	if(m_bmpBkgnd.Attach(hBitmap))
	{
		m_bmpBkgnd.GetBitmap(&m_bmpInfo);
		return TRUE;
	}
	return FALSE;
}

BOOL CImageDialog::OnEraseBkgnd(CDC* pDC) 
{
	// ��� �̹����� ������ �⺻ ��ƾ ����
	if(m_bmpBkgnd.m_hObject == NULL)
		return CDialog::OnEraseBkgnd(pDC);

	// �޸� DC�� ����� ���� ���۸� ����
	CDC MemDC;
	CBitmap ScreenBmp, *pOldBmp;

	GetClientRect(&m_rcClient);

	MemDC.CreateCompatibleDC(pDC);
	ScreenBmp.CreateCompatibleBitmap(pDC, m_rcClient.Width(), m_rcClient.Height());
	pOldBmp = MemDC.SelectObject(&ScreenBmp);

	CDC BmpDC;
	CBitmap *pOldBmp2;

	BmpDC.CreateCompatibleDC(pDC);
	pOldBmp2 = BmpDC.SelectObject(&m_bmpBkgnd);

	int x, y;

	// ��� ��Ŀ� ���� �ڵ�
	switch(m_nBkgndMode)
	{
	case MODE_CENTER:
		MemDC.FillSolidRect(&m_rcClient, m_clrBkgnd);

		x = (m_rcClient.Width() - m_bmpInfo.bmWidth) / 2;
		y = (m_rcClient.Height() - m_bmpInfo.bmHeight) / 2;
		MemDC.BitBlt(x, y, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight,
			&BmpDC, 0, 0, SRCCOPY);
		break;
	case MODE_TILE:
		for(y = 0; y < m_rcClient.Height(); y += m_bmpInfo.bmHeight)
		{
			for(x = 0; x < m_rcClient.Width(); x += m_bmpInfo.bmWidth)
			{
				MemDC.BitBlt(x, y, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight,
					&BmpDC, 0, 0, SRCCOPY);
			}
		}
		break;
	case MODE_STRETCH:
		MemDC.StretchBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(),
			&BmpDC, 0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, SRCCOPY);
		break;
	}

	pDC->BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(),
		&MemDC, 0, 0, SRCCOPY);

	BmpDC.SelectObject(pOldBmp2);
	BmpDC.DeleteDC();

	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();

	return TRUE;
}

HBRUSH CImageDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	// ��� �̹����� �����Ǿ� �ִٸ�,
	// �� ��Ʈ�ѵ��� ����� �����ϰ� �����Ѵ�.
	if(m_bmpBkgnd.m_hObject)
	{
		if(nCtlColor == CTLCOLOR_STATIC || nCtlColor == CTLCOLOR_BTN)
		{
			pDC->SetBkMode(TRANSPARENT);
			return (HBRUSH)m_NullBrush;
		}
	}

	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}

void CImageDialog::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	Invalidate();
}
