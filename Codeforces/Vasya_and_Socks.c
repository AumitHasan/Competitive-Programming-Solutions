#include<stdio.h>
int main(){

      int n,k,div,c=0,y;

      scanf("%d %d",&n,&k);

      while(n>=k)
      {
          div=n/k;
          y=div*k;
          c=c+y;
          n=(n-y)+div;
      }

      printf("%d",c+n);

return 0;
}
