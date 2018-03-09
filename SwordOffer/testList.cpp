#include <iostream>
using namespace std;
#include <list>

int main()
{
	list<int> l1;
	list<int> l2;
	list<int> l3;

	for(int i = 0; i<5; i++)
		l1.push_back(i);

	for(int i = 10; i<15; i++)
		l2.push_back(i);


	auto it_t = l1.begin();
	it_t++, it_t++;

	cout<<*it_t<<endl;

	for(auto it = l1.begin(); it!=l1.end(); it++)
		cout<<*it<<" ";
	cout<<endl;

	l1.splice(l2.begin(),l3,it_t);

	cout<<*it_t<<endl;

	for(auto it = l1.begin(); it!=l1.end(); it++)
		cout<<*it<<" ";
	cout<<endl;

	for(auto it = l2.begin(); it!=l2.end(); it++)
	cout<<*it<<" ";
	cout<<endl;
    //test //

	return 0;
}