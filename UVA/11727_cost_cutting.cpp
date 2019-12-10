#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N=0,T,sal[3];
    scanf("%d",&T);
    while(++N<=T)
    {
        scanf("%d%d%d",&sal[0],&sal[1],&sal[2]);
        sort(sal,sal+3);
        printf("Case %d: %d\n",N,sal[1]);
    }

return 0;
}
