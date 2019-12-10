#include<bits/stdc++.h>
using namespace std;

int main(){

    int test,n,a,d,sum,n2;

    cin>>test;

    while(test--){

        cin>>n>>a>>d;

        sum=n2=0;
        n2=n-1;

        sum = ((n2*n)/2)*d;


        cout<<(a*n)+sum<<endl;

    }


return 0;
}
