#include<stdio.h>
int main(){

    long long t,a,b;
    scanf("%lld",&t);

    while(t--){

        scanf("%lld %lld",&a,&b);

        if(a>b)
            printf(">\n");
        else if(a<b)
            printf("<\n");
        else
            printf("=\n");

    }

return 0;
}
