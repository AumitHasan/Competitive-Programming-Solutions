#include<stdio.h>

int main(){

    int n,i,c,j=0,k;
    long long p,max;
    while(scanf("%d",&n)==1){

        long long  s[n];
        p=1;
        max=0;
        j++;
        for(i=0;i<n;i++)
            scanf("%lld",&s[i]);

         c=max=0;
        for(i=0;i<n;i++)
        {
           p=1;
           for(k=i;k<n;k++)
           {
                if(s[k]>0)
                {
                    p*=s[k];
                    c=1;
                }


           }
           if(p>=max)
            max=p;
        }
        max*=c;
        printf("Case #%d: The maximum product is %lld.\n",j,max);
        printf("\n");

    }

return 0;
}
