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
	// 멤버 변수들을 초기화한다
	m_nTextType		= TEXT_PERCENT;
	m_strFormat		= "%%d";
	m_bHorz			= TRUE;

	m_clrLight		= ::GetSysColor(COLOR_3DHIGHLIGHT);
	m_clrShadow		= ::GetSysColor(COLOR_3DSHADOW);
	m_clrBkgnd		= ::GetSysColor(COLOR_3DFACE);
	m_clrPos		= ::GetSysColor(COLOR_ACTIVECAPTION);
	m_clrText		= ::GetSysColor(COLOR_HIGHLIGHTTEXT);

	m_nFontSize		= 8;
	m_strFontName	= "굴림체";

	HDC hDC = ::GetDC(NULL);
	m_TextFont.CreateFont(-MulDiv(m_nFontSize, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, m_strFontName);
	::ReleaseDC(NULL, hDC);
}

CImageProgressCtrl::~CImageProgressCtrl()
{
	// 생성 되었던 비트맵과 폰트 객체를 소멸시킨다
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
	// 프로그레스바가 수평인지 수직인지 알아낸다
	m_bHorz = !(GetStyle() & PBS_VERTICAL);

	// 클라이언트 영역을 저장한다
	GetClientRect(&m_rcClient);

	CProgressCtrl::PreSubclassWindow();
}

// 진행 상태 출력 형식을 설정하는 함수
void CImageProgressCtrl::SetTextType(TEXT_TYPE nType)
{
	// 현재 값과 같을 경우 리턴
	if(m_nTextType == nType)					return;

	// 새로운 값을 저장
	m_nTextType = nType;

	// 화면 다시 그림
	Invalidate(FALSE);
}

// 문자열 포맷을 설정하는 함수
void CImageProgressCtrl::SetTextFormat(LPCTSTR pFormat)
{
	// 현재 값과 같을 경우 리턴
	if(m_strFormat.Compare(pFormat) == 0)		return;

	// 새로운 값을 저장
	m_strFormat = pFormat;

	// 화면 다시 그림
	Invalidate(FALSE);
}

// 테두리 밝은 색상 설정 함수
void CImageProgressCtrl::SetLightColor(COLORREF clrLight)
{
	// 현재 값과 같을 경우 리턴
	if(m_clrLight == clrLight)					return;

	// 새로운 값을 저장
	m_clrLight = clrLight;

	// 만약 비트맵을 사용하지 않는다면 화면 다시 그림
	if(m_bmpBorderLeft.m_hObject == NULL
		|| m_bmpBorderCenter.m_hObject == NULL
		|| m_bmpBorderRight.m_hObject == NULL)		Invalidate(FALSE);
}

// 테두리 어두운 색상 설정 함수
void CImageProgressCtrl::SetShadowColor(COLORREF clrShadow)
{
	// 현재 값과 같을 경우 리턴
	if(m_clrShadow == clrShadow)				return;

	// 새로운 값을 저장
	m_clrShadow = clrShadow;

	// 만약 비트맵을 사용하지 않는다면 화면 다시 그림
	if(m_bmpBorderLeft.m_hObject == NULL
		|| m_bmpBorderCenter.m_hObject == NULL
		|| m_bmpBorderRight.m_hObject == NULL)		Invalidate(FALSE);
}

// 배경색 설정 함수
void CImageProgressCtrl::SetBkgndColor(COLORREF clrBkgnd)
{
	// 현재 값과 같을 경우 리턴
	if(m_clrBkgnd == clrBkgnd)					return;

	// 새로운 값을 저장
	m_clrBkgnd = clrBkgnd;

	// 만약 비트맵을 사용하지 않는다면 화면 다시 그림
	if(m_bmpBorderLeft.m_hObject == NULL
		|| m_bmpBorderCenter.m_hObject == NULL
		|| m_bmpBorderRight.m_hObject == NULL)		Invalidate(FALSE);
}

// 진행바 색상 설정 함수
void CImageProgressCtrl::SetPosColor(COLORREF clrPos)
{
	// 현재 값과 같을 경우 리턴
	if(m_clrPos == clrPos)					return;

	// 새로운 값을 저장
	m_clrPos = clrPos;

	// 만약 비트맵을 사용하지 않는다면 화면 다시 그림
	if(m_bmpPosLeft.m_hObject == NULL
		|| m_bmpPosCenter.m_hObject == NULL
		|| m_bmpPosRight.m_hObject == NULL)		Invalidate(FALSE);
}

// 텍스트 색상 설정 함수
void CImageProgressCtrl::SetTextColor(COLORREF clrText)
{
	// 현재 값과 같을 경우 리턴
	if(m_clrText == clrText)					return;

	// 새로운 값을 저장
	m_clrText = clrText;

	// 화면 다시 그림
	Invalidate(FALSE);
}

// 폰트 설정 함수
void CImageProgressCtrl::SetTextFont(int nSize, LPCTSTR pFontName)
{
	// 현재 값과 같을 경우 리턴
	if(m_nFontSize == nSize && m_strFontName == pFontName)	return;

	// 새로운 값을 저장
	m_nFontSize		= nSize;
	m_strFontName	= pFontName;

	// 이전 폰트를 제거한다
	if(m_TextFont.m_hObject)		m_TextFont.DeleteObject();

	// 새로운 폰트를 생성한다
	HDC hDC = ::GetDC(NULL);
	m_TextFont.CreateFont(-MulDiv(m_nFontSize, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, m_strFontName);
	::ReleaseDC(NULL, hDC);

	// 화면 다시 그림
	Invalidate(FALSE);
}

// 배경 테두리 비트맵 리턴 함수
HBITMAP CImageProgressCtrl::GetBorderBitmap(BMP_TYPE nType)
{
	// 비트맵의 종류에 따라 해당 비트맵 핸들을 리턴한다
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

// 배경 테두리 비트맵 설정 함수
void CImageProgressCtrl::SetBorderBitmap(BMP_TYPE nType, UINT nBmpID)
{
	// 비트맵의 종류에 따라 해당 비트맵을 제거하고 비트맵을 로드한다
	// 그리고 비트맵의 정보를 구한다
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

// 배경 테두리 비트맵 설정 함수
void CImageProgressCtrl::SetBorderBitmap(BMP_TYPE nType, HBITMAP hBmp)
{
	// 비트맵의 종류에 따라 해당 비트맵을 제거하고 비트맵을 Attach한다
	// 그리고 비트맵의 정보를 구한다
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

// 진행바 비트맵 리턴 함수
HBITMAP CImageProgressCtrl::GetPosBitmap(BMP_TYPE nType)
{
	// 비트맵의 종류에 따라 해당 비트맵 핸들을 리턴한다
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

// 진행바 비트맵 설정 함수
void CImageProgressCtrl::SetPosBitmap(BMP_TYPE nType, UINT nBmpID)
{
	// 비트맵의 종류에 따라 해당 비트맵을 제거하고 비트맵을 로드한다
	// 그리고 비트맵의 정보를 구한다
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

// 진행바 비트맵 설정 함수
void CImageProgressCtrl::SetPosBitmap(BMP_TYPE nType, HBITMAP hBmp)
{
	// 비트맵의 종류에 따라 해당 비트맵을 제거하고 비트맵을 Attach한다
	// 그리고 비트맵의 정보를 구한다
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

	// 부드러운 화면 갱신을 위해 더블버퍼링을 실행한다
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	CBitmap MemBmp;
	MemBmp.CreateCompatibleBitmap(&dc, m_rcClient.Width(), m_rcClient.Height());
	CBitmap *pOldBitmap = MemDC.SelectObject(&MemBmp);

	// 이미지의 크기가 프로그레스바의 크기보다 작을 수 있기 때문에,
	// 현재 화면의 내용을 메모리 DC에 복사한다
	MemDC.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(),
		&dc, 0, 0, SRCCOPY);

	CDC BmpDC;
	CBitmap *pOldBmp;
	CRect rcTemp, rcTemp2;

	// 비트맵 출력용 DC를 생성한다
	BmpDC.CreateCompatibleDC(&dc);

	// 만약 배경 테두리 비트맵이 설정되지 않았다면
	if(m_bmpBorderLeft.m_hObject == NULL
		|| m_bmpBorderCenter.m_hObject == NULL
		|| m_bmpBorderRight.m_hObject == NULL)
	{
		// 클라이언트 영역만큼 3차원 테두리를 출력한다
		rcTemp = m_rcClient;
		MemDC.Draw3dRect(&rcTemp, m_clrShadow, m_clrLight);

		// 테두리 안쪽을 배경 색상으로 칠한다
		rcTemp.DeflateRect(1, 1);
		MemDC.FillSolidRect(&rcTemp, m_clrBkgnd);
	}
	else
	{
		// 클라이언트 영역의 좌측의 테두리 이미지 출력 영역을 계산한다
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

		// 좌측 테두리 이미지를 출력한다
		pOldBmp = BmpDC.SelectObject(&m_bmpBorderLeft);
		MemDC.BitBlt(rcTemp.left, rcTemp.top, m_infoBorderLeft.bmWidth, m_infoBorderLeft.bmHeight,
			&BmpDC, 0, 0, SRCCOPY);

		// 클라이언트 영역의 우측의 테두리 이미지 출력 영역을 계산한다
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

		// 우측 테두리 이미지를 출력한다
		BmpDC.SelectObject(&m_bmpBorderRight);
		MemDC.BitBlt(rcTemp.left, rcTemp.top, m_infoBorderRight.bmWidth, m_infoBorderRight.bmHeight,
			&BmpDC, 0, 0, SRCCOPY);

		// 좌측과 우측 테두리 이미지 사이에 테두리 중앙 이미지를 출력한다
		BmpDC.SelectObject(&m_bmpBorderCenter);
		MemDC.StretchBlt(rcTemp2.left, rcTemp2.top, rcTemp2.Width(), rcTemp2.Height(),
			&BmpDC, 0, 0, m_infoBorderCenter.bmWidth, m_infoBorderCenter.bmHeight, SRCCOPY);

		BmpDC.SelectObject(pOldBmp);
	}

	// 현재 진행바 위치와 전체 범위를 얻는다
	int nPos = GetPos(), nMin, nMax;
	GetRange(nMin, nMax);

	// 0을 기준으로한 위치와 최대값을 계산한다
	nPos -= nMin;
	nMax -= nMin;

	// 현재 위치를 퍼센테이지로 계산한다
	double dRate = (double)nPos / nMax;

	// 만약 진행바 비트맵이 설정되지 않았다면
	if(m_bmpPosLeft.m_hObject == NULL
		|| m_bmpPosCenter.m_hObject == NULL
		|| m_bmpPosRight.m_hObject == NULL)
	{
		// 클라이언트 영역에서 안쪽으로 2픽셀 줄인다
		rcTemp = m_rcClient;
		rcTemp.DeflateRect(2, 2);

		// 현재 진행률에 따른 진행바 끝 좌표를 구한다
		if(m_bHorz)		rcTemp.right	= rcTemp.left + (int)(rcTemp.Width() * dRate);
		else			rcTemp.top		= rcTemp.bottom - (int)(rcTemp.Height() * dRate);

		// 진행바를 출력한다
		MemDC.FillSolidRect(&rcTemp, m_clrPos);
	}
	else
	{
		// 클라이언트 영역에서 안쪽으로 2픽셀 줄인다
		rcTemp = m_rcClient;
		rcTemp.DeflateRect(2, 2);

		// 진행바 좌측 이미지 출력 영역을 계산한다
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

		// 진행바 좌측 이미지를 출력한다
		pOldBmp = BmpDC.SelectObject(&m_bmpPosLeft);
		MemDC.BitBlt(rcTemp.left, rcTemp.top, m_infoPosLeft.bmWidth, m_infoPosLeft.bmHeight,
			&BmpDC, 0, 0, SRCCOPY);

		// 현재 진행률에 따른 진행바 끝 위치를 계산한다
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

		// 진행바 끝 위치에 맞게 진행바 중앙 이미지를 출력한다
		BmpDC.SelectObject(&m_bmpPosCenter);
		MemDC.StretchBlt(rcTemp.left, rcTemp.top, rcTemp.Width(), rcTemp.Height(),
			&BmpDC, 0, 0, m_infoPosCenter.bmWidth, m_infoPosCenter.bmHeight, SRCCOPY);

		// 진행바 중앙 이미지의 오른쪽으로 진행바 우측 이미지 출력 영역을 계산한다
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

		// 진행바 우측 이미지를 출력한다
		BmpDC.SelectObject(&m_bmpPosRight);
		MemDC.BitBlt(rcTemp2.left, rcTemp2.top, m_infoPosRight.bmWidth, m_infoPosRight.bmHeight,
			&BmpDC, 0, 0, SRCCOPY);

		BmpDC.SelectObject(pOldBmp);
	}

	// 만약 진행 상태를 출력해야 한다면
	if(m_nTextType != TEXT_NONE)
	{
		CString strText;

		// 퍼센테이지라면 현재 백분율을 문자열로 설정한다
		if(m_nTextType == TEXT_PERCENT)		strText.Format("%d%%", (int)(dRate * 100));
		// 만약 포맷 문자열을 사용한다면, 포맷 문자열을 사용하여 문자열을 설정한다
		if(m_nTextType == TEXT_FORMAT)		strText.Format(m_strFormat, GetPos());

		// 텍스트 출력용 폰트를 설정한다
		CFont *pOldFont = MemDC.SelectObject(&m_TextFont);

		// 텍스트 배경을 투명으로 설정한다
		MemDC.SetBkMode(TRANSPARENT);
		// 우선 진행바 색상을 텍스트 색상으로 설정한다
		MemDC.SetTextColor(m_clrPos);
		// 진행 상태 문자열을 출력한다
		MemDC.DrawText(strText, &m_rcClient, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		// 현재 진행바의 영역을 클리핑 영역으로 설정한다
		CRgn ClipRgn;
		ClipRgn.CreateRectRgn(rcTemp.left, rcTemp.top, rcTemp.right, rcTemp.bottom);
		MemDC.SelectClipRgn(&ClipRgn);

		// 텍스트 색상을 설정한다
		MemDC.SetTextColor(m_clrText);
		// 진행 상태 문자열을 출력한다
		MemDC.DrawText(strText, &m_rcClient, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		// 클리핑 영역을 해제한다
		MemDC.SelectClipRgn(NULL);
		// 영역 객체를 삭제한다
		ClipRgn.DeleteObject();
		// 폰트를 반환한다
		MemDC.SelectObject(pOldFont);
	}

	// 화면에 현재까지 그린 내용을 출력한다
	dc.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(),
		&MemDC, 0, 0, SRCCOPY);

	// 비트맵 DC를 제거한다
	BmpDC.DeleteDC();

	// 메모리 DC를 제거하고 비트맵을 제거한다
	MemDC.SelectObject(pOldBitmap);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

BOOL CImageProgressCtrl::OnEraseBkgnd(CDC* pDC) 
{
	// 배경은 지우지 않는다
	return TRUE;
//	return CProgressCtrl::OnEraseBkgnd(pDC);
}

void CImageProgressCtrl::OnNcPaint() 
{
	// 프로그레스바 자체의 테두리를 출력하지 않기 위해서
	// 아무 작업도 안하고 리턴한다
}
