#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int x = 240-k;
    int c=0,res=0;
    for(int i=1;i<=n;i++){

        res += i*5;
        if(res<=x) c++;
        else break;
    }
    cout<<c<<endl;
}
