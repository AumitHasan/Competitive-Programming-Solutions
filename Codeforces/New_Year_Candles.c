#include<stdio.h>

int main(){

        int a,b,x,y,sum;
        scanf("%d %d",&a,&b);
        sum=a;
        y=a;
        while(y>=b)
        {
            x=y/b;
            sum=sum+x;
            y=x+(y%b);
        }
        printf("%d",sum);

return 0;
}
