#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("out.txt","w",stdout);

    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a>b) cout<<-1<<endl;
        else if(b%a==0) cout<<a<<" "<<b<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
