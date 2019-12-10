#include<bits/stdc++.h>
using namespace std;

long long int sum,n,w,a,b,c;

int main()
{
    cin>>w>>n;
    while(n--){
        cin>>a>>b;
        sum += a*b;
    }
    cout<<sum/w<<endl;
}
