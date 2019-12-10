#include<bits/stdc++.h>
using namespace std;

int s,n,dp[2001][2001],w[2001],p[2001];

int knap(int i, int wt){

    if(i>=n) return 0;

    if(dp[i][wt] != -1) return dp[i][wt];

    int p1=0,p2=0;

    if(w[i]+wt<=s)
        p1 = knap(i+1, wt+w[i]) + p[i];

    p2 = knap(i+1, wt);

    dp[i][wt] = max(p1,p2);

return dp[i][wt];
}

int main(){

    cin>>s>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
        scanf("%d %d",&w[i],&p[i]);

    cout<<knap(0,0)<<endl;
return 0;
}
