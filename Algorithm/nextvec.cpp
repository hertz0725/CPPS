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


int main()
{
	
	return 0;
}