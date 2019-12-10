#include<stdio.h>
main(){

     long a[4],c=0,i,j,num=4,temp;

     for(i=0;i<4;i++)
     {
        scanf("%ld",&a[i]);

     }

     for (i = 1; i <=4; i++) {
      for (j = 0; j < num-1; j++) {
         if (a[j] > a[j + 1]) {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
         }
      }
      num--;
    }

     for(i=0;i<4;i++)
     {
      // printf("%d ",a[i]);
        if(i>0 && a[i]==a[i-1])
             c++;
     }
     printf("%ld",c);
return 0;
}
