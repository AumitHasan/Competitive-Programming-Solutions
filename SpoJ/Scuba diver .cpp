#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 100000000

int dp[1001][32][90],ox[2001],ni[2001],wt[2001];
int vol_ni,vol_ox,n;

int call(int i,int taken_ox,int taken_ni)
{
    if(i>=n){
        if(taken_ox>=vol_ox and taken_ni>=vol_ni) return 0;
        else return inf;
    }
    if(dp[i][taken_ox][taken_ni] != -1) return dp[i][taken_ox][taken_ni];


    int p1=0,p2=0;

    p1 = call(i+1,min(21,taken_ox + ox[i]), min(79,taken_ni + ni[i]) ) + wt[i];

    p2 = call(i+1,min(21,taken_ox),min(79,taken_ni));

    return dp[i][min(21,taken_ox)][min(79,taken_ni)] = min(p1,p2);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        mem(dp,-1);

        scanf("%d %d",&vol_ox ,&vol_ni);
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d %d %d",&ox[i] ,&ni[i] ,&wt[i]);

        int res = call(0,0,0);

        printf("%d\n",res);


    }
    return 0;
}
