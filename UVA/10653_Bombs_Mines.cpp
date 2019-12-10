#include<bits/stdc++.h>
using namespace std;

#define set(a) memset(a,0,sizeof a)
#define pii pair<int,int>

int fx[]={0,0,-1,1};
int fy[]={-1,1,0,0};

int cell[1001][1001];
int row,col,R,C;
int vis[1001][1001],grid[1001][1001];

int bfs(int i,int j)
{
    if(i==R&&j==C) return 0;

    memset(vis,0,sizeof vis);
    memset(grid,0,sizeof grid);
    queue<pii>q;

    vis[i][j]=1;
    q.push(pii(i,j));
    while(!q.empty())
    {
        pii top = q.front();
        q.pop();
        for(int k=0;k<4;k++)
        {

            int tx = top.first+fx[k];
            int ty = top.second+fy[k];

            if(cell[tx][ty]==-1 && vis[tx][ty]==0 && tx>=0 && tx<row && ty>=0 && ty<col)
            {
                vis[tx][ty]=1;
                grid[tx][ty] = grid[top.first][top.second]+1;
                if(R==tx&&C==ty) return grid[tx][ty];

                q.push(pii(tx,ty));
            }
        }
    }
}

int main()
{
    while(1)
    {
        scanf("%d%d",&row,&col);
        if(row==0&&col==0) break;

        memset(cell,-1,sizeof cell);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int r,n;
            scanf("%d%d",&r,&n);
            while(n--){
                int x;
                scanf("%d",&x);
                cell[r][x]=0;
            }
        }

        int a,b;
        scanf("%d%d",&a,&b);
        scanf("%d%d",&R,&C);

        int res = bfs(a,b);
        printf("%d\n",res);
    }

return 0;
}
