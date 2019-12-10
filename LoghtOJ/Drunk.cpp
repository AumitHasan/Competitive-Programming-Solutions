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

#define mx 20007

int cycle,vis[mx],vv[mx];
vector<int>adj[mx];
map<string,int>name;
string a,b;

void dfs(int u)
{
    if(vv[u]) return;
    vv[u] = 1;
    for(int i=0;i<adj[u].size();i++) dfs(adj[u][i]);
}
void has_cycle(int u)
{
    if(vis[u]==2 || cycle) return;
    if(vis[u]==1){
        cycle = 1;
        return;
    }
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++) has_cycle(adj[u][i]);
    vis[u] = 2;
}
void refresh()
{
    for(int i=0;i<mx;i++){
        adj[i].clear();
        vis[i] = vv[i] = 0;
    }
}
int main()
{
//    READ("in.txt");
//    WRITE("out.txt");
    IO;

    int n,T,N=0,d,u,v;
    cin>>T;
    while(++N<=T){
        refresh();
        name.clear();
        d = cycle = 0;

        cin>>n;
        while(n--){
            cin>>a>>b;
            if(!name[a]) name[a] = ++d;
            if(!name[b]) name[b] = ++d;
            u = name[a];
            v = name[b];
            adj[u].push_back(v);
        }
        cout<<"Case "<<N<<": ";

        for(int i=1;i<=d;i++) has_cycle(i);
        //cout<<cycle<<endl;
        if(cycle){
            cout<<"No"<<endl;
            continue;
        }
        //
        for(int i=1;i<=d;i++) dfs(i);

        bool flag = false;
        for(int i=1;i<=d;i++){
            if(vv[i]==0){
                flag=true;
                break;
            }
        }
        if(flag) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
