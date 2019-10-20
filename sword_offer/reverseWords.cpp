#include <iostream>
using namespace std;

void reverseBegEnd(string &s, int beg, int end)
{
    while(beg < end)
    {
        swap(s[beg++],s[end--]);
    }
    
}

void reverseWords(string &s) {
    
    reverseBegEnd(s,0,s.size()-1);
    
    int i = 0, j = 0;
    
    while( i<s.size() && j<s.size())
    {
        if(s[i]==' ')
        {
            i++, j++;
        }
        else if(s[j]==' ' || j==s.size()-1)
        {
            reverseBegEnd(s,i,j-1);
            i = j = j+1;
        }
        else
            j++;
    }
        
    while(s[0]==' ')
        s.erase(0,1);
        
    j = s.size()-1;
    while( j>=0 && s[j]==' ')
        s.erase(j--,1);

    i=0;
    while(i+1<s.size())
    {
        if(s[i]==' ' && s[i+1]==' ')
            s.erase(i,1);
        else
            i++;
    }

}


int main()
{
    // string s = "   1    233   2 3  1   ";

    // reverseWords(s);

    // cout<<s<<endl;

    char a = 'a', b = 'Z';

        cout<<a<<(int)a<<endl;

        cout<<b<<(int)b<<endl;

    return 0;
}