#include <iostream>
using namespace std;


bool fun(int **p, size_t t)
{
	*p = (int*)malloc(sizeof(int)*t);
	cout<<"**p,*p:"<<*p<<endl;
	if(*p==NULL)
		return false;
	else
		return true;
}

int main()
{
	int *p;
	size_t t=100;
	if(fun(&p,t))
		cout<<p<<endl;
	else
		cout<<"no"<<endl;

	return 0;
}