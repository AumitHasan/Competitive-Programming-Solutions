#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,ar[104],t,day,s=86400;

    cin>>n>>t;
    for(int i=1;i<=n;i++) scanf("%d",&ar[i]);

    for(int i=1;i<=n;i++){
        t -= (s-ar[i]);
        if(t<=0){
            cout<<i<<endl;
            return 0;
        }
    }
}
