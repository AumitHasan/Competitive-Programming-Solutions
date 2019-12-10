#include<bits/stdc++.h>
using namespace std;

int main(){

    int T,i,j,k,r,c;
    cin>>T;
    while(T--){

        cin>>r>>c;
        int a[r][c];
        int x[]={-1,0,1};


        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
                scanf("%d",&a[i][j]);
        }


        for(i=0;i<r;i++)
        {

            for(j=0;j<c;j++)
            {
                int check = a[i][j];
                for(k=0;k<3;k++)
                {
                    int rr = i-1;
                    int cc = j+x[k];

                    if(rr>=0 && cc>=0 && cc<c)
                        a[i][j] = max(a[i][j], a[rr][cc]+check);
                }
            }

        }
        int value = 0;
        for(i=0;i<c;i++)
        {
            if(a[r-1][i]>value)
                value = a[r-1][i];

        }

        cout<<value<<endl;
    }
}
