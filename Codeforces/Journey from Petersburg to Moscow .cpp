#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 3100
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

int n,m,k,cnt[mx],nw[mx],ar[mx],cost[mx][mx];
ll ans;
vector<int>vec[mx];

void bfs(int pos,int id,int last,ll sum)
{
    //cout<<pos<<" "<<id<<" "<<last<<endl;

    //cout<<pos<<" "<<id<<endl;
    if(pos!=n && id>m+8) return;

    if(pos==n){
        if(id==k+1 || id<=k){
            ans = min(sum,ans);
            return ;
        }
            //cout<<endl;
        //cout<<"id: "<<id<<endl;
        //sort(ar,ar+id);
        //set<int>st;
        for(int i=1;i<id;i++) nw[i] = ar[i];
        sort(nw,nw+id);
        ll c=0,val=0;
        //cout<<id<<" ck: ";
        for(int i=id-1;i>=0;i--){
            c++;
            if(c>k) break;
            val += nw[i];
            //cout<<nw[i]<<" ";
        }
        //cout<<endl;
        ans = min(ans,val);
        return;
    }
    for(int i=0;i<vec[pos].size();i++){
        if(vec[pos][i] != last){
            ar[id] = cost[pos][vec[pos][i]];
            //cout<<pos<<" x "<<vec[pos][i]<<" C:"<<cost[pos][vec[pos][i]]<<endl;
            cnt[vec[pos][i]]++;
            if(vec[pos][i]==n || cnt[vec[pos][i]]<2){
                bfs(vec[pos][i],id+1,pos,sum+ar[id]);
                cnt[vec[pos][i]]=0;
            }
        }
    }
}
int main()
{
    int u,v,tk;
    ans = 1e17;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &u, &v, &tk);
        vec[u].push_back(v);
        vec[v].push_back(u);
        cost[u][v] = cost[v][u] = tk;
    }
    bfs(1,1,1,0);
    printf("%lld\n",ans);
}
