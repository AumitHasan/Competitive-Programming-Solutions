#include<iostream>

using namespace std;

int main(){

    int c,i,n,m,j;
    cin>>n>>m;

    char a[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;i<m;j++)
            scanf("%c",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;i<m;j++)
            printf("%c",a[i][j]);
        printf("\n");
    }

return 0;
}
