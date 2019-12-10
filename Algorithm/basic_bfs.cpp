#include<bits/stdc++.h>
using namespace std;

#define mx 100000
#define mem(a,b) memset(a,b,sizeof(a))

vector<int> edge[mx],cost[mx];
int parent[mx];
queue<int>q;
int dis[mx],vis[mx];
int s,d;

void bfs(int sourse,int des)
{
    mem(vis,0);
    vis[sourse]=1;
    q.push(sourse);
    parent[0]=0;
    while(!q.empty())
    {
        int u = q.front();
        int c=0;
        q.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            int in = edge[u][i];
            if(vis[in]==0){
                parent[in]=u; // track parent
                dis[in] = dis[u]+1;
                vis[in]=1;
                q.push(in);
                if(in==d){c=1; break;}
            }
        }
        if(c==1) break;
    }
    //for(int i=0;i<=10;i++) cout<<parent[i]<<" ";
    //cout<<dis[des]<<endl;
}
void prnt(int i) //TRACK PATH & PARENT
{
    if(parent[i]==i) return;
    //int x =parent[i];
    prnt(parent[i]);
    cout<<parent[i]<<" ";
}
int main()
{
    freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);

    int N,E;
    scanf("%d%d",&N,&E);
    for(int i=0;i<E;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
        //cost[x].push_back(y);
        //cost[y].push_back(x);
    }


    //printf("Source & Destination: ");
    scanf("%d%d",&s,&d);

    bfs(s,d);
    prnt(d);

return 0;
}
