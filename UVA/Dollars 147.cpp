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

int coin[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[11][30001];
int tk;

ll call(int i,int amount)
{
    if(i>=11){
        if(amount==0) return 1;
        return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];

    ll p1=0,p2=0;
    if(amount-coin[i]>=0)
        p1 = call(i,amount-coin[i]);
    else p1 = 0;
    p2 = call(i+1,amount);

    return dp[i][amount] = p1+p2;
}

int main()
{

    mem(dp,-1);

    float nn;
    while(scanf("%f", &nn) == 1 && nn){

        tk = 0;
        tk = ((nn + 0.001) * 100);

        ll ways = call(0,tk);

        printf("%6.2f%17lld\n",nn,ways);

    }
    return 0;
}
