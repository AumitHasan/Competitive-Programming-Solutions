#include<stdio.h>
int main(){

   int a,b,test,i,j,sum;

   scanf("%d",&test);

   for(j=1;j<=test;j++)
   {
      scanf("%d %d",&a,&b);
      sum=0;
      for(i=a;i<=b;i++)
      {
         if(i&1)
         {
         sum=sum+i;
         }

      }
      printf("Case %d: %d\n",j,sum);


   }
return 0;
}
