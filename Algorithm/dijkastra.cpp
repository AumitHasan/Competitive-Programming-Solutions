#include<bits/stdc++.h>
using namespace std;
#define pr pair<int,int>
#define mx 100001
#define mem(a,b) memset(a,b,sizeof(a))
int d[mx];
vector<pr>edge[mx];
struct rc{
    int operator()(const pair<int,int>&a1,const pair<int,int>&a2){
        return a1.second>a2.second;
    }
}z;

void dijkstra(int s,int des)
{
    priority_queue<pr,vector<pr>,rc>q;


    d[s]=0;
    q.push(pr(s,0));
    while(!q.empty())
    {
        int x = q.top().first;
        q.pop();
        for(int i=0;i<edge[x].size();i++)
        {
            int u = edge[x][i].first;
            int cost = edge[x][i].second;
            //cout<<u<<" "<<cost<<endl;
            if(d[x]+cost<d[u] or d[u]==0){
                d[u] = d[x]+cost;
                q.push(pr(u,d[u]));
            }
        }
    }
    cout<<endl;
    cout<< d[des];
}
int main()
{
    int N,E;

    scanf("%d",&E);
    mem(edge,0);
    for(int i=0;i<E;i++){
        int u,v,cost;
        scanf("%d%d%d",&u,&v,&cost);
        edge[u].push_back(pr(v,cost));
        edge[v].push_back(pr(u,cost));
    }
    int s,des;
    scanf("%d%d",&s,&des);
    dijkstra(s,des);

return 0;
}
