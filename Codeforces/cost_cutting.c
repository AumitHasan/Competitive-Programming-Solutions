#include<stdio.h>
int mid(int a[],int size);
int main(){

      int tCase,s[3],p;
      scanf("%d",&tCase);
      while(tCase>0){

             scanf("%d %d %d",&s[0],&s[1],&s[2]);
             p=mid(s,3);
             printf("%d\n",p);
      tCase--;
      }
}

int mid(int a[],int size){

       int i,j,k,temp,v;
         for(i=1;i<=size;i++)
      {
      for(j=0;j<k;j++)
      {
         if(a[j]<a[j+1])
         {
           temp=a[j+1];
           a[j+1]=a[j];
           a[j]=temp;
         }

      }
       k--;
   }

    v=a[1];
      return v;
}
