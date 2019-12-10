#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>            pr;

#define pf(a)                   cout<<a<<endl
#define sci(a)                  scanf("%d",&a)
#define scii(a, b)              scanf("%d %d",&a, &b)
#define sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define scl(a)                  scanf("%lld", &a)
#define scll(a, b)              scanf("%lld %lld", &a, &b)
#define sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define umap                    unordered_map
#define mem(a,b)                memset(a,b,sizeof(a))
#define IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)

#define mx                      1000007
#define mod                     1000000007
#define base                    10000007
#define eps                     1e-9
#define INF                     1llu<<61
#define inf                     1<<29
#define PI                      acos(-1.0) //3.14159.....

////

int m,n,k,src,des,cost[10005],pre[mx];
bool flag[mx];
vector<pr>adj[10005];



void dfs(int u,int use,ll val,last)
{

}
void seive()
{
    for(int i=1;i<mx;i++) pre[i] = 1e9;
    flag[1] = 1;
    for(int i=4;i<mx;i+=2){
        pre[i] = i/2 + 4;
        flag[i] = 1;
    }
    for(int i=3;i*i<mx;i+=2){
        if(!flag[i]){
            for(int j=i*2;j<mx;j+=i){
                flag[j] = 1;
                pre[j] = min(pre[j], j/i + 2*i);
            }
        }
    }
}
void reff()
{
    for(int i=1;i<=n;i++){
        cost[i] = 2e9;
    }
}
int main()
{
    int u,v,tk;
    seive();
    //cout<<pre[18];
    int t;
    sci(t);
    while(t--){
        sciii(n,m,k);
        while(m--){
            sciii(u,v,tk);
            adj[u].push_back(pr(v,tk));
            adj[v].push_back(pr(u,tk));
        }
        scii(src,des);
        reff();
        bfs();
        cout<<cost[des]<<endl;
        for(int i=1;i<=n;i++) cout<<cost[i]<<" ";
    }
}
