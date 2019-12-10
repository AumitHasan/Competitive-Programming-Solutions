#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,n,i,j;
    cin>>s>>n;
    int dp[n+1][s+1];
    int p[n],w[n];
    for(i=0;i<n;i++)
        scanf("%d %d",&w[i],&p[i]);

    //cout<<dp[0][0]<<endl;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=s;j++)
            dp[i][j]=0;
    }


    for(i=1;i<=n;i++)
    {
        for(j=1;j<=s;j++)
        {
            if(j>=w[i-1])
                dp[i][j] = max(dp[i-1][j] , (p[i-1]+dp[i-1][j-w[i-1]]));
            else if(j<w[i-1])
                dp[i][j] = dp[i-1][j];

        }
    }

    cout<<dp[n][s]<<endl;



return 0;
}
