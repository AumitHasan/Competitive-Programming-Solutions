#include<stdio.h>
int main(){

    int year,a[4],i,j,n,flag;

    scanf("%d",&year);

   while(1)
   {
      year++;
      n=year;
      flag=0;
     for(i=0;i<4;i++)
     {
        a[i]=n%10;
        n/=10;
     }

     for(i=0;i<3;i++)
     {
        for(j=i+1;j<4;j++)
        {
           if(a[i]==a[j])
           {
           flag=1;
           break;
           }
        }
        if(flag==1)
          break;
     }

     if(flag==0)
     {
        printf("%d",year);
        break;
     }

  }
      return 0;
}
