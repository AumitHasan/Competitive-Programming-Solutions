#include<bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))

int vis[21][21];
char cell[21][21];
queue< pair<int,int> >q;
pair<int,int>top;

int src_i,src_j,des_i,des_j,row,col;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};

int bfs_2d(int si,int sj)
{
    //cout<<"ff "<<row<<col<<endl;
    int c=1;
    mem(vis,0);

    vis[si][sj]=1;
    q.push(make_pair(si,sj));
    while(!q.empty())
    {
        top = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x = top.first+dx[i];
            int y = top.second+dy[i];

            if(x>=0 and x<row and y>=0 and y<col and vis[x][y]==0 and cell[x][y]!='#'){
                c++;
                q.push(make_pair(x,y));
                vis[x][y]=1;
                //if(x==des_i-1&&y==des_j-1) return cell[x][y];
            }
            else if(cell[x][y]=='#') vis[x][y]=1;
        }
    }
    //cout<<cell[des_i][des_j]<<endl;
    return c;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T)
    {
        scanf("%d %d",&col,&row);

        int r,c;
        for(int i=0;i<row;i++)
        {
            scanf("%s",&cell[i]);
            for(int j=0;j<col;j++){
                if(cell[i][j]=='@'){r=i; c=j;}
            }
        }

        int cc = bfs_2d(r,c);
        printf("Case %d: %d\n",N,cc);
    }

return 0;
}
