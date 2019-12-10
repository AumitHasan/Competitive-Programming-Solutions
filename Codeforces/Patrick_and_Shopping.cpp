#include<bits/stdc++.h>
using namespace std;
int main(){

    long d1,d2,d3,min,dis;
    d1=d2=d3=min=dis=0;

    cin>>d1>>d2>>d3;

    dis=(2*d1)+(d3*2);
    min=dis;

    dis=0;

    dis=(2*d2)+(d3*2);
    if(dis<min)
        min=dis;

    dis=0;

    dis=d1+d2+d3;
    if(dis<min)
        min=dis;

    dis=0;

    dis=(2*d1)+(d2*2);
    if(dis<min)
        min=dis;

    cout<<min<<endl;



return 0;
}
