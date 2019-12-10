#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mem(a,b) memset(a,b,sizeof(a))

int n,k;
ll cnt,dp[101][10][2];

ll call(int i,int pre,int flag)
{
    if(i>=n){
        //cnt++;
        //cout<<flag<<endl;
        if(flag) return 0;
        return 1;
    }
    if(dp[i][pre][flag]!=-1) return dp[i][pre][flag];

    ll P=0;

    for(int j=0;j<=k;j++){
        if(abs(pre-j)<=1 || i==0){
            P += call(i+1,j,flag^0);
        }
        else{
            P += call(i+1,j,1);
        }
    }
    return dp[i][pre][flag] = P;
}
int main()
{

    while(~scanf("%d %d",&k,&n)){
        if(n==1){
            printf("100.00000\n");
            continue;
        }

        cnt=0;

        mem(dp,-1);
        ll res = call(0,0,0);

        double ans =

    }
}
