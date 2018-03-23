// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s1,s2;

    s1 = "13542687";
    s2 = "148675";
    
    if(s1.empty() || s2.empty())
        cout<<"0"<<endl;

    vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),0));
    int maxlen=0;
    dp[0][0] = s1[0]==s2[0] ? 1 : 0;
    maxlen = dp[0][0];
    for(int i=1; i<s1.size(); i++)
    {
        dp[i][0] = max(dp[i-1][0], s1[i] == s2[0] ? 1 :0 );
        maxlen = max(maxlen,dp[i][0]);
    }

    for(int j =1; j<s2.size(); j++)
    {
        dp[0][j] = max(dp[0][j-1], s2[j] == s1[0] ? 1 :0);
        maxlen = max(maxlen,dp[0][j]);
    }

    for( int i=1; i<s1.size(); i++)
    {
        for(int j=1; j<s2.size(); j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s1[i]==s2[j])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);

            maxlen = max(maxlen,dp[i][j]);
        }
    }
    cout<<maxlen<<endl;

    return 0;
}