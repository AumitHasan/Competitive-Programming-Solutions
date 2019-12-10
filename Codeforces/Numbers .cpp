#include<bits/stdc++.h>
using namespace std;

int base(int num,int bs)
{
    int sum=0;
    while(num>0){
        sum += num%bs;
        //cout<<sum<<" ";
        num/=bs;
    }
    //cout<<sum<<endl;
    return sum;
}
int main()
{
    //cout<<base(102,3);
    //return 0;

    int sum=0,n,c=0;
    cin>>n;
    for(int i=2;i<n;i++){
        c++;
        sum += base(n,i);
    }

    if(sum%c==0){
        sum = sum/c;
        c=1;
        //cout<<sum<<endl;
    }
    else{

        for(int ii=1;ii<=1000;ii++)
        {
            int x = min(sum,c);

            for(int i=2;i<=x;i++){
                if(sum%i==0 and c%i==0){sum/=i; c/=i; break;}
            }
        }
    }
    //else
    cout<<sum<<"/"<<c<<endl;
}
