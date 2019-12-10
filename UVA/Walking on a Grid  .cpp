#include<bits/stdc++.h>
using namespace std;

int dx[]={0,0,1};
int dy[]={1,-1,0};
#define ll long long int
#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 1007
#define int_map map<int,int>
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)

int grid[80][80],dp[80][80][6][3],n,k,vis[80][80],ans;
int a[80][80],flag;

bool ck(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<n) return 1;
    return 0;
}
int call(int i,int j,int neg,int dir)
{
    if(i==n-1 && j==n-1){
        if(neg<=k){
            flag = true;
            return 0;
        }
        return -1e9;
    }
    if(neg>k) return -1e9;

    if(dp[i][j][neg][dir]!=-1) return dp[i][j][neg][dir];

    int P = 0;

    if(dir==0){
        if(ck(i,j+1)) P = max(P, call(i,j+1,neg+a[i][j],0) + grid[i][j] );
        if(ck(i+1,j)) P = max(P, call(i+1,j,neg+a[i][j],2) + grid[i][j] );
    }
    else if(dir==1){
        if(ck(i,j-1)) P = max(P, call(i,j-1,neg+a[i][j],1) + grid[i][j]);
        if(ck(i+1,j)) P = max(P, call(i+1,j,neg+a[i][j],2) + grid[i][j]);
    }
    else if(dir==2){
        if(ck(i+1,j)) P = max(P, call(i+1,j,neg+a[i][j],2) + grid[i][j]);
        if(ck(i,j-1)) P = max(P, call(i,j-1,neg+a[i][j],1) + grid[i][j]);
        if(ck(i,j+1)) P = max(P, call(i,j+1,neg+a[i][j],0) + grid[i][j]);
    }

    return dp[i][j][neg][dir] = P;
}
int main()
{
    int test=0;
    while(1){
        flag = false;
        test++;

        scanf("%d%d",&n,&k);
        if(!n && !k) break;

        mem(a,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&grid[i][j]);
                if(grid[i][j]<0) a[i][j]=1;
            }
        }

        mem(dp,-1);
        int res = call(0,0,0,0);
        cout<<res<<endl;
    }
}
