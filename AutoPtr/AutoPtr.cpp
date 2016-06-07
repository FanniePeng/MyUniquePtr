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

	pW1 = pW2;// ��һ������ָ�븳������һ������ָ�룺pW2����������pW2->pW1ԭ��ָ��ӵ���߹�ϵת�ƣ�pW2��ת������ָ������ָ�룬pW2���ܼ���ʹ��
	cout << pW1.get() << endl;
	cout << pW2.get() << endl;

	std::auto_ptr<MyWebSite> pW3(pW1);// pW1->pW3��pW1���㣬pW1���ܼ���ʹ��һ��ԭ��ָ��ͬʱֻ�ܱ�һ������ָ����ӵ�У���ֵ���߹��죬���ᷢ��ԭ��ָ��ת��
	cout << pW1.get() << endl; 
	cout << pW3.get() << endl;

	return 0;
}

