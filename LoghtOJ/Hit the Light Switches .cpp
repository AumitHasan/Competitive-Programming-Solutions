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

#define mx 10007

int vis[mx],flag[mx];
vector<int>adj[100007];
int cy;


void dfs(int u)
{
    if(vis[u]==1 || vis[u]==2) return;

    vis[u] = 1;

    for(int i=0;i<adj[u].size();i++){
        if(!vis[adj[u][i]])
            dfs(adj[u][i]);
    }
    vis[u] = 2;
}
int main()
{
    int T,N=0,a,b,n,m;
    scanf("%d",&T);
    while(++N<=T){
        mem(vis,0);
        mem(flag,0);
        mem(adj,0);
        //
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
            flag[b] = 1;
        }
        int ans = 0;

        for(int i=1;i<=n;i++){
            if(!flag[i]){
                cy=0;
                ans++;
                dfs(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }
        printf("Case %d: %d\n",N,ans);
    }
    return 0;
}
