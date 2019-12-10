#include<iostream>
using namespace std;
int main(){

    int i,j,n,m;
    cin>>n>>m;
    char a[n][m],b[m];

    for(j=0;j<m;j++)
        b[j]='0';

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]>b[j])
                b[j]=a[i][j];
        }
    }


    int c=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==b[j])
            {
                c++;
                break;
            }
        }
    }

    cout<<c<<endl;

return 0;
}
