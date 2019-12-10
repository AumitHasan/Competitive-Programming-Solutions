#include<iostream>
using namespace std;
int main(){

    float a,dis,p,q,x,i,k,cl,res;

    a=p=q=cl=k=res=0;

    cin>>dis>>p>>q;

    a=p+q;

    x=(100*p)/a;
    k=dis;

    if(p+q==dis)
    {
        cout<<p<<endl;
        return 0;
    }

    while(a<k){

        k-=a;
        cl+=p;

    }

    res=cl+(k*x)/100;

    cout<<res<<endl;


return 0;
}
