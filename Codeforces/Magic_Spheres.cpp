#include<bits/stdc++.h>
using namespace std;

int main(){

    long a[3],x[3],i,j,value=0,v=0,c;

    cin>>a[0]>>a[1]>>a[2];
    cin>>x[0]>>x[1]>>x[2];

    for(i=1;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           v=0;
            if(a[j]>x[j]){
                v=a[j]-x[j];
                a[j]=x[j];
                value+=v/2;
            }
            else if(a[j]<x[j]){
                v=x[j]-a[j];
                if(v<=value)
                {
                    a[j]=x[j];
                    value-=v;
                }
            }

        }

    }

    if(a[0]==x[0] && a[1]==x[1] && a[2]==x[2])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

return 0;
}
