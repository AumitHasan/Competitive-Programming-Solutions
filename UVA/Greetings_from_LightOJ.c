#include<stdio.h>

int main(){

       int tcase,t=1,a,b;
       scanf("%d",&tcase);
       while(t<=tcase)
       {
          scanf("%d %d",&a,&b);
          if(a<10 && b<10)
             printf("Case %d: %d\n",t,a+b);


       t++;
       }
}

