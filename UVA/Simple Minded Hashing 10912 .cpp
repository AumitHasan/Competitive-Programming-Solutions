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

int L,S,dp[27][27][353],c;

int call(int i,int cnt,int val)
{

    if(i>26){
        if(val==S && cnt==L){
            c++;
            return 1;
        }
        return 0;
    }
    if(dp[i][cnt][val]!=-1) return dp[i][cnt][val];

    int P=0,Q=0;
    if(cnt<L && i+val<=S)
        P += call(i+1,cnt+1,val+i);

     P += call(i+1,cnt,val);

    return dp[i][cnt][val] = P;
}
int main()
{
    int test=0;
    while(scanf("%d%d",&L,&S) && L && S){
        int sum = 0;
        if(S<=351 && L<27){
            mem(dp,-1);
            sum = call(1,0,0);
        }
        printf("Case %d: %d\n",++test,sum);
    }
    return 0;
}
