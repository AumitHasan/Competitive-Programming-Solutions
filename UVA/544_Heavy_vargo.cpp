#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
#define mx 210
#define pr pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))

map<string,int>mp;

struct st{
    int operator()(const pair<int,int>&a , const pair<int,int>&b){
        return a.second < b.second;
    }
}z;
int d[mx],parent[mx],dis[mx][mx];
bool vis[mx];
vector<pr>edg[mx];

int prims(int s,int des)
{
    priority_queue<pr,vector<pr>,st>q;

    for(int i=0;i<mx;i++){ d[i] = 0; vis[i]=false; parent[i]=0;}
    int c=-1;
    parent[s]=0;
    d[s]=0;
    q.push(pr(s,0));
    while(!q.empty())
    {
        c++;
        int u = q.top().first;
        vis[u]=true;
        q.pop();
        //if(c==1) parent[1] = u;
        for(int i=0;i<edg[u].size();i++)
        {
            int v = edg[u][i].first;
            int cost = edg[u][i].second;
             if( (cost>d[v] or d[v]==0) && vis[v]==false){
                d[v] = cost;
                q.push(pr(v,d[v]));
                parent[v]=u;
                dis[u][v]=cost;
                dis[v][u]=cost;
            }
        }
    }


    int mn = INF;
    int a,b=des;
    while(1){
        a = b;
        b = parent[a];
        if(a==0 or b==0) break;
        if(dis[a][b]>0)mn = min(mn,dis[a][b]);
        if(a==s or b==s ) break;
    }
    //cout<<mn<<" ";


    return mn;
}
int main()
{
    int n,r,T=0;
    while(1)
    {

        scanf("%d%d",&n,&r);
        if(n==0 and r==0) break;

        int c=0;
        for(int i=0;i<mx;i++)
            for(int j=0;j<mx;j++) dis[i][j]=0;

        mem(edg,0);
        //cout<<edg[1][6].first<<endl;
        mp.clear();

        for(int i=0;i<r;i++)
        {
            string s,str;
            int cost,u,v;
            cin>>s>>str;
            scanf("%d",&cost);

            if(mp[s]==0) mp[s]=++c;
            u = mp[s];
            if(mp[str]==0) mp[str]=++c;
            v = mp[str];

            edg[u].push_back(pr(v,cost));
            edg[v].push_back(pr(u,cost));
        }
        string a,b;
        cin>>a>>b;
        int s = mp[a];
        int d = mp[b];
        if(s>d) swap(s,d);
        //cout<<s<<" "<<d<<endl;

        int res = prims(s,d);

        printf("Scenario #%d\n",++T);
        printf("%d tons\n",res);
        cout<<endl;
    }

return 0;
}

