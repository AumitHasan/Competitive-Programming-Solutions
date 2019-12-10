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

string A,B;
int len1,len2,sz;
ll dplcs[31][31],dp[31][31][64];

int LCS(int i,int j)
{
    if(i>=len1 || j>=len2) return 0;
    if(dplcs[i][j]!=-1) return dplcs[i][j];

    int res=0;
    if(A[i]==B[j])
        res = 1 + LCS(i+1,j+1);
    else
        res = max(LCS(i+1,j),LCS(i,j+1));

    return dplcs[i][j] = res;
}
ll cnt_res(int i,int j,int ln)
{
    if(i>=len1){
        ln += len2-j;
        if(ln==sz) return 1;
        return 0;
    }
    if(j>=len2){
        ln += len1-i;
        if(ln==sz) return 1;
        return 0;
    }
    if(dp[i][j][ln]!=-1) return dp[i][j][ln];

    ll res = 0;
    if(A[i]==B[j])
        res += cnt_res(i+1,j+1,ln+1);
    else{
        res += cnt_res(i+1,j,ln+1);
        res += cnt_res(i,j+1,ln+1);
    }
    return dp[i][j][ln] = res;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        cin>>A>>B;
        len1 = A.length();
        len2 = B.length();
        mem(dplcs,-1);
        sz = len1 + len2 - LCS(0,0);
        mem(dp,-1);
        ll res = cnt_res(0,0,0);
        printf("Case %d: %d %lld\n",N,sz,res);
    }
    return 0;
}
