#include<bits/stdc++.h>
using namespace std;

#define max 10000001
#define mem(a) memset(a,0,sizeof(a))
#define ll long long

ll op[664580],k=-1;
bool prime[max];

void seive()
{
    op[++k]=2;
    mem(prime);
    for(ll i=3;i<=3162;i+=2)
        if(prime[i]==false)
        {
            op[++k]=i;
            for(ll j=i*i;j<max;j+=2*i) prime[j]=true;
        }
    for(ll i=3163;i<max;i+=2) if(prime[i]==false) op[++k]=i;

    op[++k]= 10000019;
}

int main()
{
    seive();

    while(1)
    {
        ll n;
        scanf("%lld",&n);
        if (n==0) break;

        if(n<0) n*=-1;

        ll c=0;
        ll rem=0;
        for(ll i=0;op[i]*op[i]<=n;i++)
        {
            if(n%op[i]==0)
            {
                c++;
                rem=op[i];
                while(n%op[i]==0){
                    n/=op[i];
                }

            }
        }

        if(n%2!=0 && n>1 && c>0){
            rem=n;
            c++;
        }

        if(c>1) printf("%lld\n",rem);
        else printf("-1\n");
    }

return 0;
}
