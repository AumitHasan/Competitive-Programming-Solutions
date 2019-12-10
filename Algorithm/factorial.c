#include<stdio.h>


int fact(int input)
{
    if(input==1)
        return 1;
    else
        return input*fact(input-1);

}

int main()
{
    int input;
    scanf("%d",&input);

    printf("%d! = %d\n",input,fact(input));

return 0;
}

