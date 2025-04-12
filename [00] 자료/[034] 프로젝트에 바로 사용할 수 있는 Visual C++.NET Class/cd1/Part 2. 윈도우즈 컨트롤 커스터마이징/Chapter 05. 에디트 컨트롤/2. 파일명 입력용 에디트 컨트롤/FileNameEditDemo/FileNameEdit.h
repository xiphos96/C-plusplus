#if !defined(AFX_FILENAMEEDIT_H__48444A6E_7E88_40C8_AB8D_9719B96C8277__INCLUDED_)
#define AFX_FILENAMEEDIT_H__48444A6E_7E88_40C8_AB8D_9719B96C8277__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileNameEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileNameEdit window

// 파일/폴더 선택 버튼 클래스 헤더 파일
#include "FileBrowseButton.h"

// 파일/폴더 선택 버튼의 폭
#define CONST_BROWSE_BTN_WIDTH		18

// CFileNameEdit를 사용하여 DDX/DDV를 실행하기 위한 함수
void AFXAPI DDX_FileName(CDataExchange* pDX, int nIDC, CString& strText);


// 파일명 입력용 에디트 클래스
class CFileNameEdit : public CEdit
{
// Construction
public:
	CFileNameEdit();

// Attributes
public:
	// 에디트 컨트롤의 전체 클라이언트 영역
	CRect				m_rcEntireArea;
	// 버튼 영역을 제외한 클라이언트 영역
	CRect				m_rcClipArea;
	// 버튼 영역
	CRect				m_rcButton;
	// 파일/폴더 선택 버튼
	CFileBrowseButton	m_btnBrowse;
	// 파일 모드인지 폴더 모드인지 여부
	BOOL				m_bIsFileMode;
	// 현재 읽기 전용인지 여부
	BOOL				m_bIsReadOnly;
	// 읽기 전용일 경우 긴 경로명을 저장할 변수
	CString				m_strLongPath;

// Operations
public:
	// 에디트 컨트롤의 편집 영역을 전체 클라이언트로 조정하는 함수
	void RestoreArea();
	// 파일/폴더 선택 대화상자를 출력하는 함수
	void OnBrowse();

	// 파일 모드인지 리턴하는 함수
	BOOL IsFileMode()					{ return m_bIsFileMode; }
	// 파일 모드 혹은 폴더 모드 설정 함수
	void SetFileMode(BOOL bFile)		{ m_bIsFileMode = bFile; }

	// 짧은 경로를 에디트 컨트롤에 설정하는 함수
	void SetShortText(LPCTSTR lpszString);
	// 읽기 전용 여부에 따라 에디트 컨트롤의 텍스트를 리턴하는 함수
	int GetWindowText(LPTSTR lpszStringBuf, int nMaxCount) const;
	// 읽기 전용 여부에 따라 에디트 컨트롤의 텍스트를 리턴하는 함수
	void GetWindowText(CString& rString) const;
	// 읽기 전용 여부에 따라 에디트 컨트롤에 텍스트를 설정하는 함수
	void SetWindowText(LPCTSTR lpszString);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileNameEdit)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFileNameEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFileNameEdit)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnDestroy();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILENAMEEDIT_H__48444A6E_7E88_40C8_AB8D_9719B96C8277__INCLUDED_)
