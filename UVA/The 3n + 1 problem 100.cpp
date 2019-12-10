#include<bits/stdc++.h>
using namespace std;
#define ll long long int

map<int,ll>dp;
ll res,a,b;

ll call(ll n)
{
    //if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=0) return dp[n];

    ll p1=0,p2=0;
    if(n%2==0) p1 = call(n/2)+1;
    else p2 = call(n*3 + 1)+1;

    return dp[n] = p1+p2;
}
int main()
{

    ll x;
    while(scanf("%lld %lld",&a ,&b)==2){
        x = res = 0;
        for(ll i=a;i<=b;i++){
             x = call(i);
            if(x>res) res = x;
        }
        cout<<res<<endl;
    }
    return 0;
}
