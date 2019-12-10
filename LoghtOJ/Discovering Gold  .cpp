#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))

int ar[101],n,vis[110];
double dp[110];

double call(int i)
{
    if(i==n+1) return 0;
    if(vis[i]) return dp[i];

    double back_to_me=0.0,p=0.0;

    for(int j=1;j<=6;j++){
        if(j+i>n){
            back_to_me += 1.0/6;
        }
        else p += call(i+j) * 1.0/6;
    }
    back_to_me = 1.0-back_to_me;
    p += ar[i];
    vis[i] = 1;

    return dp[i] = p / (back_to_me+0.0);
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        mem(dp,0);
        mem(vis,0);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
        double res = call(1);
        printf("Case %d: %lf\n",N,res);
    }
    return 0;
}
