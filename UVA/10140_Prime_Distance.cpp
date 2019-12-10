#include<bits/stdc++.h>
using namespace std;

#define set(a) memset(a,0,sizeof(a))
#define max 46340

bool  prime[500010];
long only_prime[4792];

void seive()
{
     long in=-1;
     only_prime[++in]=2;

     for(int i=3;i<=215;i+=2)
     {
         if(prime[i] == false)
         {
            only_prime[++in]=i;

             for(long long j=i*i;j<=max;j+=2*i)
                prime[j] = true;
         }
     }

     for(long i=217;i<=max;i+=2)
        if(prime[i] == false)   only_prime[++in]=i;
    only_prime[++in]=46351;

}


int main() {

	seive();
    long L,U;

    while(scanf("%ld%ld",&L,&U)==2)
    {
        if(U==2){
            printf("There are no adjacent primes.\n");
            continue;
        }

        long r=L;
        if(L==1) L=2;

        long xx=(U-L)/2+3;
        long num[xx],indx=-1,j=0,rem=0;
        set(prime);

        if(L%2==0) L++;
        if(U%2==0){rem=1; U--;}
        //cout<<L<<" "<<U<<" "<<xx<<endl;   2146483647 2147483647

        for(long i=L;i<=U;i+=2) num[++indx]=i;

        //cout<<num[0]<<" "<<num[indx]<<endl;

        for(long i=1;only_prime[i]*only_prime[i]<=num[indx];i++)
        {
            j=0;
            long add=only_prime[i];
            long a=num[0]/only_prime[i];

            if(only_prime[i]==num[0]) j=only_prime[i];

            else if(a*only_prime[i]==num[0]) j=0;

            else if(a*only_prime[i]<num[0] && a!=0){
                long b=(a+1)*only_prime[i];
                if(b%2==0) b=(a+2)*only_prime[i];
                long c=b-num[0];
                j=c/2;
            }
            else if(a==0){

                long b=only_prime[i];
                long c=b-num[0];
                j=c/2;
                j+=only_prime[i];

            }


            for(long k=j;k<=indx;k+=only_prime[i]) prime[k]=true;

        }

        long final_prime[500000],in=-1;
        if(L==2 || r<=2)final_prime[++in]=2;

        //cout<<prime[0]<<" "<<prime[indx]<<endl;

        for(long kk=0;kk<=indx;kk++)
            if(prime[kk]==false) {

                final_prime[++in]=num[kk];

            }
        //cout<<final_prime[0]<<" "<<final_prime[in]<<endl;
        //cout<<in<<endl;

        if(in<1){
            printf("There are no adjacent primes.\n");
            continue;
        }

        long min=INFINITY,v1,v2,v3,v4,mx=0;

        for(long m=0;m<in;m++)
        {
            long dif=final_prime[m+1]-final_prime[m];
            long dif1=final_prime[m+1]-final_prime[m];

            if(dif<min){
                min=dif;
                v1=final_prime[m];
                v2=final_prime[m+1];
            }
            if(dif1>mx){
                mx=dif1;
                v3=final_prime[m];
                v4=final_prime[m+1];
            }
        }

        printf("%ld,%ld are closest, %ld,%ld are most distant.\n",v1,v2,v3,v4);

    }

return 0;
}
