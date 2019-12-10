#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        printf("Case %d:\n",N);
        ll n,sum=0,x;
        string s;
        scanf("%lld",&n);
        while(n--){
            cin>>s;
            if(s=="donate"){
                scanf("%lld",&x);
                sum += x;
            }
            else if(s=="report") cout<<sum<<endl;
        }
    }
    return 0;
}
