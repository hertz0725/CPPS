#include <iostream>
using namespace std;


class A{
public:
	int ma;
};

class B{
public:
	int mb;

};

class C:public A, public B{

};


int main()
{
	// C c;

	// cout<<&c<<endl<<reinterpret_cast<B*>(&c)<<endl<<dynamic_cast<B*>(&c)<<endl;

	double d = 3.141592654;
	int a = 5;
	cout<<static_cast<int>(d)<<endl;

	cout<<static_cast<int*>(&a)<<endl;



	cout<<reinterpret_cast<double*>(&d)<<endl;



	return 0;
}