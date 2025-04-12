// HTMLCollectorDemoDlg.h : 헤더 파일
//

#pragma once

// HTML 소스 획득 클래스 헤더
#include "HTMLCollector.h"


// CHTMLCollectorDemoDlg 대화 상자
class CHTMLCollectorDemoDlg : public CDialog
{
// 생성
public:
	CHTMLCollectorDemoDlg(CWnd* pParent = NULL);	// 표준 생성자
	virtual ~CHTMLCollectorDemoDlg();

// 대화 상자 데이터
	//{{AFX_DATA(CHTMLCollectorDemoDlg)
	enum { IDD = IDD_HTMLCOLLECTORDEMO_DIALOG };
	CListCtrl	m_IEList;
	CHTMLCollector	m_HTMLCollector;
	CString	m_strSource;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CHTMLCollectorDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL

	// 웹브라우저 리스트 출력용 이미지 리스트
	CImageList			m_ImageList;


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CHTMLCollectorDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRefreshButton();
	afx_msg void OnSaveButton();
	afx_msg void OnDblclkIeList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg LRESULT OnIEFinderStart(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIEFinderEnd(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIEFinderSelect(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
