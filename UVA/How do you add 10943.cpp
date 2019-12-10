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

ll num,dp[101][101],k;

ll call(int n,int pos)
{

    if(pos>=k-1){
        if(n==num) return 1;
        return 0;
    }
    if(dp[n][pos] != -1) return dp[n][pos];

    ll p1 = 0;
    for(int j=0;j<=num;j++){
        if(n+j<=num) p1 += call(n+j,pos+1);
    }
    return dp[n][pos] = p1%1000000;
}
int main()
{

    while(scanf("%d %d",&num,&k) && num && k){
        mem(dp,-1);
        int sum = 0;
        for(int i=0;i<=num;i++) sum += call(i,0);
        cout<<sum%1000000<<endl;
    }
    return 0;
}
