#include<stdio.h>
#include<string.h>
int main(){

    int i,c,len;
    char str[20],check[7];

    scanf("%s",str);

    len=strlen(str);

    for(i=0;i<len;i++)
    {
        if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='H' || str[i]=='W' || str[i]=='Y')
        {
           continue;
        }

       else if((str[i]=='F' || str[i]=='P' || str[i]=='B' || str[i]=='V') && check[1] !=1 )
        {
            c=1;
            check[1]=1;
            printf("%d",c);
        }

        else if((str[i]=='C' || str[i]=='G' || str[i]=='J' || str[i]=='K' || str[i]=='Q' || str[i]=='S' || str[i]=='X' || str[i]=='Z') && check[2] !=1 )
        {
           c=2;//C G J K Q S X Z
           check[2]=1;
           printf("%d",c);
        }

        else if((str[i]=='D' || str[i]=='T') && check[3] !=1 )
        {
            c=3;
            check[3]=1;
            printf("%d",c);
        }

        else if((str[i]=='L') && check[4] !=1 )
        {
            c=4;
            check[4]=1;
            printf("%d",c);
        }

        else if((str[i]=='M' || str[i]=='N') && check[5] !=1 )
        {
            c=5;
            check[5]=1;
            printf("%d",c);
        }

        else if((str[i]=='R') && check[6] !=1 )
        {
            c=6;
            check[6]=1;
            printf("%d",c);
        }


    }

return 0;
}
