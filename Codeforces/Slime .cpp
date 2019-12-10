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


#define     mx                      500001

////

int n,ar[mx];
map<int,map<int,ll> >dp,vis;

ll call(int i,int j)
{
    if(i>j) return 0;
    if(i==j) return ar[i];
    if(vis[i][j]) return dp[i][j];

    ll x,y,ans=0;
    for(int mid=i;mid<j;mid++){
        x = call(i,mid);
        y = call(mid+1,j);
        cout<<x<<" "<<y<<endl;
        ans += x - y;
    }
    vis[i][j] = 1;
    return dp[i][j] = ans;
}
int main()
{
    sci(n);
    for(int i=0;i<n;i++) sci(ar[i]);

    cout<<call(0,n-1)<<endl;

}
