#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int n,k;
    while(1){
        scanf("%d%d",&n,&k);
        if(n==0 and k==0) break;

        if(k>n-k) k = n-k;
        ll bi=1;
        for(int i=0;i<k;i++){
            bi *= n-i;
            bi /= i+1;
        }
        printf("%lld\n",bi);
    }
}
