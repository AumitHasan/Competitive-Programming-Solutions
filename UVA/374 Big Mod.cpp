#include<bits/stdc++.h>
using namespace std;

int b,p,m;

int mod_pow(int x,int y)
{
    if(y==0) return 1;
    if(y%2==0){
        int temp = mod_pow(x,y/2);
        return ((temp%m)*(temp%m))%m;
    }
    else return ((x%m)*(mod_pow(x,y-1)%m))%m;
}
int main()
{
    while(~scanf("%d%d%d",&b,&p,&m)){

        int r = mod_pow(b,p);
        printf("%d\n",r);
    }
}
