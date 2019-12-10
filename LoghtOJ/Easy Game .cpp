#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
#define ll long long int
#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 1007
#define int_map map<int,int>
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)

int ar[103],dp[103][103],n,sum[103];

int val(int lo,int hi)
{
    return sum[hi] - sum[lo-1];
}
int call(int i,int j)
{
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = -1e9,ax=0;
    for(int k=i;k<=j;k++){
        ans = max(ans, val(i,k) - call(k+1,j));
    }
    for(int k=j;k>=i;k--){
        ans = max(ans, val(k,j) - call(i,k-1));
    }

    return dp[i][j] = ans;
}
int main()
{
    int T,N=0;
    scanf("%d", &T);
    while(++N<=T){
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d", &ar[i]);
            sum[i] = sum[i-1] + ar[i];
        }
        mem(dp,-1);
        int res = call(1,n);
        printf("Case %d: %d\n",N,res);
    }
    return 0;
}
