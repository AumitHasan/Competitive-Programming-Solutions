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

int m,n,dp[101][50001],coin[101],sum;

int call(int pos,int val)
{
    if(pos>=m){
        return abs(val-(sum-val));
    }
    if(dp[pos][val]!=-1) return dp[pos][val];

    //return dp[pos][val] = min(call(pos+1,val+coin[pos]),call(pos+1,val));
    int p1=100000,p2=100000;
    p1 = min(p1,call(pos+1,val+coin[pos]));
    p2 = min(p2,call(pos+1,val));

    return dp[pos][val] = min(p1,p2);
}
int main()
{

    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        sum=0;
        mem(dp,-1);
        for(int i=0;i<m;i++){
            scanf("%d",&coin[i]);
            sum += coin[i];
        }

        int res = call(0,0);
        cout<<res<<endl;
    }
    return 0;
}
