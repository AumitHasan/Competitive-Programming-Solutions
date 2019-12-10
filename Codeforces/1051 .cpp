#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 1, 0, 1};
int dy[] = { 0, 1, 1, 0};

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


#define     mod                     998244353
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      1003

////

int n,k,tmp,dp[mx][2][2][2*mx];


int add(int a,int b,int pos)
{
    int x = dx[pos];
    int y = dy[pos];


    if(a==0 && b==1 && (x==1 && y==0) ) return 2;

    if(a==1 && b==0 && (x==0 && y==1)) return 2;

    if(a==0 && b==0 && (x==1 || y==1)) return 1;

    if(a==1 && b==1 && (x==0 || y==0)) return 1;

    return 0;
}
int call(int col,int a,int b,int cnt)
{
    //cout<<col<<" "<<a<<" "<<b<<" "<<cnt<<endl;

    if(col>=n){
        if(k==cnt) return 1;
        return 0;
    }
    if(dp[col][a][b][cnt] != -1) return dp[col][a][b][cnt];

    int sum = 0;
//
//    int tmp = add(a,b,0);
//    sum = (sum + call(col+1,1,0, cnt + tmp ) )% mod;

    for(int i=0;i<4;i++){
        tmp = add(a,b,i);
        if(tmp+cnt <= k){
            sum = (sum%mod + call(col+1,dx[i],dy[i], cnt + tmp ) )% mod;
        }
    }
    return dp[col][a][b][cnt] = sum%mod;
}
int main()
{
    scii(n,k);

    mem(dp,-1);

    int ans = call(1,0,0,1) % mod;

    //cout<<ans<<endl;

    mem(dp,-1);
    ans = (ans + call(1,1,1,1) ) % mod;

    //cout<<endl;

    mem(dp,-1);
    ans = (ans + call(1,1,0,2) ) % mod;

    //cout<<endl;

    mem(dp,-1);
    ans = (ans + call(1,0,1,2) ) % mod;

    printf("%d\n",ans);
}
