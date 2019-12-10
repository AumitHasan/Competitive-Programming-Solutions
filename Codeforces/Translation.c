#include<stdio.h>
#include<string.h>
int main(){

        int i,j=0,len1,len2,c=0;
        char str[100],ch[100],a[100];

        scanf("%s %s",str,ch);

        len1 = strlen(str);
        len2 = strlen(ch);
   if(len1==len2)
   {
        for(i=len2-1;i>=0;i--)
        {
            a[j]=ch[i];
            j++;
        }
        for(i=0;i<len1 && i<len2 ;i++)
        {
            if(str[i] != a[i])
            {
                c=1;
                break;
            }

        }
   }
   else
     c=1;

        if(c==1)
            printf("NO");
        else
            printf("YES");


return 0;
}
