// FileNameEditDemoDlg.h : 헤더 파일
//

#pragma once

// 파일명 입력용 에디트 컨트롤
#include "FileNameEdit.h"

// CFileNameEditDemoDlg 대화 상자
class CFileNameEditDemoDlg : public CDialog
{
// 생성
public:
	CFileNameEditDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CFileNameEditDemoDlg)
	enum { IDD = IDD_FILENAMEEDITDEMO_DIALOG };
	CFileNameEdit	m_FolderEdit2;
	CFileNameEdit	m_FolderEdit;
	CFileNameEdit	m_FileEdit2;
	CFileNameEdit	m_FileEdit;
	CString	m_strFilePath;
	CString	m_strFolderPath;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFileNameEditDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CFileNameEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetTextButton();
	afx_msg void OnGetTextButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
