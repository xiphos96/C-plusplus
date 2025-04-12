// CamCast.cpp : implementation file
//

#include "stdafx.h"
#include "camcastdemo.h"
#include "CamCast.h"

// ������ ��ȭ ��ۿ� ���� �ɼ� ���̾�α� Ŭ���� �������
#include "EncoderConfigDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCamCast

CCamCast::CCamCast()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	m_pEncoder			= NULL;
	m_pPreview			= NULL;
	m_pPreviewColl		= NULL;
	m_lCookie			= -1;
	m_bAudio			= FALSE;
	m_bVideo			= FALSE;
}

CCamCast::~CCamCast()
{
	// �̵�� ���ڴ� �������̽��� �����Ѵ�
	if(m_pEncoder)
	{
		m_pEncoder->PrepareToEncode(VARIANT_FALSE);
		m_pEncoder->Release();
	}
	// �̸����� �÷��� �������̽��� �����Ѵ�
	if(m_pPreviewColl)
	{
		m_pPreviewColl->RemoveAll();
		m_pPreviewColl->Release();
	}
	// �̸����� �������̽��� �����Ѵ�
	if(m_pPreview)
	{
		m_pPreview->Release();
	}

	m_pEncoder			= NULL;
	m_pPreview			= NULL;
	m_pPreviewColl		= NULL;
	m_lCookie			= -1;
	m_bAudio			= FALSE;
	m_bVideo			= FALSE;
}


BEGIN_MESSAGE_MAP(CCamCast, CStatic)
	//{{AFX_MSG_MAP(CCamCast)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamCast message handlers

// ������ ��ȭ ����� ���� �ʱ�ȭ �Լ�
BOOL CCamCast::Initialize()
{
	HRESULT hr;

	// ������ ������ �̵�� ���ڴ� �������̽��� �ִٸ� �����Ѵ�
	if(m_pEncoder)	m_pEncoder->Release();

	m_bAudio			= FALSE;
	m_bVideo			= FALSE;

	// �̵�� ���ڴ� �������̽��� �����Ѵ�
	hr = CoCreateInstance(	CLSID_WMEncoder,
							NULL,
							CLSCTX_INPROC_SERVER,
							IID_IWMEncoder,
							(void**)&m_pEncoder);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "MS Windows Media Encoder�� ���������� ��ġ���� �ʾҽ��ϴ�.",
			"������ ��� ����", MB_OK | MB_ICONERROR);
		return FALSE;
	}

	CComBSTR bstrName = NULL;
	CComVariant varProfile;

	long lCount;
	int i;

	IWMEncSourcePluginInfoManager* pSrcPlugMgr;
	IWMEncPluginInfo* pPlugInfo;

	// �ҽ� �÷����� ������ �������̽��� ��´�
	hr = m_pEncoder->get_SourcePluginInfoManager(&pSrcPlugMgr);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "�ý��ۿ��� �̵�� ��� ���� ������ ���� �� �����ϴ�.",
			"������ ��� ����", MB_OK | MB_ICONERROR);

		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// ���� �ý����� �ҽ� �÷����� ������ ��´�
    hr = pSrcPlugMgr->get_Count(&lCount);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "�ý��ۿ� ��ġ�� ������ ��� �����ϴ�.",
			"������ ��� ����", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	long lResCount;
	CComBSTR bstrResource;
	VARIANT_BOOL bResources;

	// ���� �ý����� �ҽ� �÷������� ��� �˻��Ѵ�
	for(i=0; i<lCount; i++)
	{
		// �ҽ� �÷����� �������̽��� ��´�
		hr = pSrcPlugMgr->Item(i, &pPlugInfo);

		// �ҽ� �÷������� �̸��� ��´�
		hr = pPlugInfo->get_Name(&bstrName);

		// ������� ���� ĸ�� ��ġ���� Ȯ���Ѵ�
		if(_wcsicmp(bstrName, L"Audio Capture Device") == 0
			|| _wcsicmp(bstrName, L"Video Capture Device") == 0
			|| _wcsicmp(bstrName, L"����� ĸó ��ġ") == 0
			|| _wcsicmp(bstrName, L"���� ĸó ��ġ") == 0)
		{
			// �ҽ� �÷������� ���¸� ��´�
			hr = pPlugInfo->get_SchemeType(&bstrResource);
			// �ҽ� �÷������� ���°� ��ġ���
			if(_wcsicmp(bstrResource, L"device")==0)
			{
				// ���ҽ��� �ִ��� Ȯ���Ѵ�
				hr = pPlugInfo->get_Resources(&bResources); 
				// �ҽ� �÷������� ���ҽ��� �ִٸ�
				if(bResources==VARIANT_TRUE)
				{
					// �ҽ� �÷����ο� ���� ���ҽ��� ������ ��´�
					hr = pPlugInfo->get_Count(&lResCount);

					if(lResCount > 0)
					{
						// ���� ����� ĸ�� ��ġ�� ���� ���ҽ����
						if(_wcsicmp(bstrName, L"Audio Capture Device") == 0
							|| _wcsicmp(bstrName, L"����� ĸó ��ġ") == 0)
						{
							// ���ҽ� �̸��� ��´�
							hr = pPlugInfo->Item(1, &bstrResource);
							// ����� �ҽ��� ���� ������ �̸��� �����Ѵ�
							m_strDeviceAudio = L"device://";
							m_strDeviceAudio += bstrResource;
							m_bAudio = TRUE;
						}
						else
							// ���� ���� ĸ�� ��ġ�� ���� ���ҽ����
							if(_wcsicmp(bstrName, L"Video Capture Device") == 0
								|| _wcsicmp(bstrName, L"���� ĸó ��ġ") == 0)
							{
								// ���ҽ� �̸��� ��´�
								hr = pPlugInfo->Item(1, &bstrResource);
								// ���� �ҽ��� ���� ������ �̸��� �����Ѵ�
								m_strDeviceVideo = L"device://";
								m_strDeviceVideo += bstrResource;
								m_bVideo = TRUE;
							}
					}
				}
			}
		}
    }

	// ���� ������� ������ ���� �ҽ��� ã�� ���ߴٸ� �����Ѵ�
	if(!m_bAudio && !m_bVideo)
	{
		::MessageBox(NULL, "�ý��ۿ� ����� ��ġ�� ���� ��ġ�� ��ġ���� �ʾҽ��ϴ�.",
				"������ ��� ����", MB_OK | MB_ICONERROR);

		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	IWMEncSourceGroupCollection	*pSrcGrpColl = NULL;
	IWMEncSourceGroup			*pSrcGrp = NULL;
	IWMEncSource				*pAudSrc = NULL;
	IWMEncSource				*pVidSrc = NULL;
	IWMEncProfileCollection		*pProColl = NULL;
	IWMEncProfile				*pPro = NULL;

	// �̵�� ���ڴ��� �ҽ� �׷� �÷����� ��´�
	hr = m_pEncoder->get_SourceGroupCollection(&pSrcGrpColl);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "��Ƽ�̵�� �ҽ� �׷��� ���� �� �����ϴ�.",
			"������ ��� ����", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// ���� ���ø����̼��� ���� �ҽ� �׷��� �߰��Ѵ�
	hr = pSrcGrpColl->Add(L"CamCast", &pSrcGrp);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "�ҽ��� �ý��ۿ� �߰��� �� �����ϴ�.",
			"������ ��� ����", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// ���� ����� �ҽ��� �ý��ۿ� �����Ѵٸ�
	if(m_bAudio)
	{
		// ����� �ҽ��� �ҽ� �׷쿡 �߰��Ѵ�
		hr = pSrcGrp->AddSource(WMENC_AUDIO, &pAudSrc);
		if(!SUCCEEDED(hr))
		{
			m_bAudio = FALSE;
		}
	}
	// ���� ���� �ҽ��� �ý��ۿ� �����Ѵٸ�
	if(m_bVideo)
	{
		// ���� �ҽ��� �ҽ� �׷쿡 �߰��Ѵ�
		hr = pSrcGrp->AddSource(WMENC_VIDEO, &pVidSrc);
		if(!SUCCEEDED(hr))
		{
			m_bVideo = FALSE;
		}
	}

	// �̵�� ���ڴ��� �������� �÷����� ��´�
	hr = m_pEncoder->get_ProfileCollection(&pProColl);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "�ý��ۿ� ��ġ�� �������Ͽ� ������ �� �����ϴ�.",
			"������ ��� ����", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// �������� �÷��ǿ� ����� �������� ������ ��´�
	varProfile.vt = VT_DISPATCH;
	hr = pProColl->get_Count(&lCount);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "�ý��ۿ� ��ġ�� ���������� �������� �ʽ��ϴ�.",
			"������ ��� ����", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// �������� �÷����� ��� ���������� �˻��Ѵ�
	for(i = 0; i < lCount; i++)
	{
		// �������� �������̽��� ��´�
		hr = pProColl->Item(i, &pPro);
		if(!SUCCEEDED(hr))
		{
			m_pEncoder->Release();
			m_pEncoder = NULL;
			return FALSE;
		}
		// ���������� �̸��� ��´�
		hr = pPro->get_Name(&bstrName);
		if(!SUCCEEDED(hr))
		{
			m_pEncoder->Release();
			m_pEncoder = NULL;
			return FALSE;
		}
		// ���ø����̼ǿ��� ����Ϸ��� ������������ Ȯ���Ѵ�
		if(_wcsicmp(bstrName, L"�� ������ ����(56Kbps)") == 0)
		{
			// �ҽ� �׷쿡 ���������� �����Ѵ�
			varProfile.pdispVal = pPro;
			hr = pSrcGrp->put_Profile(varProfile);
			if(!SUCCEEDED(hr))
			{
				m_pEncoder->Release();
				m_pEncoder = NULL;
				return FALSE;
			}
			break;
		}
	}
	varProfile.vt = NULL;
	varProfile.pdispVal = NULL;
	// ���� ���ø����̼ǿ��� ����Ϸ��� ���������� �������������� �����Ѵ�
	if(i >= lCount)
	{
		::MessageBox(NULL, "�� ������ ���� ���������� ��ġ���� �ʾҽ��ϴ�.",
			"������ ��� ����", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// ������ ������ �̸����� �������̽��� �ִٸ� �����Ѵ�
	if(m_pPreview)		m_pPreview->Release();
	m_pPreview = NULL;

	// ���� ���� �ý��ۿ� ���� �ҽ��� �����Ѵٸ�
	if(m_bVideo && pVidSrc)
	{
		// �̸����� �������̽��� �����Ѵ�
		hr = CoCreateInstance(	CLSID_WMEncPreview,
								NULL,
								CLSCTX_INPROC_SERVER,
								IID_IWMEncDataView,
								(void**)&m_pPreview);
		if(!SUCCEEDED(hr))
		{
			m_pPreview = NULL;
			m_pPreviewColl = NULL;
		}

		if(m_pPreview)
		{
			// ���� �ҽ��� �̸����� �÷��� �������̽��� ��´�
			hr = pVidSrc->get_PreviewCollection(&m_pPreviewColl);
			if(!SUCCEEDED(hr))
			{
				m_pPreview->Release();
				m_pPreview = NULL;
				m_pPreviewColl = NULL;
			}
			else
			{
				// �̸����� �÷��ǿ� ���� ������ �̸����� �������̽��� �߰��Ѵ�
				// �̶� ���ο� �̸����� �������̽��� ���� �̸����� �÷����� ��Ű�� ��´�
				m_lCookie = -1;
				hr = m_pPreviewColl->Add(m_pPreview, &m_lCookie);
				if(!SUCCEEDED(hr))
				{
					m_pPreviewColl->Release();
					m_pPreview->Release();
					m_pPreviewColl = NULL;
					m_pPreview = NULL;
				}
			}
		}
	}

	// ���� ���� �ҽ��� �����Ѵٸ�
	if(m_bVideo && pVidSrc)
	{
		// ���� �ҽ��� �ݺ� �ɼ��� �����Ѵ�
		hr = pVidSrc->put_Repeat(VARIANT_FALSE);
		if(!SUCCEEDED(hr))
		{
			::MessageBox(NULL, "���� �ݺ� �ɼ��� ������ �� �����ϴ�.",
				"������ ��� ����", MB_OK | MB_ICONERROR);
			m_pEncoder->Release();
			m_pEncoder = NULL;
			return FALSE;
		}
	}
	// ���� ����� �ҽ��� �����Ѵٸ�
	if(m_bAudio && pAudSrc)
	{
		// ����� �ҽ��� �ݺ� �ɼ��� �����Ѵ�
		hr = pAudSrc->put_Repeat(VARIANT_FALSE);
		if(!SUCCEEDED(hr))
		{
			::MessageBox(NULL, "����� �ݺ� �ɼ��� ������ �� �����ϴ�.",
				"������ ��� ����", MB_OK | MB_ICONERROR);
			m_pEncoder->Release();
			m_pEncoder = NULL;
			return FALSE;
		}
	}

	return TRUE;
}

// ������ ���Ϸ� ��ȭ�ϴ� �Լ�
BOOL CCamCast::Record(LPCTSTR pFileName)
{
	// �̵�� ���ڴ��� �������� ���� ���¶�� �����Ѵ�
	if(!m_pEncoder)			return FALSE;

	HRESULT hr;

	IWMEncSourceGroupCollection	*pSrcGrpColl;
	IWMEncSourceGroup			*pSrcGrp;
	IWMEncSource				*pAudSrc;
	IWMEncSource				*pVidSrc;

	CComVariant varProfile;

	// �̵�� ���ڴ��� �ҽ� �׷� �÷��� �������̽��� ��´�
	hr = m_pEncoder->get_SourceGroupCollection(&pSrcGrpColl);
	if(FAILED(hr))			return FALSE;

	// ù��° �ҽ� �׷� �������̽��� ��´�
	varProfile.vt	= VT_I2;
	varProfile.iVal	= 0;
	hr = pSrcGrpColl->Item(varProfile, &pSrcGrp);
	if(FAILED(hr))			return FALSE;

	// ���� �ý��ۿ� ����� �ҽ��� �����Ѵٸ�
	if(m_bAudio)
	{
		// ����� �ҽ� �������̽��� ��´�
		hr = pSrcGrp->get_Source(WMENC_AUDIO, 0, &pAudSrc);
		if(SUCCEEDED(hr))
		{
			// ����� �ҽ��� ����� �Է� �ҽ� �̸��� �����Ѵ�
			hr = pAudSrc->SetInput(m_strDeviceAudio);
			if(!SUCCEEDED(hr))
			{
				::MessageBox(NULL, "����� ��ġ ���� ����",
					"������ ��� ����", MB_OK | MB_ICONERROR);
				m_pEncoder->Release();
				m_pEncoder = NULL;
				return FALSE;
			}
		}
	}
	// ���� �ý��ۿ� ���� �ҽ��� �����Ѵٸ�
	if(m_bVideo)
	{
		// ���� �ҽ� �������̽��� ��´�
		hr = pSrcGrp->get_Source(WMENC_VIDEO, 0, &pVidSrc);
		if(SUCCEEDED(hr))
		{
			// ���� �ҽ��� ���� �Է� �ҽ� �̸��� �����Ѵ�
			hr = pVidSrc->SetInput(m_strDeviceVideo);
			if(!SUCCEEDED(hr))
			{
				::MessageBox(NULL, "���� ��ġ ���� ����",
					"������ ��� ����", MB_OK | MB_ICONERROR);
				m_pEncoder->Release();
				m_pEncoder = NULL;
				return FALSE;
			}
		}
	}

	IWMEncFile* pFile;

	// �������� ��ȭ�Ͽ� ������ ���� �̸��� �����Ǿ��ٸ�
	if(pFileName)
	{
		// �̵�� ���ڴ��κ��� ���� ���ڵ� �������̽��� ��´�
		hr = m_pEncoder->get_File(&pFile);    
		if(SUCCEEDED(hr))
		{
			USES_CONVERSION;

			// �������� ������ ���� �̸��� �����Ѵ�
			hr = pFile->put_LocalFileName(A2OLE(pFileName));
		}
	}

	// �̵�� ���ڴ� ������ �ʱ�ȭ�Ѵ�
	hr = m_pEncoder->PrepareToEncode(VARIANT_TRUE);

	// ���� �̸����� �������̽��� �����Ǿ� �ְ� ���� ��ġ�� �����Ѵٸ�
	if(m_pPreview && m_pPreviewColl && m_lCookie >= 0 && m_bVideo)
	{
		// �̸����� �������� �θ� ������� ���� �����츦 �����Ѵ�
		hr = m_pPreview->SetViewSetting((DWORD)m_lCookie, 
										sizeof(m_hWnd), 
										(BYTE*)&m_hWnd);
	}

	// �̵�� ���ڴ��� ��ȭ�� �����Ѵ�
	hr = m_pEncoder->Start();
	if(!SUCCEEDED(hr))
	{
		return FALSE;
	}

	// ���� �̸����� �������̽��� �����Ǿ� �ְ� ���� ��ġ�� �����Ѵٸ�
	if(m_pPreview && m_pPreviewColl && m_lCookie >= 0 && m_bVideo)
	{
		// �̸����⸦ �����Ѵ�
		hr = m_pPreview->Start(m_lCookie);
	}

	return TRUE;
}

// ���ͳ����� �������� ����ϴ� �Լ�
BOOL CCamCast::Cast(int nPort)
{
	// �̵�� ���ڴ��� �������� ���� ���¶�� �����Ѵ�
	if(!m_pEncoder)			return FALSE;

	HRESULT hr;

	IWMEncSourceGroupCollection	*pSrcGrpColl;
	IWMEncSourceGroup			*pSrcGrp;
	IWMEncSource				*pAudSrc;
	IWMEncSource				*pVidSrc;

	CComVariant varProfile;

	// �̵�� ���ڴ��� �ҽ� �׷� �÷��� �������̽��� ��´�
	hr = m_pEncoder->get_SourceGroupCollection(&pSrcGrpColl);
	if(FAILED(hr))			return FALSE;

	// ù��° �ҽ� �׷� �������̽��� ��´�
	varProfile.vt	= VT_I2;
	varProfile.iVal	= 0;
	hr = pSrcGrpColl->Item(varProfile, &pSrcGrp);
	if(FAILED(hr))			return FALSE;

	// ���� �ý��ۿ� ����� �ҽ��� �����Ѵٸ�
	if(m_bAudio)
	{
		// ����� �ҽ� �������̽��� ��´�
		hr = pSrcGrp->get_Source(WMENC_AUDIO, 0, &pAudSrc);
		if(SUCCEEDED(hr))
		{
			// ����� �ҽ��� ����� �Է� �ҽ� �̸��� �����Ѵ�
			hr = pAudSrc->SetInput(m_strDeviceAudio);
			if(!SUCCEEDED(hr))
			{
				::MessageBox(NULL, "����� ��ġ ���� ����",
					"������ ��� ����", MB_OK | MB_ICONERROR);
				m_pEncoder->Release();
				m_pEncoder = NULL;
				return FALSE;
			}
		}
	}
	// ���� �ý��ۿ� ���� �ҽ��� �����Ѵٸ�
	if(m_bVideo)
	{
		// ���� �ҽ� �������̽��� ��´�
		hr = pSrcGrp->get_Source(WMENC_VIDEO, 0, &pVidSrc);
		if(SUCCEEDED(hr))
		{
			// ���� �ҽ��� ���� �Է� �ҽ� �̸��� �����Ѵ�
			hr = pVidSrc->SetInput(m_strDeviceVideo);
			if(!SUCCEEDED(hr))
			{
				::MessageBox(NULL, "���� ��ġ ���� ����",
					"������ ��� ����", MB_OK | MB_ICONERROR);
				m_pEncoder->Release();
				m_pEncoder = NULL;
				return FALSE;
			}
		}
	}

	// �̵�� ���ڴ��κ��� ��� �������̽��� ��´�
	IWMEncBroadcast* pBrdcast;
	hr = m_pEncoder->get_Broadcast(&pBrdcast);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "��� �������̽� ȹ�� ����",
			"������ ��� ����", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// ��ۿ� �������ݰ� ��Ʈ ��ȣ�� �����Ѵ�
	hr = pBrdcast->put_PortNumber(WMENC_PROTOCOL_HTTP, nPort);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "��� ��Ʈ ���� ����",
			"������ ��� ����", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// ��ȭ�� ���۵� �� �ڵ����� ���� ���μ����� ����ǵ��� �����Ѵ�
	m_pEncoder->put_EnableAutoArchive(VARIANT_TRUE);
	// �Է� �ҽ��� ����� �� �ڵ����� ��ȭ�� �����ϵ��� �����Ѵ�
	m_pEncoder->put_AutoStop(VARIANT_TRUE);

	// �̵�� ���ڴ� ������ �ʱ�ȭ�Ѵ�
	hr = m_pEncoder->PrepareToEncode(VARIANT_TRUE);

	// ���� �̸����� �������̽��� �����Ǿ� �ְ� ���� ��ġ�� �����Ѵٸ�
	if(m_pPreview && m_pPreviewColl && m_lCookie >= 0 && m_bVideo)
	{
		// �̸����� �������� �θ� ������� ���� �����츦 �����Ѵ�
		hr = m_pPreview->SetViewSetting((DWORD)m_lCookie, 
										sizeof(m_hWnd), 
										(BYTE*)&m_hWnd);
	}

	// �̵�� ���ڴ��� ����� �����Ѵ�
	hr = m_pEncoder->Start();
	if(!SUCCEEDED(hr))
	{
		return FALSE;
	}

	// ���� �̸����� �������̽��� �����Ǿ� �ְ� ���� ��ġ�� �����Ѵٸ�
	if(m_pPreview && m_pPreviewColl && m_lCookie >= 0 && m_bVideo)
	{
		// �̸����⸦ �����Ѵ�
		hr = m_pPreview->Start(m_lCookie);
	}

	return TRUE;
}

// ������ ��ȭ�� ����� �����ϴ� �Լ�
BOOL CCamCast::Stop()
{
	// �̵�� ���ڴ��� �������� ���� ���¶�� �����Ѵ�
	if(!m_pEncoder)			return FALSE;

	HRESULT hr;
	WMENC_ENCODER_STATE EncoderState;

	// ���� �̵�� ���ڴ��� ���� ���¸� ��´�
	m_pEncoder->get_RunState(&EncoderState);
	// ���� ���� �������̰ų� �Ͻ� ���� ���¶��
	if((EncoderState == WMENC_ENCODER_RUNNING) || (EncoderState == WMENC_ENCODER_PAUSED))
	{	
		// ���� �̸����� �������̽��� �����Ǿ� �ְ� ���� ��ġ�� �����Ѵٸ�
		if(m_pPreview && m_pPreviewColl && m_lCookie >= 0 && m_bVideo)
		{
			// �̸����⸦ �����Ѵ�
			m_pPreview->StopAll();
		}

		// �̵�� ���ڴ��� ���ڵ� �۾��� �����Ѵ�
		hr = m_pEncoder->Stop();
		if(!SUCCEEDED(hr))
		{
			return FALSE;
		}

		return TRUE;
	}

	return FALSE;
}

// ������ ��ȭ ��ۿ� ���� �ɼ� ���̾�α� ��� �Լ� 
BOOL CCamCast::Config()
{
	// �̵�� ���ڴ��� �������� ���� ���¶�� �����Ѵ�
	if(!m_pEncoder)				return FALSE;

	// ������ ��ȭ ��ۿ� ���� �ɼ� ���̾�α� Ŭ���� ������ �����Ѵ�
	CEncoderConfigDlg ConfigDlg;

	// �̵�� ���ڴ��� �����Ѵ�
	ConfigDlg.SetEncoder(m_pEncoder);

	// �ɼ� ���̾�α׸� ����
	if(ConfigDlg.DoModal() == IDOK)
	{
		// �ɼ� ���̾�αװ� ���������� ����Ǿ��ٸ�
		IWMEncSourceGroupCollection	*pSrcGrpColl;
		IWMEncSourceGroup			*pSrcGrp;
		IWMEncSource				*pAudSrc;
		IWMEncSource				*pVidSrc;

		HRESULT hr;
		CComVariant varIndex;

		// �̵�� ���ڴ��� �ҽ� �׷� �÷��� �������̽��� ��´�
		hr = m_pEncoder->get_SourceGroupCollection(&pSrcGrpColl);
		if(SUCCEEDED(hr))
		{
			m_strDeviceAudio.Empty();
			m_strDeviceVideo.Empty();

			// ù��° �ҽ� �׷��� ��´�
			varIndex.vt	= VT_I2;
			varIndex.iVal	= 0;

			hr = pSrcGrpColl->Item(varIndex, &pSrcGrp);
			if(SUCCEEDED(hr))
			{
				// �ҽ� �׷��� ����� �ҽ��� ��´�
				hr = pSrcGrp->get_Source(WMENC_AUDIO, 0, &pAudSrc);
				if(SUCCEEDED(hr))
				{
					CComBSTR bstrStream;
					CComBSTR bstrScheme;
					CComBSTR bstrSource;

					m_bAudio = TRUE;

					// ����� �ҽ��� ������ ���´�
					hr = pAudSrc->GetInput(&bstrStream, &bstrScheme, &bstrSource);
					if(!SUCCEEDED(hr))
					{
						m_bAudio = FALSE;
					}
					else
					{
						// ����� �ҽ��� ���� �ҽ� �̸��� �����Ѵ�
						m_strDeviceAudio = bstrScheme;
						m_strDeviceAudio += "://";
						m_strDeviceAudio += bstrSource;
					}
				}
				else
					m_bAudio = FALSE;

				// �ҽ� �׷��� ���� �ҽ��� ��´�
				hr = pSrcGrp->get_Source(WMENC_VIDEO, 0, &pVidSrc);
				if(SUCCEEDED(hr))
				{
					CComBSTR bstrStream;
					CComBSTR bstrScheme;
					CComBSTR bstrSource;

					m_bVideo = TRUE;

					// ���� �ҽ��� ������ ���´�
					hr = pVidSrc->GetInput(&bstrStream, &bstrScheme, &bstrSource);
					if(!SUCCEEDED(hr))
					{
						m_bVideo = FALSE;
					}
					else
					{
						// ���� ���� �ҽ��� ���°� ȭ�� ��ȭ���
						m_strDeviceVideo = bstrScheme;
						if(_wcsicmp(bstrScheme, L"screencap") == 0)
						{
							// ���� �ҽ��� ���ҽ��� �����Ѵ�
							m_strDeviceVideo += "://ScreenCapture1";
						}
						else
						{
							// ���� �ҽ��� ���� �ҽ� �̸��� �����Ѵ�
							m_strDeviceVideo += "://";
							m_strDeviceVideo += bstrSource;
						}
					}
				}
				else
					m_bVideo = FALSE;
			}
		}
		return TRUE;
	}
	
	return FALSE;
}

void CCamCast::OnPaint() 
{
	// ���� ���ڴ��� �����ǰ� �̸����Ⱑ �����ϴٸ�
	if(m_pEncoder && m_pPreview)
	{
		WMENC_ENCODER_STATE EncoderState;

		// ���� ��ȭ/��� ���̰ų� �Ͻ� ������ ���¶�� �⺻ �۾��� �����Ѵ�
		m_pEncoder->get_RunState(&EncoderState);
		if((EncoderState == WMENC_ENCODER_RUNNING) || (EncoderState == WMENC_ENCODER_PAUSED))
		{
			Default();
			return;
		}
	}

	// ���� �����Ǿ� �ְų� �̸����Ⱑ �ȵǴ� ��Ȳ�̸�
	CPaintDC dc(this); // device context for painting

	CRect rcClient;
	GetClientRect(&rcClient);

	// Ŭ���̾�Ʈ ������ ���������� ĥ�Ѵ�
	dc.FillSolidRect(&rcClient, RGB(0, 0, 0));
}

BOOL CCamCast::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

void CCamCast::OnDestroy() 
{
	CStatic::OnDestroy();
	
	// ������ ����� ��ȭ�� ����� �����Ѵ�
	Stop();
}
