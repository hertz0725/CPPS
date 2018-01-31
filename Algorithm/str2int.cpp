#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	// char *str = (char*)malloc(sizeof(char)*100);
	// strcpy(str,"1212");
	// cout << atoi(str) <<endl;

	char ch[4]={'0','1','2','\0'};
	
	for(auto x:ch)
		cout<<x<<endl;
	
	cout<<strlen(ch)<<endl;
	cout<<sizeof(ch)<<endl;

	return 0;
}