#include<bits/stdc++.h>
using namespace std;

int dp[2001][2001],w[2001],p[2001],s,n;

int knap(int i, int wt){


    if(i>=n) return 0;

    if(dp[i][wt] != -1) return dp[i][wt];

    int p1=0,p2=0;

    if(wt+w[i]<=s)
        p1 = knap(i+1, wt+w[i])+p[i];
    else p1=0;

        p2 = knap(i+1, wt);


     dp[i][wt] = max(p1,p2);

return dp[i][wt];
}

int main(){

    memset(dp,-1,sizeof(dp));
    int i,j;
    cin>>s>>n;
    for(i=0;i<n;i++)
        scanf("%d %d",&w[i],&p[i]);

    cout<<knap(0,0)<<endl;

}
