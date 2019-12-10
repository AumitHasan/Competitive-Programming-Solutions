#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll ar[100007],mx=-1e9,mn=1e9;
struct st{
    ll mx,mn;
}before[100007];
struct stt{
    ll mx,mn;
}after[100007];

int main()
{
    //cout<<1e1;
    ll n,p,q,r;
    cin>>n>>p>>q>>r;
    for(ll i=0;i<n;i++){
        cin>>ar[i];
    }

    for(ll i=0;i<n;i++){
        mn = min(ar[i],mn);
        mx = max(mx,ar[i]);
        before[i].mn = mn;
        before[i].mx = mx;
    }
    mn = 1e9;
    mx = ar[n-1];
    for(ll i=n-1;i>=0;i--){
        mn = min(ar[i],mn);
        mx = max(mx,ar[i]);
        after[i].mn = mn;
        after[i].mx = mx;
        //cout<<after[i].mx<<" ";
    }
    //cout<<endl;
    ll ans;
    //cout<<ans<<endl;
    for(ll i=0;i<n;i++){
        ll a = p*ar[i] + q*ar[i] + r*ar[i];
        //cout<<"r: "<<before[i].mn<<" "<<before[i].mx<<" "<<after[i].mn<<" "<<after[i].mx<<endl;
        ll b = max(p*before[i].mn , p*before[i].mx) + (q*ar[i]) + max(r*after[i].mn , r*after[i].mx);
        //ll x = (p*before[i].mn) + (q*before[i].)
        //cout<<a<<" "<<b<<" "<<ans<<endl<<endl;
        if(i==0) ans = max(a,b);
        else ans = max(ans,max(a,b));
    }
    cout<<ans<<endl;

}
