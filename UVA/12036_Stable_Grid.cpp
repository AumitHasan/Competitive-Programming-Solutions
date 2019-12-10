#include<bits/stdc++.h>
using namespace std;

#define mem(a) memset(a,0,sizeof(a))

int main(){

    int T,N=0;
    cin>>T;
    while(++N<=T)
    {
        int grid;
        scanf("%d",&grid);
        int g[grid][grid];
        int check[100];
        mem(check);

        for(int i=0;i<grid;i++)
        {
            for(int j=0;j<grid;j++){
                scanf("%d",&g[i][j]);
                ++check[g[i][j]];
            }
        }
        int c=0;
        for(int i=0;i<100;i++)
            if(check[i]>grid){
                c=1;
                break;
            }

        if(c==1) printf("Case %d: no\n",N);
        else printf("Case %d: yes\n",N);


    }

return 0;
}
