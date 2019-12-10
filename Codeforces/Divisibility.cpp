#include<bits/stdc++.h>
using namespace std;
int main(){

    long long int k,a,b,i=1,j,c=0;

    cin>>k>>a>>b;

    if(a<=0)
    {
        i=0;
        for(i=a;i<=0;i++)
        {
            if(i%k==0)
                c++;
        }
    }

    for(j=i;j<=b;j++)
    {
            if(j%k==0)
                c++;
    }

    cout<<c<<endl;


return 0;
}
