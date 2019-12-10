#include<bits/stdc++.h>
using namespace std;

#define pr pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))

int di[]={0,-1,0,1};
int dj[]={-1,0,1,0};
int vis[21][21],dis[21][21],row,col;
char grid[21][21];


void bfs(int hx,int hy)
{
    queue<pr>Q;
    mem(vis,0);
    mem(dis,0);

    Q.push(pr(hx,hy));
    vis[hx][hy] = 1;
    while(!Q.empty())
    {
        pr x = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
           int a = x.first+di[i];
           int b = x.second+dj[i];
           if(vis[a][b]==0 and grid[a][b]!='m' and grid[a][b]!='#' and (a>=0 and a<row) and (b>=0 and b<col))
           {
                dis[a][b] = dis[x.first][x.second]+1;
                vis[a][b] = 1;
                Q.push(pr(a,b));
           }
        }
    }
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T)
    {
        int x,y;
        pr a,b,c;
        scanf("%d%d",&row,&col);
        for(int i=0;i<row;i++)
        {
            scanf("%s",grid[i]);
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++){

                if(grid[i][j]=='h'){x=i; y=j;}
                else if(grid[i][j]=='a'){a.first=i; a.second=j;}
                else if(grid[i][j]=='b'){b.first=i; b.second=j;}
                else if(grid[i][j]=='c'){c.first=i; c.second=j;}
            }
        }

        bfs(x,y);

        int res = max(dis[a.first][a.second],max(dis[b.first][b.second],dis[c.first][c.second]));
        printf("Case %d: %d\n",N,res);

    }
}
