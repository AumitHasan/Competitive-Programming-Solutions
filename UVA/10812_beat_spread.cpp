#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int s,d;
        scanf("%d%d",&s,&d);

        int x = (s+d)/2;
        int y = s-x;
        int c=0;

        if((s%2==0&&d%2==0) || (s%2==1&&d%2==1)) c=1;
        if(s<d || (x-y)!=d || (x+y)!=s || c==0) printf("impossible\n");
        else printf("%d %d\n",x,y);
    }

return 0;
}
