#include<stdio.h>
#include<conio.h>
main()
{
    int n,c,t,i;
    scanf("%d", &n);

    for(i=2;i<=n/2;i++){
        if(n % i == 0){
            printf("Not prime");
            break;
        }
    }
}
