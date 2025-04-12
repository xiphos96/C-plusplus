// LinkStatic.cpp : implementation file
//

#include "stdafx.h"
#include "linkstaticdemo.h"
#include "LinkStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinkStatic

// 손 모양의 마우스 커서 ID
#define IDC_HAND            MAKEINTRESOURCE(32649)
// 라인과 텍스트 사이의 여백
#define CONST_ITEM_GAP		6


CLinkStatic::CLinkStatic()
{
	// 멤버 변수들을 초기화한다
	m_clrText		= RGB(0, 0, 238);
	m_clrHover		= ::GetSysColor(COLOR_HIGHLIGHTTEXT);
	m_clrBkgnd		= ::GetSysColor(COLOR_BTNFACE);

	m_bHover		= FALSE;
	m_bLeftImage	= TRUE;

	// 손모양 마우스 커서를 로드한다
	m_hCursor		= ::LoadCursor(NULL, MAKEINTRESOURCE(IDC_HAND));
}

CLinkStatic::~CLinkStatic()
{
	// 각종 리소스들을 반환한다
	if(m_hCursor)				::DeleteObject(m_hCursor);

	if(m_bmpImage.m_hObject)	m_bmpImage.DeleteObject();
	if(m_bmpMask.m_hObject)		m_bmpMask.DeleteObject();
	m_HoverFont.DeleteObject();
}


BEGIN_MESSAGE_MAP(CLinkStatic, CStatic)
	//{{AFX_MSG_MAP(CLinkStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_CONTROL_REFLECT(BN_CLICKED, OnClicked)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinkStatic message handlers

void CLinkStatic::PreSubclassWindow() 
{
	// 테두리 속성을 없애고 알림 메시지 속성을 설정한다
	ModifyStyle(WS_BORDER, SS_NOTIFY);
	ModifyStyleEx(WS_EX_CLIENTEDGE | WS_EX_STATICEDGE, 0);

	// 클라이언트 영역을 구한다
	GetClientRect(&m_rcClient);
	// 텍스트의 출력 영역을 클라이언트 영역으로 설정한다
	m_rcText = m_rcClient;

	// 스태틱 컨트롤의 폰트를 얻는다
	LOGFONT LogFont;
	CFont *pFont = GetFont();
	// 스태틱 컨트롤의 폰트에서 로그 폰트를 얻는다
	pFont->GetLogFont(&LogFont);

	// 밑줄 속성을 설정한다
	LogFont.lfUnderline = TRUE;

	// 밑줄 속성을 갖는 폰트를 생성한다
	m_HoverFont.CreateFontIndirect(&LogFont);

	// 툴팁 컨트롤을 생성한다
	m_wndToolTip.Create(this, TTS_ALWAYSTIP);
	m_wndToolTip.Activate(FALSE);
	m_wndToolTip.AddTool(this, m_strToolTip, m_rcClient, 1);
	m_wndToolTip.Activate(TRUE);

	CStatic::PreSubclassWindow();
}

BOOL CLinkStatic::PreTranslateMessage(MSG* pMsg) 
{
	// 툴팁 컨트롤에게 마우스 이벤트를 전달한다
	m_wndToolTip.RelayEvent(pMsg);
	
	return CStatic::PreTranslateMessage(pMsg);
}

void CLinkStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	// 부드러운 화면 출력을 위해 더블 버퍼링을 한다
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);

	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(&dc, m_rcClient.Width(), m_rcClient.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// 배경을 배경색으로 칠한다
	MemDC.FillSolidRect(&m_rcClient, m_clrBkgnd);

	// 비트맵이 설정되었다면
	if(m_bmpImage.m_hObject)
	{
		// 비트맵을 이미지 출력 영역에 출력한다
		CDC BmpDC;
		BmpDC.CreateCompatibleDC(NULL);

		CBitmap *pOldBmp = BmpDC.SelectObject(&m_bmpImage);

		// 만약 투명색이 적용되어 있다면
		if(m_bmpMask.m_hObject)
		{
			// 마스크 비트맵을 사용해서 투명 처리를 하여 비트맵을 출력한다
			CDC MaskDC;
			MaskDC.CreateCompatibleDC(NULL);
			CBitmap *pOldMask = MaskDC.SelectObject(&m_bmpMask);

			// 마스크 비트맵은 흑백이기 때문에,
			// 1은 윈도우 기본 배경색인 하얀색으로 바뀌고 0은 글자색인 검정색으로 바뀐다.
			// 그리고 화면의 내용과 AND 되어,
			// 마스크의 투명 영역은 배경이 그대로 드러나고 마스크의 이미지 영역은 검정색으로 배경이 지워진다.
			MemDC.BitBlt(m_ptImage.x, m_ptImage.y, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight,
				&MaskDC, 0, 0, SRCAND);
			// 원본 비트맵의 투명 부분은 이미 검정색으로 처리되었기 때문에
			// 투명 부분은 배경과 OR 되어 배경을 그대로 유지하고,
			// 원본 비트맵의 비투명 부분은 그대로 유지되어 있으므로
			// 배경의 검정색과 OR 되어 원본 이미지를 그대로 출력한다.
			MemDC.BitBlt(m_ptImage.x, m_ptImage.y, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight,
				&BmpDC, 0, 0, SRCPAINT);

			MaskDC.SelectObject(pOldMask);
			MaskDC.DeleteDC();
		}
		else
		{
			// 투명색이 적용되지 않았다면 이미지를 그냥 출력한다
			MemDC.BitBlt(m_ptImage.x, m_ptImage.y, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight,
				&BmpDC, 0, 0, SRCCOPY);
		}

		BmpDC.SelectObject(pOldBmp);
		BmpDC.DeleteDC();
	}

	// 기본 폰트를 설정한다
	CFont *pOldFont = MemDC.SelectObject(GetFont());
	if(m_bHover)
	{
		// 만약 마우스가 위치해 있다면 밑줄 폰트를 설정한다
		MemDC.SelectObject(&m_HoverFont);
		MemDC.SetTextColor(m_clrHover);
	}
	else
	{
		MemDC.SetTextColor(m_clrText);
	}
	// 텍스트의 배경을 투명으로 설정한다
	MemDC.SetBkMode(TRANSPARENT);

	// 이미지의 위치에 따라 텍스트를 정렬한다
	int nDrawMode = DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
	if(m_bLeftImage)	nDrawMode |= DT_LEFT;
	else				nDrawMode |= DT_RIGHT;

	// 스태틱 컨트롤의 텍스트를 얻어 출력한다
	CString strText;
	GetWindowText(strText);
	MemDC.DrawText(strText, &m_rcText, nDrawMode);

	// 이전 폰트를 반환한다
	MemDC.SelectObject(pOldFont);

	// 메모리 DC에 있는 내용을 화면으로 출력한다
	dc.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(),
		&MemDC, 0, 0, SRCCOPY);

	// GDI 객체들을 반환한다
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

// 스태틱 컨트롤에 비트맵을 설정하는 함수
void CLinkStatic::SetLinkBmp(UINT nBitmapID, BOOL bLeft)
{
	// 이전 비트맵들을 삭제한다
	if(m_bmpImage.m_hObject)			m_bmpImage.DeleteObject();
	if(m_bmpMask.m_hObject)				m_bmpMask.DeleteObject();

	// 새 비트맵을 로드한다
	m_bmpImage.LoadBitmap(nBitmapID);
	m_bmpInfo.bmWidth = m_bmpInfo.bmHeight = 0;

	if(m_bmpImage.m_hObject)
	{
		// 비트맵의 정보를 새로 읽는다
		m_bmpImage.GetBitmap(&m_bmpInfo);
	}

	// 이미지 출력 위치를 저장한다
	m_bLeftImage = bLeft;
	// 기본 텍스트 출력 위치를 클라이언트 영역으로 한다
	m_rcText = m_rcClient;

	// 이미지 출력 위치를 계산한다
	m_ptImage.y = (m_rcClient.Height() - m_bmpInfo.bmHeight) / 2;
	if(m_bLeftImage)
	{
		m_ptImage.x = 0;
		// 텍스트 출력 위치를 보정한다
		m_rcText.left = m_bmpInfo.bmWidth + CONST_ITEM_GAP;
	}
	else
	{
		m_ptImage.x = m_rcClient.right - m_bmpInfo.bmWidth;
		// 텍스트 출력 위치를 보정한다
		m_rcText.right = m_rcClient.right - m_bmpInfo.bmWidth - CONST_ITEM_GAP;
	}
}

// 스태틱 컨트롤에 비트맵을 설정하고 투명색을 설정하는 함수
void CLinkStatic::SetLinkBmp(UINT nBitmapID, COLORREF clrTransparent, BOOL bLeft)
{
	// 이전 비트맵을 삭제한다
	if(m_bmpImage.m_hObject)			m_bmpImage.DeleteObject();
	if(m_bmpMask.m_hObject)				m_bmpMask.DeleteObject();

	// 새 비트맵을 로드한다
	m_bmpImage.LoadBitmap(nBitmapID);
	m_bmpInfo.bmWidth = m_bmpInfo.bmHeight = 0;

	if(m_bmpImage.m_hObject)
	{
		// 비트맵의 정보를 새로 읽는다
		m_bmpImage.GetBitmap(&m_bmpInfo);
	}

	// 이미지 출력 위치를 저장한다
	m_bLeftImage = bLeft;
	// 기본 텍스트 출력 위치를 클라이언트 영역으로 한다
	m_rcText = m_rcClient;

	// 이미지 출력 위치를 계산한다
	m_ptImage.y = (m_rcClient.Height() - m_bmpInfo.bmHeight) / 2;
	if(m_bLeftImage)
	{
		m_ptImage.x = 0;
		// 텍스트 출력 위치를 보정한다
		m_rcText.left = m_bmpInfo.bmWidth + CONST_ITEM_GAP;
	}
	else
	{
		m_ptImage.x = m_rcClient.right - m_bmpInfo.bmWidth;
		// 텍스트 출력 위치를 보정한다
		m_rcText.right = m_rcClient.right - m_bmpInfo.bmWidth - CONST_ITEM_GAP;
	}

	COLORREF	clrBmpBk, clrBmpText;

	// 투명색을 저장한다
	m_clrTransparent = clrTransparent;

	CDC BmpDC, MaskDC;
	
	BmpDC.CreateCompatibleDC(NULL);
	MaskDC.CreateCompatibleDC(NULL);

	// 마스크 비트맵을 생성한다 - 마스크 비트맵은 흑백 비트맵이다
	m_bmpMask.CreateBitmap(m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, 1, 1, NULL);

	CBitmap *pOldBmp = BmpDC.SelectObject(&m_bmpImage);
	CBitmap *pOldMask = MaskDC.SelectObject(&m_bmpMask);

	// 원본 비트맵의 DC의 배경색을 투명색으로 설정하고 마스크 비트맵에 복사한다
	// 이때 마스크 비트맵은 흑백이기 때문에,
	// 원본 비트맵 DC의 배경색인 투명색 부분은 흰색으로 설정되고
	// 나머지 부분들은 검은색으로 설정된다
	clrBmpBk = BmpDC.SetBkColor(m_clrTransparent);
	MaskDC.BitBlt(0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, &BmpDC, 0, 0, SRCCOPY);

	// 원본 비트맵의 DC의 글자색을 하얀색으로 하고,
	// 원본 비트맵의 DC의 배경색을 검은색으로 하여 마스크 비트맵과 AND 연산을 한다
	// 이때 마스크 비트맵의 검은색 부분은 글자색인 하얀색이 되고
	// 마스크 비트맵의 하얀색 부분은 배경색인 검은색으로 바뀌게 된다.
	// 바뀐 마스크 비트맵과 원본 비트맵이 AND 됨으로 해서,
	// 마스트 비트맵의 하얀색에 해당하는 원본 비트맵 부분은 원본 이미지가 유지되고,
	// 마스크 비트맵의 검은색에 해당하는 원본 비트맵 부분은 검은색으로 칠해진다
	clrBmpText = BmpDC.SetTextColor(RGB(255, 255, 255));
	BmpDC.SetBkColor(RGB(0, 0, 0));
	BmpDC.BitBlt(0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, &MaskDC, 0, 0, SRCAND);

	// 원래 색상들을 되돌려 놓는다
	BmpDC.SetTextColor(clrBmpText);
	BmpDC.SetBkColor(clrBmpBk);

	// 원래 비트맵으로 되돌려 놓는다
	BmpDC.SelectObject(pOldBmp);
	MaskDC.SelectObject(pOldMask);

	// DC들을 삭제한다
	BmpDC.DeleteDC();
	MaskDC.DeleteDC();
}

// 스태틱 컨트롤의 툴팁을 설정하는 함수
void CLinkStatic::SetToolTipText(LPCTSTR pTip)
{
	// 툴팁을 저장하고
	m_strToolTip = pTip;

	// 툴팁 컨트롤을 비활성화 시킨 후
	m_wndToolTip.Activate(FALSE);
	// 툴팁을 갱신하고
	m_wndToolTip.UpdateTipText(m_strToolTip, this, 1);
	// 툴팁 컨트롤을 다시 활성화 시킨다
	m_wndToolTip.Activate(TRUE);
}

BOOL CLinkStatic::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

BOOL CLinkStatic::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// 스태틱 컨트롤에서의 마우스 커서를 바꾼다
	::SetCursor(m_hCursor);

	return TRUE;
//	return CStatic::OnSetCursor(pWnd, nHitTest, message);
}

void CLinkStatic::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 마우스가 스태틱 컨트롤 위에서 이동 중이면,
	// 시스템에게 마우스의 스태틱 컨트롤로부터의 탈출에 대한 메시지를 보내줄 것을 요청
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags		= TME_LEAVE;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);

	// 마우스가 위치해 있음을 설정한다
	m_bHover = TRUE;
	// 화면을 다시 그린다
	Invalidate(FALSE);
	
	CStatic::OnMouseMove(nFlags, point);
}

LRESULT CLinkStatic::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// 마우스가 스태틱 컨트롤에서 탈출했으므로 스태틱 컨트롤 다시 그림
	m_bHover = FALSE;
	Invalidate(FALSE);

	return 0;
}

void CLinkStatic::OnClicked() 
{
	// 스태틱 컨트롤의 텍스트를 얻는다
	CString strText;
	GetWindowText(strText);

	// 만약 프로토콜이 설정되어 있지 않다면
	if(strText.Find(":") < 0)
	{
		// 만약 메일 주소가 아니라면 "http://"를 앞에 붙인다
		if(strText.Find("@") < 0)		strText.Insert(0, "http://");
		// 만약 메일 주소라면 "mailto:"를 앞에 붙인다
		else							strText.Insert(0, "mailto:");
	}

	// 링크를 실행한다
	::ShellExecute(NULL, "open", strText, NULL, NULL, SWP_SHOWWINDOW);
}
