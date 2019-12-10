#include<bits/stdc++.h>
using namespace std;
#define mx 70
#define mem(a,b) memset(a,b,sizeof(a))

int vis[mx],tt[mx],root[mx];
queue<int>q;
vector<int>edg[mx];


void bfs(int s)
{
    while(!q.empty()){
        q.pop();
    }
    mem(vis,0);
    mem(tt,0);
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i=0;i<edg[f].size();i++){
            int in = edg[f][i];
            if(vis[in]==0){
                tt[in] = tt[f]+1;
                vis[in]=1;
                q.push(in);
            }
        }
    }
}
int main()
{
    int nc,cs=0;
    while(1)
    {
        scanf("%d",&nc);
        if(nc==0) break;

        mem(root,-1);
        mem(edg,0);
        edg[0].push_back(0);

        int a,b,i=0;
        while(nc--){
            scanf("%d%d",&a,&b);
            int x=0,y=0;
            for(int j=1;j<=i;j++){
                if(root[j]==a) x=j;
                if(root[j]==b) y=j;
            }
            if(a==b){
                if(x==0 and y==0) root[++i]=a;
            }
            else if(x==0 and y==0){
                root[++i]=a;
                int si=i;
                root[++i]=b;
                int sj=i;
                edg[si].push_back(sj);
                edg[sj].push_back(si);
            }
            else if(x>0 and y>0 and x!=y){
                edg[x].push_back(y);
                edg[y].push_back(x);
            }
            else if(x==0){
                root[++i]=a;
                edg[i].push_back(y);
                edg[y].push_back(i);
            }
            else if(y==0){
                root[++i]=b;
                edg[i].push_back(x);
                edg[x].push_back(i);
            }
        }
        int node=i;

        int s,t;
        while(1){
            scanf("%d%d",&s,&t);
            if(s==0 and t==0) break;

            int ss=0;
            for(int i=1;i<mx;i++){
                if(root[i]==s){ss=i;break;}
            }

            if(ss==0){
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cs,node,s,t);
                continue;
            }

            bfs(ss);
            int c=1;
            for(int i=1;i<=node;i++)
                if(tt[i]>0 and tt[i]<=t) c++;

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cs,node-c,s,t);
        }
    }

return 0;
}
