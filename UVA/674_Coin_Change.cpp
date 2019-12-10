#include<bits/stdc++.h>
using namespace std;

#define st(a) memset(a,-1,sizeof(a))

//int c[]={5,8,11,15,18};
//int n[]={6,5,4,3,2,1};
int c[]={1,5,10,25,50};
int dp[7][7493],make;

int coin(int i,int amount)
{
    if(i>=5){
        if(amount==0) return 1;
        else return 0;
    }
    if(dp[i][amount] != -1) return dp[i][amount];

    int r1=0,r2=0;
    if(amount-c[i]>=0) r1 = coin(i,amount-c[i]);

    r2 = coin(i+1,amount);

    dp[i][amount] = r1+r2;

return dp[i][amount];
}
int main()
{
    st(dp);
    while(cin>>make)
    {
        cout<<coin(0,make)<<endl;
    }
}

