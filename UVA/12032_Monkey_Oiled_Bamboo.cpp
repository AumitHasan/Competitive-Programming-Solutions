#include<bits/stdc++.h>
using namespace std;

int main()
{
    long T,N=0;
    cin>>T;
    while(++N<=T)
    {
        long n;
        scanf("%ld",&n);
        long rung[n+1];
        rung[0]=0;
        for(long i=1;i<=n;i++) scanf("%ld",&rung[i]);

        long k=rung[1];
        for(long i=1;i<n;i++)
        {
            long dif=abs(rung[i+1]-rung[i]);
            if(dif>k) k=dif;
            else if(dif==k) k++;
        }

        printf("Case %ld: %ld\n",N,k);
    }

return 0;
}
