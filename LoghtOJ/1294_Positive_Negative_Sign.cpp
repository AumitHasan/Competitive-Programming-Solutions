#include<bits/stdc++.h>
using namespace std;

int main(){

    long test,m,n,x,y,dif,sum,res;

    cin>>test;
    for(int i=1;i<=test;i++){

        m=n=res=x=y=0;
        cin>>m>>n;

        x=(2*n*((2*n)+1))/2;
        y=(n*(n+1)/2)*2;

        dif=x-y;

        res=((m/n)/2)*dif;

        cout<<"Case "<<i<<": "<<res<<endl;

    }

return 0;
}
