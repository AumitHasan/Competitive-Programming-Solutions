#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 100007

int n,m,lim,tmp,ar[30],cnt[10];
ll dp[(1<<19)+2][101],fact[20];

ll call(int mask,int num,int flag)
{
    if(mask == lim){
        if(num % m == 0) return 1;
        return 0;
    }
    if(dp[mask][num] != -1) return dp[mask][num];

    ll ans = 0;

    if(!flag){
        for(int i=0;i<n;i++){
            if(ar[i] && !(mask & (1<<i))){
                tmp = (num*10) + ar[i];
                ans += call(mask|(1<<i),tmp%m,1);
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(!(mask & (1<<i))){
                tmp = (num*10) + ar[i];
                ans += call(mask|(1<<i),tmp%m,1);
            }
        }
    }
    return dp[mask][num] = ans;
}
int main()
{
    fact[0] = 1;
    for(int i=1;i<19;i++) fact[i] = fact[i-1] * i;
    //
    string str;
    cin>>str>>m;
    n = str.length();
    for(int i=0;i<n;i++){
        ar[i] = str[i]-'0';
        cnt[ar[i]]++;
    }
    lim = (1<<n) - 1;
    mem(dp,-1);
    ll ans = call(0,0,0);
    //
    ll x = 1;
    for(int i=0;i<10;i++){
        if(cnt[i]){
            x = (x * fact[cnt[i]]);
        }
    }
    cout<<ans/x<<endl;
}
