#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define mx 507

vector<int>edg[mx];
int vis[mx],color[mx],cl;
queue<int>q;

void bfs(int src)
{
    mem(vis,0);
    mem(color,0);
    while(!q.empty()) q.pop();

    vis[src]=1;
    color[src]=1;
    q.push(src);
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i=0;i<edg[f].size();i++){
            int in = edg[f][i];
            int bi = color[f]%4;
            if(vis[in]==0){
                color[in] = color[f]+1;
                vis[in] = 1;
                q.push(in);
            }
            else{
                int b = color[in]%4;
                if(bi==b){
                    printf("NOT BICOLORABLE.\n");
                    return;
                }
            }
        }
    }
    printf("BICOLORABLE.\n");
}
int main()
{
    int T;
    while(1)
    {
        int n,e,s=0;
        scanf("%d",&n);
        if(n==0) break;
        scanf("%d",&e);

        mem(edg,0);
        for(int i=0;i<e;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(i==0) s=a;
            edg[a].push_back(b);
            edg[b].push_back(a);
        }
        bfs(s);
    }

return 0;
}
