#include<bits/stdc++.h>
using namespace std;
#define mx 1000000
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pr pair<ll,ll>
void print(ll i);

vector<pr>edg[mx];
map<ll,ll>path,d;
ll n,m;

struct st{
    int operator()(const pair<ll,ll>&a,const pair<ll,ll>&b)
    {
        return a.second>b.second;
    }
}sc;

void dijkstra()
{
    priority_queue<pr,vector<pr>,st>q;
    d[1]=0;
    path[1]=1;
    q.push(pr(1,0));
    while(!q.empty())
    {
        ll u = q.top().first;
        q.pop();
        for(int i=0;i<edg[u].size();i++){
            ll v = edg[u][i].first;
            ll cost = edg[u][i].second;
            if(d[u]+cost<d[v] or d[v]==0){
                path[v] = u;
                d[v] = d[u]+cost;
                q.push(pr(v,d[v]));
            }
        }
    }
    if(d[n]==0){
        printf("-1\n");
    }
    else{
        print(path[n]);
        cout<<n<<endl;
    }
}
void print(ll i)
{
    if(i==1){
        printf("1 ");
        return;
    }
    print(path[i]);
    //printf("%I64 ",i);
    cout<<i<<" ";
}
int main()
{
    ll u,v,cost;
    //scanf("I64 I64",&n,&m);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        scanf("%I64d %I64d %I64d",&u,&v,&cost);
        edg[u].push_back(pr(v,cost));
        edg[v].push_back(pr(u,cost));
    }
    dijkstra();

return 0;
}
