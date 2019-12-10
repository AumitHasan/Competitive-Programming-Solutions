#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;

    if(n==1){
        cout<<0<<endl;
    }
    else if(n==2){
        cout<<min(a,b)<<endl;
    }
    else{
        if(c<a && c<b){
            n-=2;
            //cout<<min(a,b)<<" "<<(n*c)<<endl;
            int ans =  min(a,b) + (n*c) ;
            cout<<ans<<endl;
        }
        else{
            n--;
            cout<<n*min(a,b)<<endl;
        }
    }
}
