#include<bits/stdc++.h>
using namespace std;

int m,n;
long long dp[50][10][(1<<10)+1];


long long call(int row,int col,int mask)
{
    long long  p=0,q=0;

    if(col>=m) p += call(row+1,0,mask);
    if(row==n) return 1;
    if(dp[row][col][mask] != -1) return dp[row][col][mask];


    if((mask & (1<<col))) p += call(row,col+1,(mask ^ (1<<col)) );

    if( !(mask & (1<<col)) && col+1<m && !(mask & (1<<(col+1))) ){
        p += call(row,col+2,mask);
    }
    if(!(mask & (1<<col)) && col<m && row<n-1){
        p += call(row,col+1,(mask |= (1<<col)));
    }

    return dp[row][col][mask] = p+q;

}
int main()
{
    int c = 1;
    while(~scanf("%d %d",&n ,&m)){
        if(c==1) memset(dp,-1,sizeof(dp));

        if(n < m) swap(n,m);
        //cout<<n<<" "<<m<<endl;
        c = 1;
        long long  res = 0;
        if(n%2==0 || m%2==0) res = call(0,0,0);
        else c=0;

        printf("%lld\n",res);
    }
    return 0;
}
