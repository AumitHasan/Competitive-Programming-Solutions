#include<bits/stdc++.h>
using namespace std;

int modx(int x,int y,int n)
{
    if(y==0) return 1;
    if(y%2==0){
        int temp = modx(x,y/2,n);
        return ((temp%n)*(temp%n))%n;
    }
    else return ((x%n)*modx(x,y-1,n))%n;
}
int main()
{
    int t,x,y,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&x,&y,&n);
        int res = modx(x,y,n);
        printf("%d\n",res);
    }
    scanf("%d",&t);
    return 0;
}
