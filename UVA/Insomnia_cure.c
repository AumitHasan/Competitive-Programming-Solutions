#include<stdio.h>
int main(){

        long k,l,m,n,d,i,hunt=0;

        scanf("%ld %ld %ld %ld %ld",&k,&l,&m,&n,&d);

        for(i=1;i<=d;i++)
        {
            if(i%k==0 || i%l==0 || i%m==0 || i%n==0)
                hunt++;

        }


    printf("%ld",hunt);
return 0;
}
