#include<iostream>
#include<vector>
#include<string>
using namespace std;

size_t cnt_calls()
{
	static size_t ctr; //默认初始化0
	return ++ctr;
}

void refstr(string &str)
{
	str[0]='0';
}

int main()
{
	// int v[3][5] ={{0,1,2,3,4},{0,1,2,3,4},{0,1,2,3,4}};

	// int (*p)[5] = v;

	// string s="0123";


	// cout<<stoi(s,nullptr,10)<<endl;
	// cout<<s.substr(1,20)<<endl;
	// cout<<s<<endl;

	// for(int i = 0; i<10; i++)
	// 	cout<<cnt_calls()<<endl;

	string s="456";

	refstr(s);

	double d = 3.14159265354;


	wcout<<to_wstring(d)<<endl;


	return 0;
}