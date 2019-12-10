#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[55][55],n,ar[100003];

ll solve(ll start,ll endd)
{
    if(start==endd) return ar[start];
    if(start>endd) return 0;

    if(dp[start][endd] != -1) return dp[start][endd];

    ll mid,mx=0;
    for(mid=start;mid<endd;mid++){

        ll left =  solve(start,mid);

        ll right;
        //if(sign[mid][mid+1]==0)
        ll b = left * solve(mid+1,endd);
        ll a = left + solve(mid+1,endd);

        //ll ans = left+right;

        //if(right>mx) mx = right;
        mx = a+b;
        //if(right<mn and start==1 and endd==in) mn = right;
    }
    dp[start][endd] = mx;

    return dp[start][endd];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
            ll mx = solve(0,n-1);
            cout<<mx<<endl;
    }
    return 0;
}
