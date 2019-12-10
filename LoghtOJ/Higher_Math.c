#include<stdio.h>
int main()
{
     int a,b,c,test,angle,i;

     scanf("%d",&test);

     for(i=1;i<=test;i++)
     {

       scanf("%d %d %d",&a,&b,&c);


          if (a<=0 || b<=0 ||c<=0)
                     printf("Case %d: no\n",i);

          else if (a*a==b*b+c*c)
                     printf("Case %d: yes\n",i);

          else if (b*b==a*a+c*c)
                    printf("Case %d: yes\n",i);

          else if (c*c==a*a+b*b)
                     printf("Case %d: yes\n",i);

          else
                    printf("Case %d: no\n",i);


     }
return 0;
}

