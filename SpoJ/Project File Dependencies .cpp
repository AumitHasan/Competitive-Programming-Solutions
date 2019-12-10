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

int n,m,vis[mx],ans[10*mx],in;
vector<int>adj[mx];


void dfs(int u)
{
    cout<<u<<endl;
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++){
        if(vis[adj[u][i]] == 0){
            dfs(adj[u][i]);
        }
    }
    ans[++in] = u;
}
int main()
{
    scanf("%d %d",&n,&m);
    while(m--){
        int u,v,t;
        scanf("%d %d",&u,&t);
        while(t--){
            scanf("%d",&v);
            adj[u].push_back(v);
        }
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()>0) sort(adj[i].begin(),adj[i].end());
    }
    //
    in = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            //cout<<endl;
            dfs(i);
        }
    }
    for(int i=1;i<=in;i++){
        printf("%d",ans[i]);
        if(i==in) printf("\n");
        else printf(" ");
    }
    return 0;
}
