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

// Speech API ���̺귯�� ��ũ
#pragma comment(lib, "sapi.lib")

// ����Ʈ �ڽ��� ���ҽ� ID
#define IDC_LIST_EDIT				1

CWordBook::CWordBook()
{
	// ��� ������ �ʱ�ȭ�Ѵ�
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
	// GDI ��ü���� �����Ѵ�
	m_ShadowPen.DeleteObject();
	m_FocusPen.DeleteObject();

	// �ܾ��� �׸���� �����Ѵ�
	int nSize = m_WordArray.GetSize(), i;
	for(i = 0; i < nSize; i++)
	{
		delete m_WordArray.GetAt(i);
	}
	m_WordArray.RemoveAll();

	// Ŀ���� �����Ѵ�
	::DeleteObject(m_hSizeCursor);
	::DeleteObject(m_hArrowCursor);

	// Speech API �������̽��� �����Ѵ�
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
	// Ŭ���̾�Ʈ ������ �׵θ� �Ӽ��� ���ش�
    ModifyStyleEx(WS_EX_CLIENTEDGE, 0);
	// ����� ���� �׸��� �Ӽ��� �����ϰ�, �������� �ٽ� �׸���
	ModifyStyle(LBS_SORT | LBS_MULTIPLESEL, LBS_OWNERDRAWVARIABLE | LBS_HASSTRINGS | LBS_NOINTEGRALHEIGHT | LBS_EXTENDEDSEL | WS_BORDER, SWP_FRAMECHANGED);

	// �ܾ��� ������ �ε��Ѵ�
	ReadWordFile();

	// Speech API �������̽��� �����Ѵ�
    if(FAILED(CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL,
		IID_ISpVoice, (void**)&m_pSpeechApi)))
		m_pSpeechApi = NULL;

	CListBox::PreSubclassWindow();
}

// ���� �ܾ��� ������ �ε��ϴ� �Լ�
void CWordBook::ReadWordFile()
{
	// ���� ���丮�� Word.dat ������ �ε��Ѵ�
	CString strWordFile;
	::GetCurrentDirectory(MAX_PATH, strWordFile.GetBuffer(MAX_PATH));
	strWordFile.ReleaseBuffer();
	strWordFile += "\\Word.dat";

	CFile WordFile;

	if(!WordFile.Open(strWordFile, CFile::modeRead))	return;

	CArchive WordArchive(&WordFile, CArchive::load);

	// �ܾ��� ������ �ܾ� �׸���� �޸𸮷� �ε��Ѵ�
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

// ���� �ܾ��� ������ �����ϴ� �Լ�
void CWordBook::SaveWordFile()
{
	// ���� ���丮�� Word.dat ������ �����Ѵ�
	CString strWordFile;
	::GetCurrentDirectory(MAX_PATH, strWordFile.GetBuffer(MAX_PATH));
	strWordFile.ReleaseBuffer();
	strWordFile += "\\Word.dat";

	CFile WordFile;

	if(!WordFile.Open(strWordFile, CFile::modeCreate | CFile::modeWrite))	return;

	CArchive WordArchive(&WordFile, CArchive::store);

	SWordItem *pWord;
	int i, nSize = m_WordArray.GetSize();

	// ���� �ܾ� �迭�� ��� �׸��� �����Ѵ�
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

// �ܾ��忡 �ܾ �߰��ϴ� �Լ�
void CWordBook::AddWord(LPCTSTR pEnglish, LPCTSTR pKorean)
{
	if(::strlen(pEnglish) <= 0 || ::strlen(pKorean) <= 0)
		return;

	// �� �ܾ� �׸��� �����Ѵ�
	SWordItem *pWord = new SWordItem;

	// ���� �ܾ�� �ؼ�, �׸��� ��¥�� �����Ѵ�
	pWord->strEnglish = pEnglish;
	pWord->strKorean = pKorean;
	pWord->date = COleDateTime::GetCurrentTime();

	// ���� �ܾ� �迭�� �߰��Ѵ�
	m_WordArray.Add(pWord);
	AddString(pEnglish);

	// �ܾ����� ����Ǿ����� �����Ѵ�
	m_bModified = TRUE;
}

void CWordBook::OnMouseMove(UINT nFlags, CPoint point) 
{
	CListBox::OnMouseMove(nFlags, point);

	// ���� ���� �ܾ� ��� ������ �����ϰ� �ִ� ���¶��
	if(m_bCapture)
	{
		CRect rcClient;
		GetClientRect(&rcClient);

		// �ܾ��� ���ο��� ���콺�� �̵� ���̶��
		if(rcClient.PtInRect(point))
		{
			// ������ Ŀ���� �����Ѵ�
			SetCursor(m_hSizeCursor);

			// ������ ���۷��̼��� R2_NOT���� �����Ѵ�
			CDC *pDC = GetDC();
			int nROP2 = pDC->SetROP2(R2_NOT);

			// ���� ���м� ��ġ�� �����
			pDC->MoveTo(m_nColumnWidth, 0);
			pDC->LineTo(m_nColumnWidth, rcClient.bottom);

			// ���м� ��ġ�� �����Ѵ�
			m_nColumnWidth = point.x;
			// ���� �ܾ� ��� ���� �ּ� 10�ȼ��� �� �� �ֵ��� �����Ѵ�
			if(m_nColumnWidth < 10)		m_nColumnWidth = 10;
			// ���� ��ũ�ѹٰ� ������ �������� Ȯ���Ѵ�
			if(GetScrollBarCtrl(SB_VERT))
			{
				// ���� ��ũ�ѹٰ� ������ ���¶�� ũ�⸦ ��´�
				CRect rcScroll;
				GetScrollBarCtrl(SB_VERT)->GetWindowRect(&rcScroll);

				// ��ũ�ѹ� ������ ������ Ŭ���̾�Ʈ ��������
				// �ѱ� �ؼ� ��� ���� �ּ� 10�ȼ��� �� �� �ֵ��� �����Ѵ�
				if(m_nColumnWidth > rcClient.right - rcScroll.Width() - 10)
					m_nColumnWidth = rcClient.right - rcScroll.Width() - 10;
			}
			else
			{
				// ���� ��ũ�ѹٰ� �������� ���� ���¶��
				// Ŭ���̾�Ʈ �������� �ѱ� �ؼ� ��� ���� �ּ� 10�ȼ��� �ǵ��� �����Ѵ�
				if(m_nColumnWidth > rcClient.right - 10)
					m_nColumnWidth = rcClient.right - 10;
			}

			// �� ���м� ��ġ�� ������ ����Ѵ�
			pDC->MoveTo(m_nColumnWidth, 0);
			pDC->LineTo(m_nColumnWidth, rcClient.bottom);

			pDC->SetROP2(nROP2);

			ReleaseDC(pDC);

			return;
		}
	}

	// ���� ���м� ��ġ ���� ���°� �ƴ϶��
	// ���м� ��ġ�� ���콺�� ��ġ�� �ִٸ� Ŀ���� ������ Ŀ���� �����Ѵ�
	if(point.x > m_nColumnWidth - 3 && point.x < m_nColumnWidth + 3)
		SetCursor(m_hSizeCursor);
	else
		SetCursor(m_hArrowCursor);

	// �ý��ۿ��� ���콺�� Ż�⿡ ���� �޽����� ������ ���� ��û
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags		= TME_LEAVE;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);

	// ���� ����Ʈ �ڽ��� ��µ� ���¶�� �����Ѵ�
	if(::IsWindow(m_Edit.m_hWnd))		return;

	BOOL bOut;
	// ���� ���콺 Ŀ�� ��ġ�� �׸� ��ȣ�� ��´�
	int nItem = ItemFromPoint(point, bOut);

	// �ٷ��� ���콺�� ��ġ�ߴ� �׸�� �����ϸ� �����Ѵ�
	if(nItem == m_nTrackItem)	return;

	CRect rcItem;

	// ���� ������ ��ġ�ߴ� �׸��� �ִٸ�
	if(m_nTrackItem >= 0)
	{
		// �ش� �׸��� �簢 ������ ���Ѵ�
		GetItemRect(m_nTrackItem, &rcItem);
		// �׸� ��ȣ�� -1�� �ʱ�ȭ�Ѵ�
		m_nTrackItem = -1;
		// �ش� �׸��� �ٽ� �׸���
		InvalidateRect(&rcItem, FALSE);
	}

	// ���� ���콺�� ����Ʈ �ڽ� ������ �̵��ߴٸ� �����Ѵ�
	if(bOut)		return;

	// ���ο� �׸� ��ȣ�� �����Ѵ�
	m_nTrackItem = nItem;
	// �ش� �׸��� �簢 ������ ���Ѵ�
	GetItemRect(m_nTrackItem, &rcItem);
	// �ش� �׸��� �ٽ� �׸���
	InvalidateRect(&rcItem, FALSE);
}

LRESULT CWordBook::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// ���� ���м� ���� ���¶�� �����Ѵ�
	if(m_bCapture)		return 0;

	// ���� �ٷ��� ���콺�� ��ġ�ߴ� �׸��� �ִٸ�
	if(m_nTrackItem >= 0)
	{
		CRect rcItem;

		// �ش� �׸��� �簢 ������ ���Ѵ�
		GetItemRect(m_nTrackItem, &rcItem);
		// �׸� ��ȣ�� -1�� �ʱ�ȭ�Ѵ�
		m_nTrackItem = -1;
		// �ش� �׸��� �ٽ� �׸���
		InvalidateRect(&rcItem, FALSE);
	}

	return 0;
}

void CWordBook::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// ���� �ܾ�� �ؼ��� �����ϴ� ��ġ���� ���콺 ���� ��ư�� ���ȴٸ�
	if(point.x > m_nColumnWidth - 3 && point.x < m_nColumnWidth + 3)
	{
		// ���콺 �̺�Ʈ�� ĸ���Ѵ�
		SetCapture();
		// ���콺 Ŀ���� �����Ѵ�
		SetCursor(m_hSizeCursor);

		m_bCapture = TRUE;

		CRect rcClient;
		GetClientRect(&rcClient);

		// ���� ���м� ��ġ�� �������� ǥ���Ѵ�
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
	// ���� ���м� ���� ���¶��
	if(m_bCapture)
	{
		// ���콺 �̺�Ʈ ĸ�縦 �����Ѵ�
		ReleaseCapture();
		m_bCapture = FALSE;

		CRect rcClient;
		GetClientRect(&rcClient);

		// ������ �׷ȴ� ���м��� �����
		CDC *pDC = GetDC();
		int nROP2 = pDC->SetROP2(R2_NOT);

		pDC->MoveTo(m_nColumnWidth, 0);
		pDC->LineTo(m_nColumnWidth, rcClient.bottom);

		pDC->SetROP2(nROP2);

		ReleaseDC(pDC);

		// ���콺 ��ġ�� Ŭ���̾�Ʈ ���� ���ζ�� ���м� ��ġ�� �����Ѵ�
		if(rcClient.PtInRect(point))
		{
			m_nColumnWidth = point.x;
			Invalidate(FALSE);
		}
	}
	
	CListBox::OnLButtonUp(nFlags, point);
}

// �� �׸��� ũ�⸦ �����Ѵ�
void CWordBook::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	lpMeasureItemStruct->itemHeight = 20;
}

void CWordBook::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// ���� ����ϴ� �׸��� ��ȣ�� ��ȿ���� �ʴٸ� �����Ѵ�
	if((int)lpDrawItemStruct->itemID < 0)											return;
	// ���� ���� ���� ���� �׸��̶�� �����Ѵ�
	if((int)lpDrawItemStruct->itemID == m_nEditItem && ::IsWindow(m_Edit.m_hWnd))	return;

	// �׸��� ������ ���Ѵ�
	CRect rcItem = lpDrawItemStruct->rcItem;
	// �»���� (0, 0)���� �̵���Ų��
	rcItem.OffsetRect(-lpDrawItemStruct->rcItem.left, -lpDrawItemStruct->rcItem.top);

	// ���� ���۸��� �����Ѵ�
	CDC dc, MemDC;
	dc.Attach(lpDrawItemStruct->hDC);
	MemDC.CreateCompatibleDC(&dc);

	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(&dc, rcItem.Width(), rcItem.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// ����Ʈ �ڽ��� ��Ʈ�� �����Ѵ�
	CFont *pOldFont = MemDC.SelectObject(GetFont());

	COLORREF clrBkgnd;
	// ���� ���õ� �׸��̸� ���� ������ �������� ����Ѵ�
	if(lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		clrBkgnd = m_clrSelected;
	}
	else
	{
		// ���� ���콺�� ��ġ�� �׸����� ���ο� ���� ������ �ٸ��� ����Ѵ�
		if((int)lpDrawItemStruct->itemID == m_nTrackItem)	clrBkgnd = m_clrHighlight;
		else												clrBkgnd = m_clrBkgnd;
	}
	// ����� ĥ�Ѵ�
	MemDC.FillSolidRect(&rcItem, clrBkgnd);

	// ���� ���� ��Ŀ���� ���� �ִ� �׸��̶��
	if(lpDrawItemStruct->itemState & ODS_FOCUS)
	{
		// ��Ŀ�� ���� ����Ͽ� �׵θ��� �׸���
		CBrush *pOldBrush = MemDC.SelectObject(&m_NullBrush);
		CPen *pOldPen = MemDC.SelectObject(&m_FocusPen);

		MemDC.Rectangle(&rcItem);

		MemDC.SelectObject(pOldBrush);
		MemDC.SelectObject(pOldPen);
	}

	// ����� �������� �����ϰ�, �ؽ�Ʈ ������ �����Ѵ�
	MemDC.SetBkMode(TRANSPARENT);
	MemDC.SetTextColor(m_clrText);

	// �ܾ� �׸��� ��´�
	CRect rcEnglish, rcKorean;
	SWordItem *pItem = m_WordArray.GetAt(lpDrawItemStruct->itemID);

	// ���� �ܾ ����Ѵ�
	rcEnglish = rcItem;
	rcEnglish.right = m_nColumnWidth - 3;
	MemDC.DrawText(pItem->strEnglish,
		&rcEnglish, DT_SINGLELINE | DT_VCENTER | DT_LEFT);

	// �ѱ� �ؼ��� ����Ѵ�
	rcKorean = rcItem;
	rcKorean.left = m_nColumnWidth + 3;
	MemDC.DrawText(pItem->strKorean,
		&rcKorean, DT_SINGLELINE | DT_VCENTER | DT_LEFT);

	// ���� ù �ܾ �ƴ϶��
	if(lpDrawItemStruct->itemID > 0)
	{
		// ���� �ܾ� �׸��� ��´�
		SWordItem *pPrev = m_WordArray.GetAt(lpDrawItemStruct->itemID - 1);

		// ���� ���� �ܾ�� ���� �ܾ��� ���� ��¥�� �ٸ��ٸ�
		if(pPrev->date.GetYear() != pItem->date.GetYear()
			|| pPrev->date.GetMonth() != pItem->date.GetMonth()
			|| pPrev->date.GetDay() != pItem->date.GetDay())
		{
			// ��ܿ� ��¥ ���м��� ����Ѵ�
			MemDC.MoveTo(0, 0);
			MemDC.LineTo(rcItem.right, 0);
		}
	}

	// �޸� DC�� ������ ȭ�鿡 ����Ѵ�
	dc.BitBlt(lpDrawItemStruct->rcItem.left, lpDrawItemStruct->rcItem.top,
		rcItem.Width(), rcItem.Height(), &MemDC, 0, 0, SRCCOPY);

	// GDI ��ü���� ��ȯ�Ѵ�
	MemDC.SelectObject(pOldFont);
	MemDC.SelectObject(&pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
	dc.Detach();
}

void CWordBook::OnNcPaint() 
{
	Default();

	// ����Ʈ �ڽ��� �׵θ��� ����Ѵ�
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
	// ���� Ŀ�� ��ġ�� ���Ѵ�
	BOOL bOut;
	CPoint ptCursor;
	::GetCursorPos(&ptCursor);
	ScreenToClient(&ptCursor);

	// ���� Ŀ�� ��ġ�� �׸� ��ȣ�� ���Ѵ�
	int nItem = (int)ItemFromPoint(ptCursor, bOut);
	// ���� ���� �׸� ���� ���� �ƴ϶��
	if(nItem >= 0 && !bOut && !::IsWindow(m_Edit.m_hWnd))
	{
		CString strItem;
		CRect rcItem;

		// �ܾ� �׸��� ��´�
		SWordItem *pWord = m_WordArray.GetAt(nItem);

		// ���� ���� �׸� ��ȣ�� �����Ѵ�
		m_nEditItem = nItem;

		// X��ǥ�� ����ؼ� ���� �ܾ����� �ѱ� �ؼ����� �Ǵ��Ѵ�
		if(ptCursor.x > m_nColumnWidth)	m_bEditEnglish = FALSE;
		else							m_bEditEnglish = TRUE;

		// �׸��� ������ ���Ѵ�
		GetItemRect(nItem, &rcItem);

		// ����Ʈ ��Ʈ�� ��� ������ �����Ѵ�
		if(m_bEditEnglish)	rcItem.right = m_nColumnWidth;
		else				rcItem.left = m_nColumnWidth + 1;
			
		// ������ ����Ʈ ��Ʈ���� �����Ѵ�
		m_Edit.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT,
			rcItem, this, IDC_LIST_EDIT);
		// ����Ʈ �ڽ��� ��Ʈ�� �����Ѵ�
		m_Edit.SetFont(GetFont());
		// �ش� �׸��� �ؽ�Ʈ�� �����Ѵ�
		m_Edit.SetWindowText(m_bEditEnglish ? pWord->strEnglish : pWord->strKorean);
		// ����Ʈ �ڽ��� ��Ŀ���� �ش�
		m_Edit.SetFocus();
	}
}

void CWordBook::OnKillFocusEdit() 
{
	// ���� ����Ʈ �ڽ��� ��Ŀ���� ������ ������ �����Ѵ�
	EndEdit();
}

// �ؽ�Ʈ ������ �����ϴ� �Լ�
void CWordBook::EndEdit()
{
	// ���� ����Ʈ �ڽ��� �����찡 �ƴ϶�� �����Ѵ�
	if(!::IsWindow(m_Edit.m_hWnd))			return;

	// ����Ʈ �ڽ��� �Էµ� �ؽ�Ʈ�� ���Ѵ�
	CString strNew;
	m_Edit.GetWindowText(strNew);

	// ���� ���� �׸� ��ȣ�� �ǹٸ��ٸ�
	if(m_nEditItem >= 0)
	{
		// �ܾ� �׸��� ��´�
		SWordItem *pWord = m_WordArray.GetAt(m_nEditItem);

		// ������ �ؽ�Ʈ�� �����Ѵ�
		if(m_bEditEnglish)	pWord->strEnglish = strNew;
		else				pWord->strKorean = strNew;

		// ���� �׸� ��ȣ�� �ʱ�ȭ�Ѵ�
		m_nEditItem = -1;
	}

	// ����Ʈ �ڽ��� �Ҹ��Ų��
	m_Edit.DestroyWindow();
}

void CWordBook::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// ���� DEL Ű�� �����ٸ�
	switch(nChar)
	{
	case VK_DELETE:
		// ���� ���õ� �׸��� �ִٸ�
		if(GetCurSel() != LB_ERR)
		{
			// ���� �׸� ��ȣ�� ��´�
			int nItem = GetCurSel();

			// ���õ� �ܾ� �׸��� ��´�
			SWordItem *pWord = m_WordArray.GetAt(nItem);
			// �ܾ� �迭���� �����Ѵ�
			m_WordArray.RemoveAt(nItem);
			// ����Ʈ �ڽ��� �׸��� �����Ѵ�
			DeleteString(nItem);

			// �ܾ� �׸��� �޸𸮿��� �����Ѵ�
			delete pWord;

			// �ܾ����� �����Ǿ����� �����Ѵ�
			m_bModified = TRUE;
		}
		break;
	}
	
	CListBox::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CWordBook::OnSelchange() 
{
	// ���õ� �׸� ��ȣ�� ��´�
	int nItem = GetCurSel();
	// �׸� ��ȣ�� ��ȿ�ϰ� Speech API �������̽��� ������ ���¶��
	if(m_pSpeechApi && nItem != LB_ERR)
	{
		// �ܾ� �׸��� ��´�
		SWordItem *pItem = m_WordArray.GetAt(nItem);

		// ������ �ִ�� �����Ѵ� : 0 ~ 100
		m_pSpeechApi->SetVolume(100);
		// ���� �ӵ��� �����Ѵ� : -10 ~ 10
		m_pSpeechApi->SetRate(-5);
		// ���� �ܾ Speech API�� ���� ����Ŀ�� ����Ѵ�
		m_pSpeechApi->Speak(pItem->strEnglish.AllocSysString(), 0, NULL);
	}
}

void CWordBook::OnDestroy() 
{
	CListBox::OnDestroy();

	// ���� �ܾ����� �����Ǿ��ٸ� ���Ϸ� �����Ѵ�
	if(m_bModified)		SaveWordFile();
}
