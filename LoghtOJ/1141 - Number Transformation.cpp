#include<bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define mx 1003
#define pr pair<int,int>

bitset<mx>mark;
int fact[1003][100];
int prime[169],dis[1003];

int bfs(int src,int dst)
{
    int vis[1003]={0};
    mem(dis,0);
    queue<int>q;
    q.push(src);
    dis[src]=0;
    vis[src]=1;
    while(!q.empty()){
        int p = q.front();
        q.pop();

        for(int i=0;i<50 and fact[p][i]>0;i++){
            int x = fact[p][i];

            //cout<<x<<" "<<dis[p]<<" "<<dis[x]<<endl;
            if(p+x==dst){
               // cout<<p+x<<endl;
                return dis[p]+1;
            }
            if(vis[p+x]==0){
                dis[x+p] = dis[p]+1;
                if(p+x<dst){
                    q.push(p+x);
                    vis[p+x]=1;
                }
            }
           // cout<<p+x<<endl;
        }

    }
    return -1;
}
void seive()
{
    int in=-1;
    prime[++in]=2;
    mark[0]=mark[1]=1;
    for(int i=4;i<mx;i+=2) mark[i]=1;
    for(int i=3;i<=33;i+=2){
        if(mark[i]==0){
            prime[++in]=i;
            for(int j=i*i;j<mx;j+=2*i) mark[j]=1;
        }
    }
    for(int i=35;i<mx;i+=2){
        if(mark[i]==0) prime[++in]=i;
    }
    prime[++in]=1009;
    //cout<<prime[in]<<" "<<in<<endl;
}
void pf()
{
    for(int i=2;i<=1000;i++){
        if(mark[i]==1){
            int in = -1;
            int n=i;
            for(int j=0;j<169 and prime[j]*prime[j]<=n;j++){
                if(n%prime[j]==0){
                    fact[i][++in]=prime[j];
                    while(n%prime[j]==0){
                        n/=prime[j];
                    }
                }
            }
            if(n>1 and n!=i) fact[i][++in]=n;
        }
    }
}
int main()
{
    seive();
    pf();
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        int s,t,res;
        scanf("%d%d",&s,&t);
        if(s==t) res=0;
        else res = bfs(s,t);
        printf("Case %d: %d\n",N,res);
    }
}
