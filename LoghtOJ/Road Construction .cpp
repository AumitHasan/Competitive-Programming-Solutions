#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 55
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

int m,par[mx],in;
set<int>st;
map<string,int>mp;
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
    if(par[r]==r) return r;
    return par[r] = dsu(par[r]);
}
void mst()
{
    for(int i=1;i<=in;i++){
        par[i] = dsu(i);
        //cout<<par[i]<<endl;
    }
    st.clear();
    for(int i=1;i<=in;i++) st.insert(par[i]);
    if(st.size()>1){
        printf("Impossible\n");
        return;
    }
    //
    sort(edge.begin(),edge.end());

    for(int i=1;i<=in;i++) par[i] = i;
    int tk=0,cnt=0;
    for(int i=0;i<m;i++){
        int u = dsu(edge[i].u);
        int v = dsu(edge[i].v);
        if(u != v){
            par[u] = v;
            tk += edge[i].cost;
            cnt++;
            if(cnt == in-1) break;
        }
    }
    printf("%d\n",tk);
}
int main()
{
    string str,ch;
    int T,N=0,w;
    scanf("%d",&T);
    while(++N<=T){
        edge.clear();
        for(int i=1;i<=55;i++) par[i] = i;
        mp.clear();
        //
        in = 0;
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>str>>ch>>w;
            if(mp[str]==0) mp[str] = ++in;
            if(mp[ch]==0) mp[ch] = ++in;

            int x = dsu(mp[str]);
            int y = dsu(mp[ch]);
            if(x != y) par[x] = y;

            path.u = mp[str];
            path.v = mp[ch];
            path.cost = w;
            edge.push_back(path);
        }
        //
        printf("Case %d: ",N);
        mst();
    }
    return 0;
}
