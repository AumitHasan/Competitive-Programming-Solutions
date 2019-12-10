#include<iostream>
using namespace std;

int main(){

    long i,s,l,k,j=0,a=0;
    cin>>k>>l;

    while(1){
        if(l%k !=0)
        {
             break;
        }
         j=1;
        if(k==l)
        {

            a=0;
            break;
        }

        while(1){
                a++;
                s=l/k;
                l=s;
                if(l==k)
                    break;

        }
        if(l=k)
            break;

}
    if(j==0)
        cout<<"NO";
    else
        cout<<"YES"<<endl<<a;


return 0;
}
