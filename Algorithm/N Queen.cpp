#include<bits/stdc++.h>
using namespace std;
#define mx 100
#define m 5

int row[mx],col[mx],dig[mx],ndig[mx];
int chess[mx],way,j,x,y;

bool check(int i,int j,int n)
{
    if(col[j]==0 and dig[i+j]==0 and ndig[n+j-i]==0)return false;
    return true;
}
void backtrack(int i,int n)
{
    if(i>x){
        if(chess[x] != y) return;
    }
    if(i==n+1){
        for(int j=1;j<=n;j++) printf("%d ",chess[j]);
        printf("\n");
        way++;
        return;
    }
    for(int j=1;j<=n;j++){

        if(!check(i,j,n)){

            col[j] = dig[i+j] = ndig[n+j-i] = 1;
            chess[i] = j;
            backtrack(i+1,n);
            col[j] = dig[i+j] = ndig[n+j-i] = 0;
        }
    }
}
int main()
{
    x=0;
    y=0;
    backtrack(1,8);
    cout<<way<<endl;
}


