#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T)
    {
        double r,t;
        scanf("%lf%lf",&r,&t);

        double vm = r*t/(r-1);
        double vj = vm-t;

        printf("Case %d: %.3lf %.3lf\n",N,vj+1e-7,vm+1e-7);
    }

return 0;
}
