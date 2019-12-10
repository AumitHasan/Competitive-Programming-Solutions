#include<stdio.h>
int main(){

    int n,a,b,c;
    scanf("%d %d %d",&n,&a,&b);

    c=n-a;
    if(c>(b+1))
        c=b+1;

    printf("%d",c);

return 0;
}
