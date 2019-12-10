#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))

int dp[17][1<<16+2],n;
int ar[18][18];

int set_bit(int mask,int pos)
{
    return mask |= (1<<pos);
}
int clear_bit(int mask,int pos)
{
    return mask & ~(1<<pos);
}
int check_bit(int mask,int pos)
{
    return (bool) (mask & (1<<pos) );
}
int call(int i,int mask)
{
    if(mask==(1<<n)-1 or i>n) return 0;
    if(dp[i][mask]!=-1) return dp[i][mask];

    int price=0,x=0;
    for(int j=1;j<=n;j++){
        if(!check_bit(mask,j)){
            price = max(price,(call(i+1,set_bit(mask,j))+ar[i][j]) );
        }
    }

    return dp[i][mask] = price;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        mem(dp,-1);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) scanf("%d",&ar[i][j]);
        }
        int res = call(1,0);
        printf("Case %d: %d\n",N,res);
    }
    return 0;
}
