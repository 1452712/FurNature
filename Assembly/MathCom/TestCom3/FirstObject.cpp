// FirstObject.cpp : CFirstObject ��ʵ��

#include "stdafx.h"
#include "FirstObject.h"


// CFirstObject



STDMETHODIMP CFirstObject::Test(BSTR bstr)
{
	// TODO: �ڴ����ʵ�ִ���
	MessageBox(0, bstr, TEXT(""), 0);
	return S_OK;
}
