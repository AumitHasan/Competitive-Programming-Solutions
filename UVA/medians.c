#include<stdio.h>
#include<math.h>
int main(){

     double  m1,m2,m3,area,sm;

     while(scanf("%lf %lf %lf",&m1,&m2,&m3)==3)
     {
       sm=(m1+m2+m3)/2.0;
       area=(4.0/3.0)*sqrt(sm*(sm-m1)*(sm-m2)*(sm-m3));
       if(!(area>0)){
         area=-1.0;
         printf("%0.3lf\n",area);
        }
        else
           printf("%0.3lf\n",area);

     }
     return 0;
}
