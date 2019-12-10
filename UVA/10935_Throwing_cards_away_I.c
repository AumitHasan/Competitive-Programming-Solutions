#include<stdio.h>
int main(){

    long n,i,j,k,m,c,d;


    while(scanf("%ld",&n)==1)
    {
        if(n==0)
            break;

        long a[n];

        if(n==1)
        {
            a[1]=1;
            printf("Discarded cards:\n");
            printf("Remaining card: %ld\n",a[1]);
            continue;
        }

        c=2;
        d=1;

        printf("Discarded cards: ");
        for(i=1;d<=n;i++)
        {
            printf("%ld",d);
            if(d<n-1)
                printf(", ");
            d+=2;
        }


        for(i=1;i<=n/2;i++)
        {
            a[i]=c;
            c+=2;
        }


        k=n/2;
        m=k;

        if(n%2 != 0) // for odd n
            j=1;
        else         //for even n
            j=2;

        d=1;
        if(n%2 != 0)
            d=2;

        for(i=1;i<k;i++)
        {
            m++;
             if(i<k)
               printf(", ");

            printf("%ld",a[d]);


            a[m]=a[j];
            j+=2;
            d+=2;
        }

        printf("\nRemaining card: %ld\n",a[m]);
        m=0;
        n=0;
    }

return 0;
}

