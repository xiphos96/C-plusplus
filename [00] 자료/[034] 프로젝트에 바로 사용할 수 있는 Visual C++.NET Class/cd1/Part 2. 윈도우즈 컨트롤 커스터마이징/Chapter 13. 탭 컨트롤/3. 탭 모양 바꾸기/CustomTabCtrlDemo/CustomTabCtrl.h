#if !defined(AFX_CUSTOMTABCTRL_H__2D6E4273_A3DE_4118_8CE5_AAC9F2C07763__INCLUDED_)
#define AFX_CUSTOMTABCTRL_H__2D6E4273_A3DE_4118_8CE5_AAC9F2C07763__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomTabCtrl.h : header file
//

// CArray를 사용하기 위한 헤더 파일
#include <afxtempl.h>

// 사용자 정의 탭에서 부모 다이얼로그에게 보내는 메시지 정의
#define WM_OT_SELCHANGING		(WM_USER + 1)	// 선택 탭이 변경됨을 알리는 메시지
#define WM_OT_SELCHANGE			(WM_USER + 2)	// 선택 탭이 변경되었음을 알리는 메시지

class CCustomTabCtrl;


// 사용자 정의 탭에서 탭에 속하는 컨트롤을 관리하는 클래스
class CControlContainer
{
	// 탭에 속하는 컨트롤의 윈도우 포인터 배열
	CArray<CWnd*, CWnd*>	m_Controls;
	// 현재 보이는 탭인지 여부
	BOOL					m_bShow;

public:
	// 생성자
	CControlContainer();
	// 소멸자
	virtual ~CControlContainer();

	// 컨테이너에 컨트롤을 추가하는 함수
	int AddControl(CWnd *pCtrl);
	// 컨테이너의 컨트롤들을 보이거나 감추는 함수
	void ShowControls(BOOL bShow = TRUE);
};


/////////////////////////////////////////////////////////////////////////////
// CCustomTabCtrl window

// 사용자 정의 탭 컨트롤 클래스
class CCustomTabCtrl : public CTabCtrl
{
// Construction
public:
	CCustomTabCtrl();

// Attributes
public:
	// 탭 버튼의 배경으로 출력할 비트맵 객체들
	CBitmap			m_bmpTabBkgndLeft;
	CBitmap			m_bmpTabBkgndCenter;
	CBitmap			m_bmpTabBkgndRight;
	// 탭 버튼 비트맵들의 비트맵 정보 
	BITMAP			m_infoTabBkgndLeft;
	BITMAP			m_infoTabBkgndCenter;
	BITMAP			m_infoTabBkgndRight;

	COLORREF		m_clrButtonText;			// 버튼의 텍스트 색상
	COLORREF		m_clrButtonFace;			// 버튼의 면 색상
	COLORREF		m_clrButtonLight;			// 버튼의 밝은 색상
	COLORREF		m_clrButtonShadow;			// 버튼의 어두운 색상
	CPen			m_penButtonLight;			// 버튼의 밝은색 펜
	CPen			m_penButtonShadow;			// 버튼의 어두운색 펜

	CPen			m_penBorder;				// 탭의 뷰 영역 테두리 펜
	COLORREF		m_clrBorder;				// 탭의 뷰 영역 테두리 색상
	COLORREF		m_clrBkgnd;					// 탭의 배경 색상

	CRect			m_rcClient;					// 탭의 전체 클라이언트 영역
	CRect			m_rcView;					// 탭의 뷰 영역

	int				m_nHoverItem;				// 현재 마우스가 위치한 항목 번호

	// 탭 컨트롤의 탭에 대한 컨테이너 배열
	CArray<CControlContainer*, CControlContainer*>	m_Containers;

// Operations
public:
	// 특정 탭의 텍스트와 이미지 번호를 리턴하는 함수
	int GetTabText(int nItem, CString &strText);
	// 현재 추가된 탭과 이미지를 계산하여 탭 버튼의 사이즈를 계산하는 함수
	void RecalcTabSize();

	// 탭 버튼 비트맵 핸들을 리턴하는 함수
	HBITMAP GetTabLeftBmp()			{ return (HBITMAP)m_bmpTabBkgndLeft; }
	HBITMAP GetTabCenterBmp()		{ return (HBITMAP)m_bmpTabBkgndCenter; }
	HBITMAP GetTabRightBmp()		{ return (HBITMAP)m_bmpTabBkgndRight; }
	// 탭 버튼 비트맵을 설정하는 함수
	void SetTabBmp(UINT nLeftID, UINT nCenterID, UINT nRightID);
	// 이미지 리스트를 설정하는 함수
	CImageList* SetImageList(CImageList * pImageList);

	// 버튼의 텍스트 색상을 리턴/설정하는 함수
	COLORREF GetButtonTextColor()	{ return m_clrButtonText; }
	void SetButtonTextColor(COLORREF clrText);
	// 버튼의 면 색상을 리턴/설정하는 함수
	COLORREF GetButtonFaceColor()	{ return m_clrButtonFace; }
	void SetButtonFaceColor(COLORREF clrFace);
	// 버튼의 밝은 색상을 리턴/설정하는 함수
	COLORREF GetButtonLightColor()	{ return m_clrButtonLight; }
	void SetButtonLightColor(COLORREF clrLight);
	// 버튼의 어두운 색상을 리턴/설정하는 함수
	COLORREF GetButtonShadowColor()	{ return m_clrButtonShadow; }
	void SetButtonShadowColor(COLORREF clrShadow);
	// 탭의 뷰 영역 테두리 색상을 리턴/설정하는 함수
	COLORREF GetBorderColor()		{ return m_clrBorder; }
	void SetBorderColor(COLORREF clrBorder);
	// 탭의 배경 색상을 리턴/설정하는 함수
	COLORREF GetBkgndColor()		{ return m_clrBkgnd; }
	void SetBkgndColor(COLORREF clrBkgnd);

	// 특정 탭 버튼을 그리는 함수
	void DrawTab(int nItem, CDC *pDC);

	// 특정 탭을 선택하는 함수
	int SetCurSel(int nItem);
	// 특정 탭에 컨트롤을 추가하는 함수
	BOOL AddControl(int nTab, CWnd *pWnd);

	// 새로운 탭을 생성하는 함수
	BOOL InsertItem(int nItem, TCITEM* pTabCtrlItem);
	// 새로운 탭을 생성하는 함수
	BOOL InsertItem(int nItem, LPCTSTR lpszItem);
	// 새로운 탭을 생성하는 함수
	BOOL InsertItem(int nItem, LPCTSTR lpszItem, int nImage);
	// 새로운 탭을 생성하는 함수
	BOOL InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam);
	// 특정 탭을 삭제하는 함수
	BOOL DeleteItem(int nItem);
	// 모든 탭을 삭제하는 함수
	BOOL DeleteAllItems();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomTabCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomTabCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomTabCtrl)
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMTABCTRL_H__2D6E4273_A3DE_4118_8CE5_AAC9F2C07763__INCLUDED_)
