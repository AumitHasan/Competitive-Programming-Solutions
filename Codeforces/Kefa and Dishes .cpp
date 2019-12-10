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

#define mx 19

int n,m,k,lim,sat[19][19],ar[19];
ll dp[524293][19];


ll call(int cnt,int mask,int last)
{
    if(cnt==m) return 0;
    if(dp[mask][last] != -1) return dp[mask][last];

    ll ans = 0;

    for(int i=1;i<=n;i++){
        if(!(mask & (1<<i))){
            //cout<<ar[i]<<" "<<sat[last][i]<<endl;
            ans = max(ans, ar[i] + sat[last][i] + call(cnt+1,mask|(1<<i),i));
        }
    }
    //cout<<endl;
    return dp[mask][last] = ans;
}
int main()
{
    int x,y,c;

    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
    for(int i=0;i<k;i++){
        scanf("%d %d %d",&x,&y,&c);
        sat[x][y] = c;
    }
    //
    mem(dp,-1);
    cout<<call(0,0,0)<<endl;
}
