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
#define mx 10007

int n,m,apt,airport,par[mx],ans;
bool vis[mx],mark[mx];
vector<pr>edge[mx];
set<int>st;
struct info{
    int u,v,cost;
    bool operator<(const info& p) const
    {
        return cost < p.cost;
    }
}path;
vector<info>vec;

int dsu(int r)
{
    if(par[r] == r) return r;
    return par[r] = dsu(par[r]);
}
void mst()
{
    int c=0;
    sort(vec.begin(),vec.end());
    for(int i=1;i<=n;i++) par[i] = i;

    for(int i=0;i<vec.size();i++){

        int u = dsu(par[vec[i].u]);
        int v = dsu(par[vec[i].v]);
        if(u != v){

            par[u] = v;
            c++;

            edge[vec[i].u].push_back(pr(vec[i].cost,vec[i].v));
            edge[vec[i].v].push_back(pr(vec[i].cost,vec[i].u));

            if(c == n-1) break;
        }
    }
}
void dfs(int u)
{
    vis[u] = 1;

    for(int i=0;i<edge[u].size();i++){

        if(vis[edge[u][i].second]==0){
            ans += edge[u][i].first;
            dfs(edge[u][i].second);
        }
    }
}
int main()
{
//    READ("in.txt");
//    WRITE("out.txt");
    //
    int T,N=0,u,v,cost;
    scanf("%d", &T);
    while(++N<=T){
        ans = airport = 0;
        mem(edge,0);
        mem(vis,0);
        vec.clear();
        //
        scanf("%d %d %d", &n, &m, &apt);
        while(m--){
            scanf("%d %d %d", &u, &v, &cost);
            if(cost>=apt) continue;
            path.u = u; path.v = v; path.cost = cost;
            vec.push_back(path);
        }
        //
        mst();
        //
        for(int i=1;i<=n;i++){
            sort(edge[i].begin(),edge[i].end());

        }

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i] = 1;
                airport++;
                ans += apt;

                dfs(i);
            }
        }
        printf("Case %d: %d %d\n",N,ans,airport);
    }
    return 0;
}
