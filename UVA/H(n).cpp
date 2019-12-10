#include<bits/stdc++.h>
using namespace std;

long long H(int n){

     long long res = 0;

     for( int i = 1; i <=sqrt(n); i=i+1 ){

            res = (res + n/i);

      }
      long long r = sqrt(n);
      res = (2*res) - (r*r);

     return res;

}

int main(){

    long long T,n;
    cin>>T;
    while(T--){

        scanf("%lld",&n);
        printf("%lld\n",H(n));
    }

return 0;
}
