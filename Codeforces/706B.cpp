#include<bits/stdc++.h>
using namespace std;
#define mx 100003

int a[mx],res[mx];
struct st{
    int d,in;
    int operator < (const st & a) const
    {
        return d<a.d;
    }
}Q[100003];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&Q[i].d);
        Q[i].in = i;
    }

    sort(Q,Q+t);
    int c=0,k=0;

    for(int i=0;i<t;i++)
    {
        int num = Q[i].d;
        while(num>=a[k] and k<n)
        {
            c++;
            k++;
        }
        res[Q[i].in] = c;
    }

    for(int i=0;i<t;i++) printf("%d\n",res[i]);

return 0;
}
