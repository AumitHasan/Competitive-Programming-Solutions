#include<bits/stdc++.h>

using namespace std;

int dp[100][100];

long long C(int n, int r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
ll nCr(int n,int r)
{
    if(n==1 && r==1) return 1;
    if(r==1) return n;
    if(r==0 || r>n) return 0;
    if(dp[n][r] != -1) return dp[n][r];

    return dp[n][r] = ( nCr(n-1,r)%mod + nCr(n-1,r-1)%mod ) % mod;
}
int main()
{

}
