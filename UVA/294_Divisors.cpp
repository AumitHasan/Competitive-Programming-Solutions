#include<bits/stdc++.h>
using namespace std;

#define mx 31623

bitset<mx>mark;
int prime[3401];

void seive()
{
    int in=-1;
    prime[++in]=2;
    for(int i=3;i*i<=mx;i+=2){
        if(mark[i]==0){
            for(int j=i*i;j<mx;j+=2*i) mark[j]=1;
        }
    }
    for(int i=3;i<mx;i+=2)
        if(mark[i]==0) prime[++in]=i;
}
int main()
{
    seive();

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,m=0,num;
        scanf("%d%d",&a,&b);
        for(int i=a;i<=b;i++)
        {
            int x = i;
            int div=1;
            for(int j=0;j<3401 and prime[j]*prime[j]<=i;j++){
                if(x%prime[j]==0){
                    int s=1;
                    while(x%prime[j]==0){
                        s++;
                        x/=prime[j];
                    }
                    div *= s;
                }
            }
            if(x>=2) div*=2;

            if(div>m){
                m = div;
                num = i;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",a,b,num,m);
    }

return 0;
}
