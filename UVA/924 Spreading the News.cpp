#include<bits/stdc++.h>
using namespace std;
#define mx 25003
#define mem(a,b) memset(a,b,sizeof(a))

vector<int>edge[mx];
int vis[mx],dis[mx],cnt[mx],fnd;

void bfs(int src)
{
    fnd=0;
    queue<int>q;
    mem(vis,0);
    mem(dis,0);
    mem(cnt,0);
    vis[src]=1;
    q.push(src);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<edge[x].size();i++){
            int y = edge[x][i];
            if(vis[y]==0){
                q.push(y);
                vis[y]=1;
                dis[y] = dis[x]+1;
                cnt[dis[y]]++;
                if(cnt[dis[y]]>fnd) fnd = cnt[dis[y]];
            }
        }
    }
}
int main()
{
    int e,a,n,s,t,M,D;
    while(~scanf("%d",&e)){
        for(int i=0;i<e;i++){
            scanf("%d",&a);
            while(a--){
                scanf("%d",&n);
                edge[i].push_back(n);
            }
        }
        scanf("%d",&t);
        for(int j=0;j<t;j++){
            scanf("%d",&s);
            if(edge[s].size()>0){
                bfs(s);
                for(int i=0;i<mx;i++){
                    if(cnt[i]==fnd){
                        M = fnd;
                        D = i;
                        break;
                    }
                }
                printf("%d %d\n",M,D);
            }
            else printf("0\n");
        }
    }
    return 0;
}
