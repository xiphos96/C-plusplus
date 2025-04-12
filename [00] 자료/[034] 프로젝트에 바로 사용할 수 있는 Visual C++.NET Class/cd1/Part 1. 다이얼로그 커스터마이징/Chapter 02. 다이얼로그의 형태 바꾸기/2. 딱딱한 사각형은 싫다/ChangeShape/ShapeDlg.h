#if !defined(AFX_SHAPEDLG_H__9B8553B7_21D8_4CC1_A471_71EEA831148B__INCLUDED_)
#define AFX_SHAPEDLG_H__9B8553B7_21D8_4CC1_A471_71EEA831148B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShapeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShapeDlg dialog

// 다이얼로그의 모양을 변경하기 위한 기본 클래스
class CShapeDlg : public CDialog
{
// Construction
public:
	CShapeDlg(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShapeDlg)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	CRgn		m_rgnBitmap;			// 비트맵에서 추출한 영역을 저장하는 변수

	// 다이얼로그 모양 변경에 사용할 비트맵을 설정하는 함수 : 파일에서 읽기
	void SetShapeBitmap(LPCTSTR pFileName, COLORREF clrTransparent);
	// 다이얼로그 모양 변경에 사용할 비트맵을 설정하는 함수 : 로드된 리소스를 설정
	void SetShapeBitmap(HBITMAP hBitmap, COLORREF clrTransparent);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShapeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShapeDlg)
	afx_msg UINT OnNcHitTest(CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHAPEDLG_H__9B8553B7_21D8_4CC1_A471_71EEA831148B__INCLUDED_)
