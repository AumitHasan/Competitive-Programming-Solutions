#include<bits/stdc++.h>
using namespace std;
int main(){

    long p,x,n,a,b,c,d,e;

    cin>>p>>n>>x;
    a=b=c=d=e=0;

    if(x<p){

        cout<<x<<endl;
        return 0;
    }

    a=x/p;

    if(a*p == x){

        cout<<a<<endl;

    }else{

        b = a*p;
        c = b+p-1;

        d = a+(x-b);
        e = a+(c-x)+1;

        if(d>e)
            cout<<e<<endl;
        else
            cout<<d<<endl;


    }


return 0;
}
