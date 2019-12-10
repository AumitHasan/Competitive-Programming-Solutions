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

#define     mx                      5007
#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....

////


int n,l,r,q,ar[mx],clc[mx][mx],dp[mx][mx];



int call(int i,int j)
{
    if(i==j) return ar[i];
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;

    ans = MAX3(ans, clc[j-i][i], call(i,j-1));
    ans = MAX3(ans, clc[j-i][i], call(i+1,j));

    return dp[i][j] = ans;
}
int main()
{
    //cout<<(8^4);
    sci(n);
    for(int i=1;i<=n;i++) sci(ar[i]), clc[0][i] = ar[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            clc[i][j] = clc[i-1][j] ^ clc[i-1][j+1];
            //ans[i][j] = max(clc[i][j],clc)
        }
    }

    mem(dp,-1);
    int q;
    sci(q);
    while(q--){
        scii(l,r);
        printf("%d\n",call(l,r));
    }

    return 0;
}
