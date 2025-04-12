#if !defined(AFX_CAMCAST_H__788A92EC_11DA_4DB3_A843_E96B645FA70B__INCLUDED_)
#define AFX_CAMCAST_H__788A92EC_11DA_4DB3_A843_E96B645FA70B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CamCast.h : header file
//

// Windows Media Encoder SDK
#include "wmencode.h"
#include "wmencvu.h"

// ATL : CComBSTR�� CComVariant�� ����ϱ� ���� ��� ����
#include "Atlbase.h"


/////////////////////////////////////////////////////////////////////////////
// CCamCast window


// ������ ��ȭ ��� Ŭ����
class CCamCast : public CStatic
{
// Construction
public:
	CCamCast();

// Attributes
public:
	IWMEncoder*					m_pEncoder;			// �̵�� ���ڴ� �������̽�
	IWMEncDataView*				m_pPreview;			// �̸����� �������̽�
	IWMEncDataViewCollection*	m_pPreviewColl;		// �̸����� �÷��� �������̽�
	long						m_lCookie;			// �̸����� ��Ű

	BOOL						m_bAudio;			// ����� �ҽ� ��ġ ���� ����
	BOOL						m_bVideo;			// ���� �ҽ� ��ġ ���� ����
	CComBSTR					m_strDeviceAudio;	// ����� ��ġ�� �̸�
	CComBSTR					m_strDeviceVideo;	// ���� ��ġ�� �̸�

// Operations
public:

	// ������ ��ȭ ����� ���� �ʱ�ȭ �Լ�
	BOOL Initialize();
	// ������ ���Ϸ� ��ȭ�ϴ� �Լ�
	BOOL Record(LPCTSTR pFileName);
	// ���ͳ����� �������� ����ϴ� �Լ�
	BOOL Cast(int nPort = 8080);
	// ������ ��ȭ�� ����� �����ϴ� �Լ�
	BOOL Stop();
	// ������ ��ȭ ��ۿ� ���� �ɼ� ���̾�α� ��� �Լ� 
	BOOL Config();

	// ���� ��ġ�� �����ϴ��� �����ϴ� �Լ�
	BOOL CanVideo()				{ return m_pEncoder && m_bVideo; }
	// ����� ��ġ�� �����ϴ��� �����ϴ� �Լ�
	BOOL CanAudio()				{ return m_pEncoder && m_bAudio; }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamCast)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCamCast();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCamCast)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMCAST_H__788A92EC_11DA_4DB3_A843_E96B645FA70B__INCLUDED_)
