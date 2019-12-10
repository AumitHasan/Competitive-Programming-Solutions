#include<bits/stdc++.h>
using namespace std;
#define set(a) memset(a,-1,sizeof(a))

long n,w,b[1005];
long dp[1005][1005];

long berry(long i,long wt)
{

    if(i>=n) return 0;
    if(dp[i][wt]!=-1) return dp[i][wt];

    long t=0,tt=0;
    if(wt+b[i]<=w) t = berry(i+2,wt+b[i])+b[i];
    tt = berry(i+1,wt);

    dp[i][wt] = max(t,tt);
    //dp[i][wt] = max(berry(i+2,wt+b[i])+b[i],berry(i+2,wt));

return dp[i][wt];
}

int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T)
    {
        scanf("%ld %ld",&n,&w);
        for(long j=0;j<n;j++) scanf("%ld",&b[j]);

        memset(dp,-1,sizeof(dp));
        long  res = berry(0,0);
        //memset(dp,-1,sizeof(dp));
        //long r =0;// berry(1,0);

        printf("Scenario #%d: %ld\n",N,res);
    }

return 0;
}

