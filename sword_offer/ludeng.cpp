#include <iostream>
#include <vector>
using namespace std;

int getmin(string &s)
{
    int minl = 0;
    vector<int> dp(s.size(),0);
    if(s[0]=='.')
    {
        if(s.size()==1)
        {
            dp[0]=1;
            return 1;
        }else if(s.size()==2)
        {
            dp[0] = dp[1] =1;
            return 1;
        }
        else if(s.size()==3)
        {
            dp[0] = dp[1] = dp[2] = 1;
            return 1;
        }
        else{// >=4
            dp[0] = dp[1] = dp[2] = 1;
            for(int i =3;i<s.size();i++)
            {
                if(s[i]=='X')
                    dp[i]=dp[i-1];
                else
                {//=='.'
                    if( i+2<s.size() )
                    {
                        dp[i] = dp[i+1] = dp[i+2] = dp[i-1]+1;
                        i=i+2;
                    }
                    else if(i+1<s.size())
                    {
                        dp[i] = dp[i+1] = dp[i-1]+1;
                        return dp[i];
                    }
                    else
                    {
                        dp[i]=dp[i-1]+1;
                        return dp[i];
                    }
                }
            }
            return dp[dp.size()-1];
        }
    }
    else
    {
        dp[0] = 0;
        for(int i=1; i<s.size(); i++)
        {
            if(s[i]=='X')
                dp[i]=dp[i-1];
            else
            {//=='.'
                if( i+2<s.size() )
                {
                    dp[i] = dp[i+1] = dp[i+2] = dp[i-1]+1;
                    i=i+2;
                }
                else if(i+1<s.size())
                {
                    dp[i] = dp[i+1] = dp[i-1]+1;
                    return dp[i];
                }
                else
                {
                    dp[i]=dp[i-1]+1;
                    return dp[i];
                }
            }
        }
        return dp[dp.size()-1];
    }
}

int main()
{
    string s ="...XX....XX";
    cout<<getmin(s)<<endl;

    return 0;
}