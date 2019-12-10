#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define mx 100007
#define mod 1000000009
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....
////

ll n;


void solve()
{
    int lo=1,hi=1e9,idx;
    while(lo<=hi){
        int mid = (lo+hi) / 2;
        ll val = (mid*(mid+1))/2 + ((mid-1)*mid)/2;
        if(val>=n){
            idx = mid;
            hi = mid - 1;
        }
        else if(val<n) hi = mid + 1;
    }
    cout<<idx<<endl;
}
int main()
{

    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%lld",&n);
        solve();
    }
}
