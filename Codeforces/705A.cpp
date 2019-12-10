#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s ="I hate";
    string str = "I love";
    string ch = " that ";

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i>1) cout<<ch;
        if(i%2==0) cout<<str;
        else cout<<s;
    }
    cout<<" it"<<endl;
return 0;
}
