#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     MAX3(a,b,c)              max(a,max(b,c))
#define     MAX4(a,b,c,d)            max(max(a,b),max(c,d))
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     100000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      100007

////

int n,k,s,dp[1003][15003];



int call(int pos,int sum)
{
    if(sum<0) return 0;
    if(pos>=n){
        //cout<<sum<<endl;
        if(sum==0) return 1;
        return 0;
    }
    if(dp[pos][sum] != -1) return dp[pos][sum];

    int res = 0;

//    for(int i=cur;i<=k;i++){
//        res = (res + call(pos+1,i+1,sum+k) ) % mod;
//        res = (res + call(pos+1,i+1,sum)) % mod;
//    }
    for(int i=k;i>0 && sum-i>=0;i--){
        res = (res + call(pos+1,sum-i)) % mod;
    }

    return dp[pos][sum] = res % mod;
}
int main()
{
    int N=0,T;
    sci(T);
    while(++N<=T){
        sciii(n,k,s);
        mem(dp,-1);
        int ans = call(0,s) % mod;
        printf("Case %d: %d\n",N,ans);
    }
    return 0;
}
