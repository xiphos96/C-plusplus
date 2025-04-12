// ShapeProp.h : CShapeProp의 선언입니다.


#pragma once
#include <atlctrls.h>
using namespace WTL;

#include "resource.h"       // 주 기호입니다.

// CShapeProp

[
	coclass,
	threading("apartment"),
	vi_progid("Shape.ShapeProp"),
	progid("Shape.ShapeProp.1"),
	version(1.0),
	uuid("1183C3B8-F389-42E8-B36D-C2C6675713B3"),
	helpstring("ShapeProp Class")
]
class ATL_NO_VTABLE CShapeProp :
	public IPropertyPageImpl<CShapeProp>,
	public CDialogImpl<CShapeProp>
{
public:
	CShapeProp() 
	{
		m_dwTitleID = IDS_TITLEShapeProp;
		m_dwHelpFileID = IDS_HELPFILEShapeProp;
		m_dwDocStringID = IDS_DOCSTRINGShapeProp;
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

	enum {IDD = IDD_SHAPEPROP};


BEGIN_MSG_MAP(CShapeProp)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_HANDLER(IDC_SHAPE, CBN_SELCHANGE, OnShapeTypeChange)
	CHAIN_MSG_MAP(IPropertyPageImpl<CShapeProp>)
END_MSG_MAP()

// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnShapeTypeChange(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	STDMETHOD(Apply)(void);
protected:
	CComboBox m_shape;
};


