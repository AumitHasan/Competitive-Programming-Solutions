#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mod 10056
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 1003

int n,dp[mx],ck[mx][mx];

int ncr(int nn,int r)
{
    if(r==1) return nn;
    if(r==0 || r==nn) return 1;
    if(ck[nn][r] != -1) return ck[nn][r];

    int ans = 0;

    ans = (ans + ncr(nn-1,r)) % mod;
    ans = (ans + ncr(nn-1,r-1)) % mod;
    return ck[nn][r] = ans % mod;
}
int call(int horse)
{
    if(!horse) return 1;
    if(dp[horse] != -1) return dp[horse];

    int tmp,ans = 0;
    for(int i=1;i<=horse;i++){
        tmp = ncr(horse,i) % mod;
        ans = (ans +  (tmp * call(horse-i))%mod ) % mod;
    }
    return dp[horse] = ans%mod;
}
int main()
{
    int T,N=0;
    mem(ck,-1);
    mem(dp,-1);
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d",&n);
        printf("Case %d: %d\n",N,call(n));
    }
    return 0;
}
