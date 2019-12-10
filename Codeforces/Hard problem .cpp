#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int n,cost[mx][2];
string str[mx][2],tmp;
ll dp[mx][2];

ll call(int i,int j)
{
    //cout<<i<<" "<<j<<endl;
    if(i==n-1) return cost[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    ll P = 1e17;

    if(i==0 && j==0){
        if(str[i][0] <= str[i+1][0]){
            P = min(P, cost[i][0] + call(i+1,0) );
        }
        if(str[i][0] <= str[i+1][1]){
            P = min(P, cost[i][0] + call(i+1,1) );
        }
        if(str[i][1] <= str[i+1][0]){
            P = min(P, cost[i][1] + call(i+1,0) );
        }
        if(str[i][1] <= str[i+1][1]){
            P = min(P, cost[i][1] + call(i+1,1) );
        }
    }
    else{
        if(str[i][j] <= str[i+1][0]){
            P = min(P, cost[i][j] + call(i+1,0) );
        }
        if(str[i][j] <= str[i+1][1]){
            P = min(P, cost[i][j] + call(i+1,1) );
        }
    }
    return dp[i][j] = P;
}
int main()
{
    IO;

    cin>>n;
    for(int i=0;i<n;i++) cin>>cost[i][1];
    for(int i=0;i<n;i++){
        cin>>str[i][0];
        tmp = str[i][0];
        reverse(tmp.begin(),tmp.end());
        str[i][1] = tmp;
        //cout<<str[i][0]<<" "<<str[i][1]<<endl;
    }
    mem(dp,-1);

    ll ans = call(0,0);

    if(ans == 1e17) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}
