#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define mx 21

vector<int>edg[mx];
int vis[mx],dis[mx];
queue<int>q;

void bfs(int src,int des)
{
    mem(vis,0);
    mem(dis,0);
    while(!q.empty()) q.pop();

    vis[src]=1;
    q.push(src);
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i=0;i<edg[f].size();i++){
            int in = edg[f][i];
            if(vis[in]==0){
                dis[in] = dis[f]+1;
                vis[in] = 1;
                q.push(in);
            }
        }
    }
    printf("%2d to %2d: %d\n",src,des,dis[des]);

}
int main()
{
    //freopen("in.text","r",stdin);
    //freopen("out.text","w",stdout);

    int x,T=0;
    while(~scanf("%d",&x))
    {
        mem(edg,0);

        int node=1,y;
        for(int i=0;i<x;i++){
            scanf("%d",&y);
            edg[node].push_back(y);
            edg[y].push_back(node);
        }
        for(int i=0;i<18;i++)
        {
            ++node;
            scanf("%d",&x);
            while(x--){
                scanf("%d",&y);
                edg[node].push_back(y);
                edg[y].push_back(node);
            }
        }
        int t;
        scanf("%d",&t);
        printf("Test Set #%d\n",++T);
        for(int i=0;i<t;i++){
            int src,des;
            scanf("%d%d",&src,&des);
            bfs(src,des);
        }
        cout<<endl;
    }

return 0;
}
