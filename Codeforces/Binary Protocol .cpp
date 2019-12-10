#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
#define All(v) v.begin(),v.end()
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(2*k >= a[i])
            k = max(k,a[i]);
        else
        {
            while(2*k < a[i]+a[i]%2)
            {
                k = k*2;
                ans++;
            }
        }
        k = max(k,a[i]);
    }
    cout<<ans;
}
