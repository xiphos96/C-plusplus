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
	// ��� ���� �ʱ�ȭ
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

	// 32 * 32 ũ���� �ý��� �̹��� ����Ʈ�� ��´�
	HIMAGELIST hLargeIcon = (HIMAGELIST)::SHGetFileInfo("c:\\", 0, &ShellFileInfo, sizeof(SHFILEINFO),
		SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
	// 16 * 16 ũ���� �ý��� �̹��� ����Ʈ�� ��´�
	HIMAGELIST hSmallIcon = (HIMAGELIST)::SHGetFileInfo("c:\\", 0, &ShellFileInfo, sizeof(SHFILEINFO),
		SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_SMALLICON);

	// �̹��� ����Ʈ �ڵ�� �̹��� ����Ʈ ��ü�� �����
	CImageList LargeImageList, SmallImageList;
	LargeImageList.Attach(hLargeIcon);
	SmallImageList.Attach(hSmallIcon);

	// Ž���� ����Ʈ ��Ʈ�ѿ� �ý��� �̹��� ����Ʈ�� �����Ѵ�
	SetImageList(&LargeImageList, LVSIL_NORMAL);
	SetImageList(&SmallImageList, LVSIL_SMALL);

	// �̹��� ����Ʈ ��ü���� �̹��� ����Ʈ �ڵ��� Detach() �Ѵ�
	LargeImageList.Detach();
	SmallImageList.Detach();

	CRect rcClient;
	GetClientRect(&rcClient);

	InsertColumn(0, "���ϸ�", LVCFMT_LEFT, rcClient.Width());

	// Ž���� ����Ʈ ��Ʈ���� �ٽ� �����Ѵ�
	RefreshExplorer();

	CListCtrl::PreSubclassWindow();
}

// ���� ����̺긦 �����ϴ� �Լ�
void CExplorerListCtrl::ChangeDrive(LPCTSTR pDrive)
{
	m_strDrive = pDrive;
	m_strCurPath = m_strDrive;

	RefreshExplorer();
}

// ���� ������ �����ϴ� �Լ�
void CExplorerListCtrl::ChangeFolder(LPCTSTR pFolder)
{
	CString strFolder = pFolder;

	if(strFolder.Find(":\\") < 0)		return;

	// ����̺� �̸��� ��´�
	m_strDrive = strFolder.Left(strFolder.Find(":\\") + 2);

	// ��ο� '\' ���ڰ� ���� ��� �߰��Ѵ�
	if(strFolder.GetAt(strFolder.GetLength() - 1) != '\\')
		strFolder += "\\";
	// ���� ������ �����Ѵ�
	m_strCurPath = strFolder;

	// Ž���� ����Ʈ ��Ʈ���� �ٽ� �����Ѵ�
	RefreshExplorer();
}

// �Ѵܰ� ���� ������ �̵��ϴ� �Լ�
BOOL CExplorerListCtrl::GoUp()
{
	// ���� ����� ������ '\'�� �����Ѵ�
	CString strFolder = m_strCurPath.Left(m_strCurPath.GetLength() - 1);
	
	// ������ ��θ� �����ϴ� '\' ��ġ�� ã�´�
	int nPrev = strFolder.ReverseFind('\\');
	if(nPrev < 0)		return FALSE;

	// ������ ��θ� ������ ���� ������ ��θ� �����
	m_strCurPath = strFolder.Left(nPrev + 1);

	// Ž���� ����Ʈ ��Ʈ���� �ٽ� �����Ѵ�
	RefreshExplorer();

	return TRUE;
}

// Ž���� ����Ʈ ��Ʈ�ѿ��� �������� �����ֵ��� �����ϴ� �Լ�
void CExplorerListCtrl::SetFolderOnly(BOOL bOnly)
{
	// ���� ���� ������ ���� �����Ѵ�
	m_bFolderOnly = bOnly;

	// Ž���� ����Ʈ ��Ʈ���� �ٽ� �����Ѵ�
	RefreshExplorer();
}

// ���� ���õ� �׸��� �������� �����ϴ� �Լ�
BOOL CExplorerListCtrl::IsFolder()
{
	POSITION pos = GetFirstSelectedItemPosition();

	if(pos == NULL)		return FALSE;
	int nItem = GetNextSelectedItem(pos);

	DWORD dwData = (DWORD)GetItemData(nItem);

	return (dwData & FILE_ATTRIBUTE_DIRECTORY);
}

// ���� ���õ� �׸��� �������� �����ϴ� �Լ�
BOOL CExplorerListCtrl::IsFile()
{
	POSITION pos = GetFirstSelectedItemPosition();

	if(pos == NULL)		return FALSE;
	int nItem = GetNextSelectedItem(pos);

	DWORD dwData = (DWORD)GetItemData(nItem);

	return !(dwData & FILE_ATTRIBUTE_DIRECTORY);
}

// ���� ���õ� ������ ��θ� �����ϴ� �Լ�
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

// ���� ���õ� ������ ��θ� �����ϴ� �Լ�
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

// Ž���� ����Ʈ ��Ʈ���� �ٽ� �����ϴ� �Լ�
void CExplorerListCtrl::RefreshExplorer()
{
	// ����Ʈ ��Ʈ���� ������ ������Ų��
	LockWindowUpdate();

	// ��� �׸��� �����Ѵ�
	DeleteAllItems();

	// ã�� ���͸� �����Ѵ�
	CString strFilter;
	strFilter.Format("%s*.*", m_strCurPath);

	CFileFind ff;
	BOOL bContinue;
	int i, nItem, nImage;

	// ���Ϳ� �´� �����̳� ������ ã�´�
	bContinue = ff.FindFile(strFilter);
	for(i = 0; bContinue; )
	{
		bContinue = ff.FindNextFile();

		// '.' Ȥ�� '..' ���丮�� ó������ �ʴ´�
		if(ff.IsDots())								continue;
		// �������� ����ϴ� �ɼ��� ��� ������ ã���� ���� ó������ �ʴ´�
		if(!ff.IsDirectory() && m_bFolderOnly)		continue;

		// ���� Ȥ�� ������ �ý��� �̹��� ��ȣ�� ã�´�
		nImage = FindIconIndex(ff.GetFilePath(), ff.IsDirectory());
		// ã���� ������ ������ �̸��� �ý��� �̹����� �Բ� �׸����� �߰��Ѵ�
		nItem = InsertItem(i, ff.GetFileName(), nImage);
		// ������ ������ �Ӽ��� �׸��� �����ͷ� �����Ѵ�
		SetItemData(nItem, ::GetFileAttributes(ff.GetFilePath()));

		i++;
	}
	ff.Close();

	// �߰��� �׸���� �����Ѵ�
	Sort();

	// ����Ʈ ��Ʈ���� ������ �簳�Ѵ�
	UnlockWindowUpdate();
}

// Ư�� �����̳� ������ �ý��� ������ ��ȣ�� �����ϴ� �Լ�
int CExplorerListCtrl::FindIconIndex(LPCTSTR pName, BOOL bIsDirectory)
{
	SHFILEINFO		ShellFileInfo;
	LONG nStyle;

	// ������ ��Ÿ���� ���Ѵ�
	nStyle = ::GetWindowLong(m_hWnd, GWL_STYLE);

	// ���� ������ ���� ����� 32 * 32 ũ���� �ý��� �̹��� ����Ʈ���� �ش� �����̳� ������ ������ ��ȣ�� ã�´�
	if(nStyle & LVS_ICON)
		::SHGetFileInfo(pName, bIsDirectory ? FILE_ATTRIBUTE_DIRECTORY : FILE_ATTRIBUTE_NORMAL,
			&ShellFileInfo, sizeof(SHFILEINFO),
			SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
	else
		// 16 * 16 ũ���� �ý��� �̹��� ����Ʈ���� �ش� �����̳� ������ ������ ��ȣ�� ã�´�
		::SHGetFileInfo(pName, bIsDirectory ? FILE_ATTRIBUTE_DIRECTORY : FILE_ATTRIBUTE_NORMAL,
			&ShellFileInfo, sizeof(SHFILEINFO),
			SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_SMALLICON);

	// ã���� ������ ��ȣ�� �����Ѵ�
	return ShellFileInfo.iIcon;
}

// ���� �Լ�
void CExplorerListCtrl::Sort()
{
	// ���� ������ �������� �����Ѵ�
	Sort(m_bSortAscending, m_bSortByExt);
}

// ���� �Լ�
void CExplorerListCtrl::Sort(BOOL bAscending, BOOL bExt)
{
	m_bSortAscending	= bAscending;
	m_bSortByExt		= bExt;

	// �� ������ �����Ѵ�
	QuickSort(0, GetItemCount() - 1);
}

// ������ �Լ�
void CExplorerListCtrl::QuickSort(int nStart, int nEnd)
{
	// ���� ���� ��ȣ�� �� ��ȣ���� ���� �ʴٸ� ����
	if(nStart >= nEnd)		return;

	// ù �׸��� �������� ū ���� ���� ���� �����Ͽ� �� �κ����� ������
	int nHalf = Partition(nStart, nEnd);

	// ���ؿ� ���� ���� �κп� ���� �ٽ� �� ������ �����Ѵ�
	QuickSort(nStart, nHalf - 1);
	// ���ؿ� ���� ���� �κп� ���� �ٽ� �� ������ �����Ѵ�
	QuickSort(nHalf + 1, nEnd);
}

// ���� ���� �߽����� ū ���� ���� ������ ������ �Լ�
int CExplorerListCtrl::Partition(int nStart, int nEnd)
{
	BOOL bContinue;
	CString strItem;
	// ù �׸��� �������� ���, �ؽ�Ʈ�� �׸� ��ȣ�� �����Ѵ�
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

	// ���� ��ȣ�� �� ��ȣ���� ���� ���� �����Ѵ�
	for(; nStart < nEnd;)
	{
		// ���� �ٷ� �ں���
		// �����������Ľ� ���� ������ ū �׸��� ã�´�
		// �����������Ľ� ���� ������ ���� �׸��� ã�´�
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
		// �� ��ȣ����
		// �����������Ľ� ���� ������ ���� �׸��� ã�´�
		// �����������Ľ� ���� ������ ū �׸��� ã�´�
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

		// ū �׸�� ���� �׸��� ã�Ұ� ���� ��ȣ�� �� ��ȣ���� ������
		if(nStart < nEnd)
		{
			// ū �׸�� ���� �׸��� ��ġ�� �ٲ۴�
			Swap(nStart, nEnd);
		}
		else
		{
			// ���� ���� ������ ������ �̵��ϴ� �׸��� ��ġ�� �ٲ۴�
			Swap(nBase, nEnd);
		}
	}

	return nEnd;
}

// �� �׸��� �� �ٲٴ� �Լ�
void CExplorerListCtrl::Swap(int nItem1, int nItem2)
{
	// �ٲ� �� �׸��� ��ȣ�� ���ٸ� ����
	if(nItem1 == nItem2)			return;

	// �÷� ������ ��´�
	int nColSize = GetHeaderCtrl()->GetItemCount(), i;

	LVITEM Item1, Item2;
	CString strItem1, strItem2;

	// ��� �÷��� ���� �����Ѵ�
	for(i = 0; i < nColSize; i++)
	{
		// �� �׸��� �ؽ�Ʈ�� �д´�
		strItem1 = GetItemText(nItem1, i);
		strItem2 = GetItemText(nItem2, i);

		// �� �׸��� �Ӽ��� �д´�
		Item1.mask	= LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
		Item1.iItem = nItem1;
		Item1.iSubItem = i;
		Item1.stateMask = LVIS_CUT | LVIS_DROPHILITED |	LVIS_FOCUSED | LVIS_SELECTED | LVIS_OVERLAYMASK | LVIS_STATEIMAGEMASK;
		
		Item2 = Item1;
		Item2.iItem = nItem2;

		GetItem(&Item1);
		GetItem(&Item2);

		// �� �׸��� �ؽ�Ʈ�� �ٲ۴�
		SetItemText(nItem1, i, strItem2);
		SetItemText(nItem2, i, strItem1);

		// �� �׸��� �Ӽ��� �ٲ۴�
		Item1.iItem = nItem2;
		Item2.iItem = nItem1;

		SetItem(&Item1);
		SetItem(&Item2);
	}
}

// �׸��� ����Ŭ���� ���
void CExplorerListCtrl::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	*pResult = 0;

	// ���� ���õ� �׸��� ������ �ƴ϶��
	if(!IsFolder())
	{
		// �θ� �����찡 �ְ� ������ ���õǾ��ٸ�
		if(IsFile() && GetParent())
		{
			CString strFile;

			// ���õ� ������ ��θ� ��´�
			GetSelectedFile(strFile);
			// �θ� �����쿡�� ������ ��θ� �޽����� ������
			GetParent()->SendMessage(WM_EXPLORER_FILE_SELECT, GetDlgCtrlID(), LPARAM(LPCTSTR(strFile)));
		}
		return;
	}

	CString strNewPath;
	// ���õ� ������ ��θ� ��´�
	GetSelectedFolder(strNewPath);

	// ���õ� ������ ���� ���丮�� �����Ѵ�
	m_strCurPath = strNewPath;

	// Ž���� ����Ʈ ��Ʈ���� �ٽ� �����Ѵ�
	RefreshExplorer();
}
