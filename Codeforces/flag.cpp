#include<iostream>
using namespace std;
#include<string.h>
int main(){

    int c=0,i,n,m,j;
    cin>>n>>m;

    char a[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(j>0)
            {
                if(a[i][j-1] != a[i][j])
                    c=1;
            }
        }
    }
    if(c!=1)
    {
        for(i=1;i<n;i++)
        {
            for(j=i-1;j<=i+1;j++)
            {
                if(j==m)
                    break;
                if(i==j)
                    continue;

                if(a[i][0] == a[j][0])
                    c=1;
            }
        }
    }

    if(c==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

return 0;
}
