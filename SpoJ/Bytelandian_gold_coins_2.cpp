#include<bits/stdc++.h>
using namespace std;

map<long long,long long>dp;
long long n,value;

long long coin(long long n)
{

    if(n==0 || n==1) return n;
    if(dp[n] != 0) return dp[n];

    value =coin(n/2)+coin(n/3)+coin(n/4);

    dp[n]=max(value,n);

return dp[n];
}


int main()
{
    while(~scanf("%lld",&n))
    {
        value=0;
        cout<<coin(n)<<endl;
    }

return 0;
}
