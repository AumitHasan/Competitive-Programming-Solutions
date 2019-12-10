#include<bits/stdc++.h>
using namespace std;

#define st(a) memset(a,-1,sizeof(a))
#define clr(a) memset(a,0,sizeof(a))
#define ll long long

ll g[200][103],dp[200][103];
ll row,col;

ll monkey(ll i,ll j)
{
    if(j<0 || j>col || i<0 || i>row || g[i][j]==0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    ll  t = monkey(i+1,j-1)+g[i][j];
    ll tt = monkey(i+1,j)+g[i][j];

    dp[i][j] = max(t,tt);

return dp[i][j];
}
int main()
{
    ll T,N=0;
    cin>>T;
    while(++N<=T)
    {
        ll n=0,m=0;
        scanf("%lld",&n);

        clr(g);
        n--;
        m=2*n;

        row = m;
        col = n;

        ll x=n;
        ll i,j=0;
        for(i=0;i<=m/2;i++)
        {
            for(j=0;j<x;j++) g[i][j]=0;
            x--;
            for(ll k=j;k<=n;k++) scanf("%lld",&g[i][k]);
        }
        ll ii;
        x=n-1;
        j=0;
        for(ii=i;ii<=m;ii++)
        {
            j=0;
            for(j=0;j<=x;j++) scanf("%lld",&g[ii][j]);
            x--;
            for(ll k=j;k<=n;k++) g[ii][k]=0;
        }
        /*cout<<endl;
        for(int a=0;a<=m;a++)
        {
            for(int b=0;b<=n;b++) printf("%d ",g[a][b]);
            cout<<endl;
        }
        cout<<endl;*/

        st(dp);
        printf("Case %lld: ",N);
        cout<<monkey(0,n)<<endl;

        /*cout<<endl<<"dp\n\n";
        for(int a=0;a<=m;a++)
        {
            for(int b=0;b<=n;b++) printf("%d ",dp[a][b]);
            cout<<endl;
        }
        cout<<endl;*/
    }


return 0;
}
