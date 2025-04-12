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
	// 멤버 변수들을 초기화한다
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

	// 큰 쉘 아이콘 이미지 리스트를 얻는다
	hShellImage = (HIMAGELIST)::SHGetFileInfo("c:\\", 0, &ShellFileInfo, sizeof(SHFILEINFO),
		SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
	// 이미지 리스트에 Attach한다
	m_BigImageList.Attach(hShellImage);
	// 이미지 리스트의 배경을 투명으로 설정한다
	m_BigImageList.SetBkColor(CLR_NONE);
	// 첫번째 이미지의 이미지 정보를 얻는다
	m_BigImageList.GetImageInfo(0, &ImageInfo);
	// 이미지의 수평/수직 크기를 저장한다
	m_szBigIcon.cx = ImageInfo.rcImage.right - ImageInfo.rcImage.left;
	m_szBigIcon.cy = ImageInfo.rcImage.bottom - ImageInfo.rcImage.top;

	// 작은 쉘 아이콘 이미지 리스트를 얻는다
	hShellImage = (HIMAGELIST)::SHGetFileInfo("c:\\", 0, &ShellFileInfo, sizeof(SHFILEINFO),
		SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_SMALLICON);
	// 이미지 리스트에 Attach한다
	m_SmallImageList.Attach(hShellImage);
	// 이미지 리스트의 배경을 투명으로 설정한다
	m_SmallImageList.SetBkColor(CLR_NONE);
	// 첫번째 이미지의 이미지 정보를 얻는다
	m_SmallImageList.GetImageInfo(0, &ImageInfo);
	// 이미지의 수평/수직 크기를 저장한다
	m_szSmallIcon.cx = ImageInfo.rcImage.right - ImageInfo.rcImage.left;
	m_szSmallIcon.cy = ImageInfo.rcImage.bottom - ImageInfo.rcImage.top;

	// 시스템의 드라이브 비트 마스크를 얻는다
	DWORD dwDrive = ::GetLogicalDrives();
	int i;

	// 시스템의 드라이브 갯수를 센다
	for(i = 0; i < 32; i++)
	{
		if(dwDrive & ((DWORD)0x01 << i))		m_nDriveCount++;
	}

	// 드라이브 이름을 얻을 버퍼를 만든다
	char *pDriveName = new char[m_nDriveCount * 4 + 1];
	// 드라이브 이름 배열을 얻는다
	::GetLogicalDriveStrings(m_nDriveCount * 4 + 1, pDriveName);
	
	int nDrive;
	// 모든 드라이브에 대해
	for(i = 0; i < m_nDriveCount; i++)
	{
		// 드라이브의 아이콘 정보를 얻는다
		::SHGetFileInfo(pDriveName + i * 4, FILE_ATTRIBUTE_DIRECTORY,
			&ShellFileInfo, sizeof(SHFILEINFO),
			SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_LARGEICON);

		// 드라이브 이름을 콤보 박스에 추가한다
		nDrive = AddString(pDriveName + i * 4);
		// 드라이브 아이콘 번호를 저장한다
		SetItemData(nDrive, ShellFileInfo.iIcon);
	}

	// 드라이브 이름 버퍼를 삭제한다
	delete[] pDriveName;

	// 현재 아이콘 크기에 따라 항목의 크기를 설정한다
	SetItemHeight(-1, (m_bBigIcon ? m_szBigIcon.cy : m_szSmallIcon.cy) + CONST_ITEM_GAP);
	SetItemHeight(0, (m_bBigIcon ? m_szBigIcon.cy : m_szSmallIcon.cy) + CONST_ITEM_GAP);

	CComboBox::PreSubclassWindow();
}

void CDriveComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
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

	// 아이콘이 출력될 위치를 계산한다
	CPoint ptIcon = rcItem.TopLeft();
	ptIcon.x = CONST_ITEM_GAP / 2;
	if(m_bBigIcon)
	{
		ptIcon.y = rcItem.top + (rcItem.Height() - m_szBigIcon.cy) / 2;
		// 큰 드라이브 아이콘을 출력한다
		m_BigImageList.Draw(&dc, lpDrawItemStruct->itemData, ptIcon, ILD_NORMAL);
		// 드라이브 이름을 출력할 수 있도록 좌표를 조정한다
		rcItem.left += m_szBigIcon.cx + CONST_ITEM_GAP;
	}
	else
	{
		ptIcon.y = rcItem.top + (rcItem.Height() - m_szSmallIcon.cy) / 2;
		// 작은 드라이브 아이콘을 출력한다
		m_SmallImageList.Draw(&dc, lpDrawItemStruct->itemData, ptIcon, ILD_NORMAL);
		// 드라이브 이름을 출력할 수 있도록 좌표를 조정한다
		rcItem.left += m_szSmallIcon.cx + CONST_ITEM_GAP;
	}

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
	// 텍스트를 수직 중앙에 출력한다
	dc.DrawText(strText, rcItem, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	
	// 폰트를 반환한다
	dc.SelectObject(pOldFont);
	dc.Detach();
}

void CDriveComboBox::OnDestroy() 
{
	CComboBox::OnDestroy();
	
	// 저장했던 쉘 이미지 리스트들을 Detach한다
	m_BigImageList.Detach();
	m_SmallImageList.Detach();
}

BOOL CDriveComboBox::SetBigIcon(BOOL bBig)
{
	// 만약 현재 아이콘 크기와 같다면 리턴한다
	if(m_bBigIcon == bBig)		return m_bBigIcon;
	
	// 새로운 아이콘 크기를 설정한다
	m_bBigIcon = bBig;

	// 새로운 아이콘 크기에 맞춰 항목의 크기를 조정한다
	SetItemHeight(-1, (m_bBigIcon ? m_szBigIcon.cy : m_szSmallIcon.cy) + CONST_ITEM_GAP);
	SetItemHeight(0, (m_bBigIcon ? m_szBigIcon.cy : m_szSmallIcon.cy) + CONST_ITEM_GAP);

	// 새로운 아이콘 크기를 리턴한다
	return m_bBigIcon;
}
