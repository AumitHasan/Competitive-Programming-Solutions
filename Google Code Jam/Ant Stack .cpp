#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define mx 100007
#define mod 1000000009
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....
////
double angle(double cone){ return (PI * cone) / 180.0;}
//
int n,ar[mx];//dp[103][100005];
umap<int,umap<int,ll> > dp;

ll call(int i,int wt)
{
    if(i>=n) return 0;
    if(dp[i][wt] != 0) return dp[i][wt];

    ll ans = 0;

    if(wt <= 6*ar[i]){
        ans  = max(ans, 1 + call(i+1,wt+ar[i]));
    }
    ans = max(ans, call(i+1,wt));

    return dp[i][wt] = ans;
}
int main()
{
    IO;

    int T,N=0;
    cin>>T;
    while(++N<=T){
        cin>>n;
        for(int i=0;i<n;i++) cin>>ar[i];
        dp.clear();
        cout<<"Case #"<<N<<": "<<call(0,0)<<endl;
    }
    return 0;
}
