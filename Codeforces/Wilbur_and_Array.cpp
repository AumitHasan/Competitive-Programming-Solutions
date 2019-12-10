#include<bits/stdc++.h>
using namespace std;
int main(){

    long long int n=0,i,x,c,v;
    cin>>n;
    long long int a[n],b[n];

    for(i=0;i<n;i++){

        b[i]=0;
        cin>>b[i];
      //  cout<<b[i]<<" ";
        a[i]=0;
    }

    x=c=v=0;

    for(i=0;i<n;i++){

        if(b[i]==x)
            continue;
       // cout<<endl<<v<<" "<<c<<" "<<b[i]<<endl;

        if(b[i]>=0)
        {
            v=b[i]-x;
            if(v<0)
                v*=-1;
            c+=v;
            x=0;
            x=b[i];
           // cout<<x<<" "<<c<<endl;
        }else{

            v=x-b[i];
            if(v<0)
                v*=-1;
            c+=v;
            x=0;
            x=b[i];
           // cout<<x<<" "<<c<<endl;

        }

        v=0;

    }

    cout<<c<<endl;



return 0;
}
