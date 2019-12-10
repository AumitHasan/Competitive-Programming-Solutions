#include<stdio.h>

int main(){

  int n,a,b,x=0;
  while(scanf("%d",&n)==1){

     if(n==0)
     {
       break;
     }
     while(n>2)
     {
       a=n/3;
       x=x+a;
       b=n%3;
       n=a+b;
       if(n==2)
       {
       n=n+1;
       }
       if(n==1)
       {
         break;
       }
     }

     printf("%d\n",x);
     x=0;
     a=0;
     b=0;
  }
}
