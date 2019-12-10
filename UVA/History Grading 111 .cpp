#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
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

int val,org[21],ar[21],n,dp[21][21];

int LCS(int i,int j)
{
    if(i>n || j>n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int len = 0;
    if(org[i]==ar[j])
        len = LCS(i+1,j+1) + 1;
    else
        len = max(LCS(i+1,j),LCS(i,j+1));

    return dp[i][j] = len;
}
int main()
{

    cin>>n;
    for(int i=1;i<=n;i++){
       scanf("%d",&val);
       org[val] = i;
    }
    while(cin>>val && val!=EOF){
        ar[val] = 1;
        for(int i=2;i<=n;i++){
            scanf("%d",&val);
            ar[val] = i;
        }
        mem(dp,-1);
        cout<<LCS(1,1)<<endl;
    }
    return 0;
}
