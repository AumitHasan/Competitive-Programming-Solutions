#include<bits/stdc++.h>
using namespace std;
#define ll long long int

unordered_map<int,ll>dp;
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

    ll x,n,one,two;
    while(scanf("%lld %lld",&a ,&b)){
        if(a>b) swap(a,b);
        one=a;
        two=b;
        n = 0;
        if(a==0 && b==0 ) break;
        x = res = 0;
        if(a==1){
            res = 3;
            n = 1;
            a++;
        }
        ll num;
        for(ll i=a;i<=b;i++){
            if(i%2==0) num = i/2;
            else num = 3*i + 1;
            x = call(num);
            if(x>res){
                res = x;
                n = i;
            }
        }
        cout<<"Between "<<one<<" and "<<two<<", "<<n<<" generates the longest sequence of "<<res<<" values."<<endl;
    }
    return 0;
}

