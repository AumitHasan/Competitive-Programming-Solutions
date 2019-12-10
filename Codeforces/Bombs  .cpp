#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 100007

string dir = "LRUD";
vector<pr>res;
int b,step,ar[mx][3],sx,sy,fx,fy;

umap<int,umap<int,int> > mp;
umap<int,umap<int,pr> > par;

struct info{
    int x,y,mv;
}cal,tmp,tx;

void bfs()
{
    int c=0;
    queue<info>Q;
    Q.push(cal);
    while(!Q.empty()){
        tmp = Q.front(); Q.pop();
        for(int i=0;i<4;i++){
            int x = tmp.x + dx[i];
            int y = tmp.y + dy[i];
            if(mp[x][y]){
                c++;
                step += (tmp.mv+1) * 2;
                res.push_back(pr(x,y));
            }
            tx.x = x; tx.y = y; tx.mv = tmp.mv + 1;
            Q.push(tx);
        }
        if(c==b) return;
    }
}
void go()
{
    queue<pr>Q;
    Q.push(pr(sx,sy));
    while(!Q.empty()){
        pr tmp = Q.front(); Q.pop();
        for(int i=0;i<4;i++){
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            if(par[x][y] != pr(0,0)){
                par[x][y] = pr(x,y);
                if(x==fx && y==fy){

                }
            }
        }

    }
}
int main()
{
    int x,y;
    scanf("%d",&b);
    for(int i=0;i<b;i++){
        scanf("%d %d",&x,&y);
        ar[i][0] = x; ar[i][1] = y;
        mp[x][y] = 1;
    }
    step = b*2;
    bfs();
    printf("%d\n",step);
    //
    for(int i=0;i<res.size();i++){
        sx = sy = 0;
        fx = res[i].first; fy = res[i].second;
        go();
        printf("2\n");
        fx = fy = 0;
        sx = res[i].first; sy = res[i].second;
        printf("3\n");
    }
    return 0;
}
