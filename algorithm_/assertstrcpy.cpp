#include <cstring>
#include <cmath>
#include <iostream>
#include <assert.h>
using namespace std;

char *mystrcpy(char *des, const char *src)
{
	assert(des!=NULL && src!=NULL);

	char *r = des;

	while( (*r++ = *src++) != '\0');

	return des;

}

int main()
{

	// char *s = "sadasd";
	// char *d=NULL;

	// cout<<mystrcpy(d,s)<<endl;

	// string s = "01234";

	// s.erase(3,1);

	// cout<<s<<endl;
	// cout<<ceil(1.0*6/2)<<endl;

	char c=255;
	unsigned short b = c;

	cout<<b<<endl;

	return 0;
}