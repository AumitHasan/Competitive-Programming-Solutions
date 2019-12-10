#include<stdio.h>

int main(){

       int tcase,n,a,b,c;
       scanf("%d",&tcase);
       while(tcase>0)
       {
          scanf("%d",&n);
          a=n/2;
          b=n-a;
          printf("%d %d\n",a,b);
       tcase--;
       }
}
