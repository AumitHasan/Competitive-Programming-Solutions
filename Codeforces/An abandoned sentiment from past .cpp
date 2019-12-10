#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n],b[k];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<k;i++) cin>>b[i];

    if(k>1){
        cout<<"Yes"<<endl;
        return 0;
    }

    if(a[0]==0) a[0]=b[0];
    bool flag = false;
    for(int i=1;i<n;i++){
        if(a[i]==0) a[i]=b[0];

        if(a[i]<=a[i-1]) flag = true;
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
