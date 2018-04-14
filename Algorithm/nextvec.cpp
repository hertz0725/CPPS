#include <iostream>
using namespace std;

inline void NEXT(const string&T, vector<int>&next)
{
	next[0]=-1;
	next[1]=0;

	for(int i=2; i<next.size(); i++)
	{
		if( T[i] == T[next[i-1]+1] )
			next[i]=next[i-1]+1;
		else
			next[i]=0;
	}

}

inline void getNext(const string&s, vector<int>& next)  //c++源码 用内联函数减小开销，同时传引用 也是减小开销
{
    next[0] = -1;
    
    for(int i=1; i<s.size(); i++)
    {
        int j = next[i-1];
        
        while( j>=0 && s[i-1]!=s[j] )
            j = next[j];
        
        if(j>=0 && s[i-1] == s[j])
            next[i] = j+1;
        else
            next[i] = 0;
    }

}



int strStr(string haystack, string needle) {
    
    if( needle.empty())
        return 0;
    
    
    int i=0, N = haystack.size();
    int j=0, M = needle.size();
    
    vector<int> next(M);
    
    getNext(needle,next);
    
    
    while( i<N && j<M )
    {
        if(haystack[i]==needle[j])
        {
            i++;
            j++;
        }
        else
        {
            if( next[j]==-1 )  // 等效于 next[j]==-1
                i++;
            else
                j = next[j];     
        }
        
        if(j==M) 
            return i-M;
    }
    
    
    return -1;

}


int main()
{
	
	return 0;
}