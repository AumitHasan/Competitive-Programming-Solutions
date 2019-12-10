
#include<bits/stdc++.h>
using namespace std;
#define row 10001
long arr[row];

long a, b, c, d, e, f;
long fn( long n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;

    if(arr[n] != -1) return arr[n];

     arr[n] = (fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%10000007;

return arr[n];
}
int main() {
    long n, caseno = 0, cases;
    scanf("%ld", &cases);
    while( cases-- ) {
    for(long i=0;i<row;i++)
        arr[i]=-1;

        scanf("%ld %ld %ld %ld %ld %ld %ld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %ld: %ld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
