#include<bits/stdc++.h>
using namespace std;

#define mx 30001
#define mem(a,b) memset(a,b,sizeof(a))
# define INF 0x3f3f3f3f

vector<int> edge[mx],cost[mx];
long long int dis[mx],rt;
queue<int>q;
int vis[mx];
int s,d,node;

int bfs(int sourse)
{
    mem(vis,0);
    mem(dis,0);
    vis[sourse]=1;
    dis[sourse]=0;
    q.push(sourse);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            int in = edge[u][i];
            if(vis[in]==0){
                dis[in] = dis[u]+cost[u][i];
                //cout<<in<<" "<<dis[in]<<endl;
                vis[in]=1;
                q.push(in);
            }
        }
    }
    //for(int i=0;i<node;i++) cout<<dis[i]<<" ";
    //cout<<endl;
    rt=0;
    int x=0;
    for(int i=0;i<node;i++){
        if(dis[i]>rt){x=i; rt = dis[i];}
    }
    return x;
}
int main()
{
    int N=0,T;
    scanf("%d",&T);
    while(++N<=T)
    {
        mem(edge,0);
        mem(cost,0);
        scanf("%d",&node);
        for(int i=1;i<node;i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            edge[x].push_back(y);
            edge[y].push_back(x);
            cost[x].push_back(c);
            cost[y].push_back(c);
        }
        int a = bfs(0);
        //cout<<a<<endl;
        int r = bfs(a);
        printf("Case %d: %lld\n",N,rt);

    }

return 0;
}
