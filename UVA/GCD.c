#include<stdio.h>
int gcd(int x, int y);

int main(){

    int N,G,i,j;

while(scanf("%d",&N)==1)
 {
    if(N==0)
        break;
    G=0;

    for(i=1;i<N;i++){

          for(j=i+1;j<=N;j++)
          {

              G+=gcd(i,j);
          }
    }

    printf("%d\n",G);
}

return 0;
}

int gcd(int a, int b){

    int i;
    while(a!=0)
    {
        i=b%a;
        b=a;
        a=i;
    }

 return b;

}
