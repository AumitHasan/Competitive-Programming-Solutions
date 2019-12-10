#include<bits/stdc++.h>
using namespace std;

int ps[10001];

int main()
{
    ps[1]=1;
    for(int i=3;i<=10000;i+=2)
    {
        if(i%5==0) continue;
        int m=0,n=i,j=0;
        while(1)
        {
            j++;
            m = (m*10)+1;
            m%=n;

            if(m%n==0)break;


        }

        ps[i]=j;
    }
    int in;
    while(~scanf("%d",&in)){

        printf("%d\n",ps[in]);
    }

return 0;
}
