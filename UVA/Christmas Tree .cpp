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

#define mx 1007

int n,k,dp[mx],vis[mx];
vector<int>adj[mx];
//vector<int>child;
vector<int>tmp;

int dfs(int u)
{
    vis[u] = 1;
    if(u==1 && adj[u].size()<k) return 1;
    else if(u!=1 && adj[u].size()-1 < k) return 1;

    vector<int>child;

    for(auto v : adj[u]){
        if(!vis[v]){
            int ans = dfs(v);
            child.push_back(ans);
        }
    }
    sort(child.begin(),child.end());
    int cnt = 1,in = child.size() - k;
    for(int i=in;i<child.size();i++){
        cnt += child[i];
    }
    return cnt;
}
int main()
{
    int T,N=0,u,v;
    scanf("%d",&T);
    while(++N<=T){
        mem(adj,0);
        //
        scanf("%d %d",&n,&k);
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            adj[u].push_back(v); adj[v].push_back(u);
        }
        mem(vis,0);
        //cout<<endl;
        int ans = dfs(1);
        //cout<<dp[3]<<endl;
        printf("Case %d: %d\n",N,ans);
    }
    return 0;
}
