#include<iostream>
using namespace std;
#include<stdio.h>

long a, b, c, d, e, f;
long fn( long n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
}
int main() {
    long n, caseno = 0, cases;
    scanf("%ld", &cases);
    while( cases-- ) {
        scanf("%ld %ld %ld %l %ld %ld %ld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %ld: %ld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
