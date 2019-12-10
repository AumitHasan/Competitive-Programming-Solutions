#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

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
#define pii acos(-1.0)

#define mx 100007

int n,m,coin[100],occur[100],dp[100][100][100];

int call(int i,int cnt,int val)
{
    if(i>=n) return 1;
    if(dp[i][cnt][val] != -1) return 0;

    int ans = 0;

    for(int j=0;j<=occur[i];j++){
        if(val+(j*coin[i]) <= m) ans += call(i+1,j,val+(j*coin[i]));
    }
    return dp[i][cnt][val] = ans;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&coin[i]);
        for(int i=0;i<n;i++) scanf("%d",&occur[i]);
        mem(dp,-1);
        int ans = call(0,0,0);
        printf("Case %d: %d\n",N,ans);
    }
}
