#include<bits/stdc++.h>
using namespace std;
#define mx 200017
#define mem(a,b) memset(a,b,sizeof(a))


int com[mx],n,m,a,b,dis[mx],vis[mx],res[mx],mn=10000000;
vector<int>on[mx],ab[mx];
vector<int>v;

void on_bfs()
{
    queue<int>Q;
    Q.push(0);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0;i<on[u].size();i++)
        {
            int in = on[u][i];
            if(dis[u]+1<dis[in] or dis[in]==0){

                dis[in] = dis[u]+1;
                Q.push(in);
            }
        }
    }
}
void clr()
{
    for(int i=0;i<=n;i++) res[i]=0;
}
void ab_bfs(int src)
{
    queue<int>Q;
    Q.push(src);


    while(!Q.empty())
    {
        int u = Q.front();
        int c=0;
        Q.pop();
        for(int i=0;i<ab[u].size();i++)
        {
            int in = ab[u][i];
            if(vis[in]==0){

                com[in]++;
                vis[in]=1;
                Q.push(in);
            }
        }
    }
}
int final_bfs(int src)
{
    clr();
    queue<int>Q;
    Q.push(src);


    while(!Q.empty())
    {
        int u = Q.front();
        int c=0;
        Q.pop();
        for(int i=0;i<on[u].size();i++)
        {
            int in = on[u][i];
            if(res[u]+1<res[in] or res[in]==0){

                res[in] = res[u]+1;
                Q.push(in);
            }
        }
    }
    res[src] = 0;
    int x = res[a]+res[b];
    if(mn>x) mn = x;
    return res[a]+res[b];
}
int main()
{
    scanf("%d %d %d %d",&n ,&m ,&a ,&b);

    int x,y;
    for(int i=0;i<m;i++){
        scanf("%d %d",&x ,&y);
        on[x].push_back(y);
        ab[y].push_back(x);
        //if(x==a) com[a] = 2;
        //if(x==b) com[b] = 2;
    }
    on_bfs();
    ab_bfs(a);
    for(int i=0;i<=n;i++) vis[i]=0;
    ab_bfs(b);
    //cout<<endl;
    int val;
    for(int i=1;i<=n;i++){

        if(i==a or i==b or com[i]>=2){
            if(dis[a]<mn){
                val = final_bfs(i);
                //cout<<i<<" "<<val<<endl;
                if(val>0) v.push_back(val+dis[i]);
            }
        }
    }
    sort(v.begin(),v.end());
    cout<<v[0]<<endl;

return 0;
}
