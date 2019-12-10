#include<bits/stdc++.h>
using namespace std;

int dp[101][1001];
int n,cap,wt[101],cost[101];

int knpsk(int i,int w)
{
   if(i>n) return 0;
   if(dp[i][w] != -1) return dp[i][w];

   int profit1=0,profit2=0;

   if(w+wt[i]<=cap) profit1 = knpsk(i+1,w+wt[i])+cost[i];
   profit2 = knpsk(i+1,w);

   dp[i][w]=max(profit1,profit2);
return dp[i][w];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>cap>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>wt[i]>>cost[i];
    }

    cout<<knpsk(1,0);

return 0;
}
