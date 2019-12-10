#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};

int row,col,fw[21][21],lim,nut;
int vis[21][21],dis[21][21],dp[(1<<17)+1000][21];
bool mark[21][21];

vector<pr>vec;

int call(int mask,int pos)
{
    if(mask == lim) return fw[pos][0];
    if(dp[mask][pos] != -1) return dp[mask][pos];

    int mn = 100000,p=0;
    for(int i=1;i<=nut;i++){
        if(!(mask & 1<<i)){
            mn =  min(mn,fw[pos][i]+call((mask | 1<<i),i));
        }
    }
    return dp[mask][pos] = mn;
}
int bfs(int sx,int sy,int desx,int desy)
{
    mem(vis,0);
    mem(dis,0);
    queue<pr>Q;
    Q.push(pr(sx,sy));
    vis[sx][sy]=1;
    while(!Q.empty()){
        pr u = Q.front();
        Q.pop();
        int a = u.first;
        int b = u.second;
        for(int i=0;i<8;i++){
            int x = a + d8x[i];
            int y = b + d8y[i];
            if(vis[x][y]==0 and x>=0 and x<=row and y>=0 and y<=col){
                vis[x][y]=1;
                dis[x][y] = dis[a][b] + 1;
                Q.push(pr(x,y));
                if(x==desx and y==desy) return dis[x][y];
            }
        }
     }
}
int main()
{
    while(~scanf("%d %d",&row ,&col)){
        mem(dp,-1);
        mem(mark,0);
        mem(fw,0);
        vec.clear();
        vec.push_back(pr(0,0));

        int a,b;
        string str;
        //cin.ignore();

        for(int i=0;i<row;i++){
            cin>>str;
            for(int j=0;j<str.size();j++){
                //scanf("%c",&ch[i][j]);
                if(str[j]=='L'){a=i;b=j;}
                else if(str[j]=='#') vec.push_back(pr(i,j));
            }
        }

        nut = vec.size();
        lim = (1<<nut)-1;

        vec[0].first=a;
        vec[0].second=b;
        //cout<<vec.size()<<endl;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec.size();j++){
                if(i==j or mark[i][j]) continue;
                fw[i][j] = bfs(vec[i].first,vec[i].second,vec[j].first,vec[j].second);
                fw[j][i] = fw[i][j];
                mark[j][i] = 1;
            }
        }

        int res = call(1,0);
        cout<<res<<endl;
    }
}
