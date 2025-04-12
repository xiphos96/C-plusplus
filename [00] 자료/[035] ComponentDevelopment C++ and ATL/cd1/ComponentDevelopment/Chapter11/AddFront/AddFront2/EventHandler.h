class ATL_NO_VTABLE CEventHandler : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IUnknown,
	public IDispEventImpl<1, CEventHandler, &DIID__IAddBackEvents, &LIBID_AddBackLib, 1, 0>
{
public:

	BEGIN_COM_MAP(CEventHandler)
		COM_INTERFACE_ENTRY(IUnknown)
	END_COM_MAP()

	BEGIN_SINK_MAP(CEventHandler)
		SINK_ENTRY_EX(1, DIID__IAddBackEvents, 1, OnChangedAddEnd)
		SINK_ENTRY_EX(1, DIID__IAddBackEvents, 2, OnChangedSum)
	END_SINK_MAP()

	void HookEvent(IUnknown* pSource) {
		DispEventAdvise(pSource, &DIID__IAddBackEvents);
	}

	void UnHookEvent(IUnknown* pSource) {
		DispEventUnadvise(pSource, &DIID__IAddBackEvents);
	}

	void __stdcall OnChangedAddEnd(SHORT newVal) {
		CString szMsg("AddEnd 속성이 변경되었습니다.\n");
		CString szTemp;
		szTemp.Format("AddEnd 속성 값 : %d", newVal);
		szMsg += szTemp;
		MessageBox(NULL, szMsg.GetBuffer(szMsg.GetLength()), "AddEnd 속성값 변경", MB_OK);
	}

	void __stdcall OnChangedSum(SHORT newVal) {
		CString szMsg("Sum 속성이 변경되었습니다.\n");
		CString szTemp;
		szTemp.Format("Sum 속성 값 : %d", newVal);
		szMsg += szTemp;
		MessageBox(NULL, szMsg.GetBuffer(szMsg.GetLength()), "Sum 속성값 변경", MB_OK);
	}

};
