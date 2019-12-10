#include<bits/stdc++.h>
using namespace std;

int ck[1000000];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int ar[m][3];
    int u,v,cst;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&cst);
        ar[i][0] = u;
        ar[i][1] = v;
        ar[i][2] = cst;
     }
     for(int i=1;i<=k;i++)
     {
         scanf("%d",&u);
         ck[u]=1;
     }
     long long mn = 10000000000,c;
     if(k>0){
         for(int i=0;i<m;i++)
         {
             c=0;
             if(ck[ar[i][0]]==1) c++;
             if(ck[ar[i][1]]==1) c++;
             if(c==1){
                if(ar[i][2]<mn) mn = ar[i][2];
             }
         }
     }
     if(mn==10000000000) cout<<"-1"<<endl;
     else cout<<mn<<endl;

return 0;
}

