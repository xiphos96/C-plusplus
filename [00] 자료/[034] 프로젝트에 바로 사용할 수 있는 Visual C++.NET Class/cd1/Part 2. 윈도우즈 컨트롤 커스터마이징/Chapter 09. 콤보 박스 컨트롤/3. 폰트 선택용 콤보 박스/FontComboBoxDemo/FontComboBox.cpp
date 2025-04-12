// FontComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "fontcomboboxdemo.h"
#include "FontComboBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontComboBox

// 폰트 항목 사이의 간격
#define CONST_ITEM_GAP				6
// 폰트 종류를 나타내는 이미지의 가로/세로 크기
#define CONST_TYPE_IMAGE_SIZE		15


CFontComboBox::CFontComboBox()
{
	// 멤버 변수들을 초기화한다
	m_clrBkgnd			= RGB(255, 255, 255);
	m_clrSelected		= RGB(220, 230, 245);
	m_clrText			= ::GetSysColor(COLOR_BTNTEXT);
	m_clrTextDisabled	= ::GetSysColor(COLOR_GRAYTEXT);

	// 폰트 종류 이미지 리스트를 생성한다
	m_TypeImageList.Create(IDB_FONT_TYPE, CONST_TYPE_IMAGE_SIZE, 1, RGB(255, 255, 255));
}

CFontComboBox::~CFontComboBox()
{
	// 폰트 종류 이미지 리스트를 제거한다
	m_TypeImageList.DeleteImageList();
}


BEGIN_MESSAGE_MAP(CFontComboBox, CComboBox)
	//{{AFX_MSG_MAP(CFontComboBox)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontComboBox message handlers

void CFontComboBox::PreSubclassWindow() 
{
	// 현재 시스템의 기본 문자셋으로 폰트를 검색한다
	LOGFONT LogFont;

	LogFont.lfCharSet		= DEFAULT_CHARSET;
	LogFont.lfFaceName[0]	= NULL;

	CDC *pDC = GetDC();
	::EnumFontFamiliesEx(pDC->m_hDC, &LogFont, (FONTENUMPROC)EnumFontProc, (LPARAM)this, 0);
	ReleaseDC(pDC);

	CComboBox::PreSubclassWindow();
}

// 시스템의 폰트를 찾는 정적 함수
int CALLBACK CFontComboBox::EnumFontProc(ENUMLOGFONTEX *lpelfe,NEWTEXTMETRICEX *lpntme,int FontType,LPARAM lParam)
{
	// 인자로 넘겨진 콤보 박스 포인터를 형변환한다
	CFontComboBox *pCombo = (CFontComboBox*)lParam;

	int nItem;

	// 이미 콤보 박스에 추가된 항목인지 찾는다
	nItem = pCombo->FindStringExact(-1, (LPCTSTR)lpelfe->elfFullName);
	// 이미 있다면 그냥 리턴
	if(nItem >= 0)		return 1;

	// 폰트 이름을 콤보 박스에 추가한다
	nItem = pCombo->AddString((LPCTSTR)lpelfe->elfFullName);

	// 폰트 정보 구조체 객체를 만든다
	LPFONTTYPEINFO pFont = new FONTTYPEINFO;

	// 폰트의 글꼴 크기를 10 포인트로 설정한다
	HDC hDC = ::GetDC(NULL);
	lpelfe->elfLogFont.lfHeight = -MulDiv(10, ::GetDeviceCaps(hDC, LOGPIXELSX), 72);
	lpelfe->elfLogFont.lfWidth = 0;
	::ReleaseDC(NULL, hDC);

	// 로그 폰트를 기준으로 폰트 객체를 생성한다
	pFont->Font.CreateFontIndirect(&lpelfe->elfLogFont);
	// 폰트 종류를 저장한다
	pFont->nFontType = FontType;

	// 콤보 박스 항목의 포인트 데이터로 설정한다
	pCombo->SetItemDataPtr(nItem, pFont);

	return 1;
}

// 항목의 크기를 계산한다
void CFontComboBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// 기본 항목 높이에 항목 간격을 더한다
	lpMeasureItemStruct->itemHeight += CONST_ITEM_GAP;
}

void CFontComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	CRect rcItem(&(lpDrawItemStruct->rcItem));

	// 만약 항목의 번호가 없다면
	if((int)lpDrawItemStruct->itemID < 0)
	{
		// 배경을 기본 색상으로 지우고 리턴한다
		dc.FillSolidRect(rcItem, m_clrBkgnd);
		dc.Detach();
		return;
	}

	// 현재 항목 상태를 얻는다
	BOOL bIsSelected	= (lpDrawItemStruct->itemState & ODS_SELECTED);
	BOOL bIsDisabled	= (lpDrawItemStruct->itemState & ODS_DISABLED);

	// 선택된 상태에 따라 다른 배경색으로 배경을 칠한다
	if(bIsSelected)		dc.FillSolidRect(rcItem, m_clrSelected);
	else				dc.FillSolidRect(rcItem, m_clrBkgnd);

	// 현재 항목의 폰트 정보를 얻는다
	LPFONTTYPEINFO pFont = (LPFONTTYPEINFO)lpDrawItemStruct->itemData;

	// 만약 트루타입 폰트나 래스터 폰트라면
	if(pFont->nFontType & TRUETYPE_FONTTYPE || pFont->nFontType & RASTER_FONTTYPE)
	{
		// 이미지를 출력할 위치를 계산한다
		CPoint ptIcon = rcItem.TopLeft();
		ptIcon.x = CONST_ITEM_GAP / 2;
		ptIcon.y = rcItem.top + (rcItem.Height() - CONST_TYPE_IMAGE_SIZE) / 2;
		// 해당 폰트 종류의 이미지를 화면에 출력한다
		m_TypeImageList.Draw(&dc, (pFont->nFontType & TRUETYPE_FONTTYPE ? 0 : 1), ptIcon, ILD_NORMAL);
	}

	// 이미지 크기를 제하여 텍스트 출력 위치를 보정한다
	rcItem.left += CONST_TYPE_IMAGE_SIZE + CONST_ITEM_GAP;

	// 항목의 텍스트를 얻는다
	CString strText;
	GetLBText(lpDrawItemStruct->itemID, strText);

	// 콤보 박스의 폰트를 설정한다
	CFont *pOldFont = dc.SelectObject(GetFont());

	// 텍스트 배경을 투명하게 설정한다
	dc.SetBkMode(TRANSPARENT);

	// 활성화 여부에 따라 텍스트 색상을 설정한다
	if(bIsDisabled)			dc.SetTextColor(m_clrTextDisabled);
	else					dc.SetTextColor(m_clrText);

	// 폰트 이름을 출력한다
	CRect rcText = rcItem;
	dc.DrawText(strText, rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_CALCRECT);
	dc.DrawText(strText, rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

	// 만약 에디트 박스 영역에 출력하는 것이 아니라면
	if(!(lpDrawItemStruct->itemState & ODS_COMBOBOXEDIT))
	{
		// 현재 항목의 폰트를 설정한다
		dc.SelectObject(&pFont->Font);

		// 폰트 이름 앞 뒤에 괄호를 넣는다
		strText.Insert(0, "(");
		strText += ")";

		// 폰트 이름을 출력했던 뒤 쪽으로 이어서 
		rcItem.left = rcText.right + CONST_ITEM_GAP;
		// 해당 폰트로 셈플 텍스트를 출력한다
		dc.DrawText(strText, rcItem, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	}
	
	// 폰트를 반환한다
	dc.SelectObject(pOldFont);
	dc.Detach();
}

// 현재 선택된 폰트의 포인터를 리턴하는 함수
CFont* CFontComboBox::GetCurrentFont()
{
	// 현재 선택된 항목 번호를 얻는다
	int nSel = GetCurSel();
	// 만약 선택된 항목이 없다면 리턴
	if(nSel == CB_ERR)		return NULL;

	// 해당 항목의 폰트 정보를 얻는다
	LPFONTTYPEINFO pFont = (LPFONTTYPEINFO)GetItemDataPtr(nSel);

	// 폰트 객체 포인터를 리턴한다
	return &pFont->Font;
}

// 현재 선택된 폰트의 이름을 리턴하는 함수
void CFontComboBox::GetCurrentFont(CString &strFontName)
{
	// 현재 선택된 항목 번호를 얻는다
	int nSel = GetCurSel();

	// 폰트 이름을 저장할 버퍼를 지운다
	strFontName.Empty();
	// 만약 선택된 항목이 없다면 리턴
	if(nSel == CB_ERR)		return;

	// 해당 항목의 텍스트, 즉 폰트 이름을 얻는다
	GetLBText(nSel, strFontName);
}

// 현재 선택된 폰트의 LOGFONT 정보를 리턴하는 함수
void CFontComboBox::GetLogFont(LOGFONT *pLogFont)
{
	// 현재 선택된 항목 번호를 얻는다
	int nSel = GetCurSel();
	// 만약 선택된 항목이 없다면 리턴
	if(nSel == CB_ERR)		return;

	// 해당 항목의 폰트 정보를 얻는다
	LPFONTTYPEINFO pFont = (LPFONTTYPEINFO)GetItemDataPtr(nSel);

	// 폰트 객체로부터 로그 폰트 정보를 얻는다
	pFont->Font.GetLogFont(pLogFont);
}

// 특정 폰트를 선택하는 함수
int CFontComboBox::SelectFont(LPCTSTR pFontName)
{
	// 폰트 이름이 동일한 항목을 찾는다
	int nSel = FindStringExact(-1, pFontName);
	// 만약 항목을 찾지 못하면 리턴
	if(nSel == CB_ERR)		return CB_ERR;

	// 해당 항목을 선택한다
	SetCurSel(nSel);

	// 항목 번호를 리턴한다
	return nSel;
}

void CFontComboBox::OnDestroy() 
{
	int i, nSize = GetCount();
	LPFONTTYPEINFO pFont;

	// 콤보 박스가 소멸되면서,
	// 콤보 박스에 추가되었던 모든 항목의 폰트 정보 객체를 소멸시킨다
	for(i = 0; i < nSize; i++)
	{
		pFont = (LPFONTTYPEINFO)GetItemDataPtr(i);
		delete pFont;
	}
	
	CComboBox::OnDestroy();
}
