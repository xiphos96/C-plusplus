// ExplorerListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "explorerlistctrldemo.h"
#include "ExplorerListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExplorerListCtrl

CExplorerListCtrl::CExplorerListCtrl()
{
	// 멤버 변수 초기화
	m_bFolderOnly		= FALSE;
	m_bSortByExt		= TRUE;
	m_bSortAscending	= TRUE;

	m_strDrive			= "C:\\";
	m_strCurPath		= m_strDrive;
}

CExplorerListCtrl::~CExplorerListCtrl()
{
}


BEGIN_MESSAGE_MAP(CExplorerListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CExplorerListCtrl)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExplorerListCtrl message handlers

void CExplorerListCtrl::PreSubclassWindow() 
{
	SHFILEINFO		ShellFileInfo;

	// 32 * 32 크기의 시스템 이미지 리스트를 얻는다
	HIMAGELIST hLargeIcon = (HIMAGELIST)::SHGetFileInfo("c:\\", 0, &ShellFileInfo, sizeof(SHFILEINFO),
		SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
	// 16 * 16 크기의 시스템 이미지 리스트를 얻는다
	HIMAGELIST hSmallIcon = (HIMAGELIST)::SHGetFileInfo("c:\\", 0, &ShellFileInfo, sizeof(SHFILEINFO),
		SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_SMALLICON);

	// 이미지 리스트 핸들로 이미지 리스트 객체를 만든다
	CImageList LargeImageList, SmallImageList;
	LargeImageList.Attach(hLargeIcon);
	SmallImageList.Attach(hSmallIcon);

	// 탐색기 리스트 컨트롤에 시스템 이미지 리스트를 설정한다
	SetImageList(&LargeImageList, LVSIL_NORMAL);
	SetImageList(&SmallImageList, LVSIL_SMALL);

	// 이미지 리스트 객체에서 이미지 리스트 핸들을 Detach() 한다
	LargeImageList.Detach();
	SmallImageList.Detach();

	CRect rcClient;
	GetClientRect(&rcClient);

	InsertColumn(0, "파일명", LVCFMT_LEFT, rcClient.Width());

	// 탐색기 리스트 컨트롤을 다시 구성한다
	RefreshExplorer();

	CListCtrl::PreSubclassWindow();
}

// 현재 드라이브를 변경하는 함수
void CExplorerListCtrl::ChangeDrive(LPCTSTR pDrive)
{
	m_strDrive = pDrive;
	m_strCurPath = m_strDrive;

	RefreshExplorer();
}

// 현재 폴더를 변경하는 함수
void CExplorerListCtrl::ChangeFolder(LPCTSTR pFolder)
{
	CString strFolder = pFolder;

	if(strFolder.Find(":\\") < 0)		return;

	// 드라이브 이름을 얻는다
	m_strDrive = strFolder.Left(strFolder.Find(":\\") + 2);

	// 경로에 '\' 문자가 없을 경우 추가한다
	if(strFolder.GetAt(strFolder.GetLength() - 1) != '\\')
		strFolder += "\\";
	// 현재 폴더로 저장한다
	m_strCurPath = strFolder;

	// 탐색기 리스트 컨트롤을 다시 구성한다
	RefreshExplorer();
}

// 한단계 위의 폴더로 이동하는 함수
BOOL CExplorerListCtrl::GoUp()
{
	// 현재 경로의 마지막 '\'를 제거한다
	CString strFolder = m_strCurPath.Left(m_strCurPath.GetLength() - 1);
	
	// 마지막 경로를 구분하는 '\' 위치를 찾는다
	int nPrev = strFolder.ReverseFind('\\');
	if(nPrev < 0)		return FALSE;

	// 마지막 경로를 빼내어 상위 폴더의 경로를 만든다
	m_strCurPath = strFolder.Left(nPrev + 1);

	// 탐색기 리스트 컨트롤을 다시 구성한다
	RefreshExplorer();

	return TRUE;
}

// 탐색기 리스트 컨트롤에서 폴더만을 보여주도록 설정하는 함수
void CExplorerListCtrl::SetFolderOnly(BOOL bOnly)
{
	// 폴더 전용 변수의 값을 변경한다
	m_bFolderOnly = bOnly;

	// 탐색기 리스트 컨트롤을 다시 구성한다
	RefreshExplorer();
}

// 현재 선택된 항목이 폴더인지 리턴하는 함수
BOOL CExplorerListCtrl::IsFolder()
{
	POSITION pos = GetFirstSelectedItemPosition();

	if(pos == NULL)		return FALSE;
	int nItem = GetNextSelectedItem(pos);

	DWORD dwData = (DWORD)GetItemData(nItem);

	return (dwData & FILE_ATTRIBUTE_DIRECTORY);
}

// 현재 선택된 항목이 파일인지 리턴하는 함수
BOOL CExplorerListCtrl::IsFile()
{
	POSITION pos = GetFirstSelectedItemPosition();

	if(pos == NULL)		return FALSE;
	int nItem = GetNextSelectedItem(pos);

	DWORD dwData = (DWORD)GetItemData(nItem);

	return !(dwData & FILE_ATTRIBUTE_DIRECTORY);
}

// 현재 선택된 폴더의 경로를 리턴하는 함수
BOOL CExplorerListCtrl::GetSelectedFolder(CString &strFolder)
{
	POSITION pos = GetFirstSelectedItemPosition();

	if(pos == NULL)		return FALSE;
	int nItem = GetNextSelectedItem(pos);

	DWORD dwData = (DWORD)GetItemData(nItem);

	if(!(dwData & FILE_ATTRIBUTE_DIRECTORY))		return FALSE;

	strFolder.Format("%s%s\\", m_strCurPath, GetItemText(nItem, 0));

	return TRUE;
}

// 현재 선택된 파일의 경로를 리턴하는 함수
BOOL CExplorerListCtrl::GetSelectedFile(CString &strFile)
{
	POSITION pos = GetFirstSelectedItemPosition();

	if(pos == NULL)		return FALSE;
	int nItem = GetNextSelectedItem(pos);

	DWORD dwData = (DWORD)GetItemData(nItem);

	if(dwData & FILE_ATTRIBUTE_DIRECTORY)		return FALSE;

	strFile.Format("%s%s", m_strCurPath, GetItemText(nItem, 0));

	return TRUE;
}

// 탐색기 리스트 컨트롤을 다시 구성하는 함수
void CExplorerListCtrl::RefreshExplorer()
{
	// 리스트 컨트롤의 갱신을 정지시킨다
	LockWindowUpdate();

	// 모든 항목을 제거한다
	DeleteAllItems();

	// 찾기 필터를 정의한다
	CString strFilter;
	strFilter.Format("%s*.*", m_strCurPath);

	CFileFind ff;
	BOOL bContinue;
	int i, nItem, nImage;

	// 필터에 맞는 파일이나 폴더를 찾는다
	bContinue = ff.FindFile(strFilter);
	for(i = 0; bContinue; )
	{
		bContinue = ff.FindNextFile();

		// '.' 혹은 '..' 디렉토리는 처리하지 않는다
		if(ff.IsDots())								continue;
		// 폴더만을 출력하는 옵션의 경우 파일을 찾았을 때는 처리하지 않는다
		if(!ff.IsDirectory() && m_bFolderOnly)		continue;

		// 폴더 혹은 파일의 시스템 이미지 번호를 찾는다
		nImage = FindIconIndex(ff.GetFilePath(), ff.IsDirectory());
		// 찾아진 폴더나 파일의 이름을 시스템 이미지와 함께 항목으로 추가한다
		nItem = InsertItem(i, ff.GetFileName(), nImage);
		// 폴더나 파일의 속성을 항목의 데이터로 설정한다
		SetItemData(nItem, ::GetFileAttributes(ff.GetFilePath()));

		i++;
	}
	ff.Close();

	// 추가된 항목들을 정렬한다
	Sort();

	// 리스트 컨트롤의 갱신을 재개한다
	UnlockWindowUpdate();
}

// 특정 파일이나 폴더의 시스템 아이콘 번호를 리턴하는 함수
int CExplorerListCtrl::FindIconIndex(LPCTSTR pName, BOOL bIsDirectory)
{
	SHFILEINFO		ShellFileInfo;
	LONG nStyle;

	// 윈도우 스타일을 구한다
	nStyle = ::GetWindowLong(m_hWnd, GWL_STYLE);

	// 만약 아이콘 보기 모드라면 32 * 32 크기의 시스템 이미지 리스트에서 해당 파일이나 폴더의 아이콘 번호를 찾는다
	if(nStyle & LVS_ICON)
		::SHGetFileInfo(pName, bIsDirectory ? FILE_ATTRIBUTE_DIRECTORY : FILE_ATTRIBUTE_NORMAL,
			&ShellFileInfo, sizeof(SHFILEINFO),
			SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
	else
		// 16 * 16 크기의 시스템 이미지 리스트에서 해당 파일이나 폴더의 아이콘 번호를 찾는다
		::SHGetFileInfo(pName, bIsDirectory ? FILE_ATTRIBUTE_DIRECTORY : FILE_ATTRIBUTE_NORMAL,
			&ShellFileInfo, sizeof(SHFILEINFO),
			SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_SMALLICON);

	// 찾아진 아이콘 번호를 리턴한다
	return ShellFileInfo.iIcon;
}

// 정렬 함수
void CExplorerListCtrl::Sort()
{
	// 현재 설정된 조건으로 정렬한다
	Sort(m_bSortAscending, m_bSortByExt);
}

// 정렬 함수
void CExplorerListCtrl::Sort(BOOL bAscending, BOOL bExt)
{
	m_bSortAscending	= bAscending;
	m_bSortByExt		= bExt;

	// 퀵 정렬을 실행한다
	QuickSort(0, GetItemCount() - 1);
}

// 퀵정렬 함수
void CExplorerListCtrl::QuickSort(int nStart, int nEnd)
{
	// 만약 시작 번호가 끝 번호보다 작지 않다면 리턴
	if(nStart >= nEnd)		return;

	// 첫 항목을 기준으로 큰 값과 작은 값을 구별하여 두 부분으로 나눈다
	int nHalf = Partition(nStart, nEnd);

	// 기준에 대한 앞쪽 부분에 대해 다시 퀵 정렬을 실행한다
	QuickSort(nStart, nHalf - 1);
	// 기준에 대한 뒤쪽 부분에 대해 다시 퀵 정렬을 실행한다
	QuickSort(nHalf + 1, nEnd);
}

// 기준 값을 중심으로 큰 값과 작은 값으로 나누는 함수
int CExplorerListCtrl::Partition(int nStart, int nEnd)
{
	BOOL bContinue;
	CString strItem;
	// 첫 항목을 기준으로 삼아, 텍스트와 항목 번호를 저장한다
	CString strBase = GetItemText(nStart, 0);
	CString strBaseExt, strItemExt;
	DWORD dwBaseData, dwItemData;
	int nBase = nStart;
	int nMax = ++nEnd;
	int nDot;

	if(m_bSortByExt)
	{
		nDot = strBase.ReverseFind('.');
		if(nDot >= 0)		strBaseExt = strBase.Right(strBase.GetLength() - nDot - 1);
	}
	else
		strBaseExt = strBase;
	dwBaseData = (DWORD)GetItemData(nStart);

	// 시작 번호가 끝 번호보다 작은 동안 실행한다
	for(; nStart < nEnd;)
	{
		// 기준 바로 뒤부터
		// 오름차순정렬시 기준 값보다 큰 항목을 찾는다
		// 내림차순정렬시 기준 값보다 작은 항목을 찾는다
		for(bContinue = TRUE; bContinue && nStart < nMax - 1;)
		{
			nStart++;
			strItem = GetItemText(nStart, 0);
			dwItemData = (DWORD)GetItemData(nStart);

			if(m_bSortByExt)
			{
				nDot = strItem.ReverseFind('.');
				if(nDot < 0)	strItemExt.Empty();
				else			strItemExt = strItem.Right(strItem.GetLength() - nDot - 1);
			}
			else
				strItemExt = strItem;

			if(m_bSortAscending)
			{
				if(strBaseExt.CompareNoCase(strItemExt) == 0)
				{
					if(strBaseExt.IsEmpty())
					{
						if((dwBaseData & FILE_ATTRIBUTE_DIRECTORY) == (dwItemData & FILE_ATTRIBUTE_DIRECTORY))
							bContinue = strBase.CompareNoCase(strItem) > 0;
						else
							if(dwBaseData & FILE_ATTRIBUTE_DIRECTORY)		bContinue = FALSE;
							else											bContinue = TRUE;
					}
					else
						bContinue = strBase.CompareNoCase(strItem) > 0;
				}
				else
					bContinue = strBaseExt.CompareNoCase(strItemExt) > 0;
			}
			else
			{
				if(strBaseExt.CompareNoCase(strItemExt) == 0)
				{
					if(strBaseExt.IsEmpty())
					{
						if((dwBaseData & FILE_ATTRIBUTE_DIRECTORY) == (dwItemData & FILE_ATTRIBUTE_DIRECTORY))
							bContinue = strBase.CompareNoCase(strItem) < 0;
						else
							if(dwBaseData & FILE_ATTRIBUTE_DIRECTORY)	bContinue = FALSE;
							else										bContinue = TRUE;
					}
					else
						bContinue = strBase.CompareNoCase(strItem) < 0;
				}
				else
					bContinue = strBaseExt.CompareNoCase(strItemExt) < 0;
			}
		}
		// 끝 번호부터
		// 오름차순정렬시 기준 값보다 작은 항목을 찾는다
		// 내림차순정렬시 기준 값보다 큰 항목을 찾는다
		for(bContinue = TRUE; bContinue;)
		{
			nEnd--;
			strItem = GetItemText(nEnd, 0);
			dwItemData = (DWORD)GetItemData(nEnd);

			if(m_bSortByExt)
			{
				nDot = strItem.ReverseFind('.');
				if(nDot < 0)	strItemExt.Empty();
				else			strItemExt = strItem.Right(strItem.GetLength() - nDot - 1);
			}
			else
				strItemExt = strItem;

			if(m_bSortAscending)
			{
				if(strBaseExt.CompareNoCase(strItemExt) == 0)
				{
					if(strBaseExt.IsEmpty())
					{
						if((dwBaseData & FILE_ATTRIBUTE_DIRECTORY) == (dwItemData & FILE_ATTRIBUTE_DIRECTORY))
							bContinue = strBase.CompareNoCase(strItem) < 0;
						else
							if(dwItemData & FILE_ATTRIBUTE_DIRECTORY)	bContinue = FALSE;
							else										bContinue = TRUE;
					}
					else
						bContinue = strBase.CompareNoCase(strItem) < 0;
				}
				else
					bContinue = strBaseExt.CompareNoCase(strItemExt) < 0;
			}
			else
			{
				if(strBaseExt.CompareNoCase(strItemExt) == 0)
				{
					if(strBaseExt.IsEmpty())
					{
						if((dwBaseData & FILE_ATTRIBUTE_DIRECTORY) == (dwItemData & FILE_ATTRIBUTE_DIRECTORY))
							bContinue = strBase.CompareNoCase(strItem) > 0;
						else
							if(dwItemData & FILE_ATTRIBUTE_DIRECTORY)	bContinue = FALSE;
							else										bContinue = TRUE;
					}
					else
						bContinue = strBase.CompareNoCase(strItem) > 0;
				}
				else
					bContinue = strBaseExt.CompareNoCase(strItemExt) > 0;
			}
		}

		// 큰 항목과 작은 항목을 찾았고 시작 번호가 끝 번호보다 작으면
		if(nStart < nEnd)
		{
			// 큰 항목과 작은 항목의 위치를 바꾼다
			Swap(nStart, nEnd);
		}
		else
		{
			// 기준 값과 끝에서 앞으로 이동하던 항목의 위치를 바꾼다
			Swap(nBase, nEnd);
		}
	}

	return nEnd;
}

// 두 항목을 맞 바꾸는 함수
void CExplorerListCtrl::Swap(int nItem1, int nItem2)
{
	// 바꿀 두 항목의 번호가 같다면 리턴
	if(nItem1 == nItem2)			return;

	// 컬럼 갯수를 얻는다
	int nColSize = GetHeaderCtrl()->GetItemCount(), i;

	LVITEM Item1, Item2;
	CString strItem1, strItem2;

	// 모든 컬럼에 대해 수행한다
	for(i = 0; i < nColSize; i++)
	{
		// 두 항목의 텍스트를 읽는다
		strItem1 = GetItemText(nItem1, i);
		strItem2 = GetItemText(nItem2, i);

		// 두 항목의 속성을 읽는다
		Item1.mask	= LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
		Item1.iItem = nItem1;
		Item1.iSubItem = i;
		Item1.stateMask = LVIS_CUT | LVIS_DROPHILITED |	LVIS_FOCUSED | LVIS_SELECTED | LVIS_OVERLAYMASK | LVIS_STATEIMAGEMASK;
		
		Item2 = Item1;
		Item2.iItem = nItem2;

		GetItem(&Item1);
		GetItem(&Item2);

		// 두 항목의 텍스트를 바꾼다
		SetItemText(nItem1, i, strItem2);
		SetItemText(nItem2, i, strItem1);

		// 두 항목의 속성을 바꾼다
		Item1.iItem = nItem2;
		Item2.iItem = nItem1;

		SetItem(&Item1);
		SetItem(&Item2);
	}
}

// 항목이 더블클릭된 경우
void CExplorerListCtrl::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	*pResult = 0;

	// 만약 선택된 항목이 폴더가 아니라면
	if(!IsFolder())
	{
		// 부모 윈도우가 있고 파일이 선택되었다면
		if(IsFile() && GetParent())
		{
			CString strFile;

			// 선택된 파일의 경로를 얻는다
			GetSelectedFile(strFile);
			// 부모 윈도우에게 파일의 경로를 메시지로 보낸다
			GetParent()->SendMessage(WM_EXPLORER_FILE_SELECT, GetDlgCtrlID(), LPARAM(LPCTSTR(strFile)));
		}
		return;
	}

	CString strNewPath;
	// 선택된 폴더의 경로를 얻는다
	GetSelectedFolder(strNewPath);

	// 선택된 폴더를 현재 디렉토리로 설정한다
	m_strCurPath = strNewPath;

	// 탐색기 리스트 컨트롤을 다시 구성한다
	RefreshExplorer();
}
