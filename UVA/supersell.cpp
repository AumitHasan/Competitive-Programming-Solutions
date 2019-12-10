#include<bits/stdc++.h>
using namespace std;

int dp[1001][102],w[1001],p[1001],s,n;

int knap(int i, int wt){

    int p1,p2;
    if(i>=n) return 0;

    if(dp[i][wt] != -1) return dp[i][wt];

    if(wt+w[i]<=s)
        p1 = knap(i+1, wt+w[i])+p[i];
    else p1 =0;

        p2 = knap(i+1, wt);


     dp[i][wt] = max(p1,p2);


return dp[i][wt];
}

int main(){


    int i,j;
    cin>>j;
    while(j--){

        cin>>n;
        for(i=0;i<n;i++)
            scanf("%d %d",&p[i],&w[i]);

        int x,ans=0;
        cin>>x;
        for(i=0;i<x;i++)
        {
           cin>>s;
           memset(dp,-1,sizeof(dp));
            ans+=knap(0,0);
        }
        cout<<ans<<endl;
    }
return 0;
}
