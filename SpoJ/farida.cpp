#include<bits/stdc++.h>
using namespace std;

long long n,c[10003],dp[10003];

long long coin(long long i){

    if(i>=n) return 0;

    if(dp[i] != -1) return dp[i];

    dp[i] = max((c[i]+coin(i+2)), coin(i+1));

return dp[i];
}

int main(){

    long long N=0,T;
    cin>>T;
    while(++N <=T)
    {
        long long i;
        scanf("%lld",&n);


        for(i=0;i<n;i++){
            scanf("%lld",&c[i]);
        }
        memset(dp,-1,sizeof(dp));

        printf("Case %lld: ",N);

        if(n==0)
            printf("0\n");
        else if(n==1)
            printf("%lld\n",c[0]);
        else{

            cout<<coin(0)<<endl;
        }
    }


return 0;
}
