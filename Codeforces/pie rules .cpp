#include<bits/stdc++.h>
using namespace std;

#define MAX 100007
#define mem(a,b) memset(a,b,sizeof(a))

int n,dp[MAX][2],ar[MAX];

int call(int i,int cur)
{
    if(i==n) return 0;
    if(dp[i][cur] != -1) return dp[i][2];

    if(cur){
        - ar[i] + call(i+1,cur), ar[i] + call(i+1,0)
    }
    else{

    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d", &ar[i]);
    mem(dp,-1);
    int res = call(0,1);
    cout<<res<<endl;
}
