#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,N=0,a,b,c,d;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("Case %d: ",N);
        if(abs(a-c)==abs(b-d)) printf("1\n");
        else{
            int x = abs(a-c);
            if(a>c) d+=x;
            else if(a<c) b+=x;
            int y = abs(b-d);

            if(y%2==0) printf("2\n");
            else printf("impossible\n");
        }
    }
    return 0;
}
