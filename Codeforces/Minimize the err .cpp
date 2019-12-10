#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1,1,0,0,1,1,-1,-1};
int dy[] = {0,0,-1,1,-1,1,-1,1};

#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<ll,ll>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 1007

int n,tmp,x,y,a[mx],b[mx];
umap<int,umap<int,umap<int,ll> > > dp;

ll clc(int x,int y)
{
    tmp = abs(x-y);
    return tmp*tmp;
}
ll call(int pos,int e,int f,int c,int d)
{
    if(pos>=n){
        if(!e && !f) return 0;
        return 1e18;
    }
    if(dp[pos][e][f] != -1) return dp[pos][e][f];
    ll ans = 1e18;

    ans = min(ans, clc(c,d) + call(pos+1,e,f,0,0));

    for(int i=0;i<8;i++){
        if(abs(dx[i]) > e || abs(dy[i]) > f) continue;

        int xx = c + dx[i];
        int yy = d + dy[i];

        if(x>=0 && y>=0){
            ans = min(ans,clc(x,y));
            ans = min(ans, min( call(pos,e+dx[i],f+dy[i],xx,yy) , clc(x,y) + call(pos+1,e+dx[i],f+dy[i],0,0)));
        }
    }
    return dp[pos][e][f] = ans;
}
void solve()
{

}
int main()
{
    cin>>n>>x>>y;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    //
    ll tmp,e,f;

    ll ans = call(0,x,y,a[0],b[0]);

    cout<<ans<<endl;

    return 0;


}
