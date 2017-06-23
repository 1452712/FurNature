// Add.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <string>

char buff[255];

extern "C" __declspec(dllexport) int __stdcall IntAdd(int x, int y) {
	return x + y;
}

extern "C" __declspec(dllexport) double __stdcall DoubleAdd(double x, double y) {
	return x + y;
}

extern "C" __declspec(dllexport) bool __stdcall BoolAdd(bool x, bool y) {
	return x & y;
}

extern "C" __declspec(dllexport) char* __stdcall StringAdd(char* x, char* y) {
	strcpy(buff, x);
	strcat(buff, y);
	return buff;
}

