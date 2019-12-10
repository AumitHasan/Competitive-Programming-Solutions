#include<bits/stdc++.h>
using namespace std;
#define lim (1<<15)+100
#define mem(a,b) memset(a,b,sizeof(a))

int dis[lim],m,n,pw[18];
bool vis[lim];
vector<int>v[41];

void bfs()
{
    mem(vis,0);
    mem(dis,0);

    queue<int>Q;
    Q.push(0);
    vis[0]=1;

    while(!Q.empty()){

        int u = Q.front();
        Q.pop();

        for(int i=0;i<m;i++){

            int a = u;
            for(int j=0;j<v[i].size();j++){
                int pos = v[i][j];
                if(!(a & (1<<pos))){
                    a |= (1<<pos);
                }
                else a ^= (1<<pos);
            }

            if(vis[a]==0){
                dis[a] = dis[u]+1;
                vis[a] = 1;
                Q.push(a);
            }

        }
    }
}
void power()
{
    pw[0] = 1;
    for(int i=1;i<18;i++) pw[i] = pw[i-1]*2;
}
int main()
{
    power();

    int T,N=0,x,y;
    scanf("%d",&T);
    while(++N<=T){

        mem(v,0);
        scanf("%d %d",&n ,&m);

        for(int i=0;i<m;i++){
            scanf("%d",&x);
            for(int j=0;j<x;j++){
                scanf("%d",&y);
                v[i].push_back(y);
            }
        }
        //cout<<"DFL";
        bfs();

        printf("Case %d:\n",N);

        int q;
        string ch;
        scanf("%d",&q);

        while(q--){
             cin>>ch;
             reverse(ch.begin(),ch.end());
             int bulb=0;
             for(int i=0;i<n;i++){
                 bulb += pw[i]*(ch[i]-48);
             }
             if(vis[bulb]==0) printf("-1\n");
             else printf("%d\n",dis[bulb]);
        }
        printf("\n");
    }
    return 0;
}

