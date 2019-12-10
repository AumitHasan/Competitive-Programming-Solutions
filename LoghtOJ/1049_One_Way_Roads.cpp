#include<bits/stdc++.h>
using namespace std;
#define mx 101
#define mem(a,b) memset(a,b,sizeof(a))

int cost[mx][mx];
bool vis[mx];
vector<int>v[mx];

int bfs(int s)
{
    queue<int>Q;
    int res=0,c=0;
    mem(vis,false);

    vis[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        int a = Q.front();
        Q.pop();
        c++;
        int ck=0;
        for(int i=0;i<v[a].size() and ck<1;i++){
            int b = v[a][i];
            if(vis[b]==false or (c>2 and b==s)){
                    ck++;

                vis[b] = true;
                Q.push(b);
                if(cost[a][b]<0) res += abs(cost[a][b]);
            }
        }
    }

return res;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T)
    {

        mem(cost,0);
        mem(v,0);


        int t,a,b,c,s1,s2;
        scanf("%d",&t);
        for(int i=0;i<t;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(i==0){
                s1 = a;
                s2 = b;
            }
            cost[a][b] = c;
            cost[b][a] = -c;



             v[a].push_back(b);
           v[b].push_back(a);
        }


        //cout<<endl<<s1<<" "<<s2<<endl;
        int r = bfs(s1);
        int rr = bfs(s2);
        //cout<<r<<" "<<rr<<endl;

        printf("Case %d: %d\n",N,min(r,rr));
    }
return 0;
}
