#include<stdio.h>
int main(){

    int cola,bottle;
    while(scanf("%d",&cola)==1){

    bottle=cola;

    while(cola>1){

        bottle+=cola/3;
        cola = cola/3 + cola%3;

        if(cola==2)
        {
            bottle++;
            break;
        }

    }
    printf("%d\n",bottle);
}
return 0;
}
