#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

int main()
{
    ll n,num;
    cin>>n;
    int c=1;
    int r=1;
    while(n--)
    {
        cin>>num;
        if(num==1){
            printf("2\n");
        }
        else{
            ll mv = (num*(num-1)) / 2;
            if(mv%2==0 and c!=2){
                printf("2\n");
                if(c==1) c=2;
                else c=1;
            }
            else{
                printf("1\n");
                if(c==1) c=2;
                else c=1;
            }
        }
        r=c;
    }


return 0;
}
