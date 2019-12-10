#include<bits/stdc++.h>
using namespace std;
void m(int i,int j);
long long a[100],dp[100],n;

long long clor(long long i){

    if(i>=n) return 0;

    if(dp[i] != -1) return dp[i];

    dp[i] = a[i]*a[i+1]+clor(i+1);

return dp[i];
}


int main(){

    long long i;

    while(cin>>n){
        memset(dp,-1,sizeof(dp));

        for(i=0;i<n;i++)
            cin>>a[i];
        cout<<clor(0)<<endl;
    }

return 0;
}
