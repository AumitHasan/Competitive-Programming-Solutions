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


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      100007

////

char A[50],B[50],C[50];
int sa,sb,sc,dp[50][50][50];


int call(int i,int j,int k)
{
    if(i>=sa || j>=sb || k>=sc) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];

    int ans = 0;

    if(A[i]==B[j] && B[j]==C[k]) ans = max(ans, 1 + call(i+1,j+1,k+1));
    ans = max(ans, call(i+1,j,k));
    ans = max(ans, call(i,j+1,k));
    ans = max(ans, call(i,j,k+1));

    return dp[i][j][k] = ans;
}
int main()
{
    int T,N=0;
    scanf("%d ",&T);
    while(++N<=T){
        scanf("%s",A); sa = strlen(A);
        scanf("%s",B); sb = strlen(B);
        scanf("%s",C); sc = strlen(C);

        mem(dp,-1);
        printf("Case %d: %d\n",N,call(0,0,0));
    }
    return 0;
}
