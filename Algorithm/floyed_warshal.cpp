#include<bits/stdc++.h>
using namespace std;
#define mx 4
#define mem(a,b) memset(a,b,sizeof(a))
# define INF 0x3f3f3f3f

int cost[mx][mx];

int main()
{
    mem(cost,INF);
    int pth;
    scanf("%d",&pth);
    while(pth--){
        int u,v;
        scanf("%d%d",&u,&v);

        cost[u][v] = 1;
    }
    for(int i=0;i<4;i++) cost[i][i]=0;

    for(int k=0;k<4;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                if(cost[i][k]+cost[k][j]<cost[i][j]) cost[i][j] = cost[i][k]+cost[k][j];
        }

    }
    cout<<" ";
    for(int i=0;i<4;i++) printf("%d ",i);
    cout<<endl;
    for(int i=0;i<4;i++){
        cout<<i<<" ";
        for(int j=0;j<4;j++) printf("%d ",cost[i][j]);
        cout<<endl;

    }

}
