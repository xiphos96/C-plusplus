// EncoderConfigDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "EncoderConfigDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEncoderConfigDlg dialog


CEncoderConfigDlg::CEncoderConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEncoderConfigDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEncoderConfigDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEncoderConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEncoderConfigDlg)
	DDX_Control(pDX, IDC_PROPSHELLCTRL_CONFIG, m_PropShellConfig);
	//}}AFX_DATA_MAP
}

void CEncoderConfigDlg::SetEncoder(IWMEncoder* pEncoder)
{
	m_pEncoder = pEncoder;

}
BEGIN_MESSAGE_MAP(CEncoderConfigDlg, CDialog)
	//{{AFX_MSG_MAP(CEncoderConfigDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEncoderConfigDlg message handlers

BOOL CEncoderConfigDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// �̵�� �ҽ� ������Ƽ ������ �������̽�
	IUnknown* pSourcesPage;
	// �̵�� �÷��̾ ��Ÿ�� ������ ���� ������Ƽ ������ �������̽�
	IUnknown* pDescriptionPage;
	// �������� ���� �߰� �Ӽ� ������Ƽ ������ �������̽�
	IUnknown* pAttributesPage;
	// �������� ���ÿ� ���� ������Ƽ ������ �������̽�
	IUnknown* pEncodingPage;
	// �̵�� ��¿� ���� ������Ƽ ������ �������̽�
	IUnknown* pOutputPage;

	// �̵�� �ҽ� ������Ƽ ������ �������̽��� �����Ѵ�
	HRESULT hrSrc = CoCreateInstance(CLSID_WMEncSourcesAltPage, NULL,
		CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pSourcesPage);
	// �̵�� �÷��̾ ��Ÿ�� ������ ���� ������Ƽ ������ �������̽��� �����Ѵ�
	HRESULT hrDesc = CoCreateInstance(CLSID_WMEncDisplayInfoPage, NULL,
		CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pDescriptionPage);
	// �������� ���� �߰� �Ӽ� ������Ƽ ������ �������̽��� �����Ѵ�
	HRESULT hrAttr = CoCreateInstance(CLSID_WMEncAttributesPage, NULL,
		CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pAttributesPage);
	// �������� ���ÿ� ���� ������Ƽ ������ �������̽��� �����Ѵ�
	HRESULT hrEnc = CoCreateInstance(CLSID_WMEncProfilePage, NULL,
		CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pEncodingPage);
	// �̵�� ��¿� ���� ������Ƽ ������ �������̽��� �����Ѵ�
	HRESULT hrOut = CoCreateInstance(CLSID_WMEncOutputPage, NULL,
		CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pOutputPage);
	
	// MSPropShell ��Ʈ�ѿ� �̵�� ���ڴ� ���� ������Ƽ ���������� �߰��Ѵ�
	m_PropShellConfig.AddObject(m_pEncoder);

	m_PropShellConfig.AddPage(pSourcesPage);
	m_PropShellConfig.AddPage(pDescriptionPage);
	m_PropShellConfig.AddPage(pAttributesPage);
	m_PropShellConfig.AddPage(pEncodingPage);
	m_PropShellConfig.AddPage(pOutputPage);

	// ������Ƽ ������ �������̽����� �����Ѵ�
	pSourcesPage->Release();
	pDescriptionPage->Release();
	pAttributesPage->Release();
	pEncodingPage->Release();
	pOutputPage->Release();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEncoderConfigDlg::OnOK() 
{
	// ������Ƽ ���������� �ɼ� ���� �̵�� ���ڴ����� �����ϵ��� �Ѵ�
	m_PropShellConfig.Apply();
	// �̵�� ���ڴ� ������ �ʱ�ȭ�Ѵ�
	m_pEncoder->PrepareToEncode(TRUE);

	// ���� �̵�� �ҽ��� ȭ�� ��ȭ�� �����ߴ��� Ȯ���Ѵ�
	IWMEncSourceGroupCollection	*pSrcGrpColl;
	IWMEncSourceGroup			*pSrcGrp;
	IWMEncSource				*pVidSrc;

	HRESULT hr;
	CComVariant varProfile;
	BOOL bOK = TRUE;

	// �ҽ� �׷� �÷����� ��´�
	hr = m_pEncoder->get_SourceGroupCollection(&pSrcGrpColl);
	if(SUCCEEDED(hr))
	{
		// ù��° �ҽ� �׷��� ��´�
		varProfile.vt	= VT_I2;
		varProfile.iVal	= 0;
		hr = pSrcGrpColl->Item(varProfile, &pSrcGrp);
		if(SUCCEEDED(hr))
		{
			// ���� �ҽ��� ��´�
			hr = pSrcGrp->get_Source(WMENC_VIDEO, 0, &pVidSrc);
			if(SUCCEEDED(hr))
			{
				CComBSTR bstrStream;
				CComBSTR bstrScheme;
				CComBSTR bstrSource;

				// ���� �ҽ��� ������ ��´�
				hr = pVidSrc->GetInput(&bstrStream, &bstrScheme, &bstrSource);
				if(SUCCEEDED(hr))
				{
					// ���� ȭ�� ��ȭ �ҽ����
					if(_wcsicmp(bstrScheme, L"screencap") == 0)
					{
						// ���������� ��´�
						IWMEncProfile				*pPro;
						hr = pSrcGrp->get_Profile(&pPro);
						if(SUCCEEDED(hr))
						{
							// ���������� �̸��� ��´�
							CComBSTR bstrProfile;
							hr = pPro->get_Name(&bstrProfile);
							if(SUCCEEDED(hr))
							{
								// ȭ�� ��ȭ�� ������������ Ȯ���Ѵ�
								if(_wcsnicmp(bstrProfile, L"Screen capture", 14) != 0)
								{
									bOK = FALSE;
								}
							}
						}
					}
				}
			}
		}
	}
	if(!bOK)
	{
		::AfxMessageBox("ȭ�� ��ȭ ��� ����, Profile�� �ݵ�� Screen Capture ������ �����ϼ���.",
			MB_OK | MB_ICONINFORMATION);
		return;
	}

	CDialog::OnOK();
}
