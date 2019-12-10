#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};


#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define mx 100007

int ar[40],n,mod;
umap<int,umap<int,int> > dp;

int call(int i,int val)
{
    if(i>=n) return 0;
    if(dp[i][val] != 0) return dp[i][val];

    return dp[i][val] = max( call(i+1,(ar[i]+val)%mod), call(i+1,val%mod));

}
int main()
{
    cin>>n>>mod;
    for(int i=0;i<n;i++) cin>>ar[i];


    int ans = call(0,0);

    cout<<ans<<endl;
}
