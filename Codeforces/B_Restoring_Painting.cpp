#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n,a,b,c,d,i,j,k,l,ii,jj,kk,lll;
    cin>>n>>a>>b>>c>>d;

        i = a+b+1;
        j = b+d+1;
        k = d+c+1;
        l = a+c+1;

        ll m = max(max(i,j),max(k,l));

        m++;
        ii = m-i;
        jj = m-j;
        kk = m-k;
        lll = m-l;

        ll mm = max(max(ii,jj),max(kk,lll));

        if(mm>n) cout<<"0"<<endl;
        else cout<<n*(n-mm+1)<<endl;



return 0;
}
