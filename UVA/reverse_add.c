#include<stdio.h>

long reverse(long num)
{
    long x,value=0;

    while(num>0)
    {
        value= (value*10)+num%10;
         num/=10;
    }

return value;

}
int main(){

            long num,test,rev,i,add,check;

            scanf("%ld",&test);
            while(test--){

                    scanf("%ld",&num);
                    rev=0;
                    add=0;
                    rev=reverse(num);
                    add=num+rev;

                    for(i=1;i<999;i++)
                    {
                      check=reverse(add);
                        if(add == check)
                            break;

                        num=add;
                        rev=reverse(num);

                        add=num+rev;

                 }

                    printf("%ld %ld\n",i,add);

            }

return 0;
}
