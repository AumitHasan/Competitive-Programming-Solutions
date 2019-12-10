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


ll coin[51],use[51],dp[51][1001],n,k;

ll call(int i,int make)
{
    if(i>=n){

        if(k==make){
            cout<<make<<endl;
            return 1;
        }
        else return 0;
    }
    if(dp[i][make] != -1) return dp[i][make];

    ll p1=0,p2=0;

    //for(int j=0;j<use[i];j++){
        if(coin[i]+make<=k) p1 = call(i,make+coin[i]);
        //else break;
    //}
    p2 = call(i+1,make) ;

    return dp[i][make] = (p1+p2);// % MOD;
}
int main()
{
    ll T,N=0;
    scanf("%lld",&T);
    while(++N<=T){
        mem(dp,-1);
        scanf("%lld %lld",&n ,&k);
        for(int i=0;i<n;i++) scanf("%lld",&coin[i]);
        for(int i=0;i<n;i++) scanf("%lld",&use[i]);

        ll res = call(0,0) ;

        printf("Case %lld: %lld\n",N,res);
    }
}
