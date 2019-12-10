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
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)

#define     mx                      100007
#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....

////
ll len,na,nb;
string A,B;
ll dp[31][31][62],DP[31][31][64];


ll call(int i,int j,int ln)
{

    if(ln>len || i>na || j>nb) return 0;
    if(i>=na && j>=nb && len==ln){
        //cout<<i<<" "<<j<<endl;
        return 1;
    }
    //if(i>na || j>nb) return 0;
    if(DP[i][j][ln] != -1) return DP[i][j][ln];

    ll ans = 0;

    if(A[i]==B[j]) ans += call(i+1,j+1,ln+1);
    else{
        ans += call(i+1,j,ln+1);
        ans += call(i,j+1,ln+1);
    }

    return DP[i][j][ln] = ans;
}
ll minLen(int i,int j,int ln)
{
    if(i>=na && j>=nb) return ln;
    if(i>na || j>nb) return 2e9;
    if(dp[i][j][ln] != -1) return dp[i][j][ln];

    ll ans = 2e9;

    if(A[i]==B[j]) ans = min(ans, minLen(i+1,j+1,ln+1));
    else{
        ans = min(ans, minLen(i+1,j,ln+1));
        ans = min(ans, minLen(i,j+1,ln+1));
    }
    return dp[i][j][ln] = ans;
}
int main()
{

    int T,N=0,tmp;
    cin>>T;
    getchar();
    while(++N<=T){
        getline(cin,A);
        getline(cin,B);
        //cout<<A<<" "<<B<<endl;
        na = A.size();
        nb = B.size();
        mem(dp,-1);
        len = minLen(0,0,0);
        mem(DP,-1);
        ll ans = call(0,0,0);
        cout<<"Case #"<<N<<": ";
        cout<<len<<" "<<ans<<endl;
    }
    return 0;
}
