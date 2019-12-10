#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))

ll dp[53][53],num[53];

ll prm(ll n,ll k)
{
    if(k>n) return 0;
    if(k==0 or k==n) return 1;
    if(dp[n][k]!=0) return dp[n][k];
    return dp[n][k] = prm(n-1,k)+prm(n-1,k-1);
}
int main()
{
    ll n,m,k,N=0;
    while(1){
        ll c=0;
        mem(dp,0);
        mem(num,0);
        scanf("%lld%lld",&n,&m);
        if(n==0) break;
        for(int i=0;i<n;i++){
            scanf("%lld",&k);
            num[k]++;
        }
        for(int i=1;i<53;i++){
            if(num[i]>0) c++;
        }
        printf("Case %lld:\n",++N);
        for(int i=0;i<m;i++){
            scanf("%lld",&k);
            ll res = prm(c,k);
            printf("%lld\n",res);
        }

    }
}
