// SIMDSharpenfilterDlg.h : header file
//

#pragma once


// CSIMDSharpenfilterDlg dialog
class CSIMDSharpenfilterDlg : public CDialog
{
// Construction
public:
	CSIMDSharpenfilterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SIMDSHARPENFILTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void Convolution3x3SIMD(unsigned char* pSrc,unsigned char* pDest,unsigned int nImageWidth, unsigned int nImageHeight,unsigned int *ROIPoint, short* pKernel);
	void Convolution3x3C(unsigned char *pSrc, unsigned char *pDest, unsigned int nImageWidth, unsigned int nImageHeight, unsigned int *ROIPoint, short *pKernel);
};
