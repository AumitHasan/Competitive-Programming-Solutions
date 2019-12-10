#include<bits/stdc++.h>
using namespace std;
#define mx 2000000
#define ll int
#define mem(a,b) memset(a,b,sizeof(a))

ll mp[201][1001];
ll k,n;
ll wt[501],val[501];

ll call(ll i,ll waight)
{

    if(i>=n){
            return 0;
        //if(waight<=k) return 0;
        //return INFINITY;
    }
    if(mp[i][waight]  != -1) return mp[i][waight];

    ll p1=0,p2=0;
    if(waight+wt[i] <= k) p1 = call(i+1,waight+wt[i] ) + val[i];


    p2 = call(i+1,waight );

    return mp[i][waight] = max(p1,p2);
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        mem(mp,-1);

        scanf("%d %d",&k ,&n);
        for(int i=0;i<n;i++) scanf("%d %d",&wt[i] ,&val[i]);
        ll res = call(0,0);

        printf("Hey stupid robber, you can get %d.\n",res);
    }
}
