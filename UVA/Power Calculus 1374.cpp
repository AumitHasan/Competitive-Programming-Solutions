#include<bits/stdc++.h>
using namespace std;

int n,min_step;

void power(int num,int step)
{

    if(step>min_step) return;

    if(num-1==n){
        int x = step+1;
        if(min_step>x) min_step = x;
        return;
    }
    else if(num+1==n){
        int x = step+1;
        if(min_step>x) min_step = x;
        return;
    }
    else if(num==n){
        if(min_step>step) min_step = step;
        return;
    }
    else if(num>n) return ;

    power(num+1,step+1);
    power(num+num,step+1);
}
int main()
{
    while(1){
        cin>>n;
        if(n==0) break;
        min_step=100000;
        power(1,0);
        cout<<min_step<<endl;
    }
    return 0;
}
