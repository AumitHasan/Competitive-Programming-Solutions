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

#define     mx                      22
#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....

////

ll ans,lim,n,m,k,ar[mx][mx],vis[mx][mx];
map<int,map<int, ll> > mp;


void call(int i,int j,ll sum)
{
    if(j<1 || i<1) return;
    if(vis[i][j]){
        if(mp[j][sum^k]){
            ans += mp[j][sum^k];
            //cout<<i<<" "<<j<<endl;
        }
        return;
    }

    call(i,j-1,sum^ar[i][j]);
    call(i-1,j,sum^ar[i][j]);
}
void dfs(int i,int j,ll sum)
{

    if(j>m || i>n) return;
    if(i>lim) return;

    vis[i][j] = 1;
    //cout<<i<<" "<<j<<" "<<(sum^ar[i][j])<<endl;
    if(i==lim) mp[j][sum^ar[i][j]] ++;

    dfs(i,j+1,sum^ar[i][j]);
    dfs(i+1,j,sum^ar[i][j]);
}
int main()
{
    sclll(n,m,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) scl(ar[i][j]);
    }
    lim = n/2 + (n%2);

    dfs(1,1,0);

    call(n,m,0);

    cout<<ans<<endl;
}
