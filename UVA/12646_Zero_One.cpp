#include<iostream>
using namespace std;
#include<stdio.h>
int main(){

    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)==3){

        if(a==b && b==c)
            cout<<"*"<<endl;
        else if(a==b && b!=c)
            cout<<"C"<<endl;
        else if(b==c && c!=a)
            cout<<"A"<<endl;
        else if(a==c && c!=b)
            cout<<"B"<<endl;

    }



return 0;
}
