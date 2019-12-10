#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

ll n,m,k,fact[1000007],inmod[1000007];

ll bincof(ll nn,ll k)
{
    if(k==0 || k>nn) return 0;
    ll ans = 1;
    if(ans<=1e6){
        ans = (inmod[k]%mod * inmod[nn-k]%mod) % mod;
        ans = (ans * fact[nn]) % mod;
        return ans;
    }
    //
    ll a,b;
    a = max(k,nn-k);
    b = min(k,nn-k);
    for(int i=a+1;i<=nn;i++){
        ans = (i*ans) %mod;
    }
    return (ans * inmod[b]) % mod;
}
ll bigmod(int a,int p)
{
    if(p==0) return 1;
    if(p==1) return a;

    if(p%2==0){
        ll x = bigmod(a,p/2) % mod;
        return (x * x) % mod;
    }
    else{
        ll x = a * bigmod(a,p-1);
        return x%mod;
    }
}
ll call(int x,int r)
{
    ll tmp=1,val=1;
    int a = max(r,x-r);
    int b = min(r,x-r);
    for(int i=a+1;i<=x;i++) tmp = (tmp * i) % mod;
    for(int i=1;i<=b;i++) val = (val * i) % mod;

    return (tmp * bigmod(val,mod-2)) % mod;
}
void pre()
{
    fact[0] = inmod[0] = 1;
    for(int i=1;i<=1e6;i++){
        fact[i] = (fact[i-1]*i) % mod;
        inmod[i] = bigmod(fact[i],mod-2);
    }
}
int main()
{
    pre();

    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%lld %lld %lld", &n, &m, &k);
        ll ans = 0,f=0;
        //ans = (k * bigmod(k-1,n-1)%mod)%mod;

        for(int i=k;i>1;i--){
            ll tmp = bincof(m,i);
            //ll tmp = (m * bigmod(i,mod-2)) % mod;
            //cout<<tmp<<endl;
            if(f==0){
                ans += ( tmp * (i * bigmod(i-1,n-1)) ) % mod;
                ans %= mod;
                f =1 ;
            }
            else if(f==1){
                ans -= ( tmp * (i * bigmod(i-1,n-1)) ) % mod;
                ans %= mod;
                f=0;
            }
        }
        printf("Case #%d: %lld\n",N,ans%mod);
    }
}
