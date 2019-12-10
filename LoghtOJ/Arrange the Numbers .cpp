#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      1003

////


ll fact[mx],dp[mx][mx],dir[mx];


ll direngment(int n)
{
    if(n==1) return 0;
    if(n==0) return 1;
    if(n==2) return 1;
    if(dir[n] != -1) return dir[n];

    return dir[n] = ((n-1) * (direngment(n-1) + direngment(n-2))%mod ) % mod;
}
ll nCr(int n,int r)
{
    if(n==1 && r==1) return 1;
    if(r==1) return n;
    if(r==0 || r>n) return 0;
    if(dp[n][r] != -1) return dp[n][r];

    return dp[n][r] = ( nCr(n-1,r)%mod + nCr(n-1,r-1)%mod ) % mod;
}
void fact_cal()
{
    fact[1] = 1;
    for(int i=2;i<mx;i++) fact[i] = (fact[i-1] * i) % mod;
}
int main()
{

    fact_cal();
    //

    int T,N=0,n,m,k;
    sci(T);
    mem(dp,-1);
    mem(dir,-1);

    while(++N<=T){
        sciii(n,m,k);
        int len = n - k;
        int koita = m - k;

        if(n==m && m==k){
            printf("Case %d: 1\n",N);
            continue;
        }
        if(n==m){
            ll ans = (nCr(m,k) * direngment(koita)) % mod;
            printf("Case %d: %lld\n",N,ans%mod);
            continue;
        }

        ll val = fact[len];
        //cout<<val<<endl;
        for(int i=1;i<=koita;i++){
            if(i&1){
                val -= (nCr(koita,i) * fact[len-i]) % mod;
            }
            else{
                val += (nCr(koita,i) * fact[len-i]) % mod;
            }

            val = (val<0) ? val+mod : val;
            val %= mod;
        }

        ll ans = (nCr(m,k) * val) % mod;
        if(n==m && m==k) ans = 1;

        printf("Case %d: %lld\n",N,ans%mod);
    }
    return 0;
}
