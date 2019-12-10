#include<stdio.h>
#include<string.h>
int main(){

        int i,j,c=0;
        char str[50];
        scanf("%d",&i);

        scanf("%s",str);


            for(j=0;j<i-1;j++)
            {
                if(str[j]==str[j+1])
                    c++;

            }
    printf("%d",c);

return 0;
}
