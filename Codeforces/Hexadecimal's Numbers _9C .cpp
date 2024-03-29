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

string num;
int n,dp[10][2];

int call(int pos,int flag)
{
    if(pos==n) return 1;
    if(dp[pos][flag] != -1) return dp[pos][flag];

    int lim = 1,p=0;
    if(flag){
        lim = min(num[pos]-'0',lim);
    }
    bool check = false;
    for(int i=0;i<=lim;i++){
        if(flag && i==num[pos]-'0' ) check = true;
        p += call(pos+1,check);
    }
    return dp[pos][flag] = p;
}
int main()
{
    mem(dp,-1);
    cin>>num;
    n = num.length();
    int res = call(0,1);
    cout<<res-1<<endl;
}
