#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
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

umap<ll,int>mp;
ll ar[mx],odd,sqr;
vector<ll>v,vec;

ll src(ll num)
{
    ll ans,lo=1,hi=1e5;
    while(lo<hi){
        ll mid = (lo+hi) / 2;

        if(num>ar[mid]){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid;
    }
    return ans;
}
int main()
{
    mp[0] = mp[1] = 1;
    for(ll i=2;i<=100000;i++){
        ar[i] = i*i;
        mp[ar[i]]=1;
    }

    ll n,num;

    cin>>n;

    for(ll i=0;i<n;i++){
        cin>>num;
        //
        if(num==0) vec.push_back(2);
        else if(mp[num]) vec.push_back(1);
        //
        if(mp[num]==1){
            sqr++;
        }
        else{
            ll idx = src(num);
            v.push_back(min((num-ar[idx]),(ar[idx+1]-num)));
        }
    }

    if(v.size()>0) sort(v.begin(),v.end());
    if(vec.size()>0) sort(vec.begin(),vec.end());

    ll c=0;

    n /= 2;

    if(sqr<n){
        for(ll i=0;i < n-sqr;i++){
            c += v[i];
        }
    }
    else if(sqr>n){
        for(ll i=0;i < sqr - n;i++){
            c += vec[i];
        }
    }

    cout<<c<<endl;
}

