#include <iostream>
using namespace std;
 
class qq{
};
 
class sonqq: public qq{
};
 
class wx{
};
 
class A{
 
public:
 
    virtual void f1(qq *arg )  //虚函数 表示可以重写
    {
        cout<<"A qq"<<endl;
    }
 
    virtual void f1(wx *arg)
    {
        cout<<"A wx"<<endl;
    }
 
    // virtual void f1(sonqq *arg )
    // {
    //     cout<<"A sonqq"<<endl;
    // }
};
 
class B: public A{
 
public:
 
    // void f1(qq *arg)
    // {
    //     cout <<"B qq"<<endl;
 
    // }
     
    void f1(wx *arg)
    {
        cout<<"B wx"<<endl;
    }
 
    void f1(sonqq *arg )
    {
        cout<<"B sonqq"<<endl;
    }
};
 
int main()
{
    A *b1 = new B(); //b1的类型是A,只能调用 A 中已有方法
     
    qq *q1 = new sonqq();
 
    b1->f1(q1); //q1 静态类型是 qq
    b1->f1(new sonqq()); //new sonqq() 是 sonqq
 
    return 0;
}