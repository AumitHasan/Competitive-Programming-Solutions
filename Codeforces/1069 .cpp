#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<ll,ll>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     MAX3(a,b,c)              max(a,max(b,c))
#define     MAX4(a,b,c,d)            max(max(a,b),max(c,d))
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     998244353
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      100007

////
int lx,hx;
ll dp[mx][201];
int n,ar[mx];


void check(int last,int cur)
{
    if(cur<=last) lx=1,hx=200;
    else lx=cur,hx=200;
}
ll call(int pos,int last,int lo,int hi)
{
    if(pos>n) return 1;
    if(dp[pos][last] != -1) return dp[pos][last];

    ll ans = 0;

    if(pos==1){
        if(ar[pos]==-1){
            for(int i=1;i<=200;i++){
                ans = (ans + call(pos+1,i,i,200) ) % mod;
            }
        }
        else{
            ans = (ans + call(pos+1,ar[pos],ar[pos],200) ) % mod;
        }
    }
    if(ar[pos] < 0){
        if(pos==n){
            for(int i=hi;i>=lo;i--){
                if(i<=last) ans = (ans + call(pos+1,i,i,i) ) % mod;
            }
        }
        else{
            for(int i=lo;i<=hi;i++){
                check(last,i);
                ans = (ans + call(pos+1,i,lx,hx) ) % mod;
            }
        }
    }
    else{
        if(pos==n){
            if(last >= ar[pos] && ar[pos]>=lo && ar[pos]<=hi)
                ans = (ans + call(pos+1,ar[pos],ar[pos],ar[pos]) ) % mod;
        }
        else{
            if(ar[pos]>=lo && ar[pos]<=hi){
                check(last,ar[pos]);
                ans = (ans + call(pos+1,ar[pos],lx,hx) ) % mod;
            }
        }
    }
    return dp[pos][last] = ans%mod;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) sci(ar[i]);

    mem(dp,-1);
    ll ans = call(1,1,1,1) - 1;

    if(ans<0) cout<<1<<endl;
    else cout<<ans%mod<<endl;

}

