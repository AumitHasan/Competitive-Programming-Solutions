#include<stdio.h>

long long tens(long long n)
{
    int i,c;
    for( i=1;i<3;i++)
    {
        c=n%10;
        n/=10;
    }
    if(c<0)
        c*=-1;

return c;
}

int main(){

    long long t,n,result;
    scanf("%lld",&t);

    while(t--){

        scanf("%lld",&n);

        result=((((((n*567)/9)+7492)*235)/47)-498);
        printf("%lld\n",tens(result));

    }

return 0;
}

