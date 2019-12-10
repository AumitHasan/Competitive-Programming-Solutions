#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int cycle,vis[100];
vector<int>adj[100];


void dfs(int u)
{
    if(vis[u]==2 || cycle) return;

    if(vis[u]==1){
        cycle = 1;
        return;
    }

    vis[u] = 1;

    for(int i=0;i<adj[u].size();i++){
        dfs(adj[u][i]);
    }

    vis[u] = 2;
}
int main()
{
    int n,u,v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        dfs(i);
    }
    if(cycle) cout<<"has cycle"<<endl;
    else cout<<"no cycle"<<endl;
}
