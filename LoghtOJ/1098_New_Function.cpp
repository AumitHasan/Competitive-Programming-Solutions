#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll csod(ll num)
{
    ll s,e,a,b,i=2,res=0;
    while(num>=i)
    {
        //cout<<i<<endl;
        s=e=a=b=0;
        s = num/i;
        e = num/s;
        a = (e*(e+1))/2;
        b = (i*(i-1))/2;
        res += (a-b)*s;
        i=e+1;

    }
     res -= (num*(num+1))/2-1;
return res;
}

int main()
{
    //freopen("in.text","r",stdin);
    //freopen("out.text","w",stdout);

    int T,N=0;
    scanf("%d",&T);
    while(++N<=T)
    {
        ll num;
        scanf("%lld",&num);

        if(num<=2){
            printf("Case %d: 0\n",N);
            continue;
        }

        printf("Case %d: %lld\n",N,csod(num));
    }

return 0;
}
