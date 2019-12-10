#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
#define mx 10001
#define pr pair<int,int>

struct st{
    int operator()(const pair<int,int>&a , const pair<int,int>&b){
        return a.second > b.second;
    }
}z;
int d[mx],parent[mx];
bool vis[mx];
vector<pr>edg[mx];

void prims()
{
    priority_queue<pr,vector<pr>,st>q;

    for(int i=0;i<mx;i++) d[i] = INF;
    parent[1]=1;
    d[1]=0;
    q.push(pr(1,0));
    while(!q.empty())
    {
        int u = q.top().first;
        vis[u]=true;
        q.pop();
        for(int i=0;i<edg[u].size();i++)
        {
            int v = edg[u][i].first;
            int cost = edg[u][i].second;
            if(d[v]>cost && vis[v]==false){
                d[v] = cost;
                q.push(pr(v,d[v]));
                parent[v]=u;
            }
        }
    }
    cout<<endl;
    for (int i = 1; i < 6; ++i)
        printf("%d - %d\n", parent[i], i);
}
int main()
{
    int E;
    scanf("%d",&E);
    for(int i=0;i<E;i++)
    {
        int u,v,cost;
        scanf("%d%d%d",&u,&v,&cost);
        edg[u].push_back(pr(v,cost));
        edg[v].push_back(pr(u,cost));
    }
    prims();

return 0;
}
