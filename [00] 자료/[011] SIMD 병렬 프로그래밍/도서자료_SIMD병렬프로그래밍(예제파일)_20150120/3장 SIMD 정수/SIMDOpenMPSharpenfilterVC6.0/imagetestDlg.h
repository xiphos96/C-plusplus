// imagetestDlg.h : header file
//

#if !defined(AFX_IMAGETESTDLG_H__2DE01114_F9AC_4010_BDAA_92DD25580E05__INCLUDED_)
#define AFX_IMAGETESTDLG_H__2DE01114_F9AC_4010_BDAA_92DD25580E05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CImagetestDlg dialog

class CImagetestDlg : public CDialog
{
// Construction
public:
	void Convolution3x3C(unsigned char* pSrc,unsigned char* pDest,unsigned int nImageWidth, unsigned int nImageHeight, unsigned int * ROIPoint, short* pKernel);
	void Convolution3x3SIMD(unsigned char* pSrc,unsigned char* pDest,unsigned int nImageWidth, unsigned int nImageHeight,
					unsigned int *ROIPoint, short* pKernel);
	CImagetestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CImagetestDlg)
	enum { IDD = IDD_IMAGETEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImagetestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CImagetestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGETESTDLG_H__2DE01114_F9AC_4010_BDAA_92DD25580E05__INCLUDED_)
