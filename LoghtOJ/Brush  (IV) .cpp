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


int n,dp[1<<17],x[17],y[17],lim;

inline bool one(int a,int b,int c)
{
    return ( (x[a]-x[b])*(y[b]-y[c]) == (y[a]-y[b])*(x[b]-x[c]) );
}
int call(int mask)
{
    if(mask == lim) return 0;
    if(dp[mask] != -1) return dp[mask];

    int c=0;
    for(int ii=0;ii<n;ii++){
        if(!(mask & 1<<ii)) c++;
    }
    if(c==1) return 1;

    int ret = 1e9;

    for(int i=0;i<n;i++){
        if(!(mask & 1<<i)){

                for(int j=i+1;j<n;j++){
                    if(!(mask & 1<<j)){

                        int tmp = (mask | 1<<i) | (mask | 1<<j);

                        for(int k=j+1;k<n;k++){
                            if(!(tmp & 1<<k) && one(i,j,k)){
                                tmp |= 1<<k;
                            }
                        }

                        ret = min(ret, 1 + call(tmp));
                    }
                }

            break;
        }
    }
    return dp[mask] = ret;
}
int main()
{

    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d",&n);
        lim = (1<<n)-1;

        for(int i=0;i<n;i++) scanf("%d %d", &x[i], &y[i]);
        mem(dp,-1);
        int res = call(0);
        printf("Case %d: %d\n", N, res);
    }
    return 0;
}
