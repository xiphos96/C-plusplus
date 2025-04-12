// FlatListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "FlatListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlatListCtrl

CFlatListCtrl::CFlatListCtrl()
{
}

CFlatListCtrl::~CFlatListCtrl()
{
	// 이미지 리스트가 생성된 상태라면 소멸 시킨다
	if(m_ImageList.m_hImageList)
		m_ImageList.DeleteImageList();
}


BEGIN_MESSAGE_MAP(CFlatListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CFlatListCtrl)
	//}}AFX_MSG_MAP
	// 반드시 아래와 같이 타입에 따른 핸들러를 지정해야 한다
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW, 0, 0xFFFF, OnNeedText)
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnNeedText)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlatListCtrl message handlers

void CFlatListCtrl::PreSubclassWindow() 
{
	CListCtrl::PreSubclassWindow();

	// 기본 헤더 컨트롤 대신 평면 헤더 컨트롤을 리스트 컨트롤에 설정한다
	m_wndHeaderCtrl.SubclassWindow(::GetDlgItem(m_hWnd, 0));

	// 행 전체가 선택되는 속성을 설정한다
	SetExtendedStyle(LVS_EX_FULLROWSELECT);

	// 윈도우가 갖고 있는 툴팁 기능을 활성화 한다
	EnableToolTips();
}

void CFlatListCtrl::SetHeaderImage(UINT nBitmap, int cx, int nGrow)
{
	// 만약 이미지 리스트가 생성되어 있다면 소멸 시킨다
	if(m_ImageList.m_hImageList)
		m_ImageList.DeleteImageList();

	// 이미지 리스트를 생성한다
	m_ImageList.Create(nBitmap, cx, nGrow, RGB(255, 255, 255));
	// 평면 헤더 컨트롤에 이미지 리스트를 설정한다
	m_wndHeaderCtrl.SetImageList(&m_ImageList);

	// 헤더 컨트롤의 항목들에 대해 이미지를 설정한다
	int nSize = m_wndHeaderCtrl.GetItemCount(), i;
	HDITEM Item;

	for(i = 0; i < nSize; i++)
	{
		// 헤더의 항목 정보를 얻는다
		Item.mask = HDI_FORMAT | HDI_IMAGE;
		m_wndHeaderCtrl.GetItem(i, &Item);

		// 이미지 속성을 설정한다
		Item.fmt	|= HDF_IMAGE;
		Item.iImage = i;
		m_wndHeaderCtrl.SetItem(i, &Item);
	}
}

BOOL CFlatListCtrl::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	LPNMHEADER pNMHD = (LPNMHEADER)lParam;

	switch(pNMHD->hdr.code)
	{
	case HDN_ITEMCHANGEDA:
	case HDN_ITEMCHANGEDW:
		// 만약 항목에 변화가 생기면 헤더 컨트롤의 툴팁 영역을 다시 계산한다
		m_wndHeaderCtrl.RecalcToolRect();
		break;
	}
	
	return CListCtrl::OnNotify(wParam, lParam, pResult);
}

// 컬럼 추가 처리 함수
int CFlatListCtrl::InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat, int nWidth, int nSubItem)
{
	// 리스트 컨트롤의 기본 컬럼 추가 루틴을 실행한다
	int nIndex = CListCtrl::InsertColumn(nCol, lpszColumnHeading, nFormat, nWidth, nSubItem);

	// 만약 리포트 형식이고 컬럼이 정상적으로 추가되었다면
	if(nIndex >= 0 && (GetStyle() & LVS_TYPEMASK) == LVS_REPORT)
	{
		// 헤더 컨트롤의 해당 컬럼에 툴팁을 추가한다
		if(!m_wndHeaderCtrl.AddTool(nIndex, lpszColumnHeading))	return -1;
	}

	return nIndex;
}

// EnableToolTips()에 의한 툴팁 출력 여부 요청 함수
int CFlatListCtrl::OnToolHitTest(CPoint point, TOOLINFO * pTI) const
{
	// 클라이언트 영역을 구한다
	CRect rcTemp;
	GetClientRect(&rcTemp);

	// 만약 클라이언트 영역 안에 있지 않다면 리턴
	if(!rcTemp.PtInRect(point))			return -1;
	// 만약 항목이 없다면 리턴
	if(GetItemCount() == 0)				return -1;

	// 첫번째 보이는 항목의 번호를 얻는다
	int nTop	= GetTopIndex();
	// 한 페이지에 보이는 항목의 갯수를 얻어 마지막 항목의 번호를 계산한다
	int nBottom = nTop + GetCountPerPage(), i;

	// 마지막 항목의 번호가 항목 범위를 초과한다면 조정한다
	if(nBottom >= GetItemCount())	nBottom = GetItemCount() - 1;

	// 화면에 보이는 항목들에 대해 툴팁 여부를 조사한다
	for(i = nTop; i <= nBottom; i++)
	{
		// 항목의 영역을 구한다
		GetItemRect(i, rcTemp, LVIR_BOUNDS);

		// 항목의 영역에 속한다면
		if(rcTemp.PtInRect(point))
		{
			// 툴팁 출력을 위한 속성을 설정한다
			pTI->hwnd		= m_hWnd;
			pTI->uId		= (UINT)(i + 1);
			// TTN_NEEDTEXT 알림 메시지를 받도록 LPSTR_TEXTCALLBACK을 설정한다
			pTI->lpszText	= LPSTR_TEXTCALLBACK;
			pTI->rect		= rcTemp;

			// 툴팁 ID를 리턴한다
			return pTI->uId;
		}
	}

	return -1;
}

// 툴팁 텍스트를 얻기 위해 호출되는 함수
BOOL CFlatListCtrl::OnNeedText(UINT id, NMHDR* pNMHDR, LRESULT* pResult)
{
	// ASCII 코드와 UNICODE에 대해 모두 처리한다
	TOOLTIPTEXTA* pTipAscii = (TOOLTIPTEXTA*)pNMHDR;
	TOOLTIPTEXTW* pTipUnicode = (TOOLTIPTEXTW*)pNMHDR;

	// 툴팁 ID를 얻는다
	UINT nID = pNMHDR->idFrom;

	// 만약 ID가 없다면 리턴
	if(nID == 0)		return FALSE;

	// 툴팁 ID에서 항목 번호를 얻는다
	int nItem = nID - 1;

	// 해당 항목에 대한 툴팁 텍스트를 구성한다
	CString strTipText;
	strTipText.Format("[%s] - [%s] : [%s]",
		GetItemText(nItem, 0),
		GetItemText(nItem, 1),
		GetItemText(nItem, 2));

	// 만약 아스키 코드라면
	if(pNMHDR->code == TTN_NEEDTEXTA)
	{
		// 툴팁 텍스트를 아스키코드 툴팁 구조체에 설정한다
		pTipAscii->lpszText = LPSTR(LPCTSTR(strTipText));
	}
	else
	{
		// 툴팁 텍스트를 유니코드 툴팁 구조체에 설정한다
		pTipUnicode->lpszText = (WCHAR*)strTipText.AllocSysString();
	}

	*pResult = 0;

	return TRUE;
}
