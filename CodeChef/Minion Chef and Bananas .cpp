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

int n,h,tmp,ans,ar[mx];

bool check(int mid)
{
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += ar[i]/mid;
        if(ar[i]%mid != 0) ans++;
        if(ans>h) break;
    }
    if(ans>h) return 0;
    return 1;
}
void solve()
{
    ans = 0;
    int lo = 1, hi = tmp;
    while(lo<=hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    printf("%d\n",ans);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        tmp = 0;
        scanf("%d %d",&n,&h);
        for(int i=0;i<n;i++){
            scanf("%d",&ar[i]);
            tmp = max(tmp,ar[i]);
        }
        if(h==n){
            printf("%d\n",tmp);
            continue;
        }
        solve();
    }
    return 0;
}
