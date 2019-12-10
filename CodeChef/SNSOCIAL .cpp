#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
#define ll long long int
#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 1007
#define int_map map<int,int>
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)
#define M 501

int ar[M][M],n,m,times[M][M];
bool vis[M][M];
queue<pr>Q;

int bfs_2d()
{
    int res = 0;
    while(!Q.empty()){
        pr top = Q.front();
        Q.pop();
        for(int i=0;i<8;i++){
            int x = top.first + d8x[i];
            int y = top.second + d8y[i];
            if(!vis[x][y] && x>=0 && x<n && y>=0 && y<m){
                vis[x][y] = 1;
                times[x][y] = times[top.first][top.second] + 1;
                if(times[x][y]>res) res = times[x][y];
                Q.push(pr(x,y));
            }
        }
    }
    return res;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        while(!Q.empty()) Q.pop();
        mem(vis,0);
        mem(times,0);

        scanf("%d%d",&n,&m);
        int val=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&ar[i][j]);
                if(ar[i][j]>val) val = ar[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ar[i][j]==val){
                    vis[i][j]=1;
                    Q.push(pr(i,j));
                }
            }
        }
        int res = bfs_2d();
        printf("%d\n",res);
    }
    return  0;
}
