// ExplorerTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "explorertreectrldemo.h"
#include "ExplorerTreeCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExplorerTreeCtrl

CExplorerTreeCtrl::CExplorerTreeCtrl()
{
	// �޸� ������ ����
	::SHGetMalloc(&m_pMalloc);
}

CExplorerTreeCtrl::~CExplorerTreeCtrl()
{
	// �޸� ������ �Ҹ�
	m_pMalloc->Release();
}


BEGIN_MESSAGE_MAP(CExplorerTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CExplorerTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnItemexpanding)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExplorerTreeCtrl message handlers

void CExplorerTreeCtrl::PreSubclassWindow() 
{
	// Ʈ�� �Ӽ��� �����Ѵ�
	ModifyStyle(TVS_LINESATROOT, TVS_HASBUTTONS | TVS_HASLINES);

	// �ý��� �̹��� ����Ʈ�� ��� Ʈ���� �����Ѵ�
	SHFILEINFO ShellFileInfo;
	HIMAGELIST hShellImageList = (HIMAGELIST)::SHGetFileInfo("", 0, &ShellFileInfo,
									sizeof(SHFILEINFO), SHGFI_SYSICONINDEX | SHGFI_SMALLICON);

	SetImageList(CImageList::FromHandle(hShellImageList), LVSIL_NORMAL); 
	SetImageList(CImageList::FromHandle(hShellImageList), LVSIL_STATE); 

	// ���� ȭ�� �� ���� �������̽��� ��´�
	LPSHELLFOLDER lpShellFolder;

	if(SUCCEEDED(::SHGetDesktopFolder(&lpShellFolder)))
	{
		// ����ȭ���� PIDL�� ��´�
		LPITEMIDLIST pIDList;
		::SHGetSpecialFolderLocation(NULL, CSIDL_DESKTOP, &pIDList);

		// ����ȭ�� �׸��� Ʈ���� �߰��Ѵ�
		HTREEITEM hRoot = InsertFolderItem(NULL, NULL, lpShellFolder, pIDList, pIDList);

		lpShellFolder->Release();
	}

	CTreeCtrl::PreSubclassWindow();
}

void CExplorerTreeCtrl::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	// �׸��� Ȯ��Ǵ� ���� �ƴϰų� ���丮 ������ �������� �ʴ´ٸ� ����
	if(pNMTreeView->hdr.code != TVN_ITEMEXPANDING || pNMTreeView->itemNew.lParam == NULL)
	{
		*pResult = 1;
		return;
	}

	// Ȯ��Ǵ� �׸��� �ڵ��� ��´�
	HTREEITEM hItem = pNMTreeView->itemNew.hItem;
	// Ȯ��Ǵ� �׸��� ���丮 ������ ��´�
	LPTVITEMDATA pData = (LPTVITEMDATA)pNMTreeView->itemNew.lParam;
	IShellFolder *lpShellFolder;

	// ���� ��Ʈ �׸��̶��
	if(GetParentItem(hItem) == NULL)
	{
		// ���丮 ������ �� ���� �������̽��� ����Ѵ�
		lpShellFolder = pData->pParentFolder;
	}
	else
	{
		// ���丮 ������ �� ���� �������̽��� ���Ͽ�,
		// ���� �׸��� ���丮�� ���� �� ���� �������̽��� ��´�
		pData->pParentFolder->BindToObject(pData->pIDList, NULL, IID_IShellFolder, (LPVOID *)&lpShellFolder);
		if(lpShellFolder == NULL)
		{
			*pResult = 1;
			return;
		}
	}

	LPENUMIDLIST pEnumIDL = NULL;

	// �� ���� �������̽��� ����Ͽ� ���� �������� ã�´�
	lpShellFolder->EnumObjects(NULL, SHCONTF_FOLDERS | SHCONTF_INCLUDEHIDDEN, &pEnumIDL);
	if(pEnumIDL == NULL)
	{
		*pResult = 1;
		return;
	}

	// Ʈ�� �ٽ� �׸��⸦ ���´�
	SetRedraw(FALSE);

	// ���� �������� �����Ѵ�
	DeleteChildFolder(hItem);

	LPITEMIDLIST pChildIDL;
	ULONG nAttr;

	// ��� ���� �����鿡 ���� �ݺ��Ѵ� - ���� ������ PIDL�� ��´�
	for(; S_OK == pEnumIDL->Next(1, &pChildIDL, NULL); )
	{
		// ���� ������ �Ӽ��� ��´�
		nAttr = SFGAO_FOLDER;
		lpShellFolder->GetAttributesOf(1, (const struct _ITEMIDLIST **)&pChildIDL, &nAttr);
		// ���� �������
		if(nAttr & SFGAO_FOLDER)
		{
			// Ʈ���� ���� �׸����� �߰��Ѵ�
			InsertFolderItem(hItem, NULL, lpShellFolder, pData->pFQIDList, pChildIDL);
		}
	}

	// ���� �׸��� ���� �׸���� �����Ѵ�
	TVSORTCB SortCB;
	SortCB.hParent		= hItem;
	SortCB.lParam		= 0;
	SortCB.lpfnCompare	= SortTreeProc;

	SortChildrenCB(&SortCB);

	// �ٽ� �׸��⸦ �����Ѵ�
	SetRedraw(TRUE);

	*pResult = 0;
}

// Ʈ���� �׸��� �����ϴ� �Լ�
int CALLBACK CExplorerTreeCtrl::SortTreeProc(LPARAM lParam1, LPARAM lParam2, LPARAM lSortParam)
{
	// �� Ʈ�� �׸��� ���丮 ������ ���Ѵ�
	LPTVITEMDATA pData1 = (LPTVITEMDATA)lParam1;
	LPTVITEMDATA pData2 = (LPTVITEMDATA)lParam2;

	HRESULT   hr;

	// �� Ʈ�� �׸��� ���丮 �������� PIDL�� ����Ͽ� ���Ѵ�
	hr = pData1->pParentFolder->CompareIDs(0, pData1->pIDList, pData2->pIDList);

	if(FAILED(hr))	return 0;

	// �� ����� �����Ѵ�
	return (short)SCODE_CODE(GetScode(hr));
}

// ���ο� ���丮�� Ʈ���� �߰��ϴ� �Լ�
HTREEITEM CExplorerTreeCtrl::InsertFolderItem(HTREEITEM hParent, HTREEITEM hPrev,
						LPSHELLFOLDER pFolder, LPITEMIDLIST pFQIDList, LPITEMIDLIST pIDList)
{
	// ���丮 ���� ����ü�� ���� �޸𸮸� �����Ѵ�
	LPTVITEMDATA pData = (LPTVITEMDATA)m_pMalloc->Alloc(sizeof(TVITEMDATA));
	// ���丮 ���� ����ü�� ä���
	pData->pParentFolder	= pFolder;						// ���� �� ���� �������̽��� �����Ѵ�
	pData->pIDList			= DuplicateIDL(pIDList);		// ���� ���丮�� PIDL�� ����/�����Ͽ� �����Ѵ�
	pData->pFQIDList		= UnionIDL(pFQIDList, pIDList);	// ���� ���丮������ ������ PIDL�� ���� ���丮�� PIDL�� ����δ�

	// Ʈ�� �׸� �߰� ����ü�� ä���
	TVINSERTSTRUCT tvInsert;
	tvInsert.hParent		= hParent;						// �θ� �׸� �ڵ�
	tvInsert.hInsertAfter	= hPrev;						// ���� �׸� �ڵ�
	tvInsert.item.mask		= TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM | TVIF_CHILDREN;
															// Ʈ�� �׸� ����ũ

	// ���� ���丮�� ���� �Ӽ��� ���Ѵ�
	ULONG nAttr = SFGAO_HASSUBFOLDER | SFGAO_FOLDER | SFGAO_FILESYSTEM | SFGAO_GHOSTED | SFGAO_LINK | SFGAO_SHARE;
	pFolder->GetAttributesOf(1, (const struct _ITEMIDLIST **)&pIDList, &nAttr);

	// ���� ���� ���丮�� ���ٸ�
	if(!(nAttr & SFGAO_HASSUBFOLDER))
	{
		tvInsert.item.cChildren = 0;
	}
	// ������ �׸����� ��Ÿ���� �ִٸ�
	if(nAttr & SFGAO_GHOSTED)
	{
		tvInsert.item.mask		|= LVIF_STATE;
		tvInsert.item.stateMask	= LVIS_CUT;
		tvInsert.item.state		= LVIS_CUT;
	}
	// ���� ���� �������̶��
	if(nAttr & SFGAO_LINK)
	{
		tvInsert.item.mask		|= LVIF_STATE;
		tvInsert.item.stateMask	= LVIS_OVERLAYMASK;
		tvInsert.item.state		= INDEXTOOVERLAYMASK(2);
	}
	// ���� ������ �������
	if(nAttr & SFGAO_SHARE)
	{
		tvInsert.item.mask		|= LVIF_STATE;
		tvInsert.item.stateMask	= LVIS_OVERLAYMASK;
		tvInsert.item.state		= INDEXTOOVERLAYMASK(1);
	}

	// PIDL�κ��� ���丮�� �̸��� ��´�
	char *pName = new char[MAX_PATH];
	::memset(pName, 0, MAX_PATH);
	GetFriendlyName(pFolder, pIDList, pName);

	// Ʈ�� �׸��� �̸��� �����Ѵ�
	tvInsert.item.pszText		= pName;
	tvInsert.item.cchTextMax	= MAX_PATH;
	// Ʈ�� �׸��� �����͸� �����Ѵ�
	tvInsert.item.lParam		= (LPARAM)pData;

	// �ش� ���丮�� �̹����� �� �̹��� ����Ʈ���� ��´�
	SHFILEINFO ShellFileInfo;
	::SHGetFileInfo((LPCSTR)pData->pFQIDList, 0, &ShellFileInfo, sizeof (SHFILEINFO),
		SHGFI_PIDL | SHGFI_SYSICONINDEX | SHGFI_SMALLICON);
	tvInsert.item.iImage		= ShellFileInfo.iIcon;
	::SHGetFileInfo((LPCSTR)pData->pFQIDList, 0, &ShellFileInfo, sizeof (SHFILEINFO),
		SHGFI_PIDL | SHGFI_SYSICONINDEX | SHGFI_SMALLICON | SHGFI_OPENICON);
	tvInsert.item.iSelectedImage = ShellFileInfo.iIcon;

	// �ش� �׸��� Ʈ���� �߰��Ѵ�
	HTREEITEM hItem = InsertItem(&tvInsert);

	delete[] pName;

	// �߰��� �׸��� �ڵ��� �����Ѵ�
	return hItem;
}

// Ư�� ���丮�� ���� ���丮���� �����ϴ� �Լ�
int CExplorerTreeCtrl::DeleteChildFolder(HTREEITEM hItem)
{
	int nDelete;
	// ���� �׸��� �ڵ��� ���Ѵ�
	HTREEITEM hChild = GetChildItem(hItem), hNext;

	// ��� ���� �׸���� �����Ѵ�
	for(nDelete = 0; hChild != NULL; nDelete++)
	{
		hNext = GetNextSiblingItem(hChild);
		DeleteItem(hChild);
		hChild = hNext;
	}

	return nDelete;
}

// Ư�� Ʈ�� �׸��� ��θ� �����ϴ� �Լ�
void CExplorerTreeCtrl::GetPath(HTREEITEM hItem, CString &strPath)
{
	// �׸� �ڵ��� NULL�̸� ����
	if(hItem == NULL)		return;

	// �׸��� ���丮 ������ ��´�
	LPTVITEMDATA pData = (LPTVITEMDATA)GetItemData(hItem);

	strPath.Empty();
	// ���丮 ������ ������ PIDL�κ��� ��θ� ��´�
	::SHGetPathFromIDList(pData->pFQIDList, strPath.GetBuffer(MAX_PATH));
	strPath.ReleaseBuffer();
}

// Ư�� Ʈ�� �׸��� ��θ� �����ϴ� �Լ�
LPSTR CExplorerTreeCtrl::GetPath(HTREEITEM hItem)
{
	// �׸� �ڵ��� NULL�̸� ����
	if(hItem == NULL)		return NULL;

	// �׸��� ���丮 ������ ��´�
	LPTVITEMDATA pData = (LPTVITEMDATA)GetItemData(hItem);

	// ��θ� ������ �޸𸮸� �����Ѵ�
	char *pName = new char[MAX_PATH];
	::memset(pName, 0, MAX_PATH);

	// ���丮 ������ ������ PIDL�κ��� ��θ� ��´�
	::SHGetPathFromIDList(pData->pFQIDList, pName);

	// ��θ� �����Ѵ�
	return pName;
}

// ���� ���õ� Ʈ�� �׸��� ��θ� �����ϴ� �Լ�
void CExplorerTreeCtrl::GetSelectedPath(CString &strPath)
{
	GetPath(GetSelectedItem(), strPath);
}

// ���� ���õ� Ʈ�� �׸��� ��θ� �����ϴ� �Լ�
LPSTR CExplorerTreeCtrl::GetSelectedPath()
{
	return GetPath(GetSelectedItem());
}

// Ư�� ��ο� �ش��ϴ� Ʈ�� �׸��� �����ϴ� �Լ�
BOOL CExplorerTreeCtrl::SelectPath(LPCTSTR pPath)
{
	CString strPath = pPath, strMyCom, strFolder;
	strPath.MakeUpper();

	// ��ΰ� '\'�� ������ ������ '\'�� �����δ�
	if(strPath.GetAt(strPath.GetLength() - 1) != '\\')
		strPath += "\\";

	// ����ȭ�� �� ���� �������̽��� ��´�
	LPSHELLFOLDER lpShellFolder;
	::SHGetDesktopFolder(&lpShellFolder);

	LPITEMIDLIST pIDList;
	// "�� ��ǻ��"�� PIDL�� ��´�
	::SHGetSpecialFolderLocation(NULL, CSIDL_DRIVES, &pIDList);
	// PIDL�κ��� �̸�("�� ��ǻ��")�� ��´�
	GetFriendlyName(lpShellFolder, pIDList, strMyCom.GetBuffer(MAX_PATH));
	strMyCom.ReleaseBuffer();

	lpShellFolder->Release();

	// Ʈ�� �ٽ� �׸��⸦ ���´�
	SetRedraw(FALSE);

	// ����ȭ�� �׸� �Ʒ��� "�� ��ǻ��" �׸��� ã�´�
	HTREEITEM hParent = SearchChildFolder(GetRootItem(), strMyCom, FALSE);
	// �� ã���� ����
	if(hParent == NULL)				return FALSE;

	// ����̺� ��Ʈ���� ã�� ����
	BOOL bRoot = TRUE;
	UINT nState;
	int i, nSize = strPath.GetLength();
	// ��θ� �ѱ��ھ� ���캸�鼭 ����̺�, ���丮���� �ش� �׸��� ã�´�
	for(i = 0; i < nSize; i++)
	{
		// ���� ���丮 �и� ���� '\'�� ������
		if(strPath.GetAt(i) == '\\')
		{
			// ���� �׸��� ���� �׸� �߿���,
			// ������� ����� ���丮 ��� ������ �̸��� �׸��� �ִ��� ã�´�
			hParent = SearchChildFolder(hParent, strFolder, bRoot);

			// ���� ����̺� ��Ʈ�� ã�´ٸ� bRoot�� FALSE�� ����
			if(bRoot)				bRoot = FALSE;
			// ���� �ش� �׸��� �� ã�Ҵٸ� ����
			if(hParent == NULL)		break;

			// ���� �ѹ��� �� ��常 Ȯ��� �� �ִٸ�
			nState = GetItemState(hParent, TVIS_EXPANDEDONCE);
			if(nState)
			{
				// �ش� �׸��� Ȯ���Ѵ�
				Expand(hParent, TVE_EXPAND);
				// �ش� �׸��� �ٽ� ����Ѵ�
				Expand(hParent, TVE_COLLAPSE | TVE_COLLAPSERESET);
				// �ش� �׸� �Ʒ��� �� �׸��� �ϳ� �����
				InsertItem("", hParent);
			}
			// �ش� �׸��� Ȯ���Ѵ� 
			Expand(hParent, TVE_EXPAND);

			// ���丮 ���� �����
			strFolder.Empty();
		}
		else
		{
			// ���丮 �� ���Ѵ�
			strFolder += strPath.GetAt(i);
		}
	}

	// ���� ��ο� �´� �׸��� ã�Ҵٸ�
	if(hParent)
	{
		// �ش� �׸��� �����Ѵ�
		SelectItem(hParent);
		// �ش� �׸��� ȭ�鿡 ���̵��� ��ũ���Ѵ�
		SelectSetFirstVisible(hParent);
	}

	// �ٽ� �׸��⸦ �����Ѵ�
	SetRedraw(TRUE);

	// �������� �����Ѵ�
	return (hParent != NULL);
}

// Ư�� Ʈ�� �׸��� ���� �׸񿡼� Ư�� �ؽ�Ʈ�� ���� �׸��� ã�� �Լ�
HTREEITEM CExplorerTreeCtrl::SearchChildFolder(HTREEITEM hParent, LPCTSTR pFolderName, BOOL bRoot)
{
	// ���� �׸��� ã�´�
	HTREEITEM hChild = GetChildItem(hParent);
	CString strTemp;

	// ��� ���� �׸� ���� �ݺ��Ѵ�
	for(; hChild; )
	{
		// �׸��� �ؽ�Ʈ�� ���Ѵ�
		strTemp = GetItemText(hChild);

		// ���� ����̺� ��Ʈ�� ã�� ���̶��
		if(bRoot)
		{
			// '('�� ')' ���̿� �ִ� ����̺���� �����Ѵ�
			CString strRoot = strTemp;
			strTemp.Empty();

			int nStart = strRoot.ReverseFind('(');
			int nEnd = strRoot.ReverseFind(')');
			strTemp = strRoot.Mid(nStart + 1, nEnd - nStart - 1);
		}

		// ã�� ���丮��� �׸� �̸��� ���Ѵ�
		if(strTemp.CompareNoCase(pFolderName) == 0)
		{
			// ���� ã�Ҵٸ� �ش� �׸��� Ȯ���Ѵ�
			Expand(hChild, TVE_EXPAND);
			// �ش� �׸��� �ڵ��� �����Ѵ�
			return hChild;
		}

		// ���� �׸��� ã�´�
		hChild = GetNextItem(hChild, TVGN_NEXT);
	}

	// �� ã���� NULL�� �����Ѵ�
	return NULL;
}

// PIDL���� ���丮 �̸��� �����ϴ� �Լ�
void CExplorerTreeCtrl::GetFriendlyName(LPSHELLFOLDER pFolder, LPITEMIDLIST pIDList, LPSTR pName)
{
	STRRET strName;

	// PIDL���� ���丮 �̸��� �����Ѵ�
	if(SUCCEEDED(pFolder->GetDisplayNameOf(pIDList, SHGDN_NORMAL, &strName)))
	{
		// ���ϵ� ���ڿ��� ǥ�� ��Ŀ� ���� MBCS ���ڿ��� �����Ѵ�
		switch(strName.uType)
		{
		case STRRET_WSTR:	// �����ڵ� ���ڿ��� ���
			::WideCharToMultiByte(CP_ACP, 0, strName.pOleStr, -1, pName, sizeof(strName), NULL, NULL);
			break;
		case STRRET_OFFSET:	// ���������� ǥ���� ���ڿ��� ���
			::strcpy(pName, (LPSTR)pIDList + strName.uOffset);
			break;
		case STRRET_CSTR:	// cStr�� ����� ���ڿ��� ���
			::strcpy(pName, (LPSTR)strName.cStr);
			break;
		}
	}
}

// �� PIDL�� ��ġ�� �Լ�
LPITEMIDLIST CExplorerTreeCtrl::UnionIDL(LPITEMIDLIST pIDList1, LPITEMIDLIST pIDList2)
{
	// ù��° IDL�� ũ�⸦ ���ϰ� ITEMIDLIST ����ü ũ�⸦ ����
	UINT nSize1 = GetIDLSize(pIDList1) - sizeof(ITEMIDLIST);
	// �ι�° IDL�� ũ�⸦ ���Ѵ�
	UINT nSize2 = GetIDLSize(pIDList2);
	// �� IDL�� ũ���� �ո�ŭ �޸𸮸� �����Ѵ�
	LPITEMIDLIST pNew = (LPITEMIDLIST)m_pMalloc->Alloc(nSize1 + nSize2);

	// ���ο� �޸𸮿� IDL1�� �����Ѵ�
	::CopyMemory(pNew, pIDList1, nSize1);
	// ���ο� �޸��� IDL1 �ڿ� IDL2�� �����Ѵ�
	::CopyMemory((LPBYTE)pNew + nSize1, pIDList2, nSize2);

	// ���ο� �޸𸮸� �����Ѵ�
	return pNew;
}

// Ư�� PIDL�� ������ PIDL�� �����ϴ� �Լ�
LPITEMIDLIST CExplorerTreeCtrl::DuplicateIDL(LPITEMIDLIST pSource)
{ 
	// IDL�� ũ�⸦ ���Ѵ�
	UINT nSize = GetIDLSize(pSource);
	// IDL�� ũ�� ��ŭ �޸𸮸� �����Ѵ�
	LPITEMIDLIST pNew = (LPITEMIDLIST)m_pMalloc->Alloc(nSize);
	// ���ο� �޸𸮿� IDL�� �����Ѵ�
	::CopyMemory(pNew, pSource, nSize);

	// ���ο� �޸𸮸� �����Ѵ�
	return pNew; 
}

// Ư�� PIDL�� ũ�⸦ ���ϴ� �Լ�
UINT CExplorerTreeCtrl::GetIDLSize(LPITEMIDLIST pIDList) 
{ 
	UINT nSize = 0;

	// ID�� ũ��(mkid.cb)�� ������ ������ �ݺ��Ѵ�
	for(; pIDList->mkid.cb;)
	{
		// ID�� ũ�⸦ �ջ��Ѵ�
		nSize += pIDList->mkid.cb;
		// PIDL���� ID�� ũ�� ��ŭ �ڷ� �̵��Ѵ�
		pIDList = (LPITEMIDLIST)((LPBYTE)pIDList + pIDList->mkid.cb);
	}

	// ���������� �� IDL ũ�⸦ ���Ѵ�
	nSize += sizeof(ITEMIDLIST);

	// ũ�⸦ �����Ѵ�
	return nSize;
}

void CExplorerTreeCtrl::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	*pResult = 0;

	// ���콺�� ��ġ�� ���Ѵ�
	POINT pt, ptClient;
	::GetCursorPos(&pt);
	ptClient = pt;

	// ��ũ�� ��ǥ�迡�� Ŭ���̾�Ʈ ��ǥ��� �ٲ۴�
	ScreenToClient(&ptClient);
	// �ش� ��ǥ�� �׸��� ã�´�
	HTREEITEM hItem = HitTest(ptClient);
	// ���� �׸��� ���ٸ� ����
	if(hItem == NULL)			return;

	// �ش� �׸��� ���丮 ������ ���Ѵ�
	LPTVITEMDATA pData = (LPTVITEMDATA)GetItemData(hItem);

	HMENU hMenu;
	IContextMenu *pMenu;

	// �ش� �׸��� �� ���� �������̽��� ����Ͽ� ���ؽ�Ʈ �޴��� ��´�
	if(FAILED(pData->pParentFolder->GetUIObjectOf(m_hWnd, 1, (const struct _ITEMIDLIST **)&pData->pIDList,
		IID_IContextMenu, NULL, (LPVOID*)&pMenu)))	return;

	// �˾� �޴��� �����Ѵ�
	hMenu = ::CreatePopupMenu();
	// ���ؽ�Ʈ �޴� �������̽��� ����Ͽ� �˾� �޴��� �����Ѵ�
	if(FAILED(pMenu->QueryContextMenu(hMenu, 0, 1, 0x7fff, CMF_NORMAL | CMF_EXPLORE)))
		return;

	// �˾� �޴��� ����Ѵ�
	UINT nMenu = ::TrackPopupMenu(hMenu, TPM_LEFTALIGN | TPM_RETURNCMD | TPM_RIGHTBUTTON, 
		pt.x, pt.y, 0, m_hWnd, NULL);

	// ���� ���õ� �޴� �׸��� �ִٸ�
	if(nMenu)
	{
		// �ش� �޴��� �����Ѵ�
		CMINVOKECOMMANDINFO CmdInfo;
		CmdInfo.cbSize			= sizeof(CMINVOKECOMMANDINFO);
		CmdInfo.fMask			= 0;
		CmdInfo.hwnd			= m_hWnd;
		CmdInfo.lpVerb			= (LPCSTR)(INT_PTR)(nMenu - 1);
		CmdInfo.lpParameters	= NULL;
		CmdInfo.lpDirectory		= NULL;
		CmdInfo.nShow			= SW_SHOWNORMAL;
		CmdInfo.dwHotKey		= 0;
		CmdInfo.hIcon			= NULL;

		pMenu->InvokeCommand(&CmdInfo);
	}

	pMenu->Release();
}
