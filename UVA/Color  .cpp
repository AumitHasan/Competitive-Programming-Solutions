#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

#define pf(a) cout<<a<<endl
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define MX 100007
#define MOD 1000000007
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....

////



ll bigmod(int n,int pw)
{
    if(pw==0) return 1;

    if(pw&1){
        return (n%MOD * bigmod(n,pw-1)) % MOD;
    }
    else{
        ll tmp = bigmod(n,pw/2) % MOD;
        return  (tmp * tmp) % MOD;
    }
}
ll ncr(int n,int r)
{
    if(r > n/2) r = n - r;
    ll ans = 1,tmp=1;
    for(int i=1;i<=r;i++){
        ans *= n - r + i;
        ans %= MOD;
        tmp = (tmp * i) % MOD;
    }
    return (ans * bigmod(tmp,MOD-2)%MOD ) % MOD;
}
int main()
{
    int n,m,k;
    int N=0,t;
    scanf("%d",&t);

    while(++N<=t){
        scanf("%d %d %d", &n, &m, &k);

        ll ans = ncr(m,k) % MOD ;
        ans = (ans * (k * bigmod(k-1,n-1)%MOD) ) % MOD;

        printf("Case #%d: %lld\n",N,ans);
    }
    return 0;
}
