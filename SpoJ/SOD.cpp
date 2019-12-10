#include<bits/stdc++.h>
using namespace std;

int main(){

    long t,n,i,summation;
    cin>>t;
    while(t--)
    {
        cin>>n;
        summation=1;
        for(i=2;i*i<=n;i++)
        {
           if(n%i==0)
                summation+=i+n/i;
        }

        if((i-1)*(i-1)==n)
            summation-=i-1;

        cout<<summation<<endl;
    }


return 0;
}
