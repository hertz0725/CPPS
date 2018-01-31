#include <iostream>
using namespace std;

class A{

private:
	int val;

public:
	A()
	{
		cout<<"construct A"<<endl;
	}

	A(int n)
	{
		val = n;
		cout<<"construct A"<<endl;
	}

	virtual void disp()
	{
		cout<<"AAAA"<<endl;
	}

	virtual ~A()
	{
		cout<<"destory A"<<endl;
	}

};

class B:public A {

public:

	B()
	{
		cout<<"construct B"<<endl;
	}

	virtual void disp(int a) //是基类的扩展(重载，只能B的实例来调用)，不是重写！！
	{
		cout<<"BBBB"<<endl;
	}

	virtual ~B()
	{
		cout<<"destory B"<<endl;
	}
};

int main()
{
	//A *b = new B();

	//A *a = b; //A只是个指针 并没有构造 只需要析构b即可

	//a->disp(2); //no matching function for call to 'A::disp(int)'
				//就是说a中没有的方法不能乱调用

	//a->disp();//派生类中没有重写，则调用基类版本

	//delete b;

	A a = 10; //可以用等号直接赋值

	return 0;
}