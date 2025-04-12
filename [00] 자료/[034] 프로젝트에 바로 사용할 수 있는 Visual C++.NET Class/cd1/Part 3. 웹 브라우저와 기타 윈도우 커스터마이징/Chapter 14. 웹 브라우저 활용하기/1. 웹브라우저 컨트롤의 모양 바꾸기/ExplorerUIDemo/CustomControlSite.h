// ExplorerUIDemo.h : 헤더 파일
//

#pragma once

// IDocHostUIHandler와 DOCHOSTUIINFO 구조체를 사용하기 위한 헤더 파일
#include <mshtmhst.h>

// 사용자 정의 ActiveX 컨트롤 컨테이너 메니저와 컨트롤 사이트 구현을 위한 헤더 파일과
// 그 헤더 파일을 컴파일할 수 있기 위한 선언들

// 아래의 주석 부분은 Visual C++ 6.0에서 컴파일할 때 사용합니다.
/*
#undef AFX_DATA
#define AFX_DATA AFX_DATA_IMPORT

#include <../src/mfc/occimpl.h>

#undef AFX_DATA
#define AFX_DATA AFX_DATA_EXPORT
*/
// 아래의 코드는 VisualStudio.NET에서 컴파일할 때 사용합니다.
#include <afxocc.h>


// 사용자 정의 ActiveX 컨트롤 사이트
class CCustomControlSite : public COleControlSite
{
public:
	CCustomControlSite(COleControlContainer *pCnt) : COleControlSite(pCnt) {}

protected:

// IDocHostUIHandler 인터페이스에서 상속 받아 새로운 내부 클래스를 생성한다
DECLARE_INTERFACE_MAP();
BEGIN_INTERFACE_PART(DocHostUIHandler, IDocHostUIHandler)
	// IDocHostUIHandler가 갖는 Method들
	STDMETHOD(GetHostInfo)(
		/* [out][in] */ DOCHOSTUIINFO			__RPC_FAR *pInfo);
	STDMETHOD(ShowContextMenu)(
		/* [in] */		DWORD					dwID,
		/* [in] */		POINT					__RPC_FAR *ppt,
		/* [in] */		IUnknown				__RPC_FAR *pcmdtReserved,
		/* [in] */		IDispatch				__RPC_FAR *pdispReserved);
	STDMETHOD(ShowUI)(
		/* [in] */		DWORD					dwID,
		/* [in] */		IOleInPlaceActiveObject	__RPC_FAR *pActiveObject,
		/* [in] */		IOleCommandTarget		__RPC_FAR *pCommandTarget,
		/* [in] */		IOleInPlaceFrame		__RPC_FAR *pFrame,
		/* [in] */		IOleInPlaceUIWindow		__RPC_FAR *pDoc);
	STDMETHOD(HideUI)(void);
	STDMETHOD(UpdateUI)(void);
	STDMETHOD(EnableModeless)(
		/* [in] */		BOOL					fEnable);
	STDMETHOD(ResizeBorder)( 
		/* [in] */		LPCRECT					prcBorder,
		/* [in] */		IOleInPlaceUIWindow		__RPC_FAR *pUIWindow,
		/* [in] */		BOOL					fRameWindow);
	STDMETHOD(TranslateAccelerator)( 
		/* [in] */		LPMSG					lpMsg,
		/* [in] */		const GUID				__RPC_FAR *pguidCmdGroup,
		/* [in] */		DWORD					nCmdID);
	STDMETHOD(TranslateUrl)( 
		/* [in] */		DWORD					dwTranslate,
		/* [in] */		OLECHAR					__RPC_FAR *pchURLIn,
		/* [out] */		OLECHAR					__RPC_FAR *__RPC_FAR *ppchURLOut);
	STDMETHOD(GetOptionKeyPath)( 
		/* [out] */		LPOLESTR				__RPC_FAR *pchKey,
		/* [in] */		DWORD					dw);
	STDMETHOD(GetDropTarget)(
		/* [in] */		IDropTarget				__RPC_FAR *pDropTarget,
		/* [out] */		IDropTarget				__RPC_FAR *__RPC_FAR *ppDropTarget);
	STDMETHOD(GetExternal)( 
		/* [out] */		IDispatch				__RPC_FAR *__RPC_FAR *ppDispatch);
	STDMETHOD(FilterDataObject)( 
		/* [in] */		IDataObject				__RPC_FAR *pDO,
		/* [out] */		IDataObject				__RPC_FAR *__RPC_FAR *ppDORet);
	STDMETHOD(OnDocWindowActivate)(
		/* [in] */		BOOL					fEnable);
	STDMETHOD(OnFrameWindowActivate)(
		/* [in] */		BOOL					fEnable);
END_INTERFACE_PART(DocHostUIHandler)
};


// 사용자 정의 ActiveX 컨트롤 컨테이너 메니저 클래스
class CCustomOccManager :public COccManager
{
public:
	CCustomOccManager() {}
	COleControlSite* CreateSite(COleControlContainer* pCtrlCont)
	{
		// 새로운 컨트롤 사이트를 생성할 때 위의 CCustomControlSite 클래스로 생성한다
		CCustomControlSite *pSite = new CCustomControlSite(pCtrlCont);
		return pSite;
	}
};
