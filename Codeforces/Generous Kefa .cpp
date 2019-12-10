#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,a,f=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a%2==1) f=1;
    }
    if(f) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}
