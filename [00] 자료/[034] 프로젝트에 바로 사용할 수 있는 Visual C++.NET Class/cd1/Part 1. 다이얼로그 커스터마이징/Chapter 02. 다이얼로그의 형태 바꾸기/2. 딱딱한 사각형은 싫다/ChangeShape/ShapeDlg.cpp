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

// 다이얼로그 모양 변경에 사용할 비트맵을 설정하는 함수 : 파일에서 읽기
void CShapeDlg::SetShapeBitmap(LPCTSTR pFileName, COLORREF clrTransparent)
{
	// 파일에서 비트맵을 로드한다
	HBITMAP hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			LPCTSTR(pFileName), IMAGE_BITMAP,
			0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	if(hBmp == NULL)		return;

	// 로드된 비트맵을 다이얼로그의 모양으로 설정한다
	SetShapeBitmap(hBmp, clrTransparent);

	// 비트맵을 제거한다
	::DeleteObject(hBmp);
}

// 다이얼로그 모양 변경에 사용할 비트맵을 설정하는 함수 : 로드된 리소스를 설정
void CShapeDlg::SetShapeBitmap(HBITMAP hBitmap, COLORREF clrTransparent)
{
	if(hBitmap == NULL)		return;

	// 이전의 영역 객체가 있다면 제거한다
	if(m_rgnBitmap.m_hObject)		m_rgnBitmap.DeleteObject();
	// 빈 영역 객체를 생성한다
	m_rgnBitmap.CreateRectRgn(0, 0, 0, 0);

	BITMAP		bmpInfo;
	
	// 비트맵의 정보를 읽는다
	::GetObject(hBitmap, sizeof(bmpInfo), &bmpInfo);

	// 32비트 비트맵을 생성하기 위해 헤더를 우선 정의한다
	BITMAPINFOHEADER Header32Bit;
	
	::memset(&Header32Bit, 0, sizeof(Header32Bit));
	Header32Bit.biSize			= sizeof(BITMAPINFOHEADER);
	Header32Bit.biWidth			= bmpInfo.bmWidth;
	Header32Bit.biHeight		= bmpInfo.bmHeight;
	Header32Bit.biPlanes		= 1;
	Header32Bit.biBitCount		= 32;
	Header32Bit.biCompression	= BI_RGB;
	
	// 화면 DC와 호환되는 메모리 DC를 생성한다
	HDC hScreenDC = ::GetDC(NULL);
	HDC hMemDC = ::CreateCompatibleDC(hScreenDC);
	
	// 메모리 DC의 속성에 따라 32비트 비트맵을 생성한다
	void *pBmpBits = NULL;
	HBITMAP	h32BitBmp = CreateDIBSection(hMemDC, (BITMAPINFO*)&Header32Bit,
		DIB_RGB_COLORS, &pBmpBits, NULL, 0);

	if(h32BitBmp)	
	{
		// 32 비트 비트맵의 정보를 읽는다
		BITMAP bmpInfo32;
		::GetObject(h32BitBmp, sizeof(bmpInfo32), &bmpInfo32);
		// 수평 바이트 수를 4의 배수로 맞춘다
		if(bmpInfo32.bmWidthBytes % 4 > 0)
			bmpInfo32.bmWidthBytes += (4 - (bmpInfo32.bmWidthBytes % 4));

		// 메모리 DC에 32비트 비트맵을 설정한다
		HBITMAP hOldBmp = (HBITMAP)::SelectObject(hMemDC, h32BitBmp);

		// 메모리 DC에 호환되는 DC를 하나 생성하여 원본 비트맵을 설정하고,
		// 원본 비트맵을 메모리 DC의 32비트 비트맵에 복사한다
		HDC hBmpDC = ::CreateCompatibleDC(hMemDC);
		HBITMAP	hOldBmp2 = (HBITMAP)::SelectObject(hBmpDC, hBitmap);

		::BitBlt(hMemDC, 0, 0, bmpInfo32.bmWidth, bmpInfo32.bmHeight,
			hBmpDC, 0, 0, SRCCOPY);

		::SelectObject(hBmpDC, hOldBmp2);
		::DeleteDC(hBmpDC);

		// 사각 영역들을 저장하는 영역 데이터를 생성한다
		// 영역 데이터에 초기 저장할 수 있는 사각 영역은 100개로 한다
		DWORD dwMaxRect = 100;
		HANDLE hRgnData = ::GlobalAlloc(GHND, sizeof(RGNDATAHEADER) + (sizeof(RECT) * dwMaxRect));
		RGNDATA *pRgnData = (RGNDATA*)::GlobalLock(hRgnData);

		// 영역 데이터의 헤더를 초기화 한다
		pRgnData->rdh.dwSize	= sizeof(RGNDATAHEADER);
		pRgnData->rdh.iType		= RDH_RECTANGLES;
		pRgnData->rdh.nCount	= 0;
		pRgnData->rdh.nRgnSize	= 0;
		::SetRect(&pRgnData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0);

		// 32 비트 비트맵의 픽셀 포인터를 구한다
		// 비트맵이 위 아래가 뒤집혀 저장되기 때문에,
		// 제일 아래쪽 줄의 첫 위치를 먼저 설정한다
		BYTE *pPixel = (BYTE*)bmpInfo32.bmBits
			+ ((bmpInfo32.bmHeight - 1) * bmpInfo32.bmWidthBytes);

		int x, y, nStartX;
		long *pRGB;
		RECT *pRect;

		// 비트맵의 픽셀 정보에 대해 행/열 순서대로 처리한다
		for(y = 0; y < bmpInfo32.bmHeight; y++) 
		{
			for(x = 0; x < bmpInfo32.bmWidth; x++)
			{
				// 시작 위치를 저장한다
				nStartX = x;
				pRGB = (long*)pPixel + x;

				// 투명 색상이 나타날 때까지 루프를 돈다
				for(;x < bmpInfo32.bmWidth; x++, pRGB++) 
				{
					if(::memcmp((char*)pRGB + 1, (char*)&clrTransparent + 1, 3) == 0)		break;
				}
				
				// 시작 위치보다 뒤에 투명 색상이 나타난다면
				if(x > nStartX) 
				{
					// 영역 데이터의 최대 사각 영역을 다 썼다면
					if(pRgnData->rdh.nCount >= dwMaxRect)
					{
						// 메모리를 증가시켜 최대 사각 영역의 갯수를 100 증가 시킨다
						::GlobalUnlock(hRgnData);
						dwMaxRect += 100;
						hRgnData = ::GlobalReAlloc(hRgnData, sizeof(RGNDATAHEADER)
							+ (sizeof(RECT) * dwMaxRect), GMEM_MOVEABLE);
						pRgnData = (RGNDATA*)::GlobalLock(hRgnData);					
					}

					// 현재 행의 시작 위치에서 다음 행의 끝 위치까지를 하나의 사각형으로 설정한다
					pRect = (RECT*)&pRgnData->Buffer;
					::SetRect(pRect + pRgnData->rdh.nCount, nStartX, y, x, y + 1);		

					// 영역의 경계를 벗어난다면 영역의 경계를 조절한다
					if(nStartX < pRgnData->rdh.rcBound.left) 
						pRgnData->rdh.rcBound.left = nStartX;

					if(y < pRgnData->rdh.rcBound.top) 
						pRgnData->rdh.rcBound.top = y;

					if(x > pRgnData->rdh.rcBound.right) 
						pRgnData->rdh.rcBound.right = x;
					
					if(y + 1 > pRgnData->rdh.rcBound.bottom) 
						pRgnData->rdh.rcBound.bottom = y + 1;
	
					// 영역 데이터의 사각 영역 갯수를 증가시킨다
					pRgnData->rdh.nCount++;

					// 윈도우즈95/98에서는 최대 2,000개까지의 사각형까지만 영역 객체로 생성할 수 있기 때문에
					// 현재 사각 영역 갯수가 2,000개라면 현재까지의 사각 영역만으로 영역 객체를 생성한다
					// 그리고 사각 영역을 초기화하여 다시 사각 영역을 수집한다
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

			// 비트맵의 윗줄로 이동한다
			pPixel -= bmpInfo32.bmWidthBytes;
		}

		// 현재까지의 사각영역으로 영역 객체를 생성하고,
		// 멤버 변수인 영역 객체 변수에 합한다
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

	// 비트맵의 사각 영역 만큼으로 다이얼로그의 크기를 변경한다
	SetWindowPos(NULL, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SWP_NOZORDER | SWP_NOMOVE);

	// 생성한 영역 객체를 윈도우의 영역으로 설정한다
	SetWindowRgn(m_rgnBitmap, ::IsWindowVisible(m_hWnd));
}

// 다이얼로그 클라이언트 영역을 드래그하여 다이얼로그를 이동할 수 있도록 하는 코드
UINT CShapeDlg::OnNcHitTest(CPoint point) 
{
	UINT nHit = CDialog::OnNcHitTest(point);

	if(nHit == HTCLIENT)		nHit = HTCAPTION;

	return nHit;
}
