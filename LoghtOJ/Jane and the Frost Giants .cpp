#include<bits/stdc++.h>
using namespace std;

int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
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
#define obs 10000000

int me[205][205],fire[205][205],row,col,c;
bool vis[205][205];
vector<pr>v;

void bfs_fire(int xx,int yy)
{
    fire[xx][yy] = 0;
    queue<pr>Q;
    vis[xx][yy] = 1;
    Q.push(pr(xx,yy));
    while(!Q.empty()){
        pr frnt = Q.front();
        Q.pop();
        int a = frnt.first;
        int b = frnt.second;
        for(int i=0;i<4;i++){
            int x = a+dx[i];
            int y = b+dy[i];
            if(((c==0 && vis[x][y]==0) || fire[a][b]+1<fire[x][y]) && x>=0 && x<row && y>=0 && y<col && fire[x][y]!=obs){
                fire[x][y] = fire[a][b]+1;
                vis[x][y] = 1;
                Q.push(pr(x,y));
                //cout<<"a";
            }
        }
    }
}
int bfs_me(int xx,int yy)
{
    queue<pr>Q;
    vis[xx][yy] = 1;
    Q.push(pr(xx,yy));
    while(!Q.empty()){
        pr frnt = Q.front();
        Q.pop();
        int a = frnt.first;
        int b = frnt.second;
        for(int i=0;i<4;i++){
            int x = a+dx[i];
            int y = b+dy[i];
            if(vis[x][y]==0 && x>=0 && x<row && y>=0 && y<col && fire[x][y]!=obs){
                me[x][y] = me[a][b]+1;
                vis[x][y] = 1;
                Q.push(pr(x,y));
            }
            else if(x<0 || x>=row || y<0 || y>=col){
                if(me[a][b]<fire[a][b] && me[a][b]!=obs){
                    //cout<<a<< " "<<b<<" "<<me[a][b]<<" "<<fire[a][b]<<endl;
                    //v.push_back(me[a][b]+1);
                    return me[a][b]+1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    char ch;
    int jx,jy,fx,fy,T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        mem(vis,0);
        mem(fire,0);
        mem(me,0);
        v.clear();
        scanf("%d %d",&row ,&col);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                //scanf("%c",&ch);
                cin>>ch;
                if(ch=='J'){
                    jx = i;
                    jy = j;
                }
                else if(ch=='F'){
                    v.push_back(pr(i,j));
                }
                else if(ch=='#'){
                    fire[i][j] = obs;
                    me[i][j] = obs;
                }
            }
        }
        c = 0;
        for(int i=0;i<v.size();i++){
            bfs_fire(v[i].first,v[i].second);
            c++;
        }
        mem(vis,0);
        int res = bfs_me(jx,jy);

        if(res==0) printf("Case %d: IMPOSSIBLE\n",N);
        else printf("Case %d: %d\n",N,res);
    }
    return 0;
}
