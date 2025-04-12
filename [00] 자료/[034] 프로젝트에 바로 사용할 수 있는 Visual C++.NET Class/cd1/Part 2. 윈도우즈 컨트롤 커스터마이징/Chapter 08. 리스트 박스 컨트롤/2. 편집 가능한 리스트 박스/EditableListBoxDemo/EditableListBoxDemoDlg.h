// EditableListBoxDemoDlg.h : 헤더 파일
//

#pragma once

// 텍스트 편집 리스트 박스 컨트롤 헤더
#include "EditableListBox.h"


// CEditableListBoxDemoDlg 대화 상자
class CEditableListBoxDemoDlg : public CDialog
{
// 생성
public:
	CEditableListBoxDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CEditableListBoxDemoDlg)
	enum { IDD = IDD_EDITABLELISTBOXDEMO_DIALOG };
	CEditableListBox	m_EditableList;
	CString	m_strText;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CEditableListBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CEditableListBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
