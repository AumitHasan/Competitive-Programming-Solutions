#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int dp[10000][10000];

ll way(ll n,ll m)
{
    if(m>n) return 0;
    if(dp[n][m]!=0) return dp[n][m];
    else if(m==n or m==0) return 1;
    return dp[n][m] = way(n-1,m-1)+way(n-1,m);
}
int main()
{
    int n,m;
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0 and m==0) break;

        ll res = way(n,m);
        printf("%d things taken %d at a time is %lld exactly.\n",n,m,res);
    }

    return 0;
}
