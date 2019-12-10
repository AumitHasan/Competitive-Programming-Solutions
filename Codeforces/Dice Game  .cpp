#include<bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))

int dp[7][10009],make;
bool flag;

int call(int i,int point)
{
    if(point>make) return 1e7;
    if(point==make){
        flag = true;
        return 0;
    }
    if(dp[i][point] != -1) return dp[i][point];

    int ret = 1e9;

    for(int j=1;j<=6;j++){
        if(i==j || i+j==7) continue;
        ret = min(ret, 1 + call(j,point+j));
    }
    return dp[i][point] = ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&make);
        flag = false;
        mem(dp,-1);
        int res = call(1,0);
        if(flag) cout<<res<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
