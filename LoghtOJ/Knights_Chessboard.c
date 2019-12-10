#include<stdio.h>
int main(){

    int n,m,test,i,t;

    scanf("%d",&test);

    for(i=1;i<=test;i++)
    {
        n=m=t=0;

         scanf("%d %d",&m,&n);

         if(m==1 && n==1)
            printf("Case %d: %d\n",i,n);
        else if(m==2 && n==2)
            printf("Case %d: %d\n",i,n*m);

        else if(m==1)
            printf("Case %d: %d\n",i,n);
        else if(n==1)
            printf("Case %d: %d\n",i,m);



        else if(m==2){
            if(n%2 != 0)
                printf("Case %d: %d\n",i,n+1);
            else{
                t=n/4 * 4;
                if(n%4 != 0){
                    if(n%4 == 1)
                        t+=2;
                    else
                        t+=4;
                }
                printf("Case %d: %d\n",i,t);
            }
        }

        else if(n==2){
            if(m%2 != 0)
                printf("Case %d: %d\n",i,m+1);
            else{
                t=m/4 * 4;
                if(m%4 != 0){
                    if(m%4 == 1)
                        t+=2;
                    else
                        t+=4;
                }
                printf("Case %d: %d\n",i,t);
            }
        }


        else if((m*n)%2==0)
            printf("Case %d: %d\n",i,(m*n)/2);
        else
            printf("Case %d: %d\n",i,((m*n)/2+1));


    }


return 0;
}
