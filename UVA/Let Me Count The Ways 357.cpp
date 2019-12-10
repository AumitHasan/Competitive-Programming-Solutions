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

int coin[]={1,5,10,25,50};
ll dp[5][30001];
int tk;

ll call(int i,int amount)
{
    if(i>=5){
        if(amount==0) return 1;
        return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];

    ll p1=0,p2=0;
    if(amount-coin[i]>=0)
        p1 = call(i,amount-coin[i]);

    p2 = call(i+1,amount);

    return dp[i][amount] = p1+p2;
}

int main()
{

    mem(dp,-1);

    while(~scanf("%d",&tk)){

        ll ways = call(0,tk);
        //cout<<ways<<endl;

        if(ways==1) printf("There is only %lld way to produce %d cents change.\n",ways,tk);
        else printf("There are %lld ways to produce %d cents change.\n",ways,tk);

    }
    return 0;
}
