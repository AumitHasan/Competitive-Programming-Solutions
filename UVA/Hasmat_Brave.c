#include<stdio.h>
int main(){

     long  h,o;
     while(scanf("%ld %ld",&h,&o)==2)
     {

           if(h<o)
             printf("%ld\n",(o-h));
           else
             printf("%ld\n",(h-o));

     }
     return 0;
}
