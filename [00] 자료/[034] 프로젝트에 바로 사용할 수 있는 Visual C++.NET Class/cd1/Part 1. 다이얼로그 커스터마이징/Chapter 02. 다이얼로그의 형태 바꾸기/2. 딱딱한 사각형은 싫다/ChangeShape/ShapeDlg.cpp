// ShapeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "changeshape.h"
#include "ShapeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShapeDlg dialog

CShapeDlg::CShapeDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CShapeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CShapeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShapeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShapeDlg, CDialog)
	//{{AFX_MSG_MAP(CShapeDlg)
	ON_WM_NCHITTEST()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShapeDlg message handlers

// ���̾�α� ��� ���濡 ����� ��Ʈ���� �����ϴ� �Լ� : ���Ͽ��� �б�
void CShapeDlg::SetShapeBitmap(LPCTSTR pFileName, COLORREF clrTransparent)
{
	// ���Ͽ��� ��Ʈ���� �ε��Ѵ�
	HBITMAP hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			LPCTSTR(pFileName), IMAGE_BITMAP,
			0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	if(hBmp == NULL)		return;

	// �ε�� ��Ʈ���� ���̾�α��� ������� �����Ѵ�
	SetShapeBitmap(hBmp, clrTransparent);

	// ��Ʈ���� �����Ѵ�
	::DeleteObject(hBmp);
}

// ���̾�α� ��� ���濡 ����� ��Ʈ���� �����ϴ� �Լ� : �ε�� ���ҽ��� ����
void CShapeDlg::SetShapeBitmap(HBITMAP hBitmap, COLORREF clrTransparent)
{
	if(hBitmap == NULL)		return;

	// ������ ���� ��ü�� �ִٸ� �����Ѵ�
	if(m_rgnBitmap.m_hObject)		m_rgnBitmap.DeleteObject();
	// �� ���� ��ü�� �����Ѵ�
	m_rgnBitmap.CreateRectRgn(0, 0, 0, 0);

	BITMAP		bmpInfo;
	
	// ��Ʈ���� ������ �д´�
	::GetObject(hBitmap, sizeof(bmpInfo), &bmpInfo);

	// 32��Ʈ ��Ʈ���� �����ϱ� ���� ����� �켱 �����Ѵ�
	BITMAPINFOHEADER Header32Bit;
	
	::memset(&Header32Bit, 0, sizeof(Header32Bit));
	Header32Bit.biSize			= sizeof(BITMAPINFOHEADER);
	Header32Bit.biWidth			= bmpInfo.bmWidth;
	Header32Bit.biHeight		= bmpInfo.bmHeight;
	Header32Bit.biPlanes		= 1;
	Header32Bit.biBitCount		= 32;
	Header32Bit.biCompression	= BI_RGB;
	
	// ȭ�� DC�� ȣȯ�Ǵ� �޸� DC�� �����Ѵ�
	HDC hScreenDC = ::GetDC(NULL);
	HDC hMemDC = ::CreateCompatibleDC(hScreenDC);
	
	// �޸� DC�� �Ӽ��� ���� 32��Ʈ ��Ʈ���� �����Ѵ�
	void *pBmpBits = NULL;
	HBITMAP	h32BitBmp = CreateDIBSection(hMemDC, (BITMAPINFO*)&Header32Bit,
		DIB_RGB_COLORS, &pBmpBits, NULL, 0);

	if(h32BitBmp)	
	{
		// 32 ��Ʈ ��Ʈ���� ������ �д´�
		BITMAP bmpInfo32;
		::GetObject(h32BitBmp, sizeof(bmpInfo32), &bmpInfo32);
		// ���� ����Ʈ ���� 4�� ����� �����
		if(bmpInfo32.bmWidthBytes % 4 > 0)
			bmpInfo32.bmWidthBytes += (4 - (bmpInfo32.bmWidthBytes % 4));

		// �޸� DC�� 32��Ʈ ��Ʈ���� �����Ѵ�
		HBITMAP hOldBmp = (HBITMAP)::SelectObject(hMemDC, h32BitBmp);

		// �޸� DC�� ȣȯ�Ǵ� DC�� �ϳ� �����Ͽ� ���� ��Ʈ���� �����ϰ�,
		// ���� ��Ʈ���� �޸� DC�� 32��Ʈ ��Ʈ�ʿ� �����Ѵ�
		HDC hBmpDC = ::CreateCompatibleDC(hMemDC);
		HBITMAP	hOldBmp2 = (HBITMAP)::SelectObject(hBmpDC, hBitmap);

		::BitBlt(hMemDC, 0, 0, bmpInfo32.bmWidth, bmpInfo32.bmHeight,
			hBmpDC, 0, 0, SRCCOPY);

		::SelectObject(hBmpDC, hOldBmp2);
		::DeleteDC(hBmpDC);

		// �簢 �������� �����ϴ� ���� �����͸� �����Ѵ�
		// ���� �����Ϳ� �ʱ� ������ �� �ִ� �簢 ������ 100���� �Ѵ�
		DWORD dwMaxRect = 100;
		HANDLE hRgnData = ::GlobalAlloc(GHND, sizeof(RGNDATAHEADER) + (sizeof(RECT) * dwMaxRect));
		RGNDATA *pRgnData = (RGNDATA*)::GlobalLock(hRgnData);

		// ���� �������� ����� �ʱ�ȭ �Ѵ�
		pRgnData->rdh.dwSize	= sizeof(RGNDATAHEADER);
		pRgnData->rdh.iType		= RDH_RECTANGLES;
		pRgnData->rdh.nCount	= 0;
		pRgnData->rdh.nRgnSize	= 0;
		::SetRect(&pRgnData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0);

		// 32 ��Ʈ ��Ʈ���� �ȼ� �����͸� ���Ѵ�
		// ��Ʈ���� �� �Ʒ��� ������ ����Ǳ� ������,
		// ���� �Ʒ��� ���� ù ��ġ�� ���� �����Ѵ�
		BYTE *pPixel = (BYTE*)bmpInfo32.bmBits
			+ ((bmpInfo32.bmHeight - 1) * bmpInfo32.bmWidthBytes);

		int x, y, nStartX;
		long *pRGB;
		RECT *pRect;

		// ��Ʈ���� �ȼ� ������ ���� ��/�� ������� ó���Ѵ�
		for(y = 0; y < bmpInfo32.bmHeight; y++) 
		{
			for(x = 0; x < bmpInfo32.bmWidth; x++)
			{
				// ���� ��ġ�� �����Ѵ�
				nStartX = x;
				pRGB = (long*)pPixel + x;

				// ���� ������ ��Ÿ�� ������ ������ ����
				for(;x < bmpInfo32.bmWidth; x++, pRGB++) 
				{
					if(::memcmp((char*)pRGB + 1, (char*)&clrTransparent + 1, 3) == 0)		break;
				}
				
				// ���� ��ġ���� �ڿ� ���� ������ ��Ÿ���ٸ�
				if(x > nStartX) 
				{
					// ���� �������� �ִ� �簢 ������ �� ��ٸ�
					if(pRgnData->rdh.nCount >= dwMaxRect)
					{
						// �޸𸮸� �������� �ִ� �簢 ������ ������ 100 ���� ��Ų��
						::GlobalUnlock(hRgnData);
						dwMaxRect += 100;
						hRgnData = ::GlobalReAlloc(hRgnData, sizeof(RGNDATAHEADER)
							+ (sizeof(RECT) * dwMaxRect), GMEM_MOVEABLE);
						pRgnData = (RGNDATA*)::GlobalLock(hRgnData);					
					}

					// ���� ���� ���� ��ġ���� ���� ���� �� ��ġ������ �ϳ��� �簢������ �����Ѵ�
					pRect = (RECT*)&pRgnData->Buffer;
					::SetRect(pRect + pRgnData->rdh.nCount, nStartX, y, x, y + 1);		

					// ������ ��踦 ����ٸ� ������ ��踦 �����Ѵ�
					if(nStartX < pRgnData->rdh.rcBound.left) 
						pRgnData->rdh.rcBound.left = nStartX;

					if(y < pRgnData->rdh.rcBound.top) 
						pRgnData->rdh.rcBound.top = y;

					if(x > pRgnData->rdh.rcBound.right) 
						pRgnData->rdh.rcBound.right = x;
					
					if(y + 1 > pRgnData->rdh.rcBound.bottom) 
						pRgnData->rdh.rcBound.bottom = y + 1;
	
					// ���� �������� �簢 ���� ������ ������Ų��
					pRgnData->rdh.nCount++;

					// ��������95/98������ �ִ� 2,000�������� �簢�������� ���� ��ü�� ������ �� �ֱ� ������
					// ���� �簢 ���� ������ 2,000����� ��������� �簢 ���������� ���� ��ü�� �����Ѵ�
					// �׸��� �簢 ������ �ʱ�ȭ�Ͽ� �ٽ� �簢 ������ �����Ѵ�
					if(pRgnData->rdh.nCount == 2000)
					{
						CRgn NewRgn;
						if(NewRgn.CreateFromData(NULL, sizeof(RGNDATAHEADER) + (sizeof(RECT) * dwMaxRect), pRgnData))
						{
							m_rgnBitmap.CombineRgn(&m_rgnBitmap, &NewRgn, RGN_OR);

							NewRgn.DeleteObject();
						}

						pRgnData->rdh.nCount=0;
						SetRect(&pRgnData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0);
					}
				}
			}

			// ��Ʈ���� ���ٷ� �̵��Ѵ�
			pPixel -= bmpInfo32.bmWidthBytes;
		}

		// ��������� �簢�������� ���� ��ü�� �����ϰ�,
		// ��� ������ ���� ��ü ������ ���Ѵ�
		CRgn NewRgn;
		if(NewRgn.CreateFromData(NULL, sizeof(RGNDATAHEADER) + (sizeof(RECT) * dwMaxRect), pRgnData))
		{
			m_rgnBitmap.CombineRgn(&m_rgnBitmap, &NewRgn, RGN_OR);

			NewRgn.DeleteObject();
		}
		
		::GlobalUnlock(hRgnData);
		::GlobalFree(hRgnData);
		
		::SelectObject(hMemDC, hOldBmp);
		::DeleteObject(h32BitBmp);
	}

	::DeleteDC(hMemDC);
	::ReleaseDC(NULL, hScreenDC);

	// ��Ʈ���� �簢 ���� ��ŭ���� ���̾�α��� ũ�⸦ �����Ѵ�
	SetWindowPos(NULL, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SWP_NOZORDER | SWP_NOMOVE);

	// ������ ���� ��ü�� �������� �������� �����Ѵ�
	SetWindowRgn(m_rgnBitmap, ::IsWindowVisible(m_hWnd));
}

// ���̾�α� Ŭ���̾�Ʈ ������ �巡���Ͽ� ���̾�α׸� �̵��� �� �ֵ��� �ϴ� �ڵ�
UINT CShapeDlg::OnNcHitTest(CPoint point) 
{
	UINT nHit = CDialog::OnNcHitTest(point);

	if(nHit == HTCLIENT)		nHit = HTCAPTION;

	return nHit;
}
