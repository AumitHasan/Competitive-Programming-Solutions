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

int coin[]={50,25,10,5,1},make;
ll dp[5][7499];

ll call(int i,int amount)
{
    if(amount==0){
        //cout<<"me"<<endl;
        return 1;
    }
    if(i==5 || amount<0) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];

    ll p=0,p2=0;

    if(amount-coin[i]>=0) p += call(i,amount-coin[i]);
    p2 += call(i+1,amount);

    return dp[i][amount] = p+p2;
}
int main()
{
    mem(dp,-1);
    while(~scanf("%d",&make)){
        cout<<call(0,make)<<endl;
    }
    return 0;
}
