#include<stdio.h>
#include<string.h>
int main(){

        char str[100];
        int i=0,c=0,j,a[26];
        scanf("%s",str);
        for(j=0;j<26;j++)
          a[j]=0;

        while(str[i] != '\0')
        {
            a[str[i]-'a']++;

        i++;
        }
        for(i=0;i<26;i++)
        {
            if(a[i] != 0)
            {
                //printf("%c = %d\n",('a'+i),a[i]);
                c++;
            }
        }
        //printf("%d\n",c);

        if(c%2==0)
            printf("CHAT WITH HER!");
        else
            printf("IGNORE HIM!");

return 0;
}
