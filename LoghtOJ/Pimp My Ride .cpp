#include<bits/stdc++.h>
using namespace std;
#define lim (1<<15)+5

int dp[15][lim],chrge[15][15],n;

int call(int job,int mask)
{
    if(mask == (1<<n)-1 ) return 0;
    if(dp[job][mask] != -1) return dp[job][mask];

    int p=10e7;

    for(int i=0;i<n;i++){
        if(!(mask & (1<<i))){
            int val=0;
            for(int j=0;j<n;j++){
                if(i==j) val += chrge[i][j];
                else if((mask & (1<<j))) val += chrge[i][j];
            }
            p = min(p,call(job+1,mask|(1<<i))+val);
        }
    }
    return dp[job][mask] = p;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        memset(dp,-1,sizeof(dp));

        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) scanf("%d",&chrge[i][j]);
        }
        int res = call(0,0);
        //cout<<endl;
        printf("Case %d: %d\n",N,res);
    }
}
