#include<stdio.h>
int main(){

      unsigned int  m,n,x,y,z,r=0,carry=0;
      while(scanf("%u %u",&m,&n)==2)
      {
          if(m==0 && n==0)
              break;
          while(!(m==0 && n==0))
          {
             x=m%10;

             y=n%10;
             m=m/10;
             n=n/10;
             z=x+y;
             if(z>9)
             {
               r=r+1;
               carry++;
             }
             else
                r=0;
          }
            if(carry==0)
               printf("No carry operation.\n",carry);
            else if(carry==1)
                 printf("%u carry operation.\n",carry);
            else
               printf("%u carry operations.\n",carry);
        carry=0;
      }
   return 0;
}
