#include<stdio.h>

int main(){

     int n,k,sum;

     while(scanf("%d %d",&n,&k)==2)
     {

         sum=n;

         while(n>=k)
         {

            sum=sum+(n/k);
            n=(n/k)+(n%k);
         }
         printf("%d\n",sum);
         sum=0;
     }

     return 0;
}
