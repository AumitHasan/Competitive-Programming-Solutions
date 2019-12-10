#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

int main()
{
   int T,N=0;
   scanf("%d",&T);
   while(++N<=T)
   {
        ll n,num;
        scanf("%lld",&n);
        num = n;
        printf("Case %d: ",N);

        if(n%2!=0){
            printf("Impossible\n");
            continue;
        }

        while(n%2==0){
            n/=2;
        }


        printf("%lld %lld\n",n,num/n);
   }

return 0;
}
