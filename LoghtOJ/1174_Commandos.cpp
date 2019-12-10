#include<bits/stdc++.h>
using namespace std;

void floyed_warshal(int n);
#define mem(a,b) memset(a,b,sizeof(a))
#define mx 103

vector<int>v[mx];

int fw[101][101],dis[103];
bool vis[103];

int bfs(int s,int e)
{
    mem(vis,false);
    mem(dis,0);
    queue<int>Q;

    vis[s]=true;
    Q.push(s);
    while(!Q.empty())
    {
        int c=0;
        int x = Q.front();
        Q.pop();
        for(int i=0;i<v[x].size();i++){
            int y = v[x][i];
            if(vis[y]==false){
                c++;
                vis[y] = true;
                dis[y] = dis[x]+1;
                Q.push(y);
                //if(y==e) break;
            }
        }
        if(c==0){
            int d = dis[x]+fw[x][e];
            //cout<<"mx: "<<d<<" "<<x<<endl;
            if(d>dis[101] and d>-1) dis[101] = d;
        }
    }
    int res = *max_element(dis,dis+103);

return res;
}
void floyed_warshal(int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) fw[i][j]=0;
                else if(fw[i][k]+fw[k][j]<fw[i][j]) fw[i][j] = fw[i][k]+fw[k][j];
            }
        }
    }
    //cout<<"des: "<<fw[2][3]<<endl;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T)
    {
        for(int i=0;i<mx;i++)
            for(int j=0;j<mx;j++){
                if(i==j) fw[i][j]=0;
                else fw[i][j]=1000;
        }

        mem(v,0);

        int n,p,a,b;
        scanf("%d%d",&n,&p);
        while(p--){
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
            fw[a][b] = 1;
            fw[b][a] = 1;
        }
        int s,d;
        scanf("%d%d",&s,&d);

        floyed_warshal(n);
        int res = bfs(s,d);

        printf("Case %d: %d\n",N,res);
    }
}
