#include<stdio.h>
int main(){

    int n,i,j,k,temp;

    while(1){

        scanf("%d",&n);
        int a[n];
        k=n;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(i=1;i<=n;i++)
        {
           k--;
            for(j=0;j<k;j++)
            {
                if(a[j]<a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        /*for(i=0;i<n;i++)
            printf("%d ",a[i]);*/
        for(i=)

    }

return 0;
}
