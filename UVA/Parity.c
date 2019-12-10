#include<stdio.h>

int main(){

    long int l,test,i,j,c;

    scanf("%ld",&test);
    for(j=1;j<=test;j++){

        scanf("%ld",&l);

        i=c=0;
        while(l>0){

            if(l%2==1)
                c++;

            l/=2;
            i++;

        }

       if(c%2==0)
        printf("Case %ld: even\n",j);

        else
            printf("Case %ld: odd\n",j);


    }

return 0;
}
