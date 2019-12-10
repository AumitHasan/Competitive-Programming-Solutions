#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,b,c,com[6];
    cin>>a>>b>>c;

    com[0] = a+(b*c);
    com[1] = a*(b+c);
    com[2] = a*b*c;
    com[3] = (a+b)*c;
    com[4] = (a*b)+c;
    com[5] = (a+b)+c;

    cout<<*max_element(com,com+6)<<endl;


}
