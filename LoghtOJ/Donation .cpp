#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 57
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

int donate,n,ar[mx][mx],par[mx];

struct info{
    int u,v,cost;
    bool operator<(const info & p) const
    {
        return cost < p.cost;
    }
}path;
vector<info>vec;


int dsu(int r)
{
    if(par[r]==r) return r;
    return par[r] = dsu(par[r]);
}
void mst()
{
    for(int i=1;i<=n;i++) par[i] = dsu(i);

    set<int>st;
    for(int i=1;i<=n;i++) st.insert(par[i]);
    if(st.size()>1){
        printf("-1\n");
        return ;
    }
    //
    sort(vec.begin(),vec.end());
    for(int i=1;i<=n;i++) par[i] = i;
    //
    int cnt = 0;
    for(int i=0;i<vec.size();i++){
        int u = dsu(vec[i].u);
        int v = dsu(vec[i].v);
        if(u != v){
            //cout<<vec[i].u<<" "<<vec[i].v<<" "<<vec[i].cost<<endl;
            par[u] = v;
            cnt++;
            if(cnt == n-1){
                for(int j=i+1;j<vec.size();j++){
                    donate += vec[j].cost;
                    //cout<<vec[i].u<<" "<<vec[i].v<<" "<<vec[i].cost<<endl;
                }
                break;
            }
        }
        else donate += vec[i].cost;
    }
    if(cnt == n-1) printf("%d\n",donate);
    else printf("-1\n");
}
int main()
{
    int T,N=0;
    scanf("%d", &T);
    while(++N<=T){
        mem(ar,0);
        vec.clear();
        donate = 0;
        //
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d", &ar[i][j]);
                if(i==j){
                    donate += ar[i][j];
                    ar[i][j] = 0;
                }
            }
        }
        for(int i=1;i<=n;i++) par[i]  = i;

        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j) continue;
                if(ar[i][j] > 0 && ar[j][i] > 0){
                    donate += max(ar[i][j],ar[j][i]);
                    ar[i][j] = ar[j][i] = min(ar[i][j],ar[j][i]);
                    int x = dsu(i);
                    int y = dsu(j);
                    if(x != y){
                        par[x] = y;
                    }
//                    edge[i].push_back(j);
//                    edge[j].push_back(i);
                    path.u = i; path.v = j; path.cost = ar[i][j];
                    vec.push_back(path);
                }
                else if(ar[i][j] > 0 || ar[j][i] > 0){
                    ar[i][j] = ar[j][i] = max(ar[i][j],ar[j][i]);
                    //cout<<i<<" ck "<<j<<" "<<ar[i][j]<<endl;
                    int x = dsu(i);
                    int y = dsu(j);
                    if(x != y){
                        par[x] = y;
                    }
//                    edge[i].push_back(j);
//                    edge[j].push_back(i);
                    path.u = i; path.v = j; path.cost = ar[i][j];
                    vec.push_back(path);
                }
            }
        }
        //cout<<donate<<endl;
        printf("Case %d: ",N);
        mst();
    }
    return 0;
}
