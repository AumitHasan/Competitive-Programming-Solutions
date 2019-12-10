#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll b,c,n,cnt=0,i;
        scanf("%lld",&n);

        if(n==0){
            printf("Yes\n");
            continue;
        }
        for(i=1;i<=sqrt(n);i++){
            b = n-(i*i);
            c = sqrt(b);
            //cout<<b<<" "<<c<<endl;
            if((c*c)==b){
                printf("Yes\n");
                cnt=1;
                break;
            }
        }
        if(cnt==0) printf("No\n");
    }
    return 0;
}
