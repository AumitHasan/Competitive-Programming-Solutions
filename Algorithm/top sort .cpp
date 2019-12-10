#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
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

int d[mx],f[mx],vis[mx],somoi;
vector<int>edge[10000];
stack<int>order;

void dfs(int u)
{
    cout<<u<<endl;
    somoi = somoi + 1;
    d[u] = somoi;
    vis[u] = 1;
    for(int i=0;i<edge[u].size();i++){
        if(vis[edge[u][i]] == 0){
            dfs(edge[u][i]);
        }
    }
    somoi = somoi + 1;
    f[u] = somoi;
    order.push(u);
    //cout<<u<<" ";
    return ;
}
void topsort()
{
    somoi = 0;
    mem(vis,0);
    for(int i=1;i<=4;i++){
        if(vis[i] == 0){
            cout<<endl;
            dfs(i);
        }
    }
    // way 1
    cout<<endl;
    while(!order.empty()){
        cout<<order.top()<<" ";
        order.pop();
    }
    cout<<endl;
    for(int i=1;i<=4;i++) cout<<d[i]<<" "<<f[i]<<endl;
}
int main()
{
    edge[2].push_back(1);
    edge[2].push_back(3);
    edge[1].push_back(4);
    edge[3].push_back(4);
    //
    topsort();
    //
    return 0;
}
/*
//
int taken[55] = {};
int n, take[55][55], list[55] ,indegree[55];
int i, j, k;

// when take[a][b] = 1, that means a must come before b
// indegree[i] = number of items that that must come before i
// when taken[i] = 1, means we already have taken ith item
int invalid = 0;
for(i=0; i<n; i++) {
    for(j=0; j<n; j++){

        if( !indegree[j] && !taken[j]    ) {
            taken[j] = 1;
            list[i] = j;
            // in this step we are taking item j
            // we'd update the indegree[k] of items that depended on j
            for(k=0; k<n; k++)
                if( !taken[k] && take[j][k] ) --indegree[k];
            break;
        }
        if( j == n ) {
            invalid = 1;
            break;
        }
    }
}

if( invalid ) printf("There is no solution\n");
else for(i=0; i<n; i++) printf("%d\n", list[i] );
*/
