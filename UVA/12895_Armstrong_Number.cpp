#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long T;
    cin>>T;
    while(T--)
    {
        long long n;
        scanf("%lld",&n);
        long long num=n;
        long long a[15],k=-1;
        while(n>0){
            a[++k]=n%10;
            n/=10;
        }
        long long sum;
        for(int i=1;i<=10;i++)
        {
            sum=0;
            for(int j=0;j<=k;j++){
                sum+=pow(a[j],i);
            }
            if(sum==num || sum>num) break;
        }

        if(sum==num) printf("Armstrong\n");
        else printf("Not Armstrong\n");
    }

return 0;
}
