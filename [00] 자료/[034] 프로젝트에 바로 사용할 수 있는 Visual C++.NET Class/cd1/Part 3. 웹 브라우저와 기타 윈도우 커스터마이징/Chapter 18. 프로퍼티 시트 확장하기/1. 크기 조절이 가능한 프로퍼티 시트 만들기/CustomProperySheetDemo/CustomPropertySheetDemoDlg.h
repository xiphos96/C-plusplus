// CustomPropertySheetDemoDlg.h : 헤더 파일
//

#pragma once


// CCustomPropertySheetDemoDlg 대화 상자
class CCustomPropertySheetDemoDlg : public CDialog
{
// 생성
public:
	CCustomPropertySheetDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CCustomPropertySheetDemoDlg)
	enum { IDD = IDD_CUSTOMPROPERTYSHEETDEMO_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCustomPropertySheetDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CCustomPropertySheetDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
