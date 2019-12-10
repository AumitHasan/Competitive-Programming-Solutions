#include<bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define mx 4

int m[mx][mx],path[mx][mx];
int in = 10000;

int main()
{
    for(int i=0;i<mx;i++)
        for(int j=0;j<mx;j++){
            if(i==j) m[i][j]=0;
            else m[i][j]=in;
        }

    int E;
   scanf("%d",&E);
   for(int i=0;i<E;i++)
   {
        int u,v,cost;
        scanf("%d%d%d",&u,&v,&cost);
        m[u][v]=cost;
        m[v][u]=cost;
   }

   for(int i=0;i<mx;i++){
        for(int j=0;j<mx;j++) cout<<m[i][j]<<" ";
    cout<<endl;
   }
   cout<<endl;

   for(int k=0;k<mx;k++)
   {
       for(int i=0;i<mx;i++)
       {
           for(int j=0;j<mx;j++){
                if(m[i][k]+m[k][j]<m[i][j]){
                    m[i][j] = m[i][k]+m[k][j];
                    path[i][j] = path[i][k];
                }
           }
       }
   }

   for(int i=0;i<mx;i++){
        for(int j=0;j<mx;j++) cout<<m[i][j]<<" ";
    cout<<endl;
   }
   cout<<m[2][3]<<endl;

return 0;
}
