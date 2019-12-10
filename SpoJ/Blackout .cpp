#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1000000

int grid[2001][2001],val[2002][2002],row,col,r,c,n,K,Q,area,N,M,p,in;

map<int, map<int,int> >mp;
struct st{
    int people,area;
}res[1001];

int knapsack(int i,int man)
{
    if(i>in) return 0;
    if(mp[i][man] != 0) return mp[i][man];
    int p1=0,p2=0;

    if(man+res[i].people<=K) p1 = knapsack(i+1,man+res[i].people)+res[i].area;
    p2 = knapsack(i+1,man);

    return mp[i][man] = max(p1,p2);
}
void cal()
{
    for(int i=1;i<=N;i++){
        val[i][1] = grid[i][1];
        for(int j=2;j<=M;j++) val[i][j] = grid[i][j] + val[i][j-1];
    }

}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int i,j;
    in = -1;

    scanf("%d %d %d %d",&N ,&M ,&Q ,&K);
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++) scanf("%d",&grid[i][j]);
    }
    cal();
    //cin>>row>>col>>r>>c>>K;
    while(Q--){
        scanf("%d %d %d %d",&row ,&col ,&r ,&c);
        int cc=0;
        for(i=row;i<=r;i++){
            cc += val[i][c] - val[i][col-1];
        }
        if(cc<=K){
            res[++in].people = cc;
            res[in].area = (r-row+1)*(c-col+1);
            //cout<<cc<<" "<<(r-row+1)*(c-col+1)<<endl;
        }
    }
    cout<<endl;
    int r = knapsack(0,0);
    cout<<r<<endl;
}
