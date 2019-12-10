#include<bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define ll  long long int

int n,m,k;
ll dp[53][53][53];

ll call(int i,int take,int val)
{
    if(i>=k){
        if(val==n) return 1;
        return 0;
    }
    if(dp[i][take][val]!=-1) return dp[i][take][val];

    ll P=0;
    for(int j=1;j<=m;j++){
        if(val+j<=n) P += call(i+1,take+j,val+j);
    }
    return dp[i][take][val] = P;
}
int main()
{
    while(~scanf("%d%d%d",&n,&k,&m)){
        mem(dp,-1);
        cout<<call(0,0,0)<<endl;
    }
    return 0;
}
