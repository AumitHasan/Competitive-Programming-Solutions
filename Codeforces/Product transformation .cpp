#include<bits/stdc++.h>
using namespace std;


int ar[1000][1000];

int main()
{
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++) ar[i][j] = 1;

    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            //cout<<ar[i][j]<<" "<<ar[i][j+1]<<endl;
            //getchar();
            ar[i][j] = ar[i-1][j] + ar[i-1][j+1];
        }
    }
    for(int i=1;i<10;i++){
        for(int j=1;j<=10;j++){
            printf("%3d ",ar[i][j]);
        }
        cout<<endl;
    }
}
