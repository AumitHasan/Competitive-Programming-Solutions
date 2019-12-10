#include<bits/stdc++.h>
using namespace std;

int main(){

    long n,root,value,i,j,c=0;

    cin>>n;

    double x=pow(n,1.0/3);

    long y = static_cast<long>(x + 0.5);

    for(i=2;i<=y;i++)
    {
        value=0;
        for(j=1;j<=5;j++)
        {
            value+=pow(i,3);
            if(value==n){
                c++;
                cout<<i<<endl;
                break;
            }
            if(value>n)
                break;
        }
    }

    cout<<c<<endl;
}
