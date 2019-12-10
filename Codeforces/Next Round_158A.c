#include <stdio.h>

int main()
{
    int n,k,a[50],value,next=0,i;

    scanf("%d %d",&n,&k);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
         if(k==i)
            value=a[i];
    }

    for(i=1;i<=n;i++)
    {
       if(a[i] >= value && a[i]>0)
            next++;
    }
     printf("%d",next);
 return 0;
}

