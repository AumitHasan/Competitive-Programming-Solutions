#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 507
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int n,m,city,par[mx],fw[mx][mx],ans[mx],vis[mx];
struct info{
    int u,v,cost;
    bool operator<(const info& p) const
    {
        return cost < p.cost;
    }
}path;
vector<info>edge;
vector<int>vec[mx];

void bfs()
{
    queue<int>Q;
    Q.push(city);
    ans[city] = 0;
    vis[city] = 1;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i=0;i<vec[u].size();i++){
            int v = vec[u][i];
            if(vis[v] == 0){
                ans[v] = max(fw[u][v], ans[u]);
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
    //cout<<"ans: ";
    for(int i=0;i<n;i++){
        if(i != city && ans[i]==0) printf("Impossible\n");
        else printf("%d\n",ans[i]);
    }
    //cout<<endl;
}
int dsu(int r)
{
    if(par[r] == r) return r;
    par[r] = dsu(par[r]);
    return par[r];
}
void mst()
{
    mem(fw,0);
    sort(edge.begin(),edge.end());
    for(int i=0;i<n;i++) par[i] = i;
    //
    int cnt=0;
    for(int i=0;i<edge.size();i++){
        int u = dsu(edge[i].u);
        int v = dsu(edge[i].v);
        if(u != v){
            int x = edge[i].u;
            int y = edge[i].v;
            vec[x].push_back(y);
            vec[y].push_back(x);
            fw[edge[i].u][edge[i].v] = edge[i].cost;
            fw[edge[i].v][edge[i].u] = edge[i].cost;
            //
            par[u] = v;
            cnt++;
            if(cnt==n-1) break;
        }
    }
    //
    bfs();
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        edge.clear();
        mem(vis,0);
        mem(vec,0);
        mem(ans,0);
        //
        scanf("%d %d", &n, &m);
        for(int i=0;i<m;i++){
            scanf("%d %d %d", &path.u, &path.v, &path.cost);
            edge.push_back(path);
        }
        scanf("%d",&city);
        printf("Case %d:\n",N);
        //
        mst();
        //
    }
}
