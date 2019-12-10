#include<bits/stdc++.h>
using namespace std;

#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))

int ar[10],dp[11][11][2],n,m;

int call(int pos,int last,int flag)
{
    if(pos==n) return 1;
    if(dp[pos][last][flag] != -1) return dp[pos][last][flag];

    int ret = 0;

    for(int i=0;i<m;i++){
        if(!flag || abs(last-ar[i])<=2){
            ret += call(pos+1,ar[i],1);
        }
    }
    return dp[pos][last][flag] = ret;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d %d", &m, &n);
        for(int i=0;i<m;i++) scanf("%d", &ar[i]);
        mem(dp,-1);
        printf("Case %d: %d\n",N,call(0,0,0));
    }
    return 0;
}
