#include <stdio.h>
#include<string.h>

char S[101],str[205],comp[100];
int i,n,len,idx;

int main()
{

    scanf("%s",S);
    len = strlen(S);

    for(i=0;i<len;i++){
        str[i] = S[i];
        str[len+i] = S[i];
    }
    str[len*2] = '\0';

    scanf("%d ",&n);

    while(n--){
        scanf("%s",comp);

        if(strlen(comp) > len){
            printf("No\n");
            continue;
        }

        int flag = 0;

        for(int i=0;i<len;i++){
            int c = i;
            int tmp = 1;
            for(int j=0;j<strlen(comp);j++){
                if(str[c++] != comp[j]){
                    tmp = 0;
                    break;
                }
            }
            if(tmp==1) flag = 1;
        }

        if(flag==1) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
