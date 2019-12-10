#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);

        printf("Case %d: %d\n",N,*max_element(a,a+n));
    }

return 0;
}
