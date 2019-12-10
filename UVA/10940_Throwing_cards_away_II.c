#include<stdio.h>

int a[500001];

void set_valu(){

a[0]=0;
a[1]=1;
a[2]=2;

    long x,pos,val,i,j;
    x=1;
    pos=2;
    val=2;
    i=0;
    for(j=1;i<=500000;j++)
    {

       x*=2;
       for(i=pos;i<=x;i++)
       {
         if(i>500000)
            break;

            a[i]=val;
            val+=2;
       }
       pos=i;
       val=2;
       if(i>500000)
            break;
    }

}

int main(){

    long n;
    set_valu();

    while(scanf("%ld",&n)==1)
    {
        if(n==0)
            break;

        printf("%ld\n",a[n]);

    }

return 0;
}

