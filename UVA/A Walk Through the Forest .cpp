#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define inf INT_MAX
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,ll>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 1007

int dp[mx],n,m;
ll dis[mx];
vector<pr>adj[1007];
pr x;

int dfs(int u,int p)
{
    if(u==2) return 1;
    if(dp[u] != -1) return dp[u];

    int way = 0;

    for(int i=0;i<adj[u].size();i++){
        x = adj[u][i];
        int v = x.first;
        if(v!=p && dis[v] < dis[u]){
            way += dfs(v,u);
        }
    }
    return dp[u] = way;
}
void sbfs()
{
    pr u,v;
    set<pr>Q;
    Q.insert(pr(2,0));
    dis[2] = 0;
    while(!Q.empty()){
        u = *Q.begin(); Q.erase(u);

        for(int i=0;i<adj[u.first].size();i++){
            v = adj[u.first][i];
            if(u.second + v.second < dis[v.first]){
                dis[v.first] = u.second + v.second;
                Q.insert(pr(v.first,dis[v.first]));
            }
        }
    }
    //for(int i=1;i<=n;i++) cout<<dis[i]<< " ";
}
void refres()
{
    for(int i=0;i<mx;i++){
        adj[i].clear();
        dis[i] = inf;
        dp[i] = -1;
    }
}
int main()
{
    int u,v,d;
    while(scanf("%d",&n) && n){
        refres();
        //
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u, &v, &d);
            adj[u].push_back(pr(v,d));
            adj[v].push_back(pr(u,d));
        }
        sbfs(); // shortest path from all node.
        //
        int ans = dfs(1,1);
        printf("%d\n",(ans<0) ? 0 : ans);
    }
}
