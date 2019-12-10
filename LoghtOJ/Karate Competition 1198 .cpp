#include<bits/stdc++.h>
using namespace std;
int diff(int i,int j);

int me[55],ops[55],dp[55][55],n;

int call(int i,int j)
{
    if(i>=n || j>=n) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = max(max(call(i,j+1),call(i+1,j+1)+diff(i,j)) , call(i+1,j+2)+diff(i,j+1) );
}
int diff(int i,int j)
{
    if(i>=n or j>=n) return 0;
    if(ops[i]==me[j]) return 1;
    else if(ops[i]>me[j]) return 0;
    else if(ops[i]<me[j]) return 2;
}
int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T){
        memset(me,0,sizeof(me));
        memset(ops,0,sizeof(ops));
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&me[i]);
        for(int i=0;i<n;i++) scanf("%d",&ops[i]);
        sort(me,me+n);
        sort(ops,ops+n);
        int res = call(0,0);
        printf("Case %d: %d\n",N,res);
    }
    return 0;
}

