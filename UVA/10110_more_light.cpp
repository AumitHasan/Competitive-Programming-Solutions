#include<bits/stdc++.h>
using namespace std;

#define mx 65537
bool prime[65537];
long op[6542];

void seive()
{
    op[0]=2;
    long in=0;
    memset(prime,false,sizeof(prime));
    for(long i=3;i<=256;i+=2)
    {
        if(prime[i]==false){

            op[++in]=i;
            for(long j=i*i;j<mx;j+=2*i) prime[j]=true;
        }
    }
    for(long i=257;i<mx;i+=2)
        if(prime[i]==false) op[++in]=i;

}
int main()
{
    seive();

    while(1)
    {
        long n,div=1;
        scanf("%ld",&n);
        if(n==0) break;

        for(long i=0;i<6542&&op[i]*op[i]<=n;i++)
        {
            if(n%op[i]==0){
                long c=1;
                while(n%op[i]==0){
                    c++;
                    n/=op[i];
                }
                div*=c;
            }
        }

        if(n>2) div*=2;

        if(div%2==0) printf("no\n");
        else printf("yes\n");
    }

return 0;
}
