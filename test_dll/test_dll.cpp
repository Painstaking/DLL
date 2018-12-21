// test_dll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<windows.h>
using namespace std;

typedef  void (*FuncPtr)(LPCTSTR);//函数指针，本质是一个指针变量。
                                  //(LPCTSTR)是传参，LPCTSTR为类型
////////////////////////////////////
void p()////指针函数实例：
{


		typedef struct _Data
		{
			int a;
			int b;
		}Data;

		//指针函数
		Data* f(int a,int b)
		{
			Data * data = new Data;
			data->a = a;
			data->b = b;
			return data;
		}

		int _tmain(int argc, char *argv[])
		{

			//调用指针函数
			Data* myData = NULL;
            myData=f(10,5);
			cout << "f(10,5) = " << myData->a << myData->b<<endl;
            delete myData;
			system("pause");
			return 0;
		}
}

int _tmain(int argc, _TCHAR* argv[])
{

	cout << "Hello world!" << endl;
	FuncPtr myDllFunc;
	BOOL linkSuccessFlag = FALSE, fFreeResult;
	//获取DLL模块的句柄
	HINSTANCE hinstLib = LoadLibrary("create_dll.dll");

	if (hinstLib != NULL) {
		myDllFunc = (FuncPtr) GetProcAddress(hinstLib, "SomeFunction");

		if (myDllFunc != NULL)
		{
			linkSuccessFlag = TRUE;
			myDllFunc("Hello, World! by jash");
		}
		fFreeResult = FreeLibrary(hinstLib);
	}
	system("pause");

	return 0;
}

