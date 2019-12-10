#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define mx 100007

int u,v,n,w,m,par[mx];
struct info{
    int u,v,cost;
    bool operator<(const info & p) const
    {
        return cost < p.cost;
    }
}path;
vector<info>edge;

int dsu(int r)
{
    if(par[r] == r) return r;
    int x = dsu(par[r]); // par[r] = dsu(par[r]);
    par[r] = x; // no need if use previous
    return par[r];
}
int mst()
{
    sort(edge.begin(),edge.end());
    for(int i=1;i<=n;i++) par[i] = i;

    int cnt = 0, tk = 0;
    for(int i=0;i<edge.size();i++){
        int u = dsu(edge[i].u);
        int v = dsu(edge[i].v);
        if(u != v){
            par[u] = v;
            tk += edge[i].cost;
            cnt++;
            if(cnt == n-1) break;
        }
    }
    return tk;
}
int main()
{
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        path.u = u;
        path.v = v;
        path.cost = w;
        edge.push_back(path);
    }
    cout<<mst()<<endl;

    return 0;
}
