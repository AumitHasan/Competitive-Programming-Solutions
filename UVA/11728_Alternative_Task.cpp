#include<bits/stdc++.h>
using namespace std;

int d[8000];

int main()
{
    for(int i=1;i<2000;i++)
    {
        int sum = 0;
        for(int j=1;j<=i/2;j++){
            if(i%j==0) sum+=j;
        }
        sum+=i;
        d[sum]=i;
    }
    int N=0;
    while(++N)
    {
        int n;
        scanf("%d",&n);
        if(n==0) break;

        printf("Case %d: ",N);

        if(d[n]==0){
            printf("-1\n");
            continue;
        }else printf("%d\n",d[n]);
    }

return 0;
}
