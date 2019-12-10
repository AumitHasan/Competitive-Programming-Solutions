#include<bits/stdc++.h>
using namespace std;


int main()
{
    int x,sum=0,n,len;
    cin>>n>>len;
    for(int i=0;i<n;i++){
        cin>>x;
        sum += x;
    }
    sum += n-1;

    if(sum==len) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
