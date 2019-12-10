#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>



int main(){

    long test,i,j,k,c,x,len,l,y;
    char a[1000000],b[1000000];

    cin>>test;
    for(k=1;k<=test;k++){


        scanf("%s %s",&a,&b);
        len = strlen(a);
        l = strlen(b);

        c=y=0;
        for(i=0;i<=len-l;i++){

            x=y=0;

            if(len-i == l-1)
                break;

            if(a[i] != b[x])
                continue;

            for(j=i;x<l;j++)
            {

                if(a[j] != b[x]){
                    y=1;
                    break;
                }

            x++;
            }

            if(y == 0)
                    c++;

        }

        printf("Case %ld: %ld\n",k,c);


    }


return 0;
}
