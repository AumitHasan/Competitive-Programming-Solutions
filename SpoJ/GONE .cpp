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
int n,dp[10][73][2],mark[75],lo,hi;

int call(int pos,int carry,int flag)
{
    if(pos==n){
        if(mark[carry]==0){
            //cout<<carry<<endl;
            return 1;
        }
        return 0;
    }
    if(dp[pos][carry][flag] != -1) return dp[pos][carry][flag];

    int lim = 9,p = 0;
    if(flag) lim = num[pos]-'0';

    bool check = false;
    for(int i=0;i<=lim;i++){
        if(flag && i==num[pos]-'0') check = true;
        p += call(pos+1,carry+i,check);
    }
    return dp[pos][carry][flag] = p;
}
void seive()
{
    mark[0]=mark[1]=1;
    for(int i=4;i<=74;i+=2) mark[i] = 1;
    for(int i=3;i<=9;i+=2){
        if(mark[i]==0){
            for(int j=i*i;j<=74;j+=2*i) mark[j] = 1;
        }
    }
}
int main()
{
    seive();
    int T;
    scanf("%d",&T);
    while(T--){
        int sum = 0;
        mem(dp,-1);
        cin>>num;
        n = num.length();
        int x = call(0,0,1);
        for(int i=0;i<n;i++) sum += num[i]-'0';
        //cout<<endl;
        cin>>num;
        n = num.length();
        mem(dp,-1);
        int y = call(0,0,1);
        int res = y-x;
        if(mark[sum]==0) res++;

        cout<<res<<endl;
    }
    return 0;
}
