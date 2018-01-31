#include<iostream>
using namespace std;

class singleton{
private:
	singleton(){

	}

	static const singleton *pInstance;

public:
	static const singleton *getInstance()
	{
		return pInstance;
	}

};

const singleton * singleton:: pInstance = new singleton();

int main()
{
	singleton *a;
	a->getInstance();
	singleton *b;
	b ->getInstance();
	return 0;
}