#include<stdio.h>
long reverse(long number);
 main(){

      long number,r;
      while(scanf("%ld",&number)==1)
      {

          r=0;
          if(number<=0)
            break;
         if(number>0 && number<10)
            r=number;
         while(number>=10)
         {
             r=reverse(number);
             number=r;

         }
         printf("%ld\n",r);
         number=0;

      }
      return 0;


}

long reverse(long number){

     long sum=0;
     while(number>0)
     {
         sum=sum+(number%10);
         number/=10;
     }

     return sum;

}
