#include<stdio.h>
int main(){

        int in,x,c,a,res,start,endd,i;

        scanf("%d",&in);

        if(in>5){

                x=5;
                c=5;
                a=1;
                do{
                    x=x*2;
                    start=c;
                    c=c+x;
                    a=a*2;
                    endd=c;

                }while(c<=in);



                res=start;


                for(i=1;i<=5;i++)
                {
                    res=res+a;
                    if(in<=res)
                        break;
                }

        }

        else{

            i=in;
        }


        if(i==1)
            printf("Sheldon");
        else if(i==2)
            printf("Leonard");
        else if(i==3)
            printf("Penny");
        else if(i==4)
            printf("Rajesh");
        else
                printf("Howard");


return 0;
}

