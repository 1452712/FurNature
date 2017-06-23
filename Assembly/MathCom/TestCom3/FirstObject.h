// FirstObject.h : CFirstObject ������

#pragma once
#include "resource.h"       // ������



#include "TestCom3_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CFirstObject

class ATL_NO_VTABLE CFirstObject :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFirstObject, &CLSID_FirstObject>,
	public IDispatchImpl<IFirstObject, &IID_IFirstObject, &LIBID_TestCom3Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFirstObject()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FIRSTOBJECT)


BEGIN_COM_MAP(CFirstObject)
	COM_INTERFACE_ENTRY(IFirstObject)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(Test)(BSTR bstr);
};

OBJECT_ENTRY_AUTO(__uuidof(FirstObject), CFirstObject)
