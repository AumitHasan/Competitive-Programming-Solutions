#include<bits/stdc++.h>
using namespace std;

int a,b,dp[103][205][205];
int n,ans=0;
string str;

int call(int i,int x,int y)
{
    if(i>=n){
        if(x==105 && y==105) return 0;
        return -1000;
    }
    if(dp[i][x][y] != -1) return dp[i][x][y];

    int a=x;
    int b=y;

    if(str[i]=='U') b++;
    else if(str[i]=='D') b--;
    else if(str[i]=='L') a--;
    else if(str[i]=='R') a++;

    return dp[i][x][y] = max( 1 + call(i+1,a,b), call(i+1,x,y) );
}
int main()
{
    cin>>n;
    cin>>str;

    for(int i=0;i<n;i++){
        memset(dp,-1,sizeof(dp));
        ans = max(ans,call(i,105,105));
    }
    cout<<ans<<endl;
}
