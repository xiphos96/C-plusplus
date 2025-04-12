class ATL_NO_VTABLE CEventHandler : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IAddBackEvents, &IID_IAddBackEvents, &LIBID_AddBackLib>
{
public:
	BEGIN_COM_MAP(CEventHandler)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IAddBackEvents)
	END_COM_MAP()

	STDMETHOD(raw_ChangedAddEnd) (SHORT newVal) {
		CString szMsg("AddEnd 속성이 변경되었습니다.\n");
		CString szTemp;
		szTemp.Format("AddEnd 속성 값 : %d", newVal);
		szMsg += szTemp;
		MessageBox(NULL, szMsg.GetBuffer(szMsg.GetLength()), "AddEnd 속성값 변경", MB_OK);
		return S_OK;
	}

	STDMETHOD(raw_ChangedSum) (SHORT newVal) {
		CString szMsg("Sum 속성이 변경되었습니다.\n");
		CString szTemp;
		szTemp.Format("Sum 속성 값 : %d", newVal);
		szMsg += szTemp;
		MessageBox(NULL, szMsg.GetBuffer(szMsg.GetLength()), "Sum 속성값 변경", MB_OK);
		return S_OK;
	}
};
