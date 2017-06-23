// dllmain.h: 模块类的声明。

class CTestCom3Module : public ATL::CAtlDllModuleT< CTestCom3Module >
{
public :
	DECLARE_LIBID(LIBID_TestCom3Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TESTCOM3, "{0E541574-5B3D-4663-9BFE-9D1907E06E47}")
};

extern class CTestCom3Module _AtlModule;
