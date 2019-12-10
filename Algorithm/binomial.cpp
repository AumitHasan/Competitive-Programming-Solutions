#include<bits/stdc++.h>
using namespace std;

#define row 70
#define col 70


int bi(int n, int r, int dp[row][col]){

    if(n==r || r==0) return 1;

    if(dp[n][r] != -1) return dp[n][r];

       dp[n][r] = bi(n-1,r-1,dp) + bi(n-1,r,dp);

return dp[n][r];
}

int main(){

    int c,r;
    cin>>c>>r;
    int dp[row][col];
    for(int i=0;i<70;i++)
    {
        for(int j=0;j<70;j++)
            dp[i][j]=-1;
    }


    cout<<bi(c,r,dp)<<endl;

}
