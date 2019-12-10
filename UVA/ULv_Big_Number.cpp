#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int num;
        double dis=0;
        scanf("%d",&num);
        for(int i=1;i<=num;i++)
        {
            dis += log10 (i);
        }

        int ans = floor(dis)+1;
        printf("%d\n",ans);
    }

return 0;
}
