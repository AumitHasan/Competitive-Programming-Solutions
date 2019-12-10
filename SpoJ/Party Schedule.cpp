#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))

int budget,party,fun[101],tk[101],taka,cnt,f;
int dp[101][501],dx[101][1001],inf=100000000;

int call(int idx,int taka)
{
    if(idx >= party) return 0;
    if(taka>budget) return 0;
    if(dp[idx][taka] != -1) return dp[idx][taka];

    int total = 0,dis=0;
    if(taka + tk[idx] <= budget) total = call(idx+1,taka+tk[idx] ) + fun[idx];
    else total = 0;

    dis = call(idx+1,taka );

    return dp[idx][taka] = max(total,dis);
}
int cost(int idx,int fn)
{
    if(idx>=party ){
        if(fn>=cnt) return 0;
        return inf;
    }
    if(dx[idx][fn] != -1) return dx[idx][fn];

    int p1=0,p2=0;

    p1 = cost(idx+1,fn+fun[idx]) + tk[idx];
    p2 = cost(idx+1,fn);

    dx[idx][fn] = min(p1,p2);

    return dx[idx][fn];
}
int main()
{

    while(scanf("%d %d",&budget ,&party)){

        if(budget == 0 and party == 0) break;

        for(int i=0;i<party;i++) scanf("%d %d",&tk[i] ,&fun[i]);

        mem(dp,-1);
        f = call(0,0);

        mem(dx,-1);
        cnt = f;
        int x = cost(0,0);

        printf("%d %d\n",x,f);

    }
    return 0;
}
