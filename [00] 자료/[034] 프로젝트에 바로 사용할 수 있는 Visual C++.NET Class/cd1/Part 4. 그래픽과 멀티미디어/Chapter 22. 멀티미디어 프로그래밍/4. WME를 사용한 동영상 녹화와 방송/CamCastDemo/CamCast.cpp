// CamCast.cpp : implementation file
//

#include "stdafx.h"
#include "camcastdemo.h"
#include "CamCast.h"

// 동영상 녹화 방송에 관한 옵션 다이얼로그 클래스 헤더파일
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
	// 멤버 변수들을 초기화한다
	m_pEncoder			= NULL;
	m_pPreview			= NULL;
	m_pPreviewColl		= NULL;
	m_lCookie			= -1;
	m_bAudio			= FALSE;
	m_bVideo			= FALSE;
}

CCamCast::~CCamCast()
{
	// 미디어 인코더 인터페이스를 해제한다
	if(m_pEncoder)
	{
		m_pEncoder->PrepareToEncode(VARIANT_FALSE);
		m_pEncoder->Release();
	}
	// 미리보기 컬렉션 인터페이스를 해제한다
	if(m_pPreviewColl)
	{
		m_pPreviewColl->RemoveAll();
		m_pPreviewColl->Release();
	}
	// 미리보기 인터페이스를 해제한다
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

// 동영상 녹화 방송을 위한 초기화 함수
BOOL CCamCast::Initialize()
{
	HRESULT hr;

	// 이전에 생성된 미디어 인코더 인터페이스가 있다면 해제한다
	if(m_pEncoder)	m_pEncoder->Release();

	m_bAudio			= FALSE;
	m_bVideo			= FALSE;

	// 미디어 인코더 인터페이스를 생성한다
	hr = CoCreateInstance(	CLSID_WMEncoder,
							NULL,
							CLSCTX_INPROC_SERVER,
							IID_IWMEncoder,
							(void**)&m_pEncoder);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "MS Windows Media Encoder가 정상적으로 설치되지 않았습니다.",
			"동영상 장비 오류", MB_OK | MB_ICONERROR);
		return FALSE;
	}

	CComBSTR bstrName = NULL;
	CComVariant varProfile;

	long lCount;
	int i;

	IWMEncSourcePluginInfoManager* pSrcPlugMgr;
	IWMEncPluginInfo* pPlugInfo;

	// 소스 플러그인 관리자 인터페이스를 얻는다
	hr = m_pEncoder->get_SourcePluginInfoManager(&pSrcPlugMgr);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "시스템에서 미디어 장비에 대한 정보를 얻을 수 없습니다.",
			"동영상 장비 오류", MB_OK | MB_ICONERROR);

		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// 현재 시스템의 소스 플러그인 갯수를 얻는다
    hr = pSrcPlugMgr->get_Count(&lCount);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "시스템에 설치된 동영상 장비가 없습니다.",
			"동영상 장비 오류", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	long lResCount;
	CComBSTR bstrResource;
	VARIANT_BOOL bResources;

	// 현재 시스템의 소스 플러그인을 모두 검색한다
	for(i=0; i<lCount; i++)
	{
		// 소스 플러그인 인터페이스를 얻는다
		hr = pSrcPlugMgr->Item(i, &pPlugInfo);

		// 소스 플러그인의 이름을 얻는다
		hr = pPlugInfo->get_Name(&bstrName);

		// 오디오나 비디오 캡춰 장치인지 확인한다
		if(_wcsicmp(bstrName, L"Audio Capture Device") == 0
			|| _wcsicmp(bstrName, L"Video Capture Device") == 0
			|| _wcsicmp(bstrName, L"오디오 캡처 장치") == 0
			|| _wcsicmp(bstrName, L"비디오 캡처 장치") == 0)
		{
			// 소스 플러그인의 형태를 얻는다
			hr = pPlugInfo->get_SchemeType(&bstrResource);
			// 소스 플러그인의 형태가 장치라면
			if(_wcsicmp(bstrResource, L"device")==0)
			{
				// 리소스가 있는지 확인한다
				hr = pPlugInfo->get_Resources(&bResources); 
				// 소스 플러그인의 리소스가 있다면
				if(bResources==VARIANT_TRUE)
				{
					// 소스 플러그인에 속한 리소스의 갯수를 얻는다
					hr = pPlugInfo->get_Count(&lResCount);

					if(lResCount > 0)
					{
						// 만약 오디오 캡춰 장치에 대한 리소스라면
						if(_wcsicmp(bstrName, L"Audio Capture Device") == 0
							|| _wcsicmp(bstrName, L"오디오 캡처 장치") == 0)
						{
							// 리소스 이름을 얻는다
							hr = pPlugInfo->Item(1, &bstrResource);
							// 오디오 소스에 대한 완전한 이름을 구성한다
							m_strDeviceAudio = L"device://";
							m_strDeviceAudio += bstrResource;
							m_bAudio = TRUE;
						}
						else
							// 만약 비디오 캡춰 장치에 대한 리소스라면
							if(_wcsicmp(bstrName, L"Video Capture Device") == 0
								|| _wcsicmp(bstrName, L"비디오 캡처 장치") == 0)
							{
								// 리소스 이름을 얻는다
								hr = pPlugInfo->Item(1, &bstrResource);
								// 비디오 소스에 대한 완전한 이름을 구성한다
								m_strDeviceVideo = L"device://";
								m_strDeviceVideo += bstrResource;
								m_bVideo = TRUE;
							}
					}
				}
			}
		}
    }

	// 만약 오디오와 비디오에 대한 소스를 찾지 못했다면 리턴한다
	if(!m_bAudio && !m_bVideo)
	{
		::MessageBox(NULL, "시스템에 오디오 장치와 비디오 장치가 설치되지 않았습니다.",
				"동영상 장비 오류", MB_OK | MB_ICONERROR);

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

	// 미디어 인코더의 소스 그룹 컬렉션을 얻는다
	hr = m_pEncoder->get_SourceGroupCollection(&pSrcGrpColl);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "멀티미디어 소스 그룹을 얻을 수 없습니다.",
			"동영상 장비 오류", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// 현재 애플리케이션을 위한 소스 그룹을 추가한다
	hr = pSrcGrpColl->Add(L"CamCast", &pSrcGrp);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "소스를 시스템에 추가할 수 없습니다.",
			"동영상 장비 오류", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// 만약 오디오 소스가 시스템에 존재한다면
	if(m_bAudio)
	{
		// 오디오 소스를 소스 그룹에 추가한다
		hr = pSrcGrp->AddSource(WMENC_AUDIO, &pAudSrc);
		if(!SUCCEEDED(hr))
		{
			m_bAudio = FALSE;
		}
	}
	// 만약 비디오 소스가 시스템에 존재한다면
	if(m_bVideo)
	{
		// 비디오 소스를 소스 그룹에 추가한다
		hr = pSrcGrp->AddSource(WMENC_VIDEO, &pVidSrc);
		if(!SUCCEEDED(hr))
		{
			m_bVideo = FALSE;
		}
	}

	// 미디어 인코더의 프로파일 컬렉션을 얻는다
	hr = m_pEncoder->get_ProfileCollection(&pProColl);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "시스템에 설치된 프로파일에 접근할 수 없습니다.",
			"동영상 장비 오류", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// 프로파일 컬렉션에 저장된 프로파일 갯수를 얻는다
	varProfile.vt = VT_DISPATCH;
	hr = pProColl->get_Count(&lCount);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "시스템에 설치된 프로파일이 존재하지 않습니다.",
			"동영상 장비 오류", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// 프로파일 컬렉션의 모든 프로파일을 검색한다
	for(i = 0; i < lCount; i++)
	{
		// 프로파일 인터페이스를 얻는다
		hr = pProColl->Item(i, &pPro);
		if(!SUCCEEDED(hr))
		{
			m_pEncoder->Release();
			m_pEncoder = NULL;
			return FALSE;
		}
		// 프로파일의 이름을 얻는다
		hr = pPro->get_Name(&bstrName);
		if(!SUCCEEDED(hr))
		{
			m_pEncoder->Release();
			m_pEncoder = NULL;
			return FALSE;
		}
		// 애플리케이션에서 사용하려는 프로파일인지 확인한다
		if(_wcsicmp(bstrName, L"웹 서버용 비디오(56Kbps)") == 0)
		{
			// 소스 그룹에 프로파일을 설정한다
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
	// 만약 애플리케이션에서 사용하려는 프로파일이 존재하지않으면 리턴한다
	if(i >= lCount)
	{
		::MessageBox(NULL, "웹 서버용 비디오 프로파일이 설치되지 않았습니다.",
			"동영상 장비 오류", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// 이전에 생성된 미리보기 인터페이스가 있다면 종료한다
	if(m_pPreview)		m_pPreview->Release();
	m_pPreview = NULL;

	// 만약 현재 시스템에 비디오 소스가 존재한다면
	if(m_bVideo && pVidSrc)
	{
		// 미리보기 인터페이스를 생성한다
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
			// 비디오 소스의 미리보기 컬렉션 인터페이스를 얻는다
			hr = pVidSrc->get_PreviewCollection(&m_pPreviewColl);
			if(!SUCCEEDED(hr))
			{
				m_pPreview->Release();
				m_pPreview = NULL;
				m_pPreviewColl = NULL;
			}
			else
			{
				// 미리보기 컬렉션에 새로 생성한 미리보기 인터페이스를 추가한다
				// 이때 새로운 미리보기 인터페이스에 대한 미리보기 컬렉션의 쿠키를 얻는다
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

	// 만약 비디오 소스가 존재한다면
	if(m_bVideo && pVidSrc)
	{
		// 비디오 소스의 반복 옵션을 해제한다
		hr = pVidSrc->put_Repeat(VARIANT_FALSE);
		if(!SUCCEEDED(hr))
		{
			::MessageBox(NULL, "비디오 반복 옵션을 해제할 수 없습니다.",
				"동영상 장비 오류", MB_OK | MB_ICONERROR);
			m_pEncoder->Release();
			m_pEncoder = NULL;
			return FALSE;
		}
	}
	// 만약 오디오 소스가 존재한다면
	if(m_bAudio && pAudSrc)
	{
		// 오디오 소스의 반복 옵션을 해제한다
		hr = pAudSrc->put_Repeat(VARIANT_FALSE);
		if(!SUCCEEDED(hr))
		{
			::MessageBox(NULL, "오디오 반복 옵션을 해제할 수 없습니다.",
				"동영상 장비 오류", MB_OK | MB_ICONERROR);
			m_pEncoder->Release();
			m_pEncoder = NULL;
			return FALSE;
		}
	}

	return TRUE;
}

// 동영상 파일로 녹화하는 함수
BOOL CCamCast::Record(LPCTSTR pFileName)
{
	// 미디어 인코더가 생성되지 못한 상태라면 리턴한다
	if(!m_pEncoder)			return FALSE;

	HRESULT hr;

	IWMEncSourceGroupCollection	*pSrcGrpColl;
	IWMEncSourceGroup			*pSrcGrp;
	IWMEncSource				*pAudSrc;
	IWMEncSource				*pVidSrc;

	CComVariant varProfile;

	// 미디어 인코더의 소스 그룹 컬렉션 인터페이스를 얻는다
	hr = m_pEncoder->get_SourceGroupCollection(&pSrcGrpColl);
	if(FAILED(hr))			return FALSE;

	// 첫번째 소스 그룹 인터페이스를 얻는다
	varProfile.vt	= VT_I2;
	varProfile.iVal	= 0;
	hr = pSrcGrpColl->Item(varProfile, &pSrcGrp);
	if(FAILED(hr))			return FALSE;

	// 만약 시스템에 오디오 소스가 존재한다면
	if(m_bAudio)
	{
		// 오디오 소스 인터페이스를 얻는다
		hr = pSrcGrp->get_Source(WMENC_AUDIO, 0, &pAudSrc);
		if(SUCCEEDED(hr))
		{
			// 오디오 소스에 오디오 입력 소스 이름을 설정한다
			hr = pAudSrc->SetInput(m_strDeviceAudio);
			if(!SUCCEEDED(hr))
			{
				::MessageBox(NULL, "오디오 장치 연결 오류",
					"동영상 장비 오류", MB_OK | MB_ICONERROR);
				m_pEncoder->Release();
				m_pEncoder = NULL;
				return FALSE;
			}
		}
	}
	// 만약 시스템에 비디오 소스가 존재한다면
	if(m_bVideo)
	{
		// 비디오 소스 인터페이스를 얻는다
		hr = pSrcGrp->get_Source(WMENC_VIDEO, 0, &pVidSrc);
		if(SUCCEEDED(hr))
		{
			// 비디오 소스에 비디오 입력 소스 이름을 설정한다
			hr = pVidSrc->SetInput(m_strDeviceVideo);
			if(!SUCCEEDED(hr))
			{
				::MessageBox(NULL, "비디오 장치 연결 오류",
					"동영상 장비 오류", MB_OK | MB_ICONERROR);
				m_pEncoder->Release();
				m_pEncoder = NULL;
				return FALSE;
			}
		}
	}

	IWMEncFile* pFile;

	// 동영상을 녹화하여 저장할 파일 이름이 설정되었다면
	if(pFileName)
	{
		// 미디어 인코더로부터 파일 인코딩 인터페이스를 얻는다
		hr = m_pEncoder->get_File(&pFile);    
		if(SUCCEEDED(hr))
		{
			USES_CONVERSION;

			// 동영상을 저장할 파일 이름을 설정한다
			hr = pFile->put_LocalFileName(A2OLE(pFileName));
		}
	}

	// 미디어 인코더 엔진을 초기화한다
	hr = m_pEncoder->PrepareToEncode(VARIANT_TRUE);

	// 만약 미리보기 인터페이스가 생성되어 있고 비디오 장치가 존재한다면
	if(m_pPreview && m_pPreviewColl && m_lCookie >= 0 && m_bVideo)
	{
		// 미리보기 윈도우의 부모 윈도우로 현재 윈도우를 설정한다
		hr = m_pPreview->SetViewSetting((DWORD)m_lCookie, 
										sizeof(m_hWnd), 
										(BYTE*)&m_hWnd);
	}

	// 미디어 인코더로 녹화를 시작한다
	hr = m_pEncoder->Start();
	if(!SUCCEEDED(hr))
	{
		return FALSE;
	}

	// 만약 미리보기 인터페이스가 생성되어 있고 비디오 장치가 존재한다면
	if(m_pPreview && m_pPreviewColl && m_lCookie >= 0 && m_bVideo)
	{
		// 미리보기를 시작한다
		hr = m_pPreview->Start(m_lCookie);
	}

	return TRUE;
}

// 인터넷으로 동영상을 방송하는 함수
BOOL CCamCast::Cast(int nPort)
{
	// 미디어 인코더가 생성되지 못한 상태라면 리턴한다
	if(!m_pEncoder)			return FALSE;

	HRESULT hr;

	IWMEncSourceGroupCollection	*pSrcGrpColl;
	IWMEncSourceGroup			*pSrcGrp;
	IWMEncSource				*pAudSrc;
	IWMEncSource				*pVidSrc;

	CComVariant varProfile;

	// 미디어 인코더의 소스 그룹 컬렉션 인터페이스를 얻는다
	hr = m_pEncoder->get_SourceGroupCollection(&pSrcGrpColl);
	if(FAILED(hr))			return FALSE;

	// 첫번째 소스 그룹 인터페이스를 얻는다
	varProfile.vt	= VT_I2;
	varProfile.iVal	= 0;
	hr = pSrcGrpColl->Item(varProfile, &pSrcGrp);
	if(FAILED(hr))			return FALSE;

	// 만약 시스템에 오디오 소스가 존재한다면
	if(m_bAudio)
	{
		// 오디오 소스 인터페이스를 얻는다
		hr = pSrcGrp->get_Source(WMENC_AUDIO, 0, &pAudSrc);
		if(SUCCEEDED(hr))
		{
			// 오디오 소스에 오디오 입력 소스 이름을 설정한다
			hr = pAudSrc->SetInput(m_strDeviceAudio);
			if(!SUCCEEDED(hr))
			{
				::MessageBox(NULL, "오디오 장치 연결 오류",
					"동영상 장비 오류", MB_OK | MB_ICONERROR);
				m_pEncoder->Release();
				m_pEncoder = NULL;
				return FALSE;
			}
		}
	}
	// 만약 시스템에 비디오 소스가 존재한다면
	if(m_bVideo)
	{
		// 비디오 소스 인터페이스를 얻는다
		hr = pSrcGrp->get_Source(WMENC_VIDEO, 0, &pVidSrc);
		if(SUCCEEDED(hr))
		{
			// 비디오 소스에 비디오 입력 소스 이름을 설정한다
			hr = pVidSrc->SetInput(m_strDeviceVideo);
			if(!SUCCEEDED(hr))
			{
				::MessageBox(NULL, "비디오 장치 연결 오류",
					"동영상 장비 오류", MB_OK | MB_ICONERROR);
				m_pEncoder->Release();
				m_pEncoder = NULL;
				return FALSE;
			}
		}
	}

	// 미디어 인코더로부터 방송 인터페이스를 얻는다
	IWMEncBroadcast* pBrdcast;
	hr = m_pEncoder->get_Broadcast(&pBrdcast);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "방송 인터페이스 획득 실패",
			"동영상 장비 오류", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// 방송용 프로토콜과 포트 번호를 설정한다
	hr = pBrdcast->put_PortNumber(WMENC_PROTOCOL_HTTP, nPort);
	if(!SUCCEEDED(hr))
	{
		::MessageBox(NULL, "방송 포트 설정 오류",
			"동영상 장비 오류", MB_OK | MB_ICONERROR);
		m_pEncoder->Release();
		m_pEncoder = NULL;
		return FALSE;
	}

	// 녹화가 시작될 때 자동으로 저장 프로세스가 실행되도록 설정한다
	m_pEncoder->put_EnableAutoArchive(VARIANT_TRUE);
	// 입력 소스가 종료될 때 자동으로 녹화를 종료하도록 설정한다
	m_pEncoder->put_AutoStop(VARIANT_TRUE);

	// 미디어 인코더 엔진을 초기화한다
	hr = m_pEncoder->PrepareToEncode(VARIANT_TRUE);

	// 만약 미리보기 인터페이스가 생성되어 있고 비디오 장치가 존재한다면
	if(m_pPreview && m_pPreviewColl && m_lCookie >= 0 && m_bVideo)
	{
		// 미리보기 윈도우의 부모 윈도우로 현재 윈도우를 설정한다
		hr = m_pPreview->SetViewSetting((DWORD)m_lCookie, 
										sizeof(m_hWnd), 
										(BYTE*)&m_hWnd);
	}

	// 미디어 인코더로 방송을 시작한다
	hr = m_pEncoder->Start();
	if(!SUCCEEDED(hr))
	{
		return FALSE;
	}

	// 만약 미리보기 인터페이스가 생성되어 있고 비디오 장치가 존재한다면
	if(m_pPreview && m_pPreviewColl && m_lCookie >= 0 && m_bVideo)
	{
		// 미리보기를 시작한다
		hr = m_pPreview->Start(m_lCookie);
	}

	return TRUE;
}

// 동영상 녹화나 방송을 정지하는 함수
BOOL CCamCast::Stop()
{
	// 미디어 인코더가 생성되지 못한 상태라면 리턴한다
	if(!m_pEncoder)			return FALSE;

	HRESULT hr;
	WMENC_ENCODER_STATE EncoderState;

	// 현재 미디어 인코더의 동작 상태를 얻는다
	m_pEncoder->get_RunState(&EncoderState);
	// 만약 현재 실행중이거나 일시 정지 상태라면
	if((EncoderState == WMENC_ENCODER_RUNNING) || (EncoderState == WMENC_ENCODER_PAUSED))
	{	
		// 만약 미리보기 인터페이스가 생성되어 있고 비디오 장치가 존재한다면
		if(m_pPreview && m_pPreviewColl && m_lCookie >= 0 && m_bVideo)
		{
			// 미리보기를 정지한다
			m_pPreview->StopAll();
		}

		// 미디어 인코더의 인코딩 작업을 정지한다
		hr = m_pEncoder->Stop();
		if(!SUCCEEDED(hr))
		{
			return FALSE;
		}

		return TRUE;
	}

	return FALSE;
}

// 동영상 녹화 방송에 대한 옵션 다이얼로그 출력 함수 
BOOL CCamCast::Config()
{
	// 미디어 인코더가 생성되지 못한 상태라면 리턴한다
	if(!m_pEncoder)				return FALSE;

	// 동영상 녹화 방송에 관한 옵션 다이얼로그 클래스 변수를 생성한다
	CEncoderConfigDlg ConfigDlg;

	// 미디어 인코더를 설정한다
	ConfigDlg.SetEncoder(m_pEncoder);

	// 옵션 다이얼로그를 띄운다
	if(ConfigDlg.DoModal() == IDOK)
	{
		// 옵션 다이얼로그가 정상적으로 종료되었다면
		IWMEncSourceGroupCollection	*pSrcGrpColl;
		IWMEncSourceGroup			*pSrcGrp;
		IWMEncSource				*pAudSrc;
		IWMEncSource				*pVidSrc;

		HRESULT hr;
		CComVariant varIndex;

		// 미디어 인코더의 소스 그룹 컬렉션 인터페이스를 얻는다
		hr = m_pEncoder->get_SourceGroupCollection(&pSrcGrpColl);
		if(SUCCEEDED(hr))
		{
			m_strDeviceAudio.Empty();
			m_strDeviceVideo.Empty();

			// 첫번째 소스 그룹을 얻는다
			varIndex.vt	= VT_I2;
			varIndex.iVal	= 0;

			hr = pSrcGrpColl->Item(varIndex, &pSrcGrp);
			if(SUCCEEDED(hr))
			{
				// 소스 그룹의 오디오 소스를 얻는다
				hr = pSrcGrp->get_Source(WMENC_AUDIO, 0, &pAudSrc);
				if(SUCCEEDED(hr))
				{
					CComBSTR bstrStream;
					CComBSTR bstrScheme;
					CComBSTR bstrSource;

					m_bAudio = TRUE;

					// 오디오 소스의 정보를 얻어온다
					hr = pAudSrc->GetInput(&bstrStream, &bstrScheme, &bstrSource);
					if(!SUCCEEDED(hr))
					{
						m_bAudio = FALSE;
					}
					else
					{
						// 오디오 소스에 대한 소스 이름을 구성한다
						m_strDeviceAudio = bstrScheme;
						m_strDeviceAudio += "://";
						m_strDeviceAudio += bstrSource;
					}
				}
				else
					m_bAudio = FALSE;

				// 소스 그룹의 비디오 소스를 얻는다
				hr = pSrcGrp->get_Source(WMENC_VIDEO, 0, &pVidSrc);
				if(SUCCEEDED(hr))
				{
					CComBSTR bstrStream;
					CComBSTR bstrScheme;
					CComBSTR bstrSource;

					m_bVideo = TRUE;

					// 비디오 소스의 정보를 얻어온다
					hr = pVidSrc->GetInput(&bstrStream, &bstrScheme, &bstrSource);
					if(!SUCCEEDED(hr))
					{
						m_bVideo = FALSE;
					}
					else
					{
						// 만약 비디오 소스의 형태가 화면 녹화라면
						m_strDeviceVideo = bstrScheme;
						if(_wcsicmp(bstrScheme, L"screencap") == 0)
						{
							// 비디오 소스의 리소스를 지정한다
							m_strDeviceVideo += "://ScreenCapture1";
						}
						else
						{
							// 비디오 소스에 대한 소스 이름을 구성한다
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
	// 만약 인코더가 생성되고 미리보기가 가능하다면
	if(m_pEncoder && m_pPreview)
	{
		WMENC_ENCODER_STATE EncoderState;

		// 현재 녹화/방송 중이거나 일시 정지된 상태라면 기본 작업을 수행한다
		m_pEncoder->get_RunState(&EncoderState);
		if((EncoderState == WMENC_ENCODER_RUNNING) || (EncoderState == WMENC_ENCODER_PAUSED))
		{
			Default();
			return;
		}
	}

	// 만약 정지되어 있거나 미리보기가 안되는 상황이면
	CPaintDC dc(this); // device context for painting

	CRect rcClient;
	GetClientRect(&rcClient);

	// 클라이언트 영역을 검은색으로 칠한다
	dc.FillSolidRect(&rcClient, RGB(0, 0, 0));
}

BOOL CCamCast::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

void CCamCast::OnDestroy() 
{
	CStatic::OnDestroy();
	
	// 윈도우 종료시 녹화나 방송을 정지한다
	Stop();
}
