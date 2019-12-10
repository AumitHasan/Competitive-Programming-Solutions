#include<bits/stdc++.h>
using namespace std;


int ar[6],sum,flag;

void call(int i,int val,int c)
{
    if(i>=6){
        if(c==3 && val==sum) flag = 1;
        return ;
    }
    call(i+1,ar[i]+val,c+1);
    call(i+1,val,c);
}
int main()
{
    for(int i=0;i<6;i++){
        cin>>ar[i];
        sum += ar[i];
    }
    if(sum%2==1){
        cout<<"NO"<<endl;
        return 0;
    }

    sum /= 2;

    call(0,0,0);

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
