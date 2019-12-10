#include<bits/stdc++.h>
using namespace std;
#define mx 200017
#define mem(a,b) memset(a,b,sizeof(a))


int n,m,a,b,dis[mx];
vector<int>on[mx],ab[mx];
vector<int>v;
struct st{
    int a,b;
}res[mx];

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
void ab_bfs()
{
    queue<int>Q;
    Q.push(a);


    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0;i<ab[u].size();i++)
        {
            int in = ab[u][i];
            if(res[in].a>res[u].a+1 or res[in].a==0){

                res[in].a = res[u].a+1;
                Q.push(in);
            }
        }
    }
    while(!Q.empty()) Q.pop();
    Q.push(b);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0;i<ab[u].size();i++)
        {
            int in = ab[u][i];
            if(res[in].b>res[u].b+1 or res[in].b==0){

                res[in].b = res[u].b+1;
                Q.push(in);
            }
        }
    }

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
    for(int i=0;i<mx;i++){ res[i].a=res[i].b=0; }
    on_bfs();

    ab_bfs();
    ab_bfs();

    /*for(int i=0;i<=n;i++) printf("%d ",dis[i]);
    cout<<endl;
    for(int i=0;i<=n;i++) printf("%d ",res[i].a);
    cout<<endl;
    for(int i=0;i<=n;i++) printf("%d ",res[i].b);
    cout<<endl;*/
    x = 0;
    res[a].a = res[b].b = 0;
    for(int i=0;i<=n;i++){

        if(res[i].a>0 and res[i].b>0){

            x = res[i].a+res[i].b;
            v.push_back(x+dis[i]);
        }
    }
    if(res[a].a+res[a].b>0){
        x = res[a].a+res[a].b;
        v.push_back(x+dis[a]);
    }
    if(res[b].a+res[b].b>0){
        x = res[b].a+res[b].b;
        v.push_back(x+dis[b]);
    }

    sort(v.begin(),v.end());

    cout<<v[0]<<endl;

return 0;
}
