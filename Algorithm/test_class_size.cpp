#include <iostream>
using namespace std;

class A{
public:
	virtual void fun1(){}

private:
	int a;

};

class B:public A{
public:
	virtual void fun2(){}

private:
	int b;
};

class C:public B{
public:
	virtual void fun3(){}
	
private:
	int c;

};

int main()
{
	cout<<sizeof(A)<<endl;
	cout<<sizeof(B)<<endl;
	cout<<sizeof(C)<<endl;

	return 0;
}