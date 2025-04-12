// WordBook.cpp : implementation file
//

#include "stdafx.h"
#include "WordBookdemo.h"
#include "WordBook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWordBook

// Speech API 라이브러리 링크
#pragma comment(lib, "sapi.lib")

// 에디트 박스용 리소스 ID
#define IDC_LIST_EDIT				1

CWordBook::CWordBook()
{
	// 멤버 변수를 초기화한다
	m_nTrackItem	= -1;
	m_nEditItem		= -1;
	m_bEditEnglish	= TRUE;

	m_clrText		= RGB(0, 0, 0);
	m_clrHighlight	= RGB(230, 233, 240);
	m_clrBkgnd		= RGB(255, 255, 255);
	m_clrSelected	= RGB(193, 200, 217);

	m_NullBrush.CreateStockObject(NULL_BRUSH);
	m_ShadowPen.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_3DSHADOW));
	m_FocusPen.CreatePen(PS_SOLID, 1, RGB(132, 145, 180));

	m_nColumnWidth = 160;
	m_bModified = FALSE;
	m_bCapture = FALSE;
	m_pSpeechApi = NULL;

	m_hSizeCursor = ::LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZEWE));
	m_hArrowCursor = ::LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW));
}

CWordBook::~CWordBook()
{
	// GDI 객체들을 삭제한다
	m_ShadowPen.DeleteObject();
	m_FocusPen.DeleteObject();

	// 단어장 항목들을 삭제한다
	int nSize = m_WordArray.GetSize(), i;
	for(i = 0; i < nSize; i++)
	{
		delete m_WordArray.GetAt(i);
	}
	m_WordArray.RemoveAll();

	// 커서를 삭제한다
	::DeleteObject(m_hSizeCursor);
	::DeleteObject(m_hArrowCursor);

	// Speech API 인터페이스를 해제한다
	if(m_pSpeechApi)	m_pSpeechApi->Release();
}


BEGIN_MESSAGE_MAP(CWordBook, CListBox)
	//{{AFX_MSG_MAP(CWordBook)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_NCPAINT()
	ON_CONTROL_REFLECT(LBN_DBLCLK, OnDblclk)
	ON_WM_KEYUP()
	ON_CONTROL_REFLECT(LBN_SELCHANGE, OnSelchange)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_EN_KILLFOCUS(IDC_LIST_EDIT, OnKillFocusEdit)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordBook message handlers

void CWordBook::PreSubclassWindow() 
{
	// 클라이언트 영역의 테두리 속성을 없앤다
    ModifyStyleEx(WS_EX_CLIENTEDGE, 0);
	// 사용자 정의 그리기 속성을 설정하고, 프레임을 다시 그린다
	ModifyStyle(LBS_SORT | LBS_MULTIPLESEL, LBS_OWNERDRAWVARIABLE | LBS_HASSTRINGS | LBS_NOINTEGRALHEIGHT | LBS_EXTENDEDSEL | WS_BORDER, SWP_FRAMECHANGED);

	// 단어장 파일을 로드한다
	ReadWordFile();

	// Speech API 인터페이스를 생성한다
    if(FAILED(CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL,
		IID_ISpVoice, (void**)&m_pSpeechApi)))
		m_pSpeechApi = NULL;

	CListBox::PreSubclassWindow();
}

// 영어 단어장 파일을 로드하는 함수
void CWordBook::ReadWordFile()
{
	// 현재 디렉토리의 Word.dat 파일을 로드한다
	CString strWordFile;
	::GetCurrentDirectory(MAX_PATH, strWordFile.GetBuffer(MAX_PATH));
	strWordFile.ReleaseBuffer();
	strWordFile += "\\Word.dat";

	CFile WordFile;

	if(!WordFile.Open(strWordFile, CFile::modeRead))	return;

	CArchive WordArchive(&WordFile, CArchive::load);

	// 단어장 파일의 단어 항목들을 메모리로 로드한다
	SWordItem *pWord = new SWordItem;

	for(; pWord; )
	{
		TRY
		{
			WordArchive >> pWord->strEnglish;
		}
		CATCH(CException, e)
		{
			e->Delete();
			delete pWord;
			pWord = NULL;

			continue;
		}
		END_CATCH

		WordArchive >> pWord->strKorean;
		WordArchive >> pWord->date;

		m_WordArray.Add(pWord);
		AddString(pWord->strEnglish);

		pWord = new SWordItem;
	}

	WordArchive.Close();
	WordFile.Close();

	m_bModified = FALSE;
}

// 영어 단어장 파일을 저장하는 함수
void CWordBook::SaveWordFile()
{
	// 현재 디렉토리에 Word.dat 파일을 저장한다
	CString strWordFile;
	::GetCurrentDirectory(MAX_PATH, strWordFile.GetBuffer(MAX_PATH));
	strWordFile.ReleaseBuffer();
	strWordFile += "\\Word.dat";

	CFile WordFile;

	if(!WordFile.Open(strWordFile, CFile::modeCreate | CFile::modeWrite))	return;

	CArchive WordArchive(&WordFile, CArchive::store);

	SWordItem *pWord;
	int i, nSize = m_WordArray.GetSize();

	// 영어 단어 배열의 모든 항목을 저장한다
	for(i = 0; i < nSize; i++)
	{
		pWord = m_WordArray.GetAt(i);

		WordArchive << pWord->strEnglish;
		WordArchive << pWord->strKorean;
		WordArchive << pWord->date;
	}

	WordArchive.Close();
	WordFile.Close();

	m_bModified = FALSE;
}

// 단어장에 단어를 추가하는 함수
void CWordBook::AddWord(LPCTSTR pEnglish, LPCTSTR pKorean)
{
	if(::strlen(pEnglish) <= 0 || ::strlen(pKorean) <= 0)
		return;

	// 새 단어 항목을 생성한다
	SWordItem *pWord = new SWordItem;

	// 영어 단어와 해석, 그리고 날짜를 저장한다
	pWord->strEnglish = pEnglish;
	pWord->strKorean = pKorean;
	pWord->date = COleDateTime::GetCurrentTime();

	// 영어 단어 배열에 추가한다
	m_WordArray.Add(pWord);
	AddString(pEnglish);

	// 단어장이 변경되었음을 설정한다
	m_bModified = TRUE;
}

void CWordBook::OnMouseMove(UINT nFlags, CPoint point) 
{
	CListBox::OnMouseMove(nFlags, point);

	// 만약 영어 단어 출력 영역을 조정하고 있는 상태라면
	if(m_bCapture)
	{
		CRect rcClient;
		GetClientRect(&rcClient);

		// 단어장 내부에서 마우스가 이동 중이라면
		if(rcClient.PtInRect(point))
		{
			// 사이즈 커서로 변경한다
			SetCursor(m_hSizeCursor);

			// 래스터 오퍼레이션을 R2_NOT으로 설정한다
			CDC *pDC = GetDC();
			int nROP2 = pDC->SetROP2(R2_NOT);

			// 이전 구분선 위치를 지운다
			pDC->MoveTo(m_nColumnWidth, 0);
			pDC->LineTo(m_nColumnWidth, rcClient.bottom);

			// 구분선 위치를 보정한다
			m_nColumnWidth = point.x;
			// 영어 단어 출력 폭이 최소 10픽셀이 될 수 있도록 보정한다
			if(m_nColumnWidth < 10)		m_nColumnWidth = 10;
			// 수직 스크롤바가 생성된 상태인지 확인한다
			if(GetScrollBarCtrl(SB_VERT))
			{
				// 수직 스크롤바가 생성된 상태라면 크기를 얻는다
				CRect rcScroll;
				GetScrollBarCtrl(SB_VERT)->GetWindowRect(&rcScroll);

				// 스크롤바 영역을 제외한 클라이언트 영역에서
				// 한글 해석 출력 폭이 최소 10픽셀이 될 수 있도록 보정한다
				if(m_nColumnWidth > rcClient.right - rcScroll.Width() - 10)
					m_nColumnWidth = rcClient.right - rcScroll.Width() - 10;
			}
			else
			{
				// 수직 스크롤바가 생성되지 않은 상태라면
				// 클라이언트 영역에서 한글 해석 출력 폭이 최소 10픽셀이 되도록 보정한다
				if(m_nColumnWidth > rcClient.right - 10)
					m_nColumnWidth = rcClient.right - 10;
			}

			// 새 구분선 위치에 라인을 출력한다
			pDC->MoveTo(m_nColumnWidth, 0);
			pDC->LineTo(m_nColumnWidth, rcClient.bottom);

			pDC->SetROP2(nROP2);

			ReleaseDC(pDC);

			return;
		}
	}

	// 만약 구분선 위치 조정 상태가 아니라면
	// 구분선 위치에 마우스가 위치해 있다면 커서를 사이즈 커서로 변경한다
	if(point.x > m_nColumnWidth - 3 && point.x < m_nColumnWidth + 3)
		SetCursor(m_hSizeCursor);
	else
		SetCursor(m_hArrowCursor);

	// 시스템에게 마우스의 탈출에 대한 메시지를 보내줄 것을 요청
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags		= TME_LEAVE;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);

	// 만약 에디트 박스가 출력된 상태라면 리턴한다
	if(::IsWindow(m_Edit.m_hWnd))		return;

	BOOL bOut;
	// 현재 마우스 커서 위치의 항목 번호를 얻는다
	int nItem = ItemFromPoint(point, bOut);

	// 바로전 마우스가 위치했던 항목과 동일하면 리턴한다
	if(nItem == m_nTrackItem)	return;

	CRect rcItem;

	// 만약 이전에 위치했던 항목이 있다면
	if(m_nTrackItem >= 0)
	{
		// 해당 항목의 사각 영역을 구한다
		GetItemRect(m_nTrackItem, &rcItem);
		// 항목 번호를 -1로 초기화한다
		m_nTrackItem = -1;
		// 해당 항목을 다시 그린다
		InvalidateRect(&rcItem, FALSE);
	}

	// 만약 마우스가 리스트 박스 밖으로 이동했다면 리턴한다
	if(bOut)		return;

	// 새로운 항목 번호를 저장한다
	m_nTrackItem = nItem;
	// 해당 항목의 사각 영역을 구한다
	GetItemRect(m_nTrackItem, &rcItem);
	// 해당 항목을 다시 그린다
	InvalidateRect(&rcItem, FALSE);
}

LRESULT CWordBook::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// 만약 구분선 조정 상태라면 리턴한다
	if(m_bCapture)		return 0;

	// 만약 바로전 마우스가 위치했던 항목이 있다면
	if(m_nTrackItem >= 0)
	{
		CRect rcItem;

		// 해당 항목의 사각 영역을 구한다
		GetItemRect(m_nTrackItem, &rcItem);
		// 항목 번호를 -1로 초기화한다
		m_nTrackItem = -1;
		// 해당 항목을 다시 그린다
		InvalidateRect(&rcItem, FALSE);
	}

	return 0;
}

void CWordBook::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 만약 단어와 해석을 구분하는 위치에서 마우스 왼쪽 버튼이 눌렸다면
	if(point.x > m_nColumnWidth - 3 && point.x < m_nColumnWidth + 3)
	{
		// 마우스 이벤트를 캡춰한다
		SetCapture();
		// 마우스 커서를 변경한다
		SetCursor(m_hSizeCursor);

		m_bCapture = TRUE;

		CRect rcClient;
		GetClientRect(&rcClient);

		// 현재 구분선 위치를 라인으로 표시한다
		CDC *pDC = GetDC();
		int nROP2 = pDC->SetROP2(R2_NOT);

		pDC->MoveTo(m_nColumnWidth, 0);
		pDC->LineTo(m_nColumnWidth, rcClient.bottom);

		pDC->SetROP2(nROP2);

		ReleaseDC(pDC);
	}
	
	CListBox::OnLButtonDown(nFlags, point);
}

void CWordBook::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// 만약 구분선 조정 상태라면
	if(m_bCapture)
	{
		// 마우스 이벤트 캡춰를 해제한다
		ReleaseCapture();
		m_bCapture = FALSE;

		CRect rcClient;
		GetClientRect(&rcClient);

		// 마지막 그렸던 구분선을 지운다
		CDC *pDC = GetDC();
		int nROP2 = pDC->SetROP2(R2_NOT);

		pDC->MoveTo(m_nColumnWidth, 0);
		pDC->LineTo(m_nColumnWidth, rcClient.bottom);

		pDC->SetROP2(nROP2);

		ReleaseDC(pDC);

		// 마우스 위치가 클라이언트 영역 내부라면 구분선 위치로 저장한다
		if(rcClient.PtInRect(point))
		{
			m_nColumnWidth = point.x;
			Invalidate(FALSE);
		}
	}
	
	CListBox::OnLButtonUp(nFlags, point);
}

// 각 항목의 크기를 설정한다
void CWordBook::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	lpMeasureItemStruct->itemHeight = 20;
}

void CWordBook::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// 만약 출력하는 항목의 번호가 유효하지 않다면 리턴한다
	if((int)lpDrawItemStruct->itemID < 0)											return;
	// 만약 현재 편집 중인 항목이라면 리턴한다
	if((int)lpDrawItemStruct->itemID == m_nEditItem && ::IsWindow(m_Edit.m_hWnd))	return;

	// 항목의 영역을 구한다
	CRect rcItem = lpDrawItemStruct->rcItem;
	// 좌상단을 (0, 0)으로 이동시킨다
	rcItem.OffsetRect(-lpDrawItemStruct->rcItem.left, -lpDrawItemStruct->rcItem.top);

	// 더블 버퍼링을 구현한다
	CDC dc, MemDC;
	dc.Attach(lpDrawItemStruct->hDC);
	MemDC.CreateCompatibleDC(&dc);

	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(&dc, rcItem.Width(), rcItem.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// 리스트 박스의 폰트를 설정한다
	CFont *pOldFont = MemDC.SelectObject(GetFont());

	COLORREF clrBkgnd;
	// 현재 선택된 항목이면 선택 색상을 배경색으로 사용한다
	if(lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		clrBkgnd = m_clrSelected;
	}
	else
	{
		// 현재 마우스가 위치한 항목인지 여부에 따라 배경색을 다르게 사용한다
		if((int)lpDrawItemStruct->itemID == m_nTrackItem)	clrBkgnd = m_clrHighlight;
		else												clrBkgnd = m_clrBkgnd;
	}
	// 배경을 칠한다
	MemDC.FillSolidRect(&rcItem, clrBkgnd);

	// 만약 현재 포커스를 갖고 있는 항목이라면
	if(lpDrawItemStruct->itemState & ODS_FOCUS)
	{
		// 포커스 펜을 사용하여 테두리를 그린다
		CBrush *pOldBrush = MemDC.SelectObject(&m_NullBrush);
		CPen *pOldPen = MemDC.SelectObject(&m_FocusPen);

		MemDC.Rectangle(&rcItem);

		MemDC.SelectObject(pOldBrush);
		MemDC.SelectObject(pOldPen);
	}

	// 배경을 투명으로 설정하고, 텍스트 색상을 설정한다
	MemDC.SetBkMode(TRANSPARENT);
	MemDC.SetTextColor(m_clrText);

	// 단어 항목을 얻는다
	CRect rcEnglish, rcKorean;
	SWordItem *pItem = m_WordArray.GetAt(lpDrawItemStruct->itemID);

	// 영어 단어를 출력한다
	rcEnglish = rcItem;
	rcEnglish.right = m_nColumnWidth - 3;
	MemDC.DrawText(pItem->strEnglish,
		&rcEnglish, DT_SINGLELINE | DT_VCENTER | DT_LEFT);

	// 한글 해석을 출력한다
	rcKorean = rcItem;
	rcKorean.left = m_nColumnWidth + 3;
	MemDC.DrawText(pItem->strKorean,
		&rcKorean, DT_SINGLELINE | DT_VCENTER | DT_LEFT);

	// 만약 첫 단어가 아니라면
	if(lpDrawItemStruct->itemID > 0)
	{
		// 이전 단어 항목을 얻는다
		SWordItem *pPrev = m_WordArray.GetAt(lpDrawItemStruct->itemID - 1);

		// 만약 이전 단어와 현재 단어의 저장 날짜가 다르다면
		if(pPrev->date.GetYear() != pItem->date.GetYear()
			|| pPrev->date.GetMonth() != pItem->date.GetMonth()
			|| pPrev->date.GetDay() != pItem->date.GetDay())
		{
			// 상단에 날짜 구분선을 출력한다
			MemDC.MoveTo(0, 0);
			MemDC.LineTo(rcItem.right, 0);
		}
	}

	// 메모리 DC의 내용을 화면에 출력한다
	dc.BitBlt(lpDrawItemStruct->rcItem.left, lpDrawItemStruct->rcItem.top,
		rcItem.Width(), rcItem.Height(), &MemDC, 0, 0, SRCCOPY);

	// GDI 객체들을 반환한다
	MemDC.SelectObject(pOldFont);
	MemDC.SelectObject(&pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
	dc.Detach();
}

void CWordBook::OnNcPaint() 
{
	Default();

	// 리스트 박스의 테두리를 출력한다
    CWindowDC dc(this);

	CRect rcWindow;
	GetWindowRect(&rcWindow);

	CPen *pOldPen = dc.SelectObject(&m_ShadowPen);
	CBrush *pOldBrush = dc.SelectObject(&m_NullBrush);

	dc.Rectangle(0, 0, rcWindow.Width(), rcWindow.Height());

	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
}

void CWordBook::OnDblclk() 
{
	// 현재 커서 위치를 구한다
	BOOL bOut;
	CPoint ptCursor;
	::GetCursorPos(&ptCursor);
	ScreenToClient(&ptCursor);

	// 현재 커서 위치의 항목 번호를 구한다
	int nItem = (int)ItemFromPoint(ptCursor, bOut);
	// 만약 현재 항목 편집 중이 아니라면
	if(nItem >= 0 && !bOut && !::IsWindow(m_Edit.m_hWnd))
	{
		CString strItem;
		CRect rcItem;

		// 단어 항목을 얻는다
		SWordItem *pWord = m_WordArray.GetAt(nItem);

		// 편집 중인 항목 번호를 저장한다
		m_nEditItem = nItem;

		// X좌표를 사용해서 영어 단어인지 한글 해석인지 판단한다
		if(ptCursor.x > m_nColumnWidth)	m_bEditEnglish = FALSE;
		else							m_bEditEnglish = TRUE;

		// 항목의 영역을 구한다
		GetItemRect(nItem, &rcItem);

		// 에디트 컨트롤 출력 영역을 설정한다
		if(m_bEditEnglish)	rcItem.right = m_nColumnWidth;
		else				rcItem.left = m_nColumnWidth + 1;
			
		// 편집용 에디트 컨트롤을 생성한다
		m_Edit.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT,
			rcItem, this, IDC_LIST_EDIT);
		// 리스트 박스의 폰트를 설정한다
		m_Edit.SetFont(GetFont());
		// 해당 항목의 텍스트를 설정한다
		m_Edit.SetWindowText(m_bEditEnglish ? pWord->strEnglish : pWord->strKorean);
		// 에디트 박스에 포커스를 준다
		m_Edit.SetFocus();
	}
}

void CWordBook::OnKillFocusEdit() 
{
	// 만약 에디트 박스가 포커스를 잃으면 편집을 종료한다
	EndEdit();
}

// 텍스트 편집을 종료하는 함수
void CWordBook::EndEdit()
{
	// 만약 에디트 박스가 윈도우가 아니라면 리턴한다
	if(!::IsWindow(m_Edit.m_hWnd))			return;

	// 에디트 박스에 입력된 텍스트를 구한다
	CString strNew;
	m_Edit.GetWindowText(strNew);

	// 편집 중인 항목 번호가 옳바르다면
	if(m_nEditItem >= 0)
	{
		// 단어 항목을 얻는다
		SWordItem *pWord = m_WordArray.GetAt(m_nEditItem);

		// 편집된 텍스트를 저장한다
		if(m_bEditEnglish)	pWord->strEnglish = strNew;
		else				pWord->strKorean = strNew;

		// 편집 항목 번호를 초기화한다
		m_nEditItem = -1;
	}

	// 에디트 박스를 소멸시킨다
	m_Edit.DestroyWindow();
}

void CWordBook::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// 만약 DEL 키를 눌렀다면
	switch(nChar)
	{
	case VK_DELETE:
		// 현재 선택된 항목이 있다면
		if(GetCurSel() != LB_ERR)
		{
			// 선택 항목 번호를 얻는다
			int nItem = GetCurSel();

			// 선택된 단어 항목을 얻는다
			SWordItem *pWord = m_WordArray.GetAt(nItem);
			// 단어 배열에서 삭제한다
			m_WordArray.RemoveAt(nItem);
			// 리스트 박스의 항목을 삭제한다
			DeleteString(nItem);

			// 단어 항목을 메모리에서 삭제한다
			delete pWord;

			// 단어장이 수정되었음을 설정한다
			m_bModified = TRUE;
		}
		break;
	}
	
	CListBox::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CWordBook::OnSelchange() 
{
	// 선택된 항목 번호를 얻는다
	int nItem = GetCurSel();
	// 항목 번호가 유효하고 Speech API 인터페이스가 생성된 상태라면
	if(m_pSpeechApi && nItem != LB_ERR)
	{
		// 단어 항목을 얻는다
		SWordItem *pItem = m_WordArray.GetAt(nItem);

		// 볼륨을 최대로 설정한다 : 0 ~ 100
		m_pSpeechApi->SetVolume(100);
		// 발음 속도를 설정한다 : -10 ~ 10
		m_pSpeechApi->SetRate(-5);
		// 영어 단어를 Speech API를 통해 스피커로 출력한다
		m_pSpeechApi->Speak(pItem->strEnglish.AllocSysString(), 0, NULL);
	}
}

void CWordBook::OnDestroy() 
{
	CListBox::OnDestroy();

	// 만약 단어장이 수정되었다면 파일로 저장한다
	if(m_bModified)		SaveWordFile();
}
