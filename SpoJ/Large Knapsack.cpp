#include<bits/stdc++.h>
using namespace std;
#define mx 2000000
#define ll int
#define mem(a,b) memset(a,b,sizeof(a))

map<ll,map<ll,ll> >mp;
ll k,n;
ll wt[501],val[501];

ll call(ll i,ll waight)
{

    if(i>=n){
            return 0;
        //if(waight<=k) return 0;
        //return INFINITY;
    }
    if(mp[i][waight]  > 0) return mp[i][waight];

    ll p1=0,p2=0;
    if(waight+wt[i] <= k) p1 = call(i+1,waight+wt[i] ) + val[i];


    p2 = call(i+1,waight );

    return mp[i][waight] = max(p1,p2);
}
int main()
{
    while(~scanf("%d %d",&k ,&n)){
        mp.clear();


        for(int i=0;i<n;i++) scanf("%d %d",&val[i] ,&wt[i]);
        ll res = call(0,0);

        printf("%d\n",res);
    }
}
