#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,x,res;

    scanf("%lld",&n);

    if(n%2==0)
    {
        x=n/2;
        if(x%2==0) res = x/2-1;
        else if(x%2!=0) res = x/2;

        cout<<res<<endl;
    }
    else cout<<"0"<<endl;

return 0;
}
