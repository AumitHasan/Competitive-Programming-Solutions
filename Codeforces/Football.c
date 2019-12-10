#include<stdio.h>
#include<string.h>
int main(){

        int j,c=0,len;
        char str[100];

        scanf("%s",str);
        len=strlen(str);

        if(len<7)
            printf("NO");

        else{


            for(j=0;j<len-1;j++)
            {
                if(str[j]==str[j+1])
                {
                    c++;
                    if(c==6)
                        break;
                }
                 else
                    c=0;

            }
          if(c==6)
            printf("YES");
          else
            printf("NO");
        }


return 0;
}

