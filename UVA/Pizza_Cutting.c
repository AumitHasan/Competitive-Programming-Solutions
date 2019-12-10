#include<stdio.h>
int main(){

        long i,res;

        while(scanf("%ld",&i)==1)
        {
            if(i<0)
                break;

            res = ((i*(i+1))/2)+1;
            printf("%ld\n",res);

        }

return 0;
}
