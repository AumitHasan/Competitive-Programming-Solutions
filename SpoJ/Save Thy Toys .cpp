#include<bits/stdc++.h>
using namespace std;
#define mx 100021
int add(int i,int idx);
typedef long long int ll;

map<ll,ll>mp;
int n,ar[mx];

ll call(ll i)
{
    //cout<<i<<" "<<val<<endl;
    if(i>n) return 0;
    if(mp[i] != 0) return mp[i];

    ll p1=0,p2=0,p3=0;
    p1 = call(i+2)+add(i,1);
    p2 = call(i+4)+add(i,2);
    p3 = call(i+6)+add(i,3);

    //return mp[i][val] = p1+p2+p3;
    return mp[i]= max(p1,max(p2,p3));
}
int add(int i,int idx)
{
    ll val=0;
    idx+=i;
    for(i;i<idx;i++) val += ar[i];
    return val;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        mp.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        for(int i=n;i<n+10;i++) ar[i]=0;

        ll res = call(0);
        printf("%lld\n",res);
    }
}
