#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

#define pf(a) cout<<a<<endl
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define mx 200007
#define mod 1000000009
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....

////


int n,m,vis[mx],flag;
vector<int>adj[mx];


void dfs(int u)
{
    vis[u] = 1;
    if(adj[u].size() != 2) flag = true;
    for(auto v : adj[u]){
        if(!vis[v]) dfs(v);
    }
}
int main()
{
    int u,v;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            flag = false;
            dfs(i);
            if(!flag) ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
