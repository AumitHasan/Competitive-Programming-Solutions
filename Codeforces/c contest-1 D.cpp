#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int

ll clc[1000007],ar[10000007];

void pre()
{
    ll val = 1;
    clc[1] = ar[1] = 1;
    for(int i=2;i<=1e7;i++){
        val = (val*2) % mod;
        ar[i] = (ar[i-1]+val) % mod;
    }
}
int main()
{
    pre();

    string str;
    cin>>str;
    ll c=0,ans=0;

    int len = str.length();

    for(int i=0;i<len;i++){
        if(str[i]=='b'){
            ans = (ans + ar[c]) % mod;
        }
        else c++;
    }
    cout<<ans<<endl;
}
