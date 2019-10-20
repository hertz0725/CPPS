#include <iostream>
#include <cstdio>
using namespace std;

const char *ToString(int iVal){

	static char p[100], *q;
	q = p;
	int cnt = 0;
	while(iVal)
	{
		*q++ = (iVal%10 + '0');
		iVal = iVal /10;
		++cnt;
	}

	*q = '\0';

	char *beg = p, *end = --q;

	while(beg<end)
	{
		char tmp = *beg;
		*beg = *end;
		*end = tmp;
		beg++, end--;
	}

	return p;

}

int main()
{
	printf("%s\n",ToString(789562321));
	return 0;
}

