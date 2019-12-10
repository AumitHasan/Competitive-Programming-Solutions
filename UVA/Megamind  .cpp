#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 100007

ll e,x,k,p,r,ans,mid,tmp;

ll clc(ll bulet)
{
    cout<<bulet<<" ";
    if(bulet<=k){
        ll x = e - bulet*p;
        if(x<=0) return 1;
        return 0;
    }
    ll relod = bulet/k - 1;
    if(bulet%k!=0) relod++;
    ll x = (e - bulet*p + relod*r);
    cout<<relod<<" "<<x<<endl;
    if(x<=0) return 1;
    return 0;
}
void solve()
{
    ans = 1e9;
    ll lo = 1,hi=1e10;
    while(lo<=hi){
        mid = (lo + hi) / 2;
        cout<<lo<<" "<<hi<<endl;
        if(clc(mid)){
            //cout<<tmp<<" "<<mid<<endl;
            hi = mid - 1;
            ans = min(ans,mid);
        }
        else lo = mid + 1;
    }
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%lld %lld %lld %lld",&e,&p,&k,&r);
        //
        solve();
        if(ans==1e9) ans = -1;
        printf("Case %d: ",N);
        cout<<ans<<endl;
    }
    return 0;
}
