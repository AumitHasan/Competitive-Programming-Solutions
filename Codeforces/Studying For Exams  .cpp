#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int n;
double t,ar[11][4],dp[11][7680];
int vis[11][7680];

double clc(double tm,int pos)
{
    tm /= 30;
    return ar[pos][0]*tm*tm*1.0 + ar[pos][1]*tm*1.0 + ar[pos][2]*1.0;
}
double call(int pos,int tm)
{
    if(pos>=n) return 0;
    if(vis[pos][tm]) return dp[pos][tm];
    vis[pos][tm] = 1;
    double ans = - 1000000000.0;

    for(int i=0;i<=tm;i++){
        ans = max(ans, clc(i,pos) + call(pos+1,tm-i));
    }
    return dp[pos][tm] = ans;
}
int main()
{

    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
    }


    double ans = call(0,t*30);
    printf("%.10f\n",ans/(n*1.0));
}
