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

int n,m,k,ans;
vector<int>edge[55];

void dfs(int u,int mv)
{
    if(mv>20) return;
    if(u==n-1){
        if(mv>=k){
            ans = min(ans,mv);
            return;
        }
    }
    for(int i=0;i<edge[u].size();i++){
        dfs(edge[u][i],mv+1);
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)){
        if(!n && !m && !k) break;

        mem(edge,0);
        int u,v;
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        ans = 1e9;
        dfs(0,1);
        if(ans==1e9) cout<<"LOSER"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
