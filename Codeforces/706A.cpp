#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        int t;
        double mn=100000.0;
        scanf("%d",&t);
        while(t--)
        {
            int x,y;
            double d;
            scanf("%d%d%lf",&x,&y,&d);
            d+= 0.0;
            double dis = sqrt(((a-x)*(a-x))+((b-y)*(b-y)));
            double res = dis/d;
            if(res<mn) mn = res;
        }
        printf("%.20lf\n",mn);

    }

return 0;
}
