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

// ��Ʈ �׸� ������ ����
#define CONST_ITEM_GAP				6
// ��Ʈ ������ ��Ÿ���� �̹����� ����/���� ũ��
#define CONST_TYPE_IMAGE_SIZE		15


CFontComboBox::CFontComboBox()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	m_clrBkgnd			= RGB(255, 255, 255);
	m_clrSelected		= RGB(220, 230, 245);
	m_clrText			= ::GetSysColor(COLOR_BTNTEXT);
	m_clrTextDisabled	= ::GetSysColor(COLOR_GRAYTEXT);

	// ��Ʈ ���� �̹��� ����Ʈ�� �����Ѵ�
	m_TypeImageList.Create(IDB_FONT_TYPE, CONST_TYPE_IMAGE_SIZE, 1, RGB(255, 255, 255));
}

CFontComboBox::~CFontComboBox()
{
	// ��Ʈ ���� �̹��� ����Ʈ�� �����Ѵ�
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
	// ���� �ý����� �⺻ ���ڼ����� ��Ʈ�� �˻��Ѵ�
	LOGFONT LogFont;

	LogFont.lfCharSet		= DEFAULT_CHARSET;
	LogFont.lfFaceName[0]	= NULL;

	CDC *pDC = GetDC();
	::EnumFontFamiliesEx(pDC->m_hDC, &LogFont, (FONTENUMPROC)EnumFontProc, (LPARAM)this, 0);
	ReleaseDC(pDC);

	CComboBox::PreSubclassWindow();
}

// �ý����� ��Ʈ�� ã�� ���� �Լ�
int CALLBACK CFontComboBox::EnumFontProc(ENUMLOGFONTEX *lpelfe,NEWTEXTMETRICEX *lpntme,int FontType,LPARAM lParam)
{
	// ���ڷ� �Ѱ��� �޺� �ڽ� �����͸� ����ȯ�Ѵ�
	CFontComboBox *pCombo = (CFontComboBox*)lParam;

	int nItem;

	// �̹� �޺� �ڽ��� �߰��� �׸����� ã�´�
	nItem = pCombo->FindStringExact(-1, (LPCTSTR)lpelfe->elfFullName);
	// �̹� �ִٸ� �׳� ����
	if(nItem >= 0)		return 1;

	// ��Ʈ �̸��� �޺� �ڽ��� �߰��Ѵ�
	nItem = pCombo->AddString((LPCTSTR)lpelfe->elfFullName);

	// ��Ʈ ���� ����ü ��ü�� �����
	LPFONTTYPEINFO pFont = new FONTTYPEINFO;

	// ��Ʈ�� �۲� ũ�⸦ 10 ����Ʈ�� �����Ѵ�
	HDC hDC = ::GetDC(NULL);
	lpelfe->elfLogFont.lfHeight = -MulDiv(10, ::GetDeviceCaps(hDC, LOGPIXELSX), 72);
	lpelfe->elfLogFont.lfWidth = 0;
	::ReleaseDC(NULL, hDC);

	// �α� ��Ʈ�� �������� ��Ʈ ��ü�� �����Ѵ�
	pFont->Font.CreateFontIndirect(&lpelfe->elfLogFont);
	// ��Ʈ ������ �����Ѵ�
	pFont->nFontType = FontType;

	// �޺� �ڽ� �׸��� ����Ʈ �����ͷ� �����Ѵ�
	pCombo->SetItemDataPtr(nItem, pFont);

	return 1;
}

// �׸��� ũ�⸦ ����Ѵ�
void CFontComboBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// �⺻ �׸� ���̿� �׸� ������ ���Ѵ�
	lpMeasureItemStruct->itemHeight += CONST_ITEM_GAP;
}

void CFontComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	CRect rcItem(&(lpDrawItemStruct->rcItem));

	// ���� �׸��� ��ȣ�� ���ٸ�
	if((int)lpDrawItemStruct->itemID < 0)
	{
		// ����� �⺻ �������� ����� �����Ѵ�
		dc.FillSolidRect(rcItem, m_clrBkgnd);
		dc.Detach();
		return;
	}

	// ���� �׸� ���¸� ��´�
	BOOL bIsSelected	= (lpDrawItemStruct->itemState & ODS_SELECTED);
	BOOL bIsDisabled	= (lpDrawItemStruct->itemState & ODS_DISABLED);

	// ���õ� ���¿� ���� �ٸ� �������� ����� ĥ�Ѵ�
	if(bIsSelected)		dc.FillSolidRect(rcItem, m_clrSelected);
	else				dc.FillSolidRect(rcItem, m_clrBkgnd);

	// ���� �׸��� ��Ʈ ������ ��´�
	LPFONTTYPEINFO pFont = (LPFONTTYPEINFO)lpDrawItemStruct->itemData;

	// ���� Ʈ��Ÿ�� ��Ʈ�� ������ ��Ʈ���
	if(pFont->nFontType & TRUETYPE_FONTTYPE || pFont->nFontType & RASTER_FONTTYPE)
	{
		// �̹����� ����� ��ġ�� ����Ѵ�
		CPoint ptIcon = rcItem.TopLeft();
		ptIcon.x = CONST_ITEM_GAP / 2;
		ptIcon.y = rcItem.top + (rcItem.Height() - CONST_TYPE_IMAGE_SIZE) / 2;
		// �ش� ��Ʈ ������ �̹����� ȭ�鿡 ����Ѵ�
		m_TypeImageList.Draw(&dc, (pFont->nFontType & TRUETYPE_FONTTYPE ? 0 : 1), ptIcon, ILD_NORMAL);
	}

	// �̹��� ũ�⸦ ���Ͽ� �ؽ�Ʈ ��� ��ġ�� �����Ѵ�
	rcItem.left += CONST_TYPE_IMAGE_SIZE + CONST_ITEM_GAP;

	// �׸��� �ؽ�Ʈ�� ��´�
	CString strText;
	GetLBText(lpDrawItemStruct->itemID, strText);

	// �޺� �ڽ��� ��Ʈ�� �����Ѵ�
	CFont *pOldFont = dc.SelectObject(GetFont());

	// �ؽ�Ʈ ����� �����ϰ� �����Ѵ�
	dc.SetBkMode(TRANSPARENT);

	// Ȱ��ȭ ���ο� ���� �ؽ�Ʈ ������ �����Ѵ�
	if(bIsDisabled)			dc.SetTextColor(m_clrTextDisabled);
	else					dc.SetTextColor(m_clrText);

	// ��Ʈ �̸��� ����Ѵ�
	CRect rcText = rcItem;
	dc.DrawText(strText, rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_CALCRECT);
	dc.DrawText(strText, rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

	// ���� ����Ʈ �ڽ� ������ ����ϴ� ���� �ƴ϶��
	if(!(lpDrawItemStruct->itemState & ODS_COMBOBOXEDIT))
	{
		// ���� �׸��� ��Ʈ�� �����Ѵ�
		dc.SelectObject(&pFont->Font);

		// ��Ʈ �̸� �� �ڿ� ��ȣ�� �ִ´�
		strText.Insert(0, "(");
		strText += ")";

		// ��Ʈ �̸��� ����ߴ� �� ������ �̾ 
		rcItem.left = rcText.right + CONST_ITEM_GAP;
		// �ش� ��Ʈ�� ���� �ؽ�Ʈ�� ����Ѵ�
		dc.DrawText(strText, rcItem, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	}
	
	// ��Ʈ�� ��ȯ�Ѵ�
	dc.SelectObject(pOldFont);
	dc.Detach();
}

// ���� ���õ� ��Ʈ�� �����͸� �����ϴ� �Լ�
CFont* CFontComboBox::GetCurrentFont()
{
	// ���� ���õ� �׸� ��ȣ�� ��´�
	int nSel = GetCurSel();
	// ���� ���õ� �׸��� ���ٸ� ����
	if(nSel == CB_ERR)		return NULL;

	// �ش� �׸��� ��Ʈ ������ ��´�
	LPFONTTYPEINFO pFont = (LPFONTTYPEINFO)GetItemDataPtr(nSel);

	// ��Ʈ ��ü �����͸� �����Ѵ�
	return &pFont->Font;
}

// ���� ���õ� ��Ʈ�� �̸��� �����ϴ� �Լ�
void CFontComboBox::GetCurrentFont(CString &strFontName)
{
	// ���� ���õ� �׸� ��ȣ�� ��´�
	int nSel = GetCurSel();

	// ��Ʈ �̸��� ������ ���۸� �����
	strFontName.Empty();
	// ���� ���õ� �׸��� ���ٸ� ����
	if(nSel == CB_ERR)		return;

	// �ش� �׸��� �ؽ�Ʈ, �� ��Ʈ �̸��� ��´�
	GetLBText(nSel, strFontName);
}

// ���� ���õ� ��Ʈ�� LOGFONT ������ �����ϴ� �Լ�
void CFontComboBox::GetLogFont(LOGFONT *pLogFont)
{
	// ���� ���õ� �׸� ��ȣ�� ��´�
	int nSel = GetCurSel();
	// ���� ���õ� �׸��� ���ٸ� ����
	if(nSel == CB_ERR)		return;

	// �ش� �׸��� ��Ʈ ������ ��´�
	LPFONTTYPEINFO pFont = (LPFONTTYPEINFO)GetItemDataPtr(nSel);

	// ��Ʈ ��ü�κ��� �α� ��Ʈ ������ ��´�
	pFont->Font.GetLogFont(pLogFont);
}

// Ư�� ��Ʈ�� �����ϴ� �Լ�
int CFontComboBox::SelectFont(LPCTSTR pFontName)
{
	// ��Ʈ �̸��� ������ �׸��� ã�´�
	int nSel = FindStringExact(-1, pFontName);
	// ���� �׸��� ã�� ���ϸ� ����
	if(nSel == CB_ERR)		return CB_ERR;

	// �ش� �׸��� �����Ѵ�
	SetCurSel(nSel);

	// �׸� ��ȣ�� �����Ѵ�
	return nSel;
}

void CFontComboBox::OnDestroy() 
{
	int i, nSize = GetCount();
	LPFONTTYPEINFO pFont;

	// �޺� �ڽ��� �Ҹ�Ǹ鼭,
	// �޺� �ڽ��� �߰��Ǿ��� ��� �׸��� ��Ʈ ���� ��ü�� �Ҹ��Ų��
	for(i = 0; i < nSize; i++)
	{
		pFont = (LPFONTTYPEINFO)GetItemDataPtr(i);
		delete pFont;
	}
	
	CComboBox::OnDestroy();
}
