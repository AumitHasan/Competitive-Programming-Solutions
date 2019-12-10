#include<bits/stdc++.h>
using namespace std;

long long wt,s,n,dp[70000];

long long f(long long i, long long wt, long long *w){

    if(i>=n) return 0;

    if(dp[i] != -1) return dp[i];

    if(wt+w[i]<=s){
        long long p1 = wt+w[i]+f(i+2,wt,w);
        long long p2 = wt+f(i+2,wt,w);
        dp[i] = max(p1,p2);
    }

return dp[i];
}

int main(){

    int N=0,T;
    cin>>T;
    while(++N <=T)
    {

        long long i;
        cin>>n>>s;
        long long w[n+1];
        for(i=0;i<n;i++)
            scanf("%lld",&w[i]);

        memset(dp,-1,sizeof(dp));
         printf("Scenario #%d: ",N);
        cout<<f(0,0,w)<<endl;

    }
}
