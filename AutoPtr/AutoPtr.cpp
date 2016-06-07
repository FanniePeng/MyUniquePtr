// AutoPtr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>

using namespace std;

class MyWebSite
{
public:
	MyWebSite();
	~MyWebSite();
	void OutPut();
private:

};

MyWebSite::MyWebSite()
{
	printf("MyWebSite\n");
}

MyWebSite::~MyWebSite()
{
	printf("~MyWebSite\n");
}

void MyWebSite::OutPut()
{
	printf("OutPut\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	MyWebSite *oWebSite = new MyWebSite;
	oWebSite->OutPut();

	std::auto_ptr<MyWebSite> pWebsite(oWebSite);
	pWebsite->OutPut();

	cout << pWebsite.get() << endl;
	pWebsite.reset();
	cout << pWebsite.get() << endl;

	MyWebSite *pNewWebSite = new MyWebSite();
	pWebsite.reset(pNewWebSite);
	cout << pWebsite.get() << endl;

	std::auto_ptr<MyWebSite> pW1(new MyWebSite);
	std::auto_ptr<MyWebSite> pW2(new MyWebSite);
	cout << pW1.get() << endl;
	cout << pW2.get() << endl;

	pW1 = pW2;// 将一个智能指针赋给另外一个智能指针：pW2对象析构，pW2->pW1原生指针拥有者关系转移，pW2被转移智能指针置零指针，pW2不能继续使用
	cout << pW1.get() << endl;
	cout << pW2.get() << endl;

	std::auto_ptr<MyWebSite> pW3(pW1);// pW1->pW3，pW1置零，pW1不能继续使用一个原生指针同时只能被一个智能指针所拥有，赋值或者构造，都会发生原生指针转移
	cout << pW1.get() << endl; 
	cout << pW3.get() << endl;

	return 0;
}

