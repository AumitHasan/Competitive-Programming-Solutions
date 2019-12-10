#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<ll,ll> pr;

#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define mx 200007
#define MOD 1000000009
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....
////
struct info{
    int h,d,cost;
    bool operator<(const info& nw) const
    {
        return cost > nw.cost;
    }
}ar[mx];

vector<pr>v;

int main()
{
    int n,a,b,m=-1,ix;
    cin>>n>>a>>b;

    ll pw = 1;
    for(int i=1;i<=a;i++) pw *= 2;

    for(int i=1;i<=n;i++){
        cin>>ar[i].h>>ar[i].d;
        v.push_back(pr(pw*ar[i].h-ar[i].d,i));
    }
    sort(v.rbegin(),v.rend());


    ar[v[0].second].h *= pw;
    //cout<<ar[v[0].second].h<<endl;

    v.clear();
    for(int i=1;i<=n;i++){
        v.push_back(pr(ar[i].h - ar[i].d,i));
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size() && i<b;i++){
        if(v[i].first<=0) break;
        int idx = v[i].second;
        swap(ar[idx].h,ar[idx].d);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) ans += ar[i].d;
    cout<<ans<<endl;
}
