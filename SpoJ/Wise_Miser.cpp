#include<bits/stdc++.h>
using namespace std;

int main(){

    int i,j,k,r,c;

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

                    if(j==0 && k==0){
                        if(rr>=0)
                        a[i][j] = a[rr][j]+check;
                        k++;
                        continue;
                    }
                    if(k==0 && j>0){
                        if(rr>=0 && cc>=0 && cc<c)
                        a[i][j] = a[rr][cc]+check;
                        continue;
                    }


                    if(rr>=0 && cc>=0 && cc<c)
                        a[i][j] = min(a[i][j], a[rr][cc]+check);
                }
            }

        }
        int value = a[r-1][0];
        for(i=0;i<c;i++)
        {

            if(a[r-1][i]<value)
                value = a[r-1][i];

        }

        cout<<value<<endl;

return 0;
}

