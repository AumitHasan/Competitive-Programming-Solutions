#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n;
    cin>>n;
    if(n==1 or n==2){
        cout<<"-1"<<endl;
        return 0;
    }
    if(n&1){
        ll r = (n*n+1)/2;
        cout<<r-1<<" "<<r<<endl;
    }
    else{
        ll x = (n * n / 4 + 1);
        cout << x - 2 << " " << x << endl;
    }

return 0;
}
