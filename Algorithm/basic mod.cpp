#include<bits/stdc++.h>
using namespace std;

int m;

int pow(int x,int y)
{
    if(y==0) return 1;
    if(y%2==0){
        int temp = pow(x,y/2);
        return ((temp%m)*(temp%m))%m;
    }
    else return ((pow(x,y-1)%m)*(x%m))%m;
}
int main()
{
    int x,y;
    cin>>x>>y>>m;
    cout<<pow(x,y)<<endl;
}
