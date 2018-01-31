#include <fstream>
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	auto i=0;

	cout<<i<<endl;

	ifstream fin("in.txt");

	string str;
	string res;
	while(getline(fin,str))
	{
		res += str;
	}

	ofstream fout("out.txt");

	fout<<res<<endl;


	return 0;
}