#include<stdio.h>
int main()
{
 unsigned long long int n,p,i,result;

  while((scanf("%llu %llu",&n,&p))==2)
  {
     for(i=1;p>result;i++)
     {

       result=pow(i,n);
     }
     printf("%llu\n",i-1);
  }
}
