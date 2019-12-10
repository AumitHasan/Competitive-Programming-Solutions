#include <bits/stdc++.h>
using namespace std;

#define set(a) memset(a,0,sizeof(a))
#define max 31622

bool p[32623];
long op[3401];

void seive()
{
    int in=-1;
    for(int i=3;i<=177;i+=2)
    {
        if(p[i]==false){
            op[++in]=i;
            for(int j=i*i;j<=max;j+=2*i) p[j]=true;
        }
    }
    for(int i=179;i<=max;i+=2)
        if(p[i]==false) op[++in]=i;

}
int main()
{
    seive();
    int T;
    cin>>T;
    while(T--)
    {
        long L,U,l;
        bool prime[50007]={false};
        scanf("%ld%ld",&L,&U);
        l=L;
        long num[50007];

        if(L<=2) L=3;
        if(L%2==0) L++;
        if(U%2==0) U--;
        long in=-1;
        for(int i=L;i<=U;i+=2) num[++in]=i;

        for(int i=0;op[i]*op[i]<=U && i<=3399;i++)
        {
            int j=0;
            long a=num[0]/op[i];

            if(num[0]==op[i]) j+=op[i];
            else if(a*op[i]==num[0]) j=0;
            else if(a==0){
                long dis=op[i]-num[0];
                j = dis/2+op[i];
            }
            else if(a>0){
                long b=(a+1)*op[i];
                if(b%2==0) b=(a+2)*op[i];
                long dis=b-num[0];
                j=dis/2;
            }

            for(int k=j;k<=in;k+=op[i]) prime[k]=true;
        }

        if(l<=2) printf("2\n");
        for(int k=0;k<=in;k++)
            if(prime[k]==false) printf("%ld\n",num[k]);

        if(T>0) cout<<endl;

    }

return 0;
}
