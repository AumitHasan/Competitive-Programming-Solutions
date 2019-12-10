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

int n;
unordered_map<int,unordered_map<int,int>>dp;

struct info{
    int wt,str;
    bool operator<(const info& a) const
    {
        if(str==a.str) return wt<a.wt;
        return str>a.str;
    }
}ar[5609];

int call(int i,int wt)
{
    if(i>=n) return 0;
    if(dp[i][wt]!=0) return dp[i][wt];

    int p1=0,p2=0;
    if(wt>=ar[i].wt)
        p1 = call(i+1,min(wt-ar[i].wt,abs(ar[i].wt-ar[i].str)))+1;
    p2 = call(i+1,wt);

    return dp[i][wt] = max(p1,p2);
}
int main()
{
    int a,b;
    while(~scanf("%d %d",&a,&b)){
        ar[n].wt = a;
        ar[n++].str = b;
    }
    sort(ar,ar+n);

    cout<<call(0,200000000)<<endl;

    return 0;
}
