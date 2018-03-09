#include <iostream>
#include <cstring>
using namespace std;

/*
*这里是指针，用来接收@字符数组@
*!!直接传指针会报段错误，因为char *s = "hello world.",存在@常量区@，不可更改@！
*/
void replaceSpace(char *str,int length) 
{
    
    char *p = str;
    int cntsp = 0;
    while(*p != '\0')
    {
        if(*p++ == ' ')
            cntsp++;
    }

    length += (cntsp*2);
    char *pNew = p;
    
    for(int i=0; i<cntsp*2; i++)
        pNew++;
    
    while(p != str-1)
    {
        if(*p != ' ')
        {
            *pNew-- = *p--;
        }
        else
        {
            *pNew-- = '0';
            *pNew-- = '2';
            *pNew-- = '%';
            p--;
        }
    }
}

int main()
{

	char str1[100] = " h  e l lo  wo  r l d .";  //数组必须有@多余空间@，开100以上

	cout<<str1<<endl;

	replaceSpace(str1, strlen(str1));

	cout<<str1<<endl;


	int m = 10, n =100;

	int dp[m][n] = {0};
	return 0;
}