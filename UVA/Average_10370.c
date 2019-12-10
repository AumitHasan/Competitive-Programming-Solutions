#include<stdio.h>
void calculate(int t );
 main(){

     int  tcase,t;
     scanf("%d",&tcase);
     while(tcase>0)
     {
        scanf("%d",&t);
        calculate(t);
     tcase--;
     }
     return 0;
}

void calculate(int t ){

    int array[t];
    int  i,total=0,avg=0,x=0;
    float y=0,persentage=0;
    for(i=0;i<t;i++)
    {
       scanf("%d",&array[i]);
       total=total+array[i];

    }
    avg=total/t;
    //printf("%d\n",avg);

    for(i=0;i<t;i++)
    {
       if(array[i]>avg)
       {

          y=y+1;
       }
    }
    //printf("%f\n",y);
    persentage=(y/t)*100;
    printf("%.3f%\n",persentage);

    t=0;

}
