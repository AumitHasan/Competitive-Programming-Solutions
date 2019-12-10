#include<stdio.h>
int main(){

        int x,y=1,c=0,i,cas=0;

        while(scanf("%d",&x)==1)
        {
           cas++;
           y=1;
           c=0;

           if(x<0)
                break;

           for(i=1;y<x;i++)
           {
                y=y*2;
                c++;
           }
        printf("Case %d: %d\n",cas,c);

        }

return 0;
}
