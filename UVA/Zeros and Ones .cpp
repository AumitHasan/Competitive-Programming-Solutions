#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define ll  long long int

ll power[65];
ll dp[65][101][65][65];
ll n,k,mx_one,mx_zero,add;
ll c;

ll call(ll i,ll val,ll one,ll zero)
{
    //cout<<i<<" "<<val<<" "<<one<<" "<<zero<<endl;
    if(one>mx_one or zero>mx_zero) return 0;
    if(i==n-1){

        if(one==mx_one and zero==mx_zero){
            ll a = (val+add)%k;
            //cout<<a<<endl;
            if(a%k==0){
                return 1;
            }
        }
        return 0;
    }
    if(dp[i][val][one][zero] != -1 ) return dp[i][val][one][zero];
    //if(one+1<=mx_one)
    return dp[i][val][one][zero] = call(i+1,(val+power[i])%k,one+1,zero) + call(i+1,val,one,zero+1);

    //return dp[i][one][zero] = max(p1,p2);
}
void pw()
{
    power[0] = 1;
    for(int i=1;i<=64;i++){
        power[i] = (power[i-1]*2)%k;
    }
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        mem(dp,-1);
        scanf("%lld %lld",&n ,&k);

        if(k==0){
            printf("Case %d: 0\n",N);
            continue;
        }
        pw();
        mx_one = n/2-1;
        mx_zero = n/2;
        add = power[n-1];
        //cout<<add<<endl;

        ll res = call(0,0,0,0);

        printf("Case %d: %lld\n",N,res);
    }
    return 0;
}
