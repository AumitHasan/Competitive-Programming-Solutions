#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))

int dp[101][10201],f[101],tk[101],budget,n;

int call(int i,int cost)
{
    if(cost > budget && budget < 1800)
        return -10000;
    if(cost > budget + 200)
        return -10000;
    if(i >= n) {
        if(cost > budget && cost <= 2000)
            return -10000;
        return 0;
    }
    if(dp[i][cost] != -1) return dp[i][cost];
    //if()
    int p1=0,p2=0;

    p1 = call(i+1,cost+tk[i]) + f[i];
    p2 = call(i+1,cost);

    return dp[i][cost] = max(p1,p2);
}
int main()
{
    while(~scanf("%d %d",&budget ,&n)){
        mem(dp,-1);
        for(int i=0;i<n;i++) scanf("%d %d",&tk[i] ,&f[i]);

        int res = call(0,0);

        printf("%d\n",res);
    }
    return 0;
}
