#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};

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
#define ll int

ll dp[102][102];
ll n,m,p;

int call(int frnt,int val)
{
    if(frnt>n) return 0;
    if(frnt==n){
        if(val==m){
            //cout<<val<<endl;
            return 1;
        }
        return 0;
    }
    if(dp[frnt][val]!=-1) return dp[frnt][val];

    //dp[frnt][val]=0;
    ll P=0;
    ll s=0, cnt = (n-frnt-1)*p + val;

    if(frnt==n-1) s = m-val;
    else s = p;

    for(int i=s;i<=m-cnt;i++){
        //cout<<i<<" "<<val<<" "<<val-i<<" "<<i<<" "<<frnt<<endl;
        //getchar();
        P += call(frnt+1,val+i);
    }
    return dp[frnt][val] = P;
}
int main()
{
    IO;

    ll T;
    cin>>T;
    while(T--){
        cin>>n>>m>>p;
        mem(dp,-1);
        ll res = call(0,0);
        cout<<res<<endl;
    }
}
