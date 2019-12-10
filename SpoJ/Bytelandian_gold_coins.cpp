#include<bits/stdc++.h>
using namespace std;

long long n,value;
map <long long, long long> dp;

long long coin(long long n){


    if(n<2) return n;

    if(dp[n] != 0) return dp[n];

    value = coin(n/2)+coin(n/3)+coin(n/4);

    dp[n] = max(value,n);

return dp[n];
}
int main(){

    long long i;
    while(scanf("%lld",&n)==1){

        value = 0;

        cout<<coin(n)<<endl;

    }

return 0;
}
