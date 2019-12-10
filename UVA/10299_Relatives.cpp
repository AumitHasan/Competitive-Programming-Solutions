#include<bits/stdc++.h>
using namespace std;

#define mx 31623
#define ll long int

bool bol[31623];
int only_prime[3400];

void seive()
{
    int in=-1;
    only_prime[++in]=2;
    for(int i=3;i<=177;i+=2)
    {
        if(bol[i]==false){
            only_prime[++in]=i;
            for(int j=i*i;j<mx;j+=2*i) bol[j]=true;
        }
    }

    for(int i=179;i<mx;i+=2){
        if(bol[i]==false) only_prime[++in]=i;
    }
}
int main()
{
    seive();
    while(1)
    {
        ll num,tsn;
        scanf("%ld",&num);

        if(num==1){
            printf("0\n");
            continue;
        }

        if(num==0) break;
        tsn=num;

        for(ll i=0;i<3400&&only_prime[i]*only_prime[i]<=num;i++)
        {
            if(num%only_prime[i]==0)
            {
                tsn-= tsn/only_prime[i];

                while(num%only_prime[i]==0) num/=only_prime[i];
            }
        }

        if(num>1) tsn-= tsn/num;

        printf("%ld\n",tsn);
    }

return 0;
}
