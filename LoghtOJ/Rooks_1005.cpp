#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

ll dp[31][31];

ll nCr(ll n,ll k)
{
    if(k==0) return 1;
    if(k>n) return 0;
    if(k==1) return n;
    if(dp[n][k]!=-1) return dp[n][k];

    return dp[n][k] = nCr(n-1,k)+nCr(n-1,k-1);
}
ll nPr(ll n,ll k)
{
    ll cal=1;
    for(ll i=n-k+1;i<=n;i++) cal *= i;
    return cal;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        memset(dp,-1,sizeof(dp));
        ll n,k;
        scanf("%lld %lld",&n ,&k);
        printf("Case %d: %lld\n",N,nPr(n,k)*nCr(n,k));
    }
    return 0;
}
