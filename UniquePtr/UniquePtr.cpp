// UniquePtr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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
	MyUniquePtr cstrPtr(cstr);
	cstr = "ab";
	printf("cstr %x\n", cstr);
	return 0;
}

