#include<stdio.h>
int main(){

      int test,i,j,k,temp,num,n,count;
scanf("%d",&test);
while(test>=1)
{
      scanf("%d",&n);
      int a[n];
      for(k=0;k<n;k++)
           scanf("%d",&a[k]);
      num=n;
      count=0;
      for (i = 1; i <=n; i++) {
      for (j = 0; j < num-1; j++) {
         if (a[j] > a[j + 1]) {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            count++;
         }
      }
     }

     printf("Optimal train swapping takes %d swaps.\n",count);
test--;
}
return 0;
}
