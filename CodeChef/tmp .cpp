#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define inf 2e18
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

ll n,k,b,ar[mx],ans[mx];

ll clc(ll val)
{
    return val*k + b;
}
int main()
{
    int t;
    cin>>t;
    while(t--){

        scanf("%lld %lld %lld",&n,&k,&b);

        for(int i=0;i<n;i++){
            scanf("%lld",&ar[i]);
        }
        sort(ar,ar+n);
        //
        for(int i=0;i<n;i++) ans[i] = 1;

        int last = 0;
        for(int i=0;i<n;i++){
            ll val = clc(ar[i]);
            while(++last<n){
                if(val<=ar[last]){
                    //cout<<i<<" "<<ar[last]<<" "<<ans[i]<<endl;
                    ans[last] = max(ans[last], ans[i]+1);
                    i = last-1;
                    break;
                }
            }
        }
        ll res = 0;
        for(int i=0;i<n;i++){
            res = max(res,ans[i]);
        }
        printf("%lld\n",res);
    }
}
