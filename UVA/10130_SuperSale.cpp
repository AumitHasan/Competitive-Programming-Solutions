#include<bits/stdc++.h>
using namespace std;

int dp[1001][31],p[1001],wt[1001],cap,n;

int sale(int i,int w)
{
    if(i>=n) return 0;
    if(dp[i][w] != -1) return dp[i][w];

    int p1=0,p2=0;
    if(w+wt[i]<=cap) p1 = sale(i+1,w+wt[i])+p[i];
    p2 = sale(i+1,w);

    dp[i][w] = max(p1,p2);

return dp[i][w];
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d%d",&p[i],&wt[i]);

        int g,sum=0;
        scanf("%d",&g);
        while(g--){

            memset(dp,-1,sizeof(dp));
            scanf("%d",&cap);
            sum += sale(0,0);
        }
        printf("%d\n",sum);
    }
}
