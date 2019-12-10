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

#define mx 107

bool path[mx][mx],vis[mx];
int cur,dp[mx],dep[mx],res[mx];
vector<int>adj[mx];


void dfs(int u)
{
    vis[u] = 1;
    path[cur][u] = 1;
    for(int i=0;i<adj[u].size();i++){
        if(!vis[adj[u][i]]) dfs(adj[u][i]);
    }
}
void refresh()
{
    for(int i=0;i<mx;i++){
        adj[i].clear();
        for(int j=0;j<mx;j++) path[i][j] = 0;
    }
}
int main()
{
    READ("in.txt");
    WRITE("out.txt");
    int n;
    while(scanf("%d",&n) && n){
        refresh();
        //
        for(int i=1;i<=n;i++){
            int v,m;
            scanf("%d",&m);
            while(m--){
                scanf("%d",&v);
                adj[i].push_back(v);
            }
        }
        int mn = -1,node=1;
        for(int i=1;i<=n;i++){
            cur = i;
            mem(vis,0);
            dfs(i);
            int cnt = 0;
            for(int j=1;j<=n;j++) cnt += path[i][j];
            res[i] = cnt;
           // cout<<<<" ";
        }
        for(int i=1;i<=n;i++){
            //cout<<res[i]<<" ";
            if(mn < res[i]){
                mn = res[i];
                node = i;
            }
        }
        printf("%d\n",node);
    }
    return 0;
}
