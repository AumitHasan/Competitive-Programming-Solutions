#include<bits/stdc++.h>
using namespace std;
#define N 1000000

int a[1000000];

void seive(){

    int i,j,s;
    s=sqrt(N);
    for(i=0;i<N;i++)
        a[i]=0;
    for(i=4;i<N;i+=2)
        a[i]=1;
    for(i=3;i<s;i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<N;j+=i)
                a[j]=1;
        }
    }

    a[0]=1;
    a[1]=1;
    a[2]=0;

}

int main(){

    int value,x,p,e,c;

    seive();

    while(scanf("%d",&value)==1){

        if(a[value]==1)
            printf("%d is not prime.\n",value);
        else{

            p=e=x=c=0;
            p=value;
            while(p>0){
                x=p%10;
                p/=10;
                e=(e*10)+x;
            }

            if(a[e]==0 && value!=e)
                c=1;

            if(c==0)
                printf("%d is prime.\n",value);
            else
                printf("%d is emirp.\n",value);

        }

        value=0;
    }


return 0;
}
