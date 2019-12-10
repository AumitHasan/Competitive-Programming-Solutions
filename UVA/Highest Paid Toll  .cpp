#include<bits/stdc++.h>
using namespace std;

#define pr pair<int,int>
#define mx 100007
#define mem(a,b) memset(a,b,sizeof(a))

struct st{
    int u,v,c;
    bool operator<(const st& nw) const
    {
        return c>nw.c;
    }
}val;

int S,D,tk,d[mx],dis[mx],n,e,src,des;

vector<pr>edge[mx],rev[mx];
vector<st>vec;

struct rc{
    int operator()(const pair<int,int>&a1,const pair<int,int>&a2){
        return a1.second>a2.second;
    }
}z;

void dijkstra_2(int src,int des)
{
    priority_queue<pr,vector<pr>,rc>q;


    dis[src]=0;
    q.push(pr(src,0));
    while(!q.empty())
    {
        int x = q.top().first;
        q.pop();
        for(int i=0;i<rev[x].size();i++)
        {
            int u = rev[x][i].first;
            int cost = rev[x][i].second;
            //cout<<u<<" "<<cost<<endl;
            if(dis[x]+cost<dis[u] || dis[u]==-2){
                dis[u] = dis[x]+cost;
                if(dis[u]<=tk) q.push(pr(u,dis[u]));
            }
        }
    }
    //cout<<endl;
    //cout<< dis[1]<<" "<<dis[2]<<" "<<dis[3]<<" "<<dis[4]<<" "<<dis[5]<<endl;
}
void dijkstra_1(int src,int des)
{
    priority_queue<pr,vector<pr>,rc>q;


    d[src]=0;
    q.push(pr(src,0));
    while(!q.empty())
    {
        int x = q.top().first;
        q.pop();
        for(int i=0;i<edge[x].size();i++)
        {
            int u = edge[x][i].first;
            int cost = edge[x][i].second;
            //cout<<d[x]<<" X "<<cost<<" "<<d[u]<<endl;
            if(d[x]+cost<d[u] || d[u]==-2){
                d[u] = d[x]+cost;
                if(d[u]<=tk) q.push(pr(u,d[u]));
            }
        }
    }
    //cout<<endl;
    //cout<< d[1]<<" "<<d[2]<<" "<<d[3]<<" "<<d[4]<<" "<<d[5]<<endl;
}

int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d %d",&n,&e);
        scanf("%d%d",&S,&D);
        scanf("%d",&tk);

        mem(edge,0);
        mem(rev,0);
        vec.clear();
        val.c = val.u = val.v = 0;
        vec.push_back(val);

        for(int i=0;i<e;i++){
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            val.u = u; val.v = v; val.c = cost;
            vec.push_back(val);
            edge[u].push_back(pr(v,cost));
            rev[v].push_back(pr(u,cost));
        }

        for(int i=0;i<=n;i++){
            d[i]=dis[i] = -2;
        }


        dijkstra_1(S,D);
        dijkstra_2(D,S);


        sort(vec.begin(),vec.end());

            int res = -1;
            for(int i=0;i<e;i++){

                if(d[vec[i].u] > -2 && dis[vec[i].v] > -2){
                    long long int  cst = d[vec[i].u] + dis[vec[i].v] + vec[i].c;
                    if(cst<=tk){
                        res = max(res,vec[i].c);

                    }
                }

            }
            printf("Case %d: %d\n",N,res);

    }

return 0;
}
