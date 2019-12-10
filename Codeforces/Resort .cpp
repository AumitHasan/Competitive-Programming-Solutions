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

int n,obj[mx],par[mx],dis[mx],ar[mx];
vector<int>adj[mx];
vector<int>path;

void bfs(int s)
{
    if(dis[s]) return;
    //cout<<"suru: "<<s<<endl;
    queue<int>Q;
    Q.push(s);
    par[s] = s;
    dis[s] = 1;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        //
        if(adj[u].size()==1){
            int v = adj[u][0];
            //cout<<u<<" "<<v<<endl;
            if(dis[v] < dis[u] + 1){
                par[v] = u;
                dis[v] = dis[u] + 1;
                if(!obj[v] && adj[v].size()==1){
                    //cout<<"szpush: "<<adj[v].size()<<" "<<v<<endl;
                    Q.push(v);
                }
            }
        }
    }
}
void prnt(int h)
{
    path.push_back(h);
    if(h==par[h]) return;
    prnt(par[h]);
}
int main()
{
    int u;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&obj[i]);
    for(int i=1;i<=n;i++){
        ar[i] = i;
        scanf("%d",&u);
        if(u){
            adj[u].push_back(i);
        }
    }
    //
    random_shuffle(ar,ar+1+n);
    random_shuffle(ar,ar+1+n);
    //
    for(int i=0;i<=n;i++){
        int tmp = ar[i];
        //cout<<tmp<<endl;
        if(tmp==0) continue;
        if(!obj[tmp] && adj[tmp].size()==1){
            //cout<<i<<" "<<adj[i].size()<<endl;
            bfs(tmp);
            //cout<<endl;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(obj[i]) ans = max(ans,dis[i]);
    }
    if(!ans){
        cout<<1<<endl;
        for(int i=1;i<=n;i++){
            if(obj[i]){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    else{
            //cout<<"ans; "<<ans<<endl;
        for(int i=1;i<=n;i++){
            if(ans==dis[i] && obj[i]){
                //cout<<i<<endl;
                //cout<<ans<<endl;
                printf("%d\n",ans);
                prnt(i);
                for(int i=path.size()-1;i>=0;i--){
                    //cout<<path[i];
                    printf("%d",path[i]);
                    if(i==0) printf("\n");
                    else printf(" ");
                }
                break;
            }
        }
    }
}

