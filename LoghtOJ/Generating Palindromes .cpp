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

int dp[105][105];
char ch[109],len;

int call(int i,int j)
{
    if(i==j || i>j){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    int P = 1e9;

    if(ch[i]==ch[j]){
        P = min(P , call(i+1,j-1) );
    }
    P = min(P , 1+call(i+1,j) );
    P = min(P , 1+call(i,j-1) );

    return dp[i][j] = P;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%s",ch);
        len = strlen(ch);
        mem(dp,-1);
        int res = call(0,len-1);
        printf("Case %d: %d\n",N,res);
    }
    return 0;
}
