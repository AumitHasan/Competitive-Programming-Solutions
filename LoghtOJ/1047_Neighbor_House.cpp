#include<bits/stdc++.h>
using namespace std;

 #define mem(a) memset(a,-1,sizeof(a))

 int g[21][3],dp[21][3],n;

 int house(int i,int j)
 {
    if(i==n) return 0;
    if(j<0 || j>2) return 100000;
    if(dp[i][j] != -1) return dp[i][j];

    //int t=INFINITY,tt=INFINITY,ttt=INFINITY,tttt=INFINITY;
    int t,tt,ttt,tttt;

    t = house(i+1,j-2)+g[i][j];
    tt = house(i+1,j-1)+g[i][j];
    ttt = house(i+1,j+1)+g[i][j];
    tttt = house(i+1,j+2)+g[i][j];

    dp[i][j] = min(min(t,tt),min(ttt,tttt));
    //dp[i][j] = max(max(t,tt),max(ttt,tttt));

return dp[i][j];
 }

 int main()
 {
    int T,N=0;
    cin>>T;
    while(++N<=T)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<3;j++) scanf("%d",&g[i][j]);

        mem(dp);
        int a=house(0,0);
        mem(dp);
        int b=house(0,1);
        mem(dp);
        int c=house(0,2);

        int res = min(min(a,b),c);
        printf("Case %d: %d\n",N,res);
    }
 }
