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
#define M 100003

int ar[M],n;
unordered_map<int,unordered_map<int,int>>dp;

int call(int i,int sign)
{
    if(i==n){
        //cout<<
        return 0;
    }
    if(dp[i][sign]!=0) return dp[i][sign];

    int p1=0,p2=0;
    p1 = ar[i]+call(i+1,0);
    p2 = ar[i]*call(i+1,1);

    return dp[i][sign] = p1+p2;
}
int call2(int i,int j)
{
    if(i==n || j==n) return 0;
    if(dp[i][j]!=0) return dp[i][j];


}
int main()
{
    int T;
    cin>>T;
    while(T--){
        mem(dp,-1);
        cin>>n;
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        int res = call(0,0);
        cout<<res<<endl;
        mem(dp,-1);
        res = call2(0,0);
        cout<<res<<endl;
    }
}
