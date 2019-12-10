#include <stdio.h>

int main()
{
   int test,a[3],i,c,count=0;
   scanf("%d",&test);

   while(test>=1)
   {
      c=0;

        for(i=1;i<=3;i++)
        {
           scanf("%d",&a[i]);
           if(a[i]==1)
              c++;
        }
      if(c>=2)
         count++;

   test--;
   }
printf("%d",count);
return 0;
}

