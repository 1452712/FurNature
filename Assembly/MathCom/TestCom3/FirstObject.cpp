// FirstObject.cpp : CFirstObject 的实现

#include "stdafx.h"
#include "FirstObject.h"


// CFirstObject



STDMETHODIMP CFirstObject::Test(BSTR bstr)
{
	// TODO: 在此添加实现代码
	MessageBox(0, bstr, TEXT(""), 0);
	return S_OK;
}
