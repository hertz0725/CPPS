#include<iostream>
using namespace std;

class singleton{
private:
	singleton(){
		cout<<"construct singleton!"<<endl;
	}

	~singleton(){
		cout<<"destory singleton!"<<endl;
	}

	static singleton * pInstance;

public:
	static singleton *getInstance()
	{
		return pInstance;
	}

};

singleton *singleton::pInstance = new singleton();  //静态要在类外初始化

int main()
{
	singleton *a = singleton::getInstance();
	singleton *b = singleton::getInstance();

	return 0;
}