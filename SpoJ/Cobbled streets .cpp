#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 1007
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

int n,m,par[mx];
struct info{
    int u,v,cost;
    bool operator<(const info& p) const
    {
        return cost < p.cost;
    }
}path;
vector<info>edge;

ll dsu(int r)
{
    if(par[r] == r) return r;
    par[r] = dsu(par[r]);
    return par[r];
}
ll mst()
{
    sort(edge.begin(),edge.end());
    for(int i=1;i<=n;i++) par[i] = i;

    ll cnt=0,price = 0;
    for(int i=0;i<edge.size();i++){
        int u = dsu(edge[i].u);
        int v = dsu(edge[i].v);
        if(u != v){
            par[u] = v;
            price += edge[i].cost;
            cnt++;
            if(cnt == n-1) break;
        }
    }
    return price;
}
int main()
{
    int T,unit;
    cin>>T;
    while(T--){
        edge.clear();
        //
        scanf("%d %d %d", &unit, &n, &m);
        for(int i=0;i<m;i++){
            scanf("%d %d %d", &path.u, &path.v, &path.cost);
            edge.push_back(path);
        }
        cout<<unit * mst()<<endl;
    }
    return 0;
}
