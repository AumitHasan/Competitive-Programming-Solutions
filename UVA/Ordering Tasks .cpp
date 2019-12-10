#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 107
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

int n,m,d[mx],f[mx],vis[mx],somoi;
vector<int>edge[mx];
stack<int>order;

void dfs(int u)
{
    vis[u] = 1;
    for(int i=0;i<edge[u].size();i++){
        if(vis[edge[u][i]] == 0){
            dfs(edge[u][i]);
        }
    }
    order.push(u);
    //cout<<u<<" ";
    return ;
}
void topsort()
{
    mem(vis,0);
    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }
    // way 1
    cout<<order.top();
    order.pop();
    while(!order.empty()){
        printf(" %d",order.top());
        order.pop();
    }
    printf("\n");
}
int main()
{
    int u,v;
    while(1){
        mem(edge,0);
        cin>>n>>m;
        if(!n && !m) break;

        while(m--){
            scanf("%d %d", &u, &v);
            edge[u].push_back(v);
        }
        //
        topsort();
    }
    //
    return 0;
}

