#include<stdio.h>
int main(){

        int n,m,i,x;
        scanf("%d",&n);
        m=n*n;
        x=m-1;
        int a[m];

        for(i=0;i<m;i++)
        {
            a[i]=i+1;

        }


        for(i=0;i<=(m/2)-1;i++)
        {
            printf("%d %d\n",a[i],a[x-i]);

        }
return 0;
}
