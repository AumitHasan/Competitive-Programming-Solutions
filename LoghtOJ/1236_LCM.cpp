#include <bits/stdc++.h>
using namespace std;

long long pairsFormLCM( long long n ) {

    long long res = 0,i;

    for(i = 1; i <= n; i++ ){

        if(n%i==0)
            res++;
    }
    return res;
}


int main(){

    long long test,i,n,l;
    //scanf("%lld",&test);
    ios::sync_with_stdio(0);
    test=1;
    for(i=1;i<=test;i++){

       //scanf("%lld",&n);
        n=60850052705442;
       //n=29;
        printf("Case %lld: %lld\n",i,pairsFormLCM(n));
        n=0;

    }


return 0;
}
