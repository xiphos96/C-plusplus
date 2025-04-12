// DriveComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "drivecomboboxdemo.h"
#include "DriveComboBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDriveComboBox

#define CONST_ITEM_GAP			6

CDriveComboBox::CDriveComboBox()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	m_nDriveCount = 0;
	m_bBigIcon = FALSE;

	m_clrBkgnd			= RGB(255, 255, 255);
	m_clrSelected		= RGB(220, 230, 245);
	m_clrText			= ::GetSysColor(COLOR_BTNTEXT);
	m_clrTextDisabled	= ::GetSysColor(COLOR_GRAYTEXT);
}

CDriveComboBox::~CDriveComboBox()
{
}


BEGIN_MESSAGE_MAP(CDriveComboBox, CComboBox)
	//{{AFX_MSG_MAP(CDriveComboBox)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDriveComboBox message handlers

void CDriveComboBox::PreSubclassWindow() 
{
	SHFILEINFO		ShellFileInfo;

	HIMAGELIST hShellImage;
	IMAGEINFO ImageInfo;

	// ū �� ������ �̹��� ����Ʈ�� ��´�
	hShellImage = (HIMAGELIST)::SHGetFileInfo("c:\\", 0, &ShellFileInfo, sizeof(SHFILEINFO),
		SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
	// �̹��� ����Ʈ�� Attach�Ѵ�
	m_BigImageList.Attach(hShellImage);
	// �̹��� ����Ʈ�� ����� �������� �����Ѵ�
	m_BigImageList.SetBkColor(CLR_NONE);
	// ù��° �̹����� �̹��� ������ ��´�
	m_BigImageList.GetImageInfo(0, &ImageInfo);
	// �̹����� ����/���� ũ�⸦ �����Ѵ�
	m_szBigIcon.cx = ImageInfo.rcImage.right - ImageInfo.rcImage.left;
	m_szBigIcon.cy = ImageInfo.rcImage.bottom - ImageInfo.rcImage.top;

	// ���� �� ������ �̹��� ����Ʈ�� ��´�
	hShellImage = (HIMAGELIST)::SHGetFileInfo("c:\\", 0, &ShellFileInfo, sizeof(SHFILEINFO),
		SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_SMALLICON);
	// �̹��� ����Ʈ�� Attach�Ѵ�
	m_SmallImageList.Attach(hShellImage);
	// �̹��� ����Ʈ�� ����� �������� �����Ѵ�
	m_SmallImageList.SetBkColor(CLR_NONE);
	// ù��° �̹����� �̹��� ������ ��´�
	m_SmallImageList.GetImageInfo(0, &ImageInfo);
	// �̹����� ����/���� ũ�⸦ �����Ѵ�
	m_szSmallIcon.cx = ImageInfo.rcImage.right - ImageInfo.rcImage.left;
	m_szSmallIcon.cy = ImageInfo.rcImage.bottom - ImageInfo.rcImage.top;

	// �ý����� ����̺� ��Ʈ ����ũ�� ��´�
	DWORD dwDrive = ::GetLogicalDrives();
	int i;

	// �ý����� ����̺� ������ ����
	for(i = 0; i < 32; i++)
	{
		if(dwDrive & ((DWORD)0x01 << i))		m_nDriveCount++;
	}

	// ����̺� �̸��� ���� ���۸� �����
	char *pDriveName = new char[m_nDriveCount * 4 + 1];
	// ����̺� �̸� �迭�� ��´�
	::GetLogicalDriveStrings(m_nDriveCount * 4 + 1, pDriveName);
	
	int nDrive;
	// ��� ����̺꿡 ����
	for(i = 0; i < m_nDriveCount; i++)
	{
		// ����̺��� ������ ������ ��´�
		::SHGetFileInfo(pDriveName + i * 4, FILE_ATTRIBUTE_DIRECTORY,
			&ShellFileInfo, sizeof(SHFILEINFO),
			SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_LARGEICON);

		// ����̺� �̸��� �޺� �ڽ��� �߰��Ѵ�
		nDrive = AddString(pDriveName + i * 4);
		// ����̺� ������ ��ȣ�� �����Ѵ�
		SetItemData(nDrive, ShellFileInfo.iIcon);
	}

	// ����̺� �̸� ���۸� �����Ѵ�
	delete[] pDriveName;

	// ���� ������ ũ�⿡ ���� �׸��� ũ�⸦ �����Ѵ�
	SetItemHeight(-1, (m_bBigIcon ? m_szBigIcon.cy : m_szSmallIcon.cy) + CONST_ITEM_GAP);
	SetItemHeight(0, (m_bBigIcon ? m_szBigIcon.cy : m_szSmallIcon.cy) + CONST_ITEM_GAP);

	CComboBox::PreSubclassWindow();
}

void CDriveComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
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

	// �������� ��µ� ��ġ�� ����Ѵ�
	CPoint ptIcon = rcItem.TopLeft();
	ptIcon.x = CONST_ITEM_GAP / 2;
	if(m_bBigIcon)
	{
		ptIcon.y = rcItem.top + (rcItem.Height() - m_szBigIcon.cy) / 2;
		// ū ����̺� �������� ����Ѵ�
		m_BigImageList.Draw(&dc, lpDrawItemStruct->itemData, ptIcon, ILD_NORMAL);
		// ����̺� �̸��� ����� �� �ֵ��� ��ǥ�� �����Ѵ�
		rcItem.left += m_szBigIcon.cx + CONST_ITEM_GAP;
	}
	else
	{
		ptIcon.y = rcItem.top + (rcItem.Height() - m_szSmallIcon.cy) / 2;
		// ���� ����̺� �������� ����Ѵ�
		m_SmallImageList.Draw(&dc, lpDrawItemStruct->itemData, ptIcon, ILD_NORMAL);
		// ����̺� �̸��� ����� �� �ֵ��� ��ǥ�� �����Ѵ�
		rcItem.left += m_szSmallIcon.cx + CONST_ITEM_GAP;
	}

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
	// �ؽ�Ʈ�� ���� �߾ӿ� ����Ѵ�
	dc.DrawText(strText, rcItem, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	
	// ��Ʈ�� ��ȯ�Ѵ�
	dc.SelectObject(pOldFont);
	dc.Detach();
}

void CDriveComboBox::OnDestroy() 
{
	CComboBox::OnDestroy();
	
	// �����ߴ� �� �̹��� ����Ʈ���� Detach�Ѵ�
	m_BigImageList.Detach();
	m_SmallImageList.Detach();
}

BOOL CDriveComboBox::SetBigIcon(BOOL bBig)
{
	// ���� ���� ������ ũ��� ���ٸ� �����Ѵ�
	if(m_bBigIcon == bBig)		return m_bBigIcon;
	
	// ���ο� ������ ũ�⸦ �����Ѵ�
	m_bBigIcon = bBig;

	// ���ο� ������ ũ�⿡ ���� �׸��� ũ�⸦ �����Ѵ�
	SetItemHeight(-1, (m_bBigIcon ? m_szBigIcon.cy : m_szSmallIcon.cy) + CONST_ITEM_GAP);
	SetItemHeight(0, (m_bBigIcon ? m_szBigIcon.cy : m_szSmallIcon.cy) + CONST_ITEM_GAP);

	// ���ο� ������ ũ�⸦ �����Ѵ�
	return m_bBigIcon;
}
