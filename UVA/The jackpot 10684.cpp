#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))

int n,ar[10001],dp[10001][2];

int call(int i,int pos)
{
    if(i==n || pos==1) return 0;
    if(dp[i][pos] != -1) return dp[i][pos];

    int p1=0,p2=0;
    p1 = call(i+1,0)+ar[i];
    p2 = call(i+1,1);

    return dp[i][pos] = max(p1,p2);
}
int main()
{
    while(scanf("%d",&n) && n){
        mem(dp,-1);
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);

        int res = 0;
        for(int i=0;i<n;i++){
            int tmp = call(i,0);
            if(tmp>res) res = tmp;
        }

        if(res<=0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n",res);
    }
    return 0;
}
