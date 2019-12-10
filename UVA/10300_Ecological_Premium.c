#include<stdio.h>

int main(){

    long long t,a,b,c,f,i,j,s;

    while(scanf("%lld",&t)==1){

    for(j=1;j<=t;j++){

        s=0;

        scanf("%lld",&f);

        for(i=1;i<=f;i++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            s+=a*c;
        }
        printf("%lld\n",s);
      }
    }

return 0;
}
