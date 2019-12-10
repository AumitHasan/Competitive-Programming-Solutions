#include<bits/stdc++.h>
using namespace std;

int main(){

    long long l,r,c=0,k;

    cin>>l>>r>>k;

    long long base = (long long) (log(l) / log(k));
    //cout<<base<<endl;


    while(1)
    {
        long long x = pow(k,base);

        if(x>r)
            break;

        if(x>=l){
            printf("%lld ",x);
            c=1;
        }

        base++;
    }

    if(c==0)
        cout<<"-1"<<endl;
    else
        cout<<endl;


return 0;
}
