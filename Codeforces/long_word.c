#include<stdio.h>
#include<string.h>
int main(){

        char ch[100];
        int len,test;
        scanf("%d",&test);

        while(test>0)
        {
            scanf("%s",ch);
            len = strlen(ch);

            if(len<11)
                printf("%s\n",ch);

            else
                printf("%c%d%c\n",ch[0],len-2,ch[len-1]);

         test--;
        }
return 0;
}
