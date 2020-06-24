#include <iostream>
using namespace std;

class A{

public:
	A(){cout<<"A"<<endl;}
	~A(){cout<<"~A"<<endl;}

};

class B:public A{

public:
	B(){cout<<"B"<<endl;}
	B(A &a){cout<<"B(a)"<<endl;}
	~B(){cout<<"~B"<<endl;}

private:
	A a_;
};

int main()
{
	A a;
	B b;

	return 0;
}
