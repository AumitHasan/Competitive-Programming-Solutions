#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 100000007

int coin[101],dp[10507],make,n,tmp;


int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T){
        mem(dp,0);
        scanf("%d %d",&n,&make);
        for(int i=0;i<n;i++) scanf("%d",&coin[i]);

        int tk,add;
        dp[0] = 1;

        for(int i=0;i<n;i++){
            //tk = coin[i];
            for(int j=1;j<=make;j++){
                add = j - coin[i];
                if(add>=0){
                    dp[j] = (dp[j] + dp[add]) %mod;
                }
            }
        }

        printf("Case %d: %d\n",N,dp[make]);

    }
    return 0;
}
