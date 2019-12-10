#include<bits/stdc++.h>
using namespace std;

#define set(a) memset(a,-1,sizeof(a))

long long n,c[10007],dp[10007];

long long coin(long long i)
{
    if(i==n) return 0;
    if(dp[i] !=-1) return dp[i];

    long long t=0,tt=0;
    if(i<n) t = coin(i+2)+c[i];

    if(i<n) tt = coin(i+1);

    dp[i] = max(t,tt);

return dp[i];
}

int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T)
    {
        scanf("%lld",&n);
        for(long long i=0;i<n;i++) scanf("%lld",&c[i]);
        set(dp);
        long long res=0;
        res=coin(0);
        printf("Case %d: %lld\n",N,res);
    }

return 0;
}
