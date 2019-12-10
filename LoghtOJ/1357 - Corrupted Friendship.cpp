#include<bits/stdc++.h>
using namespace std;
#define mx 100003
#define mem(a,b) memset(a,b,sizeof(a))

int strt[mx],vis[mx],level[mx],dis[mx];
vector<int>edge[mx];

int bfs(int s)
{
    queue<int>q;
    int c=1;
    dis[s]=1;
    level[1]=1;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<edge[x].size();i++){
            int y = edge[x][i];

                dis[y]=dis[x]+1;
                level[dis[y]]++;
                c++;
                q.push(y);

        }
    }
    return c;
}
int main()
{
    int T,N=0,a,b;
    scanf("%d",&T);
    while(++N<=T){
        mem(edge,0);
        mem(dis,0);
        int f,in=-1;
        scanf("%d",&f);
        for(int i=1;i<f;i++){
            scanf("%d%d",&a,&b);
            if(a==1) strt[++in]=b;
            edge[a].push_back(b);
        }
        int prf[in+1];
        int invt=0,pr=0;
        for(int i=0;i<=in;i++){
            int fc = bfs(strt[i]);
            prf[i]=fc;
            invt+=fc;
        }
        sort(prf,prf+in+1);
        if(in==0){
            int idx=1;
            while(level[idx]>0) ++idx;
            //cout<<idx<<endl;
            for(int i=1;i<idx/2+1;i++){
                for(int j=1;j<idx-1;j++){
                    if(level[j]>0 and j+2<idx){
                        if(level[j]>=level[j+2]){
                            level[j]-=level[j+2];
                            pr += level[j+2];
                        }
                        else{
                            pr += level[j];
                            level[j+2]-=level[j];
                        }
                    }
                }
            }
            mem(level,0);
        }
        else{
            for(int i=0;i<in;i++){
                if(prf[i]>0){
                    pr += prf[i];
                    prf[i+1]-=prf[i];
                }
            }
        }
        printf("Case %d: %d %d\n",N,invt,pr);
    }
    return 0;
}
