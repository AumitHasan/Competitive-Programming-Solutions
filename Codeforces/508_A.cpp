#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define base 1e9
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int in=0,a,b,n,m,ar[mx],val[mx];
bool flag[mx];
unordered_map<int,int>mp;
vector<int>v[mx];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&ar[i]);

    while(m--){
        scanf("%d %d",&a,&b);
        if(mp[a]==0 && mp[b]==0){
            in++;
            mp[a] = mp[b] = in;
            v[in].push_back(a);
            v[in].push_back(b);
            continue;
        }
        if(mp[a]>0){
            mp[b] = mp[a];
            v[mp[a]].push_back(b);
        }
        if(mp[b]>0){
            mp[a] = mp[b];
            v[mp[a]].push_back(a);
        }
    }
    ll ans = 0,idx=0;
    cout<<endl;
    for(int i=1;i<=in;i++){
        int cost=2e9;
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
            cost = min(cost,ar[v[i][j]]);
            if(flag[v[i][j]]){

            }
            flag[v[i][j]] = 1;
        }
        cout<<endl;
        val[in] = cost;
        if(cost < 2e9) ans += cost;
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==0) ans += ar[i];
    }
    cout<<ans<<endl;

}
