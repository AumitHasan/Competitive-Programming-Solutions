#include<bits/stdc++.h>
using namespace std;

#define mx 11
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define INF 0x3f3f3f3f

int di[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};

int vis[mx][mx],dis[mx][mx],row,col,cnt;

struct st{
    int a,c;
}chs[11][11];
vector<pr>v;

void bfs(int ii,int jj,int val)
{
    mem(vis,0);
    mem(dis,0);
    queue<pr>Q;

    vis[ii][jj] = 1;
    chs[ii][jj].a++;
    Q.push(pr(ii,jj));
    while(!Q.empty())
    {
        pr x = Q.front();
        Q.pop();
        for(int i=0;i<8;i++)
        {

            int xi = di[i]+x.first;
            int xy = dy[i]+x.second;
            if(vis[xi][xy]==0 and xi>=0 and xi<row and xy>=0 and xy<col and chs[xi][xy].a<cnt){
                vis[xi][xy] = 1;

                if(chs[xi][xy].a<cnt) chs[xi][xy].a++;
                dis[xi][xy] = dis[x.first][x.second]+1;
                int e = dis[xi][xy]/val;
                if(dis[xi][xy]%val!=0 ) e++;
                chs[xi][xy].c += e;
                Q.push(pr(xi,xy));
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
        cnt=row=col=0;
        vector<pr>v;

        for(int i=0;i<mx;i++){
            for(int j=0;j<mx;j++){
                chs[i][j].a=0;
                chs[i][j].c=0;
            }
        }
        scanf("%d%d",&row,&col);

        char str[row][col];
        for(int i=0;i<row;i++){
            scanf("%s",str[i]);
        }

        for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
                int vv = (int) str[i][j];
                if(vv>=49 and vv<=57){cnt++; v.push_back(pr(i,j));}
           }
        }

        for(int i=0;i<v.size();i++)
        {
            int ii = v[i].first;
            int jj = v[i].second;
            int val = (int) (str[ii][jj]-48);
            bfs(ii,jj,val);
        }
        int m = INF;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(chs[i][j].a==cnt) m = min(m,chs[i][j].c);
            }
        }

        if(cnt==1) m=0;

        if(m==INF) printf("Case %d: -1\n",N);
        else printf("Case %d: %d\n",N,m);
    }

return 0;
}
