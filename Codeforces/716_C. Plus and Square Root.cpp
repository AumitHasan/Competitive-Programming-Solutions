#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

int main()
{
    ll lv=100000,n=6;
    //cin>>lv;
    if(lv==1){
        cout<<"14"<<endl<<"16"<<endl;
        return 0;
    }else cout<<"14"<<endl<<"16"<<endl;

    for(int i=3;i<=lv;i++){
        ll r = pow(n,.5)+1;
        //cout<<r<<endl;
        if(r==2) r=3;
        if(n%2==1 and r%2==0) r++;
        if(n%2==0 and r%2==1) r++;
       // cout<<"r: "<<r<<endl;
        for(ll j=r;;j+=2){
               //if(j==12) cout<<"j: "<<j<<endl;
               //if(j==12) cout<<j<<" "<<j*j<<" "<<n<<" "<<i<<endl;
            if(j%(i+1)==0 and (j*j-n)%i==0){
                //printf("%lld\n",(j*j-n)/i);
                n=r;
                break;
            }

            //getchar();
        }
    }
}
