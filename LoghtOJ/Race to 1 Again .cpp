#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100001
#define int_map map<int,int>
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)

vector<int>vec[100001];
double dp[MAX];
int vis[MAX];

double call(int n)
{
    if(n==1) return 0.0;
    if(vis[n]==1) return dp[n];

    double back_to_me=0.0,p=0.0;

    for(int i=0;i<vec[n].size();i++){

        if(n/vec[n][i]==n){
            back_to_me += 1.0/vec[n].size();
        }
        else p += call(n/vec[n][i]) * 1.0/vec[n].size();
    }

    back_to_me = 1.0-back_to_me;
    vis[n] = 1;

    return dp[n] = (p+1.0)/back_to_me;
}
void pre()
{
    for(int i=2;i<=MAX;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                vec[i].push_back(j);
                if(j != (i/j)) vec[i].push_back(i/j);
            }
        }
    }
}
int main()
{
    pre();

    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        mem(dp,0.0);
        mem(vis,0);
        int n;
        scanf("%d",&n);

        double res = call(n);

        printf("Case %d: %lf\n",N,res);
    }
    return 0;
}
