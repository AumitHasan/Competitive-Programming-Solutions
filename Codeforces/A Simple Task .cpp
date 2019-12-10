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

#define mx 100007

int n,m,lim,cur;
ll dp[(1<<19)][19];
vector<int>adj[mx];
bool vis[20];

ll call(int mask,int pos,int last)
{
    //cout<<mask<<" "<<pos<<" "<<last<<endl;
    //getchar();
    if(cur==pos && (mask & (1<<pos))){
        //cout<<"one"<<endl;
        return 1;
    }
    if(lim == mask){
        //cout<<"loss"<<endl;
        return 0;
    }
    if(dp[mask][pos] != -1) return dp[mask][pos];

    ll ans = 0;

    for(int i=0;i<adj[pos].size();i++){
        if(vis[adj[pos][i]] || adj[pos][i]==last || ((mask & (1<<adj[pos][i])) && adj[pos][i]!=cur))
            continue;
        ans += call(mask|(1<<pos),adj[pos][i],pos);
    }
    return dp[mask][pos] = ans;
}
int main()
{
    //
    int u,v;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    ll ans = 0;
    lim = (1<<n) - 1;
    mem(dp,-1);
    for(int i=0;i<n;i++){
        cur = i;

        ans += call(0,i,i);
        vis[i] = 1;
        //break;
    }
    cout<<ans/2<<endl;

    return 0;
}
