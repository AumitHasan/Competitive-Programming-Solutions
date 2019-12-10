#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll>v;
ll cnt[505];

int main()
{
    ll x,n,k,mx=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        mx = max(x,mx);
    }

    while(1){
        x = v[0];
        if(x==mx){
            cout<<mx<<endl;
            return 0;
        }
        v.erase(v.begin());
        while(1){
            if(x>v[0]){
                cnt[x]++;
                if(cnt[x]>=k){
                    cout<<x<<endl;
                    return 0;
                }
                v.push_back(v[0]);
                v.erase(v.begin());
            }
            else{
                cnt[v[0]]++;
                if(cnt[v[0]]>=k){
                    cout<<v[0]<<endl;
                    return 0;
                }
                v.push_back(x);
                break;
            }
        }
    }
}
