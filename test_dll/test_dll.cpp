// test_dll.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include<windows.h>
using namespace std;

typedef  void (*FuncPtr)(LPCTSTR);//����ָ�룬������һ��ָ�������
                                  //(LPCTSTR)�Ǵ��Σ�LPCTSTRΪ����
////////////////////////////////////
void p()////ָ�뺯��ʵ����
{


		typedef struct _Data
		{
			int a;
			int b;
		}Data;

		//ָ�뺯��
		Data* f(int a,int b)
		{
			Data * data = new Data;
			data->a = a;
			data->b = b;
			return data;
		}

		int _tmain(int argc, char *argv[])
		{

			//����ָ�뺯��
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
	//��ȡDLLģ��ľ��
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

