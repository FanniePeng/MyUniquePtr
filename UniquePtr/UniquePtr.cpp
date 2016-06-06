// UniquePtr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>

using namespace std;

class MyUniquePtr
{
public:
	MyUniquePtr(char *ptr);
	~MyUniquePtr();
	void MyPrint();

private:
	char *mPtr;
};

MyUniquePtr::MyUniquePtr(char * ptr)
{
	printf("\nMyUniquePtr\n");
	mPtr = ptr;
	MyPrint();
}

MyUniquePtr::~MyUniquePtr()
{
	printf("\n~MyUniquePtr\n");
	MyPrint();
	if (NULL != mPtr)
	{
		delete mPtr;
	}
	MyPrint();
}

void MyUniquePtr::MyPrint()
{
	printf("ptr %x\n", mPtr);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *cstr = NULL;
	cstr = new char[10];
	const char * cs = "dd";
	strcpy(cstr, cs);
	MyUniquePtr cstrPtr(cstr);
	printf("cstr %x\n", cstr);
	return 0;
}

