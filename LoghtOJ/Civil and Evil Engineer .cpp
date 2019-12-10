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

int dsu(int r)
{
    if(par[r] == r) return r;
    par[r] = dsu(par[r]);
    return par[r];
}
void mst()
{
    sort(edge.begin(),edge.end());
    for(int i=0;i<=n;i++) par[i] = i;

    int cnt=0,hi=0,low = 0;
    for(int i=0;i<edge.size();i++){
        int u = dsu(edge[i].u);
        int v = dsu(edge[i].v);
        if(u != v){
            par[u] = v;
            low += edge[i].cost;
            cnt++;
            if(cnt == n) break;
        }
    }
    //
    cnt = 0;
    for(int i=0;i<=n;i++) par[i] = i;
    for(int i=edge.size()-1;i>=0;i--){
        int u = dsu(edge[i].u);
        int v = dsu(edge[i].v);
        if(u != v){
            par[u] = v;
            hi += edge[i].cost;
            cnt++;
            if(cnt == n) break;
        }
    }
    //cout<<"cost: "<<low<<" "<<hi<<endl;
    int avg = (low+hi) / 2;

    if(avg*2 == low+hi) printf("%d\n",avg);
    else printf("%d/2\n",low+hi);

}
int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T){
        edge.clear();
        //
        scanf("%d",&n);
        while(1){
            scanf("%d %d %d", &path.u, &path.v, &path.cost);
            if(!path.u && !path.v && !path.cost) break;
            edge.push_back(path);
        }
        printf("Case %d: ",N);
        //
        mst();
    }
    return 0;
}

