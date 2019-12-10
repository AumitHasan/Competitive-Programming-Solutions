#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int

int main()
{
    int T;
    cin>>T;
    while(T--){
        llu n,b,a,c;
        cin>>n>>b;
        if(b>=n){
            cout<<0<<endl;
            continue;
        }

        a = n/b;
        c = n%b;
        c += (a/2)*b;
        if(a%2==1 && a>1) c+= b;
        a/=2;
        //cout<<c<<" "<<a<<endl;
        if(a==0) a = 1;
        cout<<a*c<<endl;
    }
    return 0;
}
