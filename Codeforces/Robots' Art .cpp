#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 5003
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int px,py,ans,r1,r2,n,k,in=-1;
int A[mx];
short pre_A[mx][mx],pre_B[mx][mx];

struct info{
    short a,b,cnt,val;
}parent[mx][mx];

struct st{
    short x,y;
};
st node,nw;

void bfs()
{
    queue<st>Q;
    Q.push(node);
    while(!Q.empty()){
        //c++;
        nw = Q.front();
        Q.pop();

        if(nw.x>r1 && nw.y>r2){
            ans = parent[nw.x][nw.y].cnt;
            px = nw.x;
            py = nw.y;
            //cout<<"C: "<<c<<endl;
            return;
        }
        //
        for(int i=1;i<=k;i++){
            px = (pre_A[nw.x][i] == 0) ? r1+1 :  pre_A[nw.x][i];
            py = (pre_B[nw.y][i] == 0) ? r2+1 : pre_B[nw.y][i];

            if(parent[px][py].cnt>0 && (parent[nw.x][nw.y].cnt+1 >= parent[px][py].cnt))
                continue;

            parent[px][py].cnt = parent[nw.x][nw.y].cnt + 1;
            parent[px][py].val = i;
            //cout<<px<<" "<<py<<" c: "<<parent[px][py].cnt<<endl;
            parent[px][py].a = nw.x;
            parent[px][py].b = nw.y;
            //cout<<px<<" "<<py<<" "<<nw.x<<" "<<nw.y<<endl;
            node.x = px;
            node.y = py;
            if(node.x>r1 && node.y>r2){
                ans = parent[node.x][node.y].cnt;
                return;
            }
            Q.push(node);
        }
    }
}
void prnt(short x,short y)
{
    //cout<<x<<" "<<y<<endl;
    if(x==0 && y==0) return ;
    prnt(parent[x][y].a,parent[x][y].b);
    //cout<<parent[x][y].val<<" "<<x<<" "<<y<<endl;
    A[++in] = parent[x][y].val;

}
int main()
{
    READ("robots.in");
    WRITE("robots.out");

    scanf("%d",&k);

    scanf("%d",&r1);
    for(int i=1;i<=r1;i++) scanf("%d",&A[i]);

    for(int i=0;i<=r1;i++){
        for(int j=r1;j>i;j--){
            pre_A[i][A[j]] = j;
        }
    }
    //
    scanf("%d",&r2);
    for(int i=1;i<=r2;i++) scanf("%d",&A[i]);

    for(int i=0;i<=r2;i++){
        for(int j=r2;j>i;j--){
            pre_B[i][A[j]] = j;

        }
    }

    bfs();
    prnt(px,py);

    printf("%d\n",ans);

    for(int i=0;i<=in;i++){
        if(i==in) printf("%d\n",A[i]);
        else printf("%d ",A[i]);
    }
    return 0;
}
