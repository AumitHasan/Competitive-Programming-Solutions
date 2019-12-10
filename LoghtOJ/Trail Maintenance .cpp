#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define inf 1e9
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
#define mx 203

int counter,a,b,n,ttl,w,cost[mx][mx],par[mx],sz[mx],vis[mx],cf;
struct stc{
    int u,last,val,e,f;
}three;

struct info{
    int u,v,len;
    bool operator<(const info & p) const
    {
        return len < p.len;
    }
}path,ar[205];

vector<info>vec,two;
vector<int>edge[mx];
set<int>st,ck;

int dsu(int r)
{
    if(par[r]==r) return r;
    return par[r] = dsu(par[r]);
}
void U_dsu(int u,int v)
{
    int pu = dsu(u);
    int pv = dsu(v);
    if(pu != pv){
                    //par[u] = v;
        if(sz[pu] >= sz[pv]){
            sz[pu] += sz[pv];
            par[pv] = pu;
        }
        else if(sz[pu] < sz[pv]){
            sz[pv] += sz[pu];
            par[pu] = pv;
        }
    }
}
void mst()
{
    ttl = 0;
    sort(vec.begin(),vec.end());
    for(int i=1;i<=n;i++) par[i] = i,sz[i]=1;
    //

    //
    int cnt = 0;
    for(int i=0;i<vec.size();i++){
        int pu = dsu(par[vec[i].u]);
        int pv = dsu(par[vec[i].v]);
        if(pu != pv){
            two.push_back(vec[i]);
            //ar[i].u = vec[i].u; ar[i].v = vec[i].v; ar[i].len = vec[i].len;
            if(pu != pv){
                if(sz[pu] >= sz[pv]){
                    sz[pu] += sz[pv];
                    par[pv] = pu;
                }
                else if(sz[pu] < sz[pv]){
                    sz[pv] += sz[pu];
                    par[pu] = pv;
                }
            }
            cnt++;
            ttl += vec[i].len;
            if(cnt == n-1) break;
        }
    }
    printf("%d\n",ttl);
}
void mst_two()
{
    vec.clear();
    ttl = 0;
    two.push_back(path);
    sort(two.begin(),two.end());
    for(int i=1;i<=n;i++) par[i] = i,sz[i]=1;
    //

    //
    int cnt = 0;
    for(int i=0;i<two.size();i++){
        int pu = dsu(par[two[i].u]);
        int pv = dsu(par[two[i].v]);
        if(pu != pv){
            vec.push_back(two[i]);
            //ar[i].u = two[i].u; ar[i].v = two[i].v; ar[i].len = two[i].len;
            if(pu != pv){
                if(sz[pu] >= sz[pv]){
                    sz[pu] += sz[pv];
                    par[pv] = pu;
                }
                else if(sz[pu] < sz[pv]){
                    sz[pv] += sz[pu];
                    par[pu] = pv;
                }
            }
            cnt++;
            ttl += two[i].len;
            if(cnt == n-1) break;
        }
    }
    printf("%d\n",ttl);
    two.clear();
    for(int i=0;i<vec.size();i++) two.push_back(vec[i]);
}
int main()
{
    //
    int T,N=0,u,v,len,last;
    scanf("%d", &T);
    while(++N<=T){
        bool flag = false, f = false;
        vec.clear();
        two.clear();
        //

        scanf("%d %d", &n, &w);
        printf("Case %d:\n",N);

        for(int i=1;i<=n;i++) par[i] = i, sz[i]=1;

        for(int i=0;i<w;i++){
            scanf("%d %d %d", &u, &v, &len);
            path.u = u; path.v = v; path.len = len;

            if(!flag){
                vec.push_back(path);
                //
                U_dsu(u,v);
                //
                st.clear();
                for(int i=1;i<=n;i++){
                    par[i] = dsu(i);
                    st.insert(par[i]);
                    //cout<<par[i]<<" ";
                }
                //cout<<endl;
            }
            //
            if(flag || st.size()==1){
                flag = true;
                if(!f){
                    mst();
                }
                if(f) mst_two();
                f = true;
            }
            else printf("-1\n");
        }
    }
}
