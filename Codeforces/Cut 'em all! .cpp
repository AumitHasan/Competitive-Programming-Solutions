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

#define mx 100007
#define mod 1000000009
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....

////

int n,dp[mx];
vector<int>adj[mx];


int dfs(int u,int last)
{
    if(adj[u].size()==0) return 0;
    int tmp = 1;
    for(auto v : adj[u]){
        if(v==last) continue;
        tmp += dfs(v,u);
    }
    return dp[u] = tmp;
}
int main()
{
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n==2){
        cout<<0<<endl;
        return 0;
    }
    if(n%2==1){
        cout<<-1<<endl;
        return 0;
    }
    //
    int st;
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1){
            st = i; break;
        }
    }
    //cout<<st<<endl;
    int ans = 0;
    int tmp = dfs(st,st);
    for(int i=1;i<=n;i++){
        if(dp[i]>0 && dp[i]%2==0) ans++;
        //cout<<i<<" "<<dp[i]<<endl;
    }
    cout<<ans-1<<endl;
}
