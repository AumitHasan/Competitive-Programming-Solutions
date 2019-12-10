#include<iostream>
using namespace std;
int main(){

    long num,i,c,x=1,r=0;
    cin>>num;
    c=1;
    while(1){
        x=x*2;
        if(x>num)
            break;
    }
    x=x/2;
    r=num-x;
    c+=(r/2)+(r%2);
    cout<<c<<endl;



return 0;
}
