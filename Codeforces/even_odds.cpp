#include<iostream>
using namespace std;
int main(){

    long long n,k,even,odd,x,num;

    cin>>n>>k;

    even=n/2;
    if(n%2 != 0)
        odd=even+1;
    else
        odd=even;

    if(k<=odd)
        num=(k*2)-1;
    else{
        x=k-odd;
        num=x*2;
    }


    cout<<num;

return 0;
}
