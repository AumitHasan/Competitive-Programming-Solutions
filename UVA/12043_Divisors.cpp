#include<bits/stdc++.h>
using namespace std;

#define mx 100001
#define ll long long int

int prime[9592];
bool check[mx];

void seive()
{
    check[1]=check[0]=true;
    for(int i=4;i<mx;i+=2) check[i]=true;
    int in=-1;
    prime[++in]=2;
    for(int i=3;i<=316;i+=2)
    {
        if(check[i]==false){
            prime[++in]=i;
            for(int j=i*i;j<mx;j+=2*i) check[j]=true;
        }
    }
    for(int i=317;i<mx;i+=2)
        if(check[i]==false) prime[++in]=i;
    //cout<<in<<" "<<prime[in];
}
int d(int n)
{
    if(check[n]==false) return 2;

    int div=1;
    for(int i=0;i<=9591&&prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0){
            int c = 1;
            while(n%prime[i]==0){
                c++;
                n/=prime[i];
            }
            div *= c;
        }
    }
    if(n>=2) div *= 2;

return div;
}
int sd(int n)
{
    if(check[n]==false) return n+1;
    if(n==1) return 1;

    int sum=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0){
            int res = n/i;
            if(i>res) continue;
            if(res==i) sum+=i;
            else sum += (i+res);
        }
    }
    return sum;
}
int main()
{
    seive();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        ll sumd=0,cdiv=0;
        for(int i=a;i<=b;i++)
        {
            if(i%k==0){
                sumd += sd(i);
                cdiv += d(i);
            }
        }

        printf("%lld %lld\n",cdiv,sumd);
    }

return 0;
}
