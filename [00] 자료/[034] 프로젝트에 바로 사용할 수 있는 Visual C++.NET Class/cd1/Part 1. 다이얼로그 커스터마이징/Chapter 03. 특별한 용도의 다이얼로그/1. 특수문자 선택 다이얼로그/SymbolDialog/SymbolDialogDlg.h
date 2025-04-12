// SymbolDialogDlg.h : 헤더 파일
//

#pragma once


// CSymbolDialogDlg 대화 상자
class CSymbolDialogDlg : public CDialog
{
// 생성
public:
	CSymbolDialogDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CSymbolDialogDlg)
	enum { IDD = IDD_SYMBOLDIALOG_DIALOG };
	CComboBox	m_FontCombo;					// 시스템의 폰트를 나열하는 콤보 박스
	CString	m_strCode;							// 선택된 특수 문자의 코드를 출력하는 에디트 박스
	int		m_nType;							// 특수 문자의 코드 종류
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CSymbolDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CSymbolDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelectButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
