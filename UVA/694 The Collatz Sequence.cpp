#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll a,L,t=0,n;
    while(1){
        scanf("%lld%lld",&a,&L);
        if(a<0 and L<0) break;
        n=a;

        ll c=1;
        while(1){
            if(a%2==0) a/=2;
            else a = 3*a+1;
            if(a>L or a==1) break;
            c++;
        }
        if(a==1) c++;
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",++t,n,L,c);
    }
    return 0;
}
