#include<bits/stdc++.h>
using namespace std;

#define MAX 25007
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long int

ll dp[MAX][27],path[MAX][27],ar[MAX][27],sum[MAX][27],tmm[MAX][27];
ll row,col;

ll call(int i,int j)
{
    if(i==row+1){
        //path[i+1][j] = 0;
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];

    ll ans = 1e17, tmin = 1e17;

    for(int k=j;k<=col;k++){
        ll check = sum[i][k] - sum[i][j];
        ll res = ar[i][k] + call(i+1,k);
        if(ans>res){
            ans = res;
            tmin = check + path[i+1][k];
        }
        else if(ans==res){
            tmin = min(tmin, check + path[i+1][k]);
        }
    }
    for(int k=j-1;k>0;k--){
        ll check = sum[i][j] - sum[i][k];
        ll res = ar[i][k] + call(i+1,k);
        if(ans>res){
            ans = res;
            tmin = check + path[i+1][k];
        }
        else if(ans==res){
            tmin = min(tmin, check + path[i+1][k]);
        }
    }
    path[i][j] = tmin;
    return dp[i][j] = ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld %lld", &row, &col);
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++) scanf("%d", &ar[i][j]);
        }
        for(int i=1;i<=row;i++){
            for(int j=1;j<col;j++){
                scanf("%lld", &tmm[i][j]);
                //sum[i][j] = sum[i][j-1] + tmm[i][j-1];
            }
            //sum[i][col] = sum[i][col-1] + tmm[i][col-1];
        }
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                sum[i][j] = sum[i][j-1] + tmm[i][j-1];
            }
        }
        mem(dp,-1);
        mem(path,0);
        ll res = call(1,1);
        printf("%lld %lld\n",res,path[1][1]);
    }
    return 0;
}

