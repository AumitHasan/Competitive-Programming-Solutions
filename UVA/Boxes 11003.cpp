#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int n,dp[1001][3001][2],wight[1001],load[1001];

int call(int i,int w,int pos)
{
    if(i>=n) return 0;
    if(dp[i][w][pos]!=-1) return dp[i][w][pos];

    int p1=0,p2=0;
    if(pos==0) p1 = call(i+1,w+load[i],1)+1;
    else if(w>=wight[i]) p1 = call(i+1,min(w-wight[i],load[i]),1)+1;

    p2 = call(i+1,w,pos);

    return dp[i][w][pos] = max(p1,p2);
}
int main()
{

    while(scanf("%d",&n) && n){
        mem(dp,-1);
        for(int i=0;i<n;i++){
            scanf("%d %d",&wight[i] ,&load[i]);
        }

        int res = call(0,0,0);
        printf("%d\n",res);
    }
    return 0;
}
