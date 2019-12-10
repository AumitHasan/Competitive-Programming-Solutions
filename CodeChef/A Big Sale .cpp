#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    int n;
    double price,q,dis,tk,ttl=0.0;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        ttl = 0.0;
        while(n--){
            scanf("%lf %lf %lf",&price,&q,&dis);
            tk = price + (price * (dis/100.0));
            tk = tk - (tk * (dis/100.0));
            ttl += (price-tk) * q;
        }
        printf("%.9f\n",ttl);
    }
    return 0;
}
