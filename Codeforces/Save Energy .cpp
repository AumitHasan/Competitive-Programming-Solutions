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

#define mx 200004

bool ck[100005];
int n,m,pos,cost[mx/2];
vector<int>edge[mx];
vector<int>vec;

void bfs()
{
    int u,v,s;
    set<pr>Q;
    par[pos] = pos;
    Q.insert(pr(pos,0));
    while(!Q.empty()){
        pr x = *Q.begin(); Q.erase(x);
        u = x.first; s = x.second;
        //
        for(int i=0;i<edge[u].size();i++){
            v = edge[u][i];
            if(!cost[v] || cost[u]+1 < cost[v]){
                par[v] = u;
                cost[v] = cost[u] + 1;
                if(ck[v]){
                    vec.push_back(u);
                }
                Q.insert(pr(v,cost[v]));
            }
        }
    }
}
int main()
{
    int c,u;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c;
        if(!c) ck[i] = 1;
        while(c--){
            cin>>u;
            edge[i].push_back(u);
        }
    }
    cin>>pos;
    if(ck[pos]){
        cout<<"Lose"<<endl;
        return 0;
    }
    //
    bfs();
    //cout<<vec.size();

}
