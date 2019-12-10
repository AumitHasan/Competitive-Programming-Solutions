#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int main()
{
    ll k,r;
    cin>>k>>r;
    if(k%10==0 or (k-r)%10==0) cout<<1<<endl;
    else{
        ll n = k%10;
        for(int i=1;;i++){
            ll a = n*i;
            if(a%10==r or a==0){
                cout<<i<<endl;
                break;
            }
        }
    }
}
