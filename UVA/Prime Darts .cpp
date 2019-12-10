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

#define mx 10007

double ar[mx];


void solve()
{
    int n,tmp,val,f;
    double m=0.0,ans=0.0;

    cin>>n>>f;

    for(int i=0;i<n;i++){
        cin>>val;
        ar[i] = pii * val * val;
        m = max(m,ar[i]);
    }
    double lo=0.0,hi=m;

    while(hi-lo > 1e-5){
        double mid = (lo+hi) / 2.0;
        tmp = 0;
        for(int i=0;i<n;i++){
            tmp += (int) (ar[i]/mid);
        }
        if(tmp>f){
            lo = mid;
            ans = mid;
        }
        else hi = mid;
    }
    printf("%.6f\n",ans);
}
int main()
{
    //cout<<gtv(4.0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
