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

#define mx 50007

int ar[mx],in,dp[mx][207];

int call(int i,int dif)
{
    if(i>in) return dif;
    if(dp[i][dif] != -1) return dp[i][dif];

    int yes=1e5,no=1e5;

    if(dif + ar[i] <= 200) yes = call(i+1,dif + ar[i]);
    if(dif - ar[i] >= -200) no = call(i+1,abs(dif - ar[i]));

    return dp[i][dif] = min(yes,no);
}
int main()
{
    int n,candy,cal;
    in = -1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&candy,&cal);
        for(int j=0;j<candy;j++) ar[++in] = cal;
    }
    random_shuffle(ar,ar+in+1);
    //
    mem(dp,-1);
    int ans = call(0,0);
    cout<<ans<<endl;
}
