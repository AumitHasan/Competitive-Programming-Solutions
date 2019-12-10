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


int dfs(int i)
{
    vis[i] = 1;
    if(i==1 && adj[i].size()<k) return 1;
    else if(i!=1 && adj[i].size()-1 <k){
        //dp[i] = 1;
        return 1;
    }
    //if(dp[i] != -1) return dp[i];

    //int ans = 0;
    vector<int>st;

    for(auto u : adj[i]){
        if(!vis[u]){
            int ans = dfs(u);
            st.push_back(ans);
        }
    }
    sort(st.begin(),st.end());
    int cnt = 1,in = st.size() - k;
    for(int i=in;i<st.size();i++){
        cnt += st[i];
    }
    return  cnt;
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
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //cout<<endl;
        mem(vis,0);
        int ans = dfs(1);
        //cout<<dp[3]<<endl;
        printf("Case %d: %d\n",N,ans);
    }
    return 0;
}
