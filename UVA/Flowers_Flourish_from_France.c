#include<stdio.h>
#include<string.h>
int main(){

   char a[2000],flag;
   int i,c;

   while(gets(a)){

        if(!strcmp(a,"*"))
            break;


        c=0;
        flag=a[0];
        if(flag>90)
            flag-=32;


        for(i=1;a[i]!='\0';i++)
        {
            if(a[i-1]==' ')
            {

               if(a[i]>90)
                    a[i]-=32;

               if(a[i]!=flag)
                {
                    c=1;
                    break;
                }


            }

        }

        if(c==0)
            printf("Y\n");
        else
            printf("N\n");
   }



return 0;
}


