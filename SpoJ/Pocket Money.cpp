#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n[55],dp[55][55],sign[55][55],in;
char ch[105];

ll solve_min(ll start,ll endd)
{
    if(start==endd) return n[start];
    if(start>endd) return 0;

    if(dp[start][endd] != -1) return dp[start][endd];

    ll mid,mx=INFINITY;
    for(mid=start;mid<endd;mid++){

        ll left =  solve_min(start,mid);

        ll right;
        if(sign[mid][mid+1]==0) right = left + solve_min(mid+1,endd);
        else  right = left * solve_min(mid+1,endd);

        //ll ans = left+right;

        if(right<mx) mx = right;
    }
    dp[start][endd] = mx;

    return dp[start][endd];
}
ll solve(ll start,ll endd)
{
    if(start==endd) return n[start];
    if(start>endd) return 0;

    if(dp[start][endd] != -1) return dp[start][endd];

    ll mid,mx=0;
    for(mid=start;mid<endd;mid++){

        ll left =  solve(start,mid);

        ll right;
        if(sign[mid][mid+1]==0) right = left + solve(mid+1,endd);
        else  right = left * solve(mid+1,endd);

        //ll ans = left+right;

        if(right>mx) mx = right;
        //if(right<mn and start==1 and endd==in) mn = right;
    }
    dp[start][endd] = mx;

    return dp[start][endd];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){

        memset(dp,-1,sizeof(dp));
        scanf("%s",ch);
        in = 0;
        n[++in] = ch[0] - 48;

        for(ll i=2;i<strlen(ch);i+=2){
            ll x = ++in;
            n[in] = ch[i]-48;

            ll y = x-1;
           /* if(ch[i-1]=='+'){
               //dp[x][y] = (ch[i]-48) + (ch[i-2]-48);
               //dp[y][x] = (ch[i]-48) + (ch[i-2]-48);

            }*/
            if(ch[i-1]=='*'){
                //dp[x][y] = (ch[i]-48) * (ch[i-2]-48);
                //dp[y][x] = (ch[i]-48) * (ch[i-2]-48);
                sign[x][y] = 1;
                sign[y][x] = 1;
            }
        }

        //for(ll i=1;i<=in;i++) val[i][i] = n[i];

        /*for(ll i=1;i<=in;i++ ) cout<<sign[i]<<" ";
        cout<<endl;
        for(ll i=1;i<=in;i++){
            for(ll j=1;j<=in;j++){
                cout<<val[i][j]<<" ";
            }
            cout<<endl;
        }
        //cout<<in+1<<enddl;*/
        ll mx = solve(1,in);
        memset(dp,-1,sizeof(dp));
        ll mn = solve_min(1,in);
        printf("%lld %lld\n",mx,mn);
        memset(sign,0,sizeof(sign));
    }
    return 0;
}
