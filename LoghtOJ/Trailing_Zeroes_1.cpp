#include <bits/stdc++.h>
using namespace std;

int main()
{

    long n,div,c=0,test,j;

    scanf("%ld",&test);
    for(j=1;j<=test;j++)
    {
        div=1;
        c=n=0;
        scanf("%ld",&n);

            if(n%2==0)
                c++;

            while (n%2 == 0)
            {
               // printf("%d ", 2);
                n = n/2;
                c++;
            }
            if(c!=0) div*=c;

            for (int i = 3; i<=sqrt(n); i = i+2)
            {
                c=0;
                if(n%i==0)
                    c++;

                while (n%i == 0)
                {
                    //printf("%d ", i);
                    n = n/i;
                    c++;
                }
                if(c!=0)
                    div*=c;
            }

            if(n>2)
                div*=2;

    printf("Case %ld: %ld\n",j,div-1);
    }
return 0;
}
