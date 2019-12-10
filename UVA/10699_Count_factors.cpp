#include<bits/stdc++.h>
using namespace std;

#define max 1000001
#define mem(a) memset(a,0,sizeof(a))

long op[78498];
bool prime[max];

void seive()
{
    long k=-1;
    prime[0]=true;
    prime[1]=true;
    prime[2]=false;
    op[++k]=2;

    mem(prime);
    for(long i=3;i<=1000;i+=2)
        if(prime[i]==false)
        {
            op[++k]=i;
            for(long j=i*i;j<max;j+=2*i) prime[j]=true;
        }
    for(long i=1001;i<max;i+=2) if(prime[i]==false) op[++k]=i;
}

int main()
{
    seive();
    while(1)
    {
        long n;
        scanf("%ld",&n);
        if (n==0) break;
        printf("%ld : ",n);

        int cc=0;
        long c=0;
        if(prime[n]==false && n%2!=0){
            c=1;
            cc=1;
            if(n==2) n=1;
        }


        for(long i=0;op[i]*op[i]<=n&&i<78498;i++)
        {
            if(n%op[i]==0)
            {
                 c++;
                while(n%op[i]==0){
                    n/=op[i];
                }

            }
            if(prime[n]==false) break;
        }

        if(n>1 && cc==0) c++;

        printf("%ld\n",c);
    }

return 0;
}
