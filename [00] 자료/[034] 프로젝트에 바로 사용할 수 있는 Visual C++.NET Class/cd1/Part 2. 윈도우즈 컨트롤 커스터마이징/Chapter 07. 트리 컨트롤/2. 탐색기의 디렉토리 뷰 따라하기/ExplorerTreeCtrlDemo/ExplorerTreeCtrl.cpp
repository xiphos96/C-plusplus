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
	// 메모리 관리자 생성
	::SHGetMalloc(&m_pMalloc);
}

CExplorerTreeCtrl::~CExplorerTreeCtrl()
{
	// 메모리 관리자 소멸
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
	// 트리 속성을 조정한다
	ModifyStyle(TVS_LINESATROOT, TVS_HASBUTTONS | TVS_HASLINES);

	// 시스템 이미지 리스트를 얻어 트리에 설정한다
	SHFILEINFO ShellFileInfo;
	HIMAGELIST hShellImageList = (HIMAGELIST)::SHGetFileInfo("", 0, &ShellFileInfo,
									sizeof(SHFILEINFO), SHGFI_SYSICONINDEX | SHGFI_SMALLICON);

	SetImageList(CImageList::FromHandle(hShellImageList), LVSIL_NORMAL); 
	SetImageList(CImageList::FromHandle(hShellImageList), LVSIL_STATE); 

	// 바탕 화면 쉘 폴더 인터페이스를 얻는다
	LPSHELLFOLDER lpShellFolder;

	if(SUCCEEDED(::SHGetDesktopFolder(&lpShellFolder)))
	{
		// 바탕화면의 PIDL을 얻는다
		LPITEMIDLIST pIDList;
		::SHGetSpecialFolderLocation(NULL, CSIDL_DESKTOP, &pIDList);

		// 바탕화면 항목을 트리에 추가한다
		HTREEITEM hRoot = InsertFolderItem(NULL, NULL, lpShellFolder, pIDList, pIDList);

		lpShellFolder->Release();
	}

	CTreeCtrl::PreSubclassWindow();
}

void CExplorerTreeCtrl::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	// 항목이 확장되는 것이 아니거나 디렉토리 정보가 존재하지 않는다면 리턴
	if(pNMTreeView->hdr.code != TVN_ITEMEXPANDING || pNMTreeView->itemNew.lParam == NULL)
	{
		*pResult = 1;
		return;
	}

	// 확장되는 항목의 핸들을 얻는다
	HTREEITEM hItem = pNMTreeView->itemNew.hItem;
	// 확장되는 항목의 디렉토리 정보를 얻는다
	LPTVITEMDATA pData = (LPTVITEMDATA)pNMTreeView->itemNew.lParam;
	IShellFolder *lpShellFolder;

	// 만약 루트 항목이라면
	if(GetParentItem(hItem) == NULL)
	{
		// 디렉토리 정보의 쉘 폴더 인터페이스를 사용한다
		lpShellFolder = pData->pParentFolder;
	}
	else
	{
		// 디렉토리 정보의 쉘 폴더 인터페이스를 통하여,
		// 선택 항목의 디렉토리에 대한 쉘 폴더 인터페이스를 얻는다
		pData->pParentFolder->BindToObject(pData->pIDList, NULL, IID_IShellFolder, (LPVOID *)&lpShellFolder);
		if(lpShellFolder == NULL)
		{
			*pResult = 1;
			return;
		}
	}

	LPENUMIDLIST pEnumIDL = NULL;

	// 쉘 폴더 인터페이스를 사용하여 하위 폴더들을 찾는다
	lpShellFolder->EnumObjects(NULL, SHCONTF_FOLDERS | SHCONTF_INCLUDEHIDDEN, &pEnumIDL);
	if(pEnumIDL == NULL)
	{
		*pResult = 1;
		return;
	}

	// 트리 다시 그리기를 막는다
	SetRedraw(FALSE);

	// 하위 폴더들을 삭제한다
	DeleteChildFolder(hItem);

	LPITEMIDLIST pChildIDL;
	ULONG nAttr;

	// 모든 하위 폴더들에 대해 반복한다 - 하위 폴더의 PIDL을 얻는다
	for(; S_OK == pEnumIDL->Next(1, &pChildIDL, NULL); )
	{
		// 하위 폴더의 속성을 얻는다
		nAttr = SFGAO_FOLDER;
		lpShellFolder->GetAttributesOf(1, (const struct _ITEMIDLIST **)&pChildIDL, &nAttr);
		// 만약 폴더라면
		if(nAttr & SFGAO_FOLDER)
		{
			// 트리에 하위 항목으로 추가한다
			InsertFolderItem(hItem, NULL, lpShellFolder, pData->pFQIDList, pChildIDL);
		}
	}

	// 현재 항목의 하위 항목들을 정렬한다
	TVSORTCB SortCB;
	SortCB.hParent		= hItem;
	SortCB.lParam		= 0;
	SortCB.lpfnCompare	= SortTreeProc;

	SortChildrenCB(&SortCB);

	// 다시 그리기를 설정한다
	SetRedraw(TRUE);

	*pResult = 0;
}

// 트리의 항목을 정렬하는 함수
int CALLBACK CExplorerTreeCtrl::SortTreeProc(LPARAM lParam1, LPARAM lParam2, LPARAM lSortParam)
{
	// 두 트리 항목의 디렉토리 정보를 구한다
	LPTVITEMDATA pData1 = (LPTVITEMDATA)lParam1;
	LPTVITEMDATA pData2 = (LPTVITEMDATA)lParam2;

	HRESULT   hr;

	// 두 트리 항목의 디렉토리 정보에서 PIDL을 사용하여 비교한다
	hr = pData1->pParentFolder->CompareIDs(0, pData1->pIDList, pData2->pIDList);

	if(FAILED(hr))	return 0;

	// 비교 결과를 리턴한다
	return (short)SCODE_CODE(GetScode(hr));
}

// 새로운 디렉토리를 트리에 추가하는 함수
HTREEITEM CExplorerTreeCtrl::InsertFolderItem(HTREEITEM hParent, HTREEITEM hPrev,
						LPSHELLFOLDER pFolder, LPITEMIDLIST pFQIDList, LPITEMIDLIST pIDList)
{
	// 디렉토리 정보 구조체에 대한 메모리를 생성한다
	LPTVITEMDATA pData = (LPTVITEMDATA)m_pMalloc->Alloc(sizeof(TVITEMDATA));
	// 디렉토리 정보 구조체를 채운다
	pData->pParentFolder	= pFolder;						// 상위 쉘 폴더 인터페이스를 저장한다
	pData->pIDList			= DuplicateIDL(pIDList);		// 현재 디렉토리의 PIDL을 생성/복사하여 설정한다
	pData->pFQIDList		= UnionIDL(pFQIDList, pIDList);	// 현재 디렉토리까지의 완전한 PIDL에 현재 디렉토리의 PIDL을 얻붙인다

	// 트리 항목 추가 구조체를 채운다
	TVINSERTSTRUCT tvInsert;
	tvInsert.hParent		= hParent;						// 부모 항목 핸들
	tvInsert.hInsertAfter	= hPrev;						// 이전 항목 핸들
	tvInsert.item.mask		= TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM | TVIF_CHILDREN;
															// 트리 항목 마스크

	// 현재 디렉토리에 대한 속성을 구한다
	ULONG nAttr = SFGAO_HASSUBFOLDER | SFGAO_FOLDER | SFGAO_FILESYSTEM | SFGAO_GHOSTED | SFGAO_LINK | SFGAO_SHARE;
	pFolder->GetAttributesOf(1, (const struct _ITEMIDLIST **)&pIDList, &nAttr);

	// 만약 하위 디렉토리가 없다면
	if(!(nAttr & SFGAO_HASSUBFOLDER))
	{
		tvInsert.item.cChildren = 0;
	}
	// 반투명 항목으로 나타나고 있다면
	if(nAttr & SFGAO_GHOSTED)
	{
		tvInsert.item.mask		|= LVIF_STATE;
		tvInsert.item.stateMask	= LVIS_CUT;
		tvInsert.item.state		= LVIS_CUT;
	}
	// 만약 단축 아이콘이라면
	if(nAttr & SFGAO_LINK)
	{
		tvInsert.item.mask		|= LVIF_STATE;
		tvInsert.item.stateMask	= LVIS_OVERLAYMASK;
		tvInsert.item.state		= INDEXTOOVERLAYMASK(2);
	}
	// 만약 공유된 폴더라면
	if(nAttr & SFGAO_SHARE)
	{
		tvInsert.item.mask		|= LVIF_STATE;
		tvInsert.item.stateMask	= LVIS_OVERLAYMASK;
		tvInsert.item.state		= INDEXTOOVERLAYMASK(1);
	}

	// PIDL로부터 디렉토리의 이름을 얻는다
	char *pName = new char[MAX_PATH];
	::memset(pName, 0, MAX_PATH);
	GetFriendlyName(pFolder, pIDList, pName);

	// 트리 항목의 이름을 설정한다
	tvInsert.item.pszText		= pName;
	tvInsert.item.cchTextMax	= MAX_PATH;
	// 트리 항목의 데이터를 설정한다
	tvInsert.item.lParam		= (LPARAM)pData;

	// 해당 디렉토리의 이미지를 쉘 이미지 리스트에서 얻는다
	SHFILEINFO ShellFileInfo;
	::SHGetFileInfo((LPCSTR)pData->pFQIDList, 0, &ShellFileInfo, sizeof (SHFILEINFO),
		SHGFI_PIDL | SHGFI_SYSICONINDEX | SHGFI_SMALLICON);
	tvInsert.item.iImage		= ShellFileInfo.iIcon;
	::SHGetFileInfo((LPCSTR)pData->pFQIDList, 0, &ShellFileInfo, sizeof (SHFILEINFO),
		SHGFI_PIDL | SHGFI_SYSICONINDEX | SHGFI_SMALLICON | SHGFI_OPENICON);
	tvInsert.item.iSelectedImage = ShellFileInfo.iIcon;

	// 해당 항목을 트리에 추가한다
	HTREEITEM hItem = InsertItem(&tvInsert);

	delete[] pName;

	// 추가된 항목의 핸들을 리턴한다
	return hItem;
}

// 특정 디렉토리의 하위 디렉토리들을 삭제하는 함수
int CExplorerTreeCtrl::DeleteChildFolder(HTREEITEM hItem)
{
	int nDelete;
	// 하위 항목의 핸들을 구한다
	HTREEITEM hChild = GetChildItem(hItem), hNext;

	// 모든 하위 항목들을 삭제한다
	for(nDelete = 0; hChild != NULL; nDelete++)
	{
		hNext = GetNextSiblingItem(hChild);
		DeleteItem(hChild);
		hChild = hNext;
	}

	return nDelete;
}

// 특정 트리 항목의 경로를 리턴하는 함수
void CExplorerTreeCtrl::GetPath(HTREEITEM hItem, CString &strPath)
{
	// 항목 핸들이 NULL이면 리턴
	if(hItem == NULL)		return;

	// 항목의 디렉토리 정보를 얻는다
	LPTVITEMDATA pData = (LPTVITEMDATA)GetItemData(hItem);

	strPath.Empty();
	// 디렉토리 정보의 완전한 PIDL로부터 경로를 얻는다
	::SHGetPathFromIDList(pData->pFQIDList, strPath.GetBuffer(MAX_PATH));
	strPath.ReleaseBuffer();
}

// 특정 트리 항목의 경로를 리턴하는 함수
LPSTR CExplorerTreeCtrl::GetPath(HTREEITEM hItem)
{
	// 항목 핸들이 NULL이면 리턴
	if(hItem == NULL)		return NULL;

	// 항목의 디렉토리 정보를 얻는다
	LPTVITEMDATA pData = (LPTVITEMDATA)GetItemData(hItem);

	// 경로를 리턴한 메모리를 생성한다
	char *pName = new char[MAX_PATH];
	::memset(pName, 0, MAX_PATH);

	// 디렉토리 정보의 완전한 PIDL로부터 경로를 얻는다
	::SHGetPathFromIDList(pData->pFQIDList, pName);

	// 경로를 리턴한다
	return pName;
}

// 현재 선택된 트리 항목의 경로를 리턴하는 함수
void CExplorerTreeCtrl::GetSelectedPath(CString &strPath)
{
	GetPath(GetSelectedItem(), strPath);
}

// 현재 선택된 트리 항목의 경로를 리턴하는 함수
LPSTR CExplorerTreeCtrl::GetSelectedPath()
{
	return GetPath(GetSelectedItem());
}

// 특정 경로에 해당하는 트리 항목을 선택하는 함수
BOOL CExplorerTreeCtrl::SelectPath(LPCTSTR pPath)
{
	CString strPath = pPath, strMyCom, strFolder;
	strPath.MakeUpper();

	// 경로가 '\'로 끝나지 않으면 '\'를 덧붙인다
	if(strPath.GetAt(strPath.GetLength() - 1) != '\\')
		strPath += "\\";

	// 바탕화면 쉘 폴더 인터페이스를 얻는다
	LPSHELLFOLDER lpShellFolder;
	::SHGetDesktopFolder(&lpShellFolder);

	LPITEMIDLIST pIDList;
	// "내 컴퓨터"의 PIDL을 얻는다
	::SHGetSpecialFolderLocation(NULL, CSIDL_DRIVES, &pIDList);
	// PIDL로부터 이름("내 컴퓨터")을 얻는다
	GetFriendlyName(lpShellFolder, pIDList, strMyCom.GetBuffer(MAX_PATH));
	strMyCom.ReleaseBuffer();

	lpShellFolder->Release();

	// 트리 다시 그리기를 막는다
	SetRedraw(FALSE);

	// 바탕화면 항목 아래의 "내 컴퓨터" 항목을 찾는다
	HTREEITEM hParent = SearchChildFolder(GetRootItem(), strMyCom, FALSE);
	// 못 찾으면 리턴
	if(hParent == NULL)				return FALSE;

	// 드라이브 루트부터 찾기 시작
	BOOL bRoot = TRUE;
	UINT nState;
	int i, nSize = strPath.GetLength();
	// 경로를 한글자씩 살펴보면서 드라이브, 디렉토리별로 해당 항목을 찾는다
	for(i = 0; i < nSize; i++)
	{
		// 만약 디렉토리 분리 문자 '\'를 만나면
		if(strPath.GetAt(i) == '\\')
		{
			// 현재 항목의 하위 항목 중에서,
			// 현재까지 모아진 디렉토리 명과 동일한 이름의 항목이 있는지 찾는다
			hParent = SearchChildFolder(hParent, strFolder, bRoot);

			// 만약 드라이브 루트를 찾는다면 bRoot를 FALSE로 변경
			if(bRoot)				bRoot = FALSE;
			// 만약 해당 항목을 못 찾았다면 리턴
			if(hParent == NULL)		break;

			// 만약 한번에 한 노드만 확장될 수 있다면
			nState = GetItemState(hParent, TVIS_EXPANDEDONCE);
			if(nState)
			{
				// 해당 항목을 확장한다
				Expand(hParent, TVE_EXPAND);
				// 해당 항목을 다시 축소한다
				Expand(hParent, TVE_COLLAPSE | TVE_COLLAPSERESET);
				// 해당 항목 아래에 빈 항목을 하나 만든다
				InsertItem("", hParent);
			}
			// 해당 항목을 확장한다 
			Expand(hParent, TVE_EXPAND);

			// 디렉토리 명을 지운다
			strFolder.Empty();
		}
		else
		{
			// 디렉토리 명에 더한다
			strFolder += strPath.GetAt(i);
		}
	}

	// 만약 경로에 맞는 항목을 찾았다면
	if(hParent)
	{
		// 해당 항목을 선택한다
		SelectItem(hParent);
		// 해당 항목이 화면에 보이도록 스크롤한다
		SelectSetFirstVisible(hParent);
	}

	// 다시 그리기를 설정한다
	SetRedraw(TRUE);

	// 성공인지 리턴한다
	return (hParent != NULL);
}

// 특정 트리 항목의 하위 항목에서 특정 텍스트를 갖는 항목을 찾는 함수
HTREEITEM CExplorerTreeCtrl::SearchChildFolder(HTREEITEM hParent, LPCTSTR pFolderName, BOOL bRoot)
{
	// 하위 항목을 찾는다
	HTREEITEM hChild = GetChildItem(hParent);
	CString strTemp;

	// 모든 하위 항목에 대해 반복한다
	for(; hChild; )
	{
		// 항목의 텍스트를 구한다
		strTemp = GetItemText(hChild);

		// 만약 드라이브 루트를 찾는 중이라면
		if(bRoot)
		{
			// '('와 ')' 사이에 있는 드라이브명을 추출한다
			CString strRoot = strTemp;
			strTemp.Empty();

			int nStart = strRoot.ReverseFind('(');
			int nEnd = strRoot.ReverseFind(')');
			strTemp = strRoot.Mid(nStart + 1, nEnd - nStart - 1);
		}

		// 찾는 디렉토리명과 항목 이름을 비교한다
		if(strTemp.CompareNoCase(pFolderName) == 0)
		{
			// 만약 찾았다면 해당 항목을 확장한다
			Expand(hChild, TVE_EXPAND);
			// 해당 항목의 핸들을 리턴한다
			return hChild;
		}

		// 다음 항목을 찾는다
		hChild = GetNextItem(hChild, TVGN_NEXT);
	}

	// 못 찾으면 NULL을 리턴한다
	return NULL;
}

// PIDL에서 디렉토리 이름을 리턴하는 함수
void CExplorerTreeCtrl::GetFriendlyName(LPSHELLFOLDER pFolder, LPITEMIDLIST pIDList, LPSTR pName)
{
	STRRET strName;

	// PIDL에서 디렉토리 이름을 리턴한다
	if(SUCCEEDED(pFolder->GetDisplayNameOf(pIDList, SHGDN_NORMAL, &strName)))
	{
		// 리턴된 문자열의 표현 방식에 따라 MBCS 문자열로 변경한다
		switch(strName.uType)
		{
		case STRRET_WSTR:	// 유니코드 문자열인 경우
			::WideCharToMultiByte(CP_ACP, 0, strName.pOleStr, -1, pName, sizeof(strName), NULL, NULL);
			break;
		case STRRET_OFFSET:	// 오프셋으로 표현된 문자열인 경우
			::strcpy(pName, (LPSTR)pIDList + strName.uOffset);
			break;
		case STRRET_CSTR:	// cStr에 저장된 문자열인 경우
			::strcpy(pName, (LPSTR)strName.cStr);
			break;
		}
	}
}

// 두 PIDL을 합치는 함수
LPITEMIDLIST CExplorerTreeCtrl::UnionIDL(LPITEMIDLIST pIDList1, LPITEMIDLIST pIDList2)
{
	// 첫번째 IDL의 크기를 구하고 ITEMIDLIST 구조체 크기를 뺀다
	UINT nSize1 = GetIDLSize(pIDList1) - sizeof(ITEMIDLIST);
	// 두번째 IDL의 크기를 구한다
	UINT nSize2 = GetIDLSize(pIDList2);
	// 두 IDL의 크기의 합만큼 메모리를 생성한다
	LPITEMIDLIST pNew = (LPITEMIDLIST)m_pMalloc->Alloc(nSize1 + nSize2);

	// 새로운 메모리에 IDL1을 복사한다
	::CopyMemory(pNew, pIDList1, nSize1);
	// 새로운 메모리의 IDL1 뒤에 IDL2를 복사한다
	::CopyMemory((LPBYTE)pNew + nSize1, pIDList2, nSize2);

	// 새로운 메모리를 리턴한다
	return pNew;
}

// 특정 PIDL과 동일한 PIDL을 생성하는 함수
LPITEMIDLIST CExplorerTreeCtrl::DuplicateIDL(LPITEMIDLIST pSource)
{ 
	// IDL의 크기를 구한다
	UINT nSize = GetIDLSize(pSource);
	// IDL의 크기 만큼 메모리를 생성한다
	LPITEMIDLIST pNew = (LPITEMIDLIST)m_pMalloc->Alloc(nSize);
	// 새로운 메모리에 IDL을 복사한다
	::CopyMemory(pNew, pSource, nSize);

	// 새로운 메모리를 리턴한다
	return pNew; 
}

// 특정 PIDL의 크기를 구하는 함수
UINT CExplorerTreeCtrl::GetIDLSize(LPITEMIDLIST pIDList) 
{ 
	UINT nSize = 0;

	// ID의 크기(mkid.cb)가 존재할 때까지 반복한다
	for(; pIDList->mkid.cb;)
	{
		// ID의 크기를 합산한다
		nSize += pIDList->mkid.cb;
		// PIDL에서 ID의 크기 만큼 뒤로 이동한다
		pIDList = (LPITEMIDLIST)((LPBYTE)pIDList + pIDList->mkid.cb);
	}

	// 마지막으로 빈 IDL 크기를 더한다
	nSize += sizeof(ITEMIDLIST);

	// 크기를 리턴한다
	return nSize;
}

void CExplorerTreeCtrl::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	*pResult = 0;

	// 마우스의 위치를 구한다
	POINT pt, ptClient;
	::GetCursorPos(&pt);
	ptClient = pt;

	// 스크린 좌표계에서 클라이언트 좌표계로 바꾼다
	ScreenToClient(&ptClient);
	// 해당 좌표의 항목을 찾는다
	HTREEITEM hItem = HitTest(ptClient);
	// 만약 항목이 없다면 리턴
	if(hItem == NULL)			return;

	// 해당 항목의 디렉토리 정보를 구한다
	LPTVITEMDATA pData = (LPTVITEMDATA)GetItemData(hItem);

	HMENU hMenu;
	IContextMenu *pMenu;

	// 해당 항목의 쉘 폴더 인터페이스를 사용하여 컨텍스트 메뉴를 얻는다
	if(FAILED(pData->pParentFolder->GetUIObjectOf(m_hWnd, 1, (const struct _ITEMIDLIST **)&pData->pIDList,
		IID_IContextMenu, NULL, (LPVOID*)&pMenu)))	return;

	// 팝업 메뉴를 생성한다
	hMenu = ::CreatePopupMenu();
	// 컨텍스트 메뉴 인터페이스를 사용하여 팝업 메뉴를 구성한다
	if(FAILED(pMenu->QueryContextMenu(hMenu, 0, 1, 0x7fff, CMF_NORMAL | CMF_EXPLORE)))
		return;

	// 팝업 메뉴를 출력한다
	UINT nMenu = ::TrackPopupMenu(hMenu, TPM_LEFTALIGN | TPM_RETURNCMD | TPM_RIGHTBUTTON, 
		pt.x, pt.y, 0, m_hWnd, NULL);

	// 만약 선택된 메뉴 항목이 있다면
	if(nMenu)
	{
		// 해당 메뉴를 실행한다
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
