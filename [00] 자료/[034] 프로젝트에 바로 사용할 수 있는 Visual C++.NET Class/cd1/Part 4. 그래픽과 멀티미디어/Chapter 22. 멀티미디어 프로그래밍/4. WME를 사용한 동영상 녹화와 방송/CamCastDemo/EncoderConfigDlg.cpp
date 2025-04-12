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
	
	// 미디어 소스 프로퍼티 페이지 인터페이스
	IUnknown* pSourcesPage;
	// 미디어 플레이어에 나타날 컨텐츠 정보 프로퍼티 페이지 인터페이스
	IUnknown* pDescriptionPage;
	// 컨텐츠에 대한 추가 속성 프로퍼티 페이지 인터페이스
	IUnknown* pAttributesPage;
	// 프로파일 선택에 관한 프로퍼티 페이지 인터페이스
	IUnknown* pEncodingPage;
	// 미디어 출력에 관한 프로퍼티 페이지 인터페이스
	IUnknown* pOutputPage;

	// 미디어 소스 프로퍼티 페이지 인터페이스를 생성한다
	HRESULT hrSrc = CoCreateInstance(CLSID_WMEncSourcesAltPage, NULL,
		CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pSourcesPage);
	// 미디어 플레이어에 나타날 컨텐츠 정보 프로퍼티 페이지 인터페이스를 생성한다
	HRESULT hrDesc = CoCreateInstance(CLSID_WMEncDisplayInfoPage, NULL,
		CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pDescriptionPage);
	// 컨텐츠에 대한 추가 속성 프로퍼티 페이지 인터페이스를 생성한다
	HRESULT hrAttr = CoCreateInstance(CLSID_WMEncAttributesPage, NULL,
		CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pAttributesPage);
	// 프로파일 선택에 관한 프로퍼티 페이지 인터페이스를 생성한다
	HRESULT hrEnc = CoCreateInstance(CLSID_WMEncProfilePage, NULL,
		CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pEncodingPage);
	// 미디어 출력에 관한 프로퍼티 페이지 인터페이스를 생성한다
	HRESULT hrOut = CoCreateInstance(CLSID_WMEncOutputPage, NULL,
		CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pOutputPage);
	
	// MSPropShell 컨트롤에 미디어 인코더 관련 프로퍼티 페이지들을 추가한다
	m_PropShellConfig.AddObject(m_pEncoder);

	m_PropShellConfig.AddPage(pSourcesPage);
	m_PropShellConfig.AddPage(pDescriptionPage);
	m_PropShellConfig.AddPage(pAttributesPage);
	m_PropShellConfig.AddPage(pEncodingPage);
	m_PropShellConfig.AddPage(pOutputPage);

	// 프로퍼티 페이지 인터페이스들을 해제한다
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
	// 프로퍼티 페이지들이 옵션 값을 미디어 인코더에게 설정하도록 한다
	m_PropShellConfig.Apply();
	// 미디어 인코더 엔진을 초기화한다
	m_pEncoder->PrepareToEncode(TRUE);

	// 비디오 미디어 소스로 화면 녹화를 선택했는지 확인한다
	IWMEncSourceGroupCollection	*pSrcGrpColl;
	IWMEncSourceGroup			*pSrcGrp;
	IWMEncSource				*pVidSrc;

	HRESULT hr;
	CComVariant varProfile;
	BOOL bOK = TRUE;

	// 소스 그룹 컬렉션을 얻는다
	hr = m_pEncoder->get_SourceGroupCollection(&pSrcGrpColl);
	if(SUCCEEDED(hr))
	{
		// 첫번째 소스 그룹을 얻는다
		varProfile.vt	= VT_I2;
		varProfile.iVal	= 0;
		hr = pSrcGrpColl->Item(varProfile, &pSrcGrp);
		if(SUCCEEDED(hr))
		{
			// 비디오 소스를 얻는다
			hr = pSrcGrp->get_Source(WMENC_VIDEO, 0, &pVidSrc);
			if(SUCCEEDED(hr))
			{
				CComBSTR bstrStream;
				CComBSTR bstrScheme;
				CComBSTR bstrSource;

				// 비디오 소스의 정보를 얻는다
				hr = pVidSrc->GetInput(&bstrStream, &bstrScheme, &bstrSource);
				if(SUCCEEDED(hr))
				{
					// 만약 화면 녹화 소스라면
					if(_wcsicmp(bstrScheme, L"screencap") == 0)
					{
						// 프로파일을 얻는다
						IWMEncProfile				*pPro;
						hr = pSrcGrp->get_Profile(&pPro);
						if(SUCCEEDED(hr))
						{
							// 프로파일의 이름을 얻는다
							CComBSTR bstrProfile;
							hr = pPro->get_Name(&bstrProfile);
							if(SUCCEEDED(hr))
							{
								// 화면 녹화용 프로파일인지 확인한다
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
		::AfxMessageBox("화면 녹화 모드 사용시, Profile을 반드시 Screen Capture 종류로 설정하세요.",
			MB_OK | MB_ICONINFORMATION);
		return;
	}

	CDialog::OnOK();
}
