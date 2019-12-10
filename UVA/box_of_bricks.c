#include<stdio.h>
int main(){

    int n,i,j,c,count,x,l=0;;

    while(scanf("%d",&n)==1){

        if(n==0)
            break;
        l++;
        int a[n];
        for(i=0;i<n;i++)
             a[i]=0;
        count=0;
        c=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            c=c+a[i];
        }
        c=c/n;

        for(i=0;i<n;i++)
        {
            if(a[i]<=c)
                continue;

            x=a[i]-c;
            count+=x;
            a[i]=c;

            for(j=0;i<n;j++)
            {
                if(j==i)
                    continue;
                if(a[j]<c)
                {
                    a[j]+=x;
                    x=0;
                    if(a[j]>c)
                    {
                        x=a[j]-c;
                        a[j]=c;
                    }
                }
                if(x==0)
                    break;
            }
        }

        printf("Set #%d\nThe minimum number of moves is %d.\n\n",l,count);

    }

return 0;
}
