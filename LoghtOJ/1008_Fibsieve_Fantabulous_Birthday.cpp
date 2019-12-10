#include<bits/stdc++.h>
using namespace std;

int main(){

    long long ex,pi,a,x,y,k,t,b;
    cin>>t;
    for(k=1;k<=t;k++)
    {

       a=pi=x=b=y=ex=0;
       cin>>ex;

       a=sqrt(ex);



       if(ex==a*a){

            if(a%2==0){
                x=a;
                y=1;
            }else{
                x=1;
                y=a;
            }
         cout<<"Case "<<k<<": "<<x<<" "<<y<<endl;
         continue;
       }

       a++;
       b=a*a;
       pi=b-(a-1);

       if(ex==pi){

            cout<<"Case "<<k<<": "<<a<<" "<<a<<endl;
            continue;
       }





       if(ex>pi){

            if(a%2==0){
                x=a;
                y=a-(ex-pi);
            }else{
                y=a;
                x=a-(ex-pi);
            }

       }

       else{

            if(a%2==0){
                y=a;
                x=a-(pi-ex);
            }else{
                x=a;
                y=a-(pi-ex);
            }

       }

     cout<<"Case "<<k<<": "<<x<<" "<<y<<endl;

    }


return 0;
}
