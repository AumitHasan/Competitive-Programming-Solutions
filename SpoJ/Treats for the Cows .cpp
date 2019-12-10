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

#define mx 2003

ll dp[mx][mx];
int n,milk[mx];

ll call(int i,int j,int cnt)
{
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = max(milk[i]*cnt + call(i+1,j,cnt+1) , milk[j]*cnt + call(i,j-1,cnt+1));
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&milk[i]);
    mem(dp,-1);
    cout<<call(0,n-1,1)<<endl;

    return 0;
}
