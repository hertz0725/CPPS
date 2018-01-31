#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    int m[4][4]={0};
    int dp[4][4]={0};

    for(int i=0; i<4; i++)
    {
        for(int j =0; j<4; j++)
            cin>>m[i][j];
    }

    dp[0][0] = m[0][0];

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(i==0 && j==0)
                continue;

            if(i>0 && j>0)
                dp[i][j] = m[i][j]+min(dp[i][j-1],dp[i-1][j]);
            else if(i==0)
                dp[i][j] = m[i][j]+dp[i][j-1];
            else if(j==0)
                dp[i][j] = m[i][j]+dp[i-1][j];
        }
    }


    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            cout << dp[i][j]<<" ";

        cout<<endl;
    }

    return 0;
}
